/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataVideojuegosCU5.cpp
 * Author: paulo
 * 
 * Created on 22 de junio de 2022, 05:35 PM
 */

#include "DataVideojuegosCU5.h"

DataVideojuegosCU5::DataVideojuegosCU5(string _nombre, float _costo /*, TipoSuscripcion*/) {
    this->nombre=_nombre;
    this->costo=_costo;
}

DataVideojuegosCU5::~DataVideojuegosCU5() {
    
}

string DataVideojuegosCU5::getNombre(){
    return this->nombre;
}

float DataVideojuegosCU5::getCosto(){
    return this->costo;
}
