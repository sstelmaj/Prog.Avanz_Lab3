/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Usuario.h"
#include "Controlador_Autenticacion.h"
//#include "Controlador_Desarrollador.h"
//#include "Controlador_Jugador.h"
#include "Fabrica.h"
#include "DataUsuario.h"
#include "CU1.h"

using namespace std;



//ESTO ES COMENTARIO DE SEBA


void AltaDeUsuario(){
    string mail, contrasenia, empresa;
    string nickname, descripcion;
    bool esigual;
    int opcion;
    DataUsuario* nuevoUsuario;
    fabrica *fabrica;
    
    cout<<"Ingrese mail"<<endl;
    cin>>mail;
    
    cout<<"Ingrese contrasenia"<<endl;
    cin>>contrasenia;
    
    cout<<"Que tipo de usuario desea registrar: \n[1]Jugador\n[2]Desarrollador"<<endl;
    cin>>opcion;
    
    if (opcion==2){
        cout<<"Ingrese la empresa en la que trabaja"<<endl;
        cin>>empresa;
        nuevoUsuario=new DataDesarrollador(mail, contrasenia, empresa);
    }
    else if(opcion==1){
        do{
            esigual=false;
            cout<<"Ingrese nickname"<<endl;
            cin>>nickname;
            
            //esigual = fabrica->getInterfaceusuario()->buscarJugador(nickname);
            if (esigual==true){
                cout<<"ERROR: el nickname ya existe"<<endl;
                cout<<"[0] cancelar alta\n[1] volver a internar"<<endl;
                cin>>opcion;
                if (opcion==0){
                    return;
                }
            }
        }while(esigual==true);
        
        cout<<"Ingrese descripcion"<<endl;
        cin>>descripcion;
        nuevoUsuario = new DataJugador(mail, contrasenia, nickname, descripcion);
    }
    fabrica->getInterfaceusuario()->IngresarDatosUsuario(nuevoUsuario);
    
    cout<<"[1] Confirmar alta"<<endl;
    cout<<"[0] Cancelar alta"<<endl;
    cin>>opcion;
    
    if(opcion==1){
        fabrica->getInterfaceusuario()->ConfirmarAltaUsuario();
    }
    else if (opcion==0){
        delete(nuevoUsuario);
        fabrica->getInterfaceusuario()->CancelarAltaUsuario();
    }
    
}
