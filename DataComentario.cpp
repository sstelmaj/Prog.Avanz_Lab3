/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataComentario.cpp
 * Author: paulo
 * 
 * Created on 22 de junio de 2022, 06:06 PM
 */

#include "DataComentario.h"

DataComentario::DataComentario(string _nombrejugador, int _identificador, DtDate* _fecha, DtTime* _tiempo) {
    this->nombreJugador=_nombrejugador;
    this->identificador=_identificador;
    this->tiempo=_tiempo;
    this->fecha=_fecha;
}

DataComentario::~DataComentario() {
}

string DataComentario::getNombreJugador(){
    return this->nombreJugador;
}

int DataComentario::getIdentificador(){
    return this->identificador;
}

DtDate* DataComentario::getFecha(){
    return this->fecha;
}

DtTime* DataComentario::getTiempo(){
    return this->tiempo;
}
