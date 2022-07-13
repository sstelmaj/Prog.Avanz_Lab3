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

Partida::Partida(Videojuego* _juego, DtDate* _fecha, DtTime* _hora, int _id){
    this->videojuego=_juego;
    this->fecha=_fecha;
    this->hora=_hora;
    this->idPartida=_id;
}

Partida::Partida(const Partida& orig) {
}

int Partida::getIdPartida(){
    return this->idPartida;
}

DtTime* Partida::getHora(){
    return this->hora;
}

DtDate* Partida::getFecha(){
    return this->fecha;
}

float Partida::getDuracion(){
    return this->duracion;
}

Videojuego* Partida::getVideojuego(){
    return this->videojuego;
}

void Partida::setVideojuego(Videojuego* _juego){
    this->videojuego=_juego;
}
void Partida::setFinalizada(bool _fin){
    this->finalizada=_fin;
}
void Partida::setIdPartida(int _id){
    this->idPartida=_id;
}
void Partida::setFecha(DtDate* _fecha){
    this->fecha=_fecha;
}
void Partida::setHora(DtTime* _hora){
    this->hora=_hora;
}
void Partida::setDuracion(float _duracion){
    this->duracion=_duracion;
}
Partida::~Partida() {
}

/*----------------------------------Multijugador-------------------------------------------*/

Mutlijugador::Mutlijugador(Videojuego* _juego, DtDate* _fecha, DtTime* _hora, IDictionary* _unidos, bool _transmitida,int _id): Partida(_juego,_fecha,_hora,_id){
    this->setVideojuego(_juego);
    this->setFecha(_fecha);
    this->setHora(_hora);
    this->setIdPartida(_id);
    this->jugadores=_unidos;
    this->enVivo=_transmitida;
}

Mutlijugador::Mutlijugador(){}
    Mutlijugador::Mutlijugador(const Mutlijugador& orig){}
    Mutlijugador::~Mutlijugador(){}
    
    DtTime* Mutlijugador::getHoraSalida(){}
    bool Mutlijugador::getEnVivo(){}
    void Mutlijugador::setHoraSalida(DtTime){}
    void Mutlijugador::setEnVivo(bool){}
    
    IDictionary* Mutlijugador::ListarInformacionPartida(string){}
    IDictionary* Mutlijugador::ListarInformacion(){}
    IDictionary* Mutlijugador::ListarComentarios(){}
    void Mutlijugador::EnviarComentario(){}

/*-----------------------------------Individual--------------------------------------------------------*/

Individual::Individual(Videojuego* _juego, DtDate* _fecha, DtTime* _hora,int _id):Partida(_juego,_fecha,_hora,_id){
    this->setVideojuego(_juego);
    this->setFecha(_fecha);
    this->setHora(_hora);
    this->setIdPartida(_id);
}

Individual::Individual(const Individual& orig){}
Individual::~Individual(){}

bool Individual::getPartidaNueva(){}
void Individual::setPartidaNueva(bool){}