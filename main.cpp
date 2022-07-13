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
#include "CU3.h"
#include "CU2.h"
#include "CU4.h"
#include "CU6.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    fabrica* Fabrica;
   
    AgregarCategoria();
    AgregarCategoria();
    AgregarCategoria();
    
   PublicarVideoJuego();
   
    
    
    
    //int opcion;
    /*
    do {
        system("clear");
        cin>>opcion;
        switch (opcion) {
            case 1:
            {
                
                break;
            }
            case 2:
            {

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
    } while (opcion != 0);
    */

    return 0;
}

