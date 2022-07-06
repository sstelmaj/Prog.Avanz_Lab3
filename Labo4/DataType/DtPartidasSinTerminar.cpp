/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtPartidasSinTerminar.cpp
 * Author: paulo
 * 
 * Created on 22 de junio de 2022, 05:49 PM
 */

#include "DtPartidasSinTerminar.h"

DtPartidasSinTerminar::DtPartidasSinTerminar(int _id, DtDate* _fecha, string _nombreJuego) {
    this->id=_id;
    this->fecha=_fecha;
    this->NombreJuego=_nombreJuego;
}

DtPartidasSinTerminar::~DtPartidasSinTerminar() {
}

int DtPartidasSinTerminar::getid(){
    return this->id;
}
string DtPartidasSinTerminar::getNombreJuego(){
    return this->NombreJuego;
}

DtDate * DtPartidasSinTerminar::getFecha(){
    return this->fecha;
}

DtPST_individual::DtPST_individual(int _id, DtDate* _fecha, string _nombreJuego, bool _continuacion) : DtPartidasSinTerminar( _id, _fecha, _nombreJuego){
    this->continuacion=_continuacion;
}
DtPST_individual::~DtPST_individual(){}

bool DtPST_individual::getContinuacion(){
    return this->continuacion;
}

DtPST_multijugador::DtPST_multijugador(int _id, DtDate* _fecha, string _nombreJuego, bool _transmitida) : DtPartidasSinTerminar( _id, _fecha, _nombreJuego){
    this->transmitida=_transmitida;
}

DtPST_multijugador::~DtPST_multijugador(){
}

bool DtPST_multijugador::getTransmitida(){
    return this->transmitida;
}



