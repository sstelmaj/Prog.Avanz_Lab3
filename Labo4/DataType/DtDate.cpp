/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtDate.cpp
 * Author: paulo
 * 
 * Created on 22 de junio de 2022, 05:05 PM
 */

#include "DtDate.h"

DtDate::DtDate(int _dia, int _mes,int _anio) {
    this->dia=_dia;
    this->mes=_mes;
    this->anio=_anio;
}

DtDate::~DtDate() {
}

int DtDate::getAnio(){
    return this->anio;
}

int DtDate::getMes(){
    return this->mes;
}

int DtDate::getDia(){
    return this->dia;
}


