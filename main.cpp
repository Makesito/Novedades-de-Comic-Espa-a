#include <iostream>
#include <functional>
#include <vector>
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

auto novedades = [] (string editorial){
    return [=] (string year, string month){
        if(editorial=="panini"){
            string web{"http://comics.panini.es/calendar/"};
            web.append(month);
            web.append("-");
            web.append(year);
            web.append("/");
            return web;
        }
        else if(editorial=="ecc"){
            string web{"https://www.ecccomics.com/ComunicadosNovedades/"};
            web.append(year);
            vector<string> meses {"enero","febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre","noviembre","diciembre"};
            int mespos{0};
            for(int i{0};i<meses.size();i++){
                if(meses.at(i)==month) mespos=i+1;
            }
            if(mespos<10) web.append("0");web.append(to_string(mespos));
            web.append("_ComunicadoNovedades.pdf");
            return web;
        }
    };
};

int main()
{
    cout<<"Bienvenido al buscador de novedades de comic: \n";
    cout<<"De que editorial quieres ver las novedades panini o ecc: \n";
    string editorial;
    cin>>editorial;
    cout<<"De que ciclo solar?: \n";
    string year;
    cin>>year;
    cout<<"Del mes? \n";
    string mes;
    cin>>mes;
    auto news = novedades(editorial);
    string url = news (year,mes);
    cout<<url<<endl;
    ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
    return 0;
}
