/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "CU6.h"
#include "Suscripcion.h"
#include "Categoria.h"
#include "Fabrica.h"
#include "ICollection.h"
#include "DataPartidas.h"
#include "Usuario.h"

using namespace std;

void iniciarPartida(){
    string nombre,nickname;
    int opcion,continua;
    bool transmitida;
    fabrica* fabrica;
    ICollection* datosPartidas;
    Jugador* unir=NULL;
    Partida* nueva=NULL;
    Jugador* j =new Jugador();
    if(fabrica->getInterfacejugador()->ListarVideoJuegosJugador()==false){
        return;
    }
    cout<<"Ingrese nombre de juego para iniciar partida: ";
    cin>>nombre;
    fabrica->getInstance()->getInterfacejugador()->IngresarNombreVideoJuego(nombre);
    cout<<"Ingrese tipo de partida a iniciar: \n"
            "1.Partida Individual\n"
            "2.Partida Multijugador\n";
    cin>>opcion;
    switch(opcion){
        case 1:
             cout<<"¿Continuar partida? \n"
            "1.Si\n"
            "2.No\n";
             cin>>continua;
            if(continua==1){
                cout<<"Ingrese id de la partida a continuar: "<<endl;
                datosPartidas=fabrica->getInstance()->getInterfacejugador()->HistorialPartidasIndividualesFinalizadas();
                if(!datosPartidas){
                    cout<<"No tiene partidas iniciadas"<<endl;
                    return;
                }
                IIterator* it=datosPartidas->iterator();
                while(it->hasNext()){
                    DataPartidas* actual=(DataPartidas*) it->getCurrent();
                    cout<<"ID:"<<actual->getID()<<"\tFecha de creacion: "<<actual->getFecha()<<"\tHora de creacion: "<<actual->getTiempo()<<"\tDuracion de la partida: "<<actual->getDuracion()<<endl;
                }
                delete it;
                cin>>continua;
                fabrica->getInstance()->getInterfacejugador()->ContinuarPartida(continua); 
                return;
            }
            cout<<"Crear Partida?\n"
            "1.Si\n"
            "2.No\n";
            cin>>continua;
            if(continua==1){
                nueva=fabrica->getInstance()->getInterfacejugador()->AltaPartidaI();
                fabrica->getInstance()->getInterfaceusuario()->agregarPartida(nueva);
            }else{
                fabrica->getInstance()->getInterfacejugador()->CancelarPartida();
            }
            break;
        case 2:
            cout<<"¿Partida transmitida en vivo? \n"
            "1.Si\n"
            "2.No\n";
            cin>>continua;
            if(continua==1)
                transmitida=true;
            else{
                transmitida=false;
            }
            fabrica->getInstance()->getInterfacejugador()->TransmitirPartida(transmitida);
            fabrica->getInstance()->getInterfaceusuario()->ObtenerJugadores(nombre);
            cout<<endl;
            do{
            cout<<"Ingrese nickname para unir a la partida";
            cin>>nickname;
            unir=fabrica->getInstance()->getInterfaceusuario()->NicknameJugadoresUnirPartida(nickname);
            fabrica->getInstance()->getInterfacejugador()->UnirJugador(unir);
            cout<<"0 para seguir agregando"<<endl;
            cin>>continua;
            }while(continua==0);
            cout<<"Crear Partida?\n"
            "1.Si\n"
            "2.No\n";
            cin>>continua;
            if(continua==1){
                nueva=fabrica->getInstance()->getInterfacejugador()->AltaPartidaM();
                fabrica->getInstance()->getInterfaceusuario()->agregarPartida(nueva);
            }else{
                fabrica->getInstance()->getInterfacejugador()->CancelarPartida();
            }
            break;            
    }
}
