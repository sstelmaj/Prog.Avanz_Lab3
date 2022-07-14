/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Partida.cpp
 * Author: lucho
 * 
 * Created on 23 de junio de 2022, 09:51 AM
 */

#include "Partida.h"


Partida::Partida() {
}

Partida::Partida(const Partida& orig) {
}

Partida::~Partida() {
}
//Caso de uso 8
bool Partida::getFinalizada(){
    return this->finalizada;
}
int Partida::getIdPartida(){
    return this->idPartida;
}
DtDate* Partida::getFecha(){
    return this->fecha;
}
DtTime* Partida::getDuracion(){
    return this->duracion;
}
Videojuego* Partida::getVideojuego(){
    return this->videojuego;
}

IDictionary* Multiijugador::getjugadores(){
    return this->jugadores;
}
bool Multiijugador::getEnVivo(){
    return this->enVivo;
}
string Multiijugador::getHost(){
    return host;
 }

void Multiijugador::setHost(string host) {
    this->host = host;
}
