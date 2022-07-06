/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataPartidas.cpp
 * Author: paulo
 * 
 * Created on 22 de junio de 2022, 05:27 PM
 */

#include "DataPartidas.h"

DataPartidas::DataPartidas(string _id, DtTime* _hora, DtDate* _fecha, float _duracion) {
    this->ID=_id;
    this->hora=_hora;
    this->fecha=_fecha;
    this->duracion=_duracion;
}

DataPartidas::~DataPartidas() {
}

string DataPartidas::getID(){
    return this->ID;
}

float DataPartidas::getDuracion(){
    return this->duracion;
}

DtTime* DataPartidas::getTiempo(){
    return this->hora;
}

DtDate* DataPartidas::getFecha(){
    return this->fecha;
}