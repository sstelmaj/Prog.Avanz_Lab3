/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lucho
 *
 * Created on 23 de junio de 2022, 09:23 AM
 */

#include <cstdlib>
#include "CU1.h"
#include "CU4.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    /*
    AltaDeUsuario();
    AltaDeUsuario();
    AltaDeUsuario();*/
    
    
    int opcion;
    
    
    do {
        system("clear");
        cout<<"Opcion: "
                "1.Alta de usuario\n"
                "2.PublicarVideoJuego\n";
        cin>>opcion;
        switch (opcion) {
            case 1:
            {
                AltaDeUsuario();
                break;
            }
            case 2:
            {
                PublicarVideoJuego();
                break;
            }
            case 3:
                system("clear");
            {
                break;
            }
            case 4:
                system("clear");
            {
                break;
            }
            case 5:
                system("clear");
            {
                    break;
            }
            case 6:
                system("clear");
            {
                    break;
            }
        }
        cout<<"0 para salir";
        cin>>opcion;
    } while (opcion != 0);
    

    return 0;
}

