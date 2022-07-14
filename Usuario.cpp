/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.cpp
 * Author: lucho
 * 
 * Created on 23 de junio de 2022, 10:18 AM
 */

#include "Usuario.h"
#include "Suscripcion.h"
#include "IDictionary.h"
#include "Lista.h"
#include "ListaDicc.h"
#include "Partida.h"
#include "KeyInt.h"
#include <ctime>

Usuario::Usuario() {
}

Usuario::Usuario(const Usuario& orig) {
}

Usuario::~Usuario() {
}

Usuario::Usuario(string mail, string contrasenia){
    this->email=mail;
    this->contrasenia=contrasenia;
}

Desarrollador::Desarrollador(string mail, string contrasenia, string compania) : Usuario(mail, contrasenia){
    this->setEmail(mail);
    this->setContrasenia(contrasenia);
    
    this->nombreCompania=compania;
}

Jugador::Jugador(string mail, string contrasenia, string nickname, string descripcion) : Usuario(mail, contrasenia){
    this->setEmail(mail);
    this->setContrasenia(contrasenia);
    this->nickname=nickname;
    this->descripcion=descripcion;
    
    this->suscripciones= new Lista();
    this->partidas=new ListDicc();
}

Jugador::Jugador(){
}


//getters Usuario
ICollection* Usuario::getListaUsuarios() {
    return this->listaUsuarios;
}

string Usuario::getContrasenia(){
    return this->contrasenia;
}

string Usuario::getEmail(){
    return this->email;
}

//setters Usuario
void Usuario::setEmail(string email){
    this->email = email;
}
void Usuario::setContrasenia(string contra){
    this->contrasenia = contra;
}



//getter y setter de Desarrollador
string Desarrollador::getNombreCompania(){
    return this->nombreCompania;
}
void Desarrollador::setNombreCompania(string nombre){
    this->nombreCompania = nombre;
}


//getters y setters de Jugador
string Jugador::getNickname(){
    return this->nickname;
}
string Jugador::getDescripcion(){
    return this->descripcion;
}
void Jugador::setNickname(string nick){
    this->nickname = nick;
}
void Jugador::setDescripcion(string desc){
    this->descripcion = desc;
}



ICollection* Jugador::ListarVideojuegosSuscriptos(){
    ICollection* aux_suscripciones = new Lista();
    IIterator * it = this->suscripciones->iterator();
    while (it->hasNext()) {
        Suscripcion * S = (Suscripcion*) (it->getCurrent());
        aux_suscripciones->add(S);
        it->next();
    }
    return aux_suscripciones;
}

ICollection* Jugador::ListarNombresVideojuegos(){

}

void Jugador::CancelarSuscripcion(Videojuego* videojuego){
    IIterator* it = this->suscripciones->iterator();
    
    Suscripcion * sus;
    
    while(it->hasNext()){
        Suscripcion* actual=(Suscripcion*)it->getCurrent();
        if (actual->GetVideojuego()->getNombre() == videojuego->getNombre())
            sus=actual;
        it->next();
    }
    this->suscripciones->remove(sus);
    
}


void Jugador::ConfirmarAltaSuscripcion(Suscripcion* suscripcion){
    this->suscripciones->add(suscripcion);
}


void Jugador::UnirJugador(Jugador){}
IDictionary* Jugador::ObtenerJugadorConSuscripcion(string){}
IDictionary* Jugador::ListarInformacionPartida(string){}
void Jugador::KickearJugador(int){}
IDictionary* Jugador::ListarComentariosPartida(int){}
void Jugador::ElegirComentario(int){}
void Jugador::EnviarComentario(){}
void Jugador::SeguirJugador(Jugador){}



void Desarrollador::EliminarJuego(string){
}

IDictionary* Desarrollador::ListarVideojuegos(){
}


Jugador::~Jugador(){
}
Desarrollador::~Desarrollador() {
}


//CASO DE USO 6

IDictionary* Jugador::HistorialPartidasIndividualesFinalizadas(string _juego){
    IDictionary* ListaPartidas=new ListDicc();
    IIterator * it = this->partidas->getIteratorObj();
    
    while (it->hasNext()) {
        Partida* actual=(Partida*)it->getCurrent();
        if (Individual * pPI = dynamic_cast<Individual*> (actual) ){
            if(pPI->getVideojuego()->getNombre()==_juego){
                KeyInt* key=new KeyInt(pPI->getIdPartida());
                ListaPartidas->add(pPI,key);
            }   
        }
        it->next();
    }
    return ListaPartidas;
}
void Jugador::ContinuarPartida(int _idpartida){
    Partida* elegida=NULL;
    KeyInt* key=new KeyInt(_idpartida);
    elegida=(Partida*)this->partidas->find(key);
    if(!elegida){
        cout<<"No existe la partida";
        delete key;
        return;
    }else{
        cout<<"Partida Iniciada";
    }
}

void Jugador::AltaPartida(Partida* _nueva){
    KeyInt* key=new KeyInt(_nueva->getIdPartida());
    this->partidas->add(_nueva, key);
}

//CASO DE USO 7
IDictionary* Jugador::ListarPartidasMultijugador(){
    /*
    if(this->partidas == NULL){
        return this->partidas = new ListDicc();
    }else{
     */
        return this->partidas;
    
}




void Jugador::ListarPartidasSinTerminar() {

    IIterator * it = this->partidas->getIteratorObj();

    while (it->hasNext()) {
        Partida * P = (Partida*) (it->getCurrent());
        if (P->getFinalizada() == false){
                cout << "ID: ";
                cout << P->getIdPartida() << endl;
                cout << "Fecha de comienzo: ";
                P->getFecha()->toString(); cout<<endl;
                cout << "Videojuego: ";
                Videojuego* V = P->getVideojuego();
                cout << V->getNombre() << endl;

            }
        if (Individual * I = dynamic_cast<Individual*> (P)){  
            if (I->getPartidaNueva() == true) {
                    cout << "Partida nueva" << endl;
                } else {
                    cout << "Continuación de una partida anterior" << endl;
                }
            
        } else if (Mutlijugador * M = dynamic_cast<Mutlijugador*> (P)) {
            if (P->getFinalizada() == false) {
                if (M->getHost() == this->nickname) {
                    M->ListarInformacion();
                }
            }
        }
        it->next();
    }
}

void Jugador::FinalizarPartida(int idPartida) {

    time_t now = time(0);
    tm *ltm = localtime(&now);

    DtTime* dataTiempo;
    DtDate* dataDuracion;
    DtDate* fechaCreacion;
    int anio = 1900 + ltm->tm_year;
    int mes = 1 + ltm->tm_mon;
    int dia = ltm->tm_mday;
    int hora = 5 + ltm->tm_hour;
    int minutos = 30 + ltm->tm_min;
    int segundos = ltm->tm_sec;
    int cantidadJugadores;
    int limiteJugadores = 0;


    KeyInt* key = new KeyInt(idPartida);
    Partida* P = (Partida*) (partidas->find(key));

    fechaCreacion = P->getFecha();
    dataDuracion = new DtDate(anio - fechaCreacion->getAnio(), mes - fechaCreacion->getMes(), dia - fechaCreacion->getDia());

    P->setFinalizada(true);
    P->setDuracion(dataDuracion);

    if (Mutlijugador * M = dynamic_cast<Mutlijugador*> (P)) {
        dataTiempo = new DtTime(hora, minutos, segundos);

        cantidadJugadores = M->getJugadores()->size();

        while (limiteJugadores <= cantidadJugadores) {
            M->getHoraSalida()->add(dataTiempo);
            limiteJugadores += 1;
        }
    }
}