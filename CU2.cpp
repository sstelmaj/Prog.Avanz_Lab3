
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Usuario.h"
#include "Controlador_Autenticacion.h"
#include "Fabrica.h"

#include "CU2.h"
using namespace std ;


void IniciarSesion(){
    string mail,contrasenia;
    bool esta;
    int opcion;
    fabrica * fabrica;
    
    do{
        opcion=0;
        cout<<"Ingresar mail : ";
        cin>>mail;
        cout<<"\nIngresar contrasenia : ";
        cin>>contrasenia;
      
        esta = fabrica->getInstance()->getInterfaceusuario()->IniciarSesion(mail,contrasenia);
     

        if(esta == false){
            cout<<"Usuario Invalido, vuelva a intetarlo"<<endl;
            cout<<"[1]Volver a intentarlo";
            cout<<"[2]cancelar sesion";
            cout<<"Ingresar opcion: ";
            cin>>opcion;
        }
        if(opcion == 2){
            
            fabrica->getInstance()->getInterfaceusuario()->CancelarSesion();
            return;
        }
        
    }while(opcion == 1 );
    if(esta == true){
        cout<<"Sesion Iniciada!";
    }
    else{
        cout<<"No se pudo iniciar sesion";
    }
}