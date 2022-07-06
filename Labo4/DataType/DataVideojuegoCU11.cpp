/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataVideojuegoCU11.cpp
 * Author: paulo
 * 
 * Created on 22 de junio de 2022, 06:11 PM
 */

#include "DataVideojuegoCU11.h"

DataVideojuegoCU11::DataVideojuegoCU11(string _descripcion, float _costopermanente, float _costomensual, string _empresa, float _promediopuntaje) {
    this->descripcion=_descripcion;
    this->costopermanente=_costopermanente;
    this->costomensual=_costomensual;
    this->empresa=_empresa;
    this->prom_puntaje=_promediopuntaje;
}

DataVideojuegoCU11::~DataVideojuegoCU11() {
}

string DataVideojuegoCU11::getDescripcion(){
    return this->descripcion;
}

string DataVideojuegoCU11::getEmpresa(){
    return this->empresa;
}

float DataVideojuegoCU11::getCostoMensual(){
    return this->costomensual;
}

float DataVideojuegoCU11::getCostoPermanente(){
    return this->costopermanente;
}

float DataVideojuegoCU11::getPromPuntaje(){
    return this->prom_puntaje;
}


