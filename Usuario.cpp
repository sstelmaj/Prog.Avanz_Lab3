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
#include "ListaDicc.h"

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



IDictionary* Jugador::ListarVideojuegosSuscriptos(){}
IDictionary* Jugador::ListarNombresVideojuegos(){}
void Jugador::ConfirmarAltaSuscripcion(){}
void Jugador::HistorialPartidasIndividualesFinalizadas(string){}
void Jugador::ContinuarPartida(int){}
void Jugador::UnirJugador(Jugador){}
IDictionary* Jugador::ObtenerJugadorConSuscripcion(string){}
void Jugador::AltaPartida(){}
IDictionary* Jugador::ListarInformacionPartida(string){}
void Jugador::KickearJugador(int){}
IDictionary* Jugador::ListarPartidasSinTerminar(){}
void Jugador::FinalizarPartida(){}

//CU 8 
IDictionary* Jugador::ListarPartidasMultijugador(){
    if(this->partidas == NULL){
        return this->partidas = new ListDicc();
    }else{
        return this->partidas;
    }
}
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