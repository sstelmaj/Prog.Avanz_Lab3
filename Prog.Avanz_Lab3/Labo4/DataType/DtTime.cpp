/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtTime.cpp
 * Author: paulo
 * 
 * Created on 22 de junio de 2022, 04:46 PM
 */

#include "DtTime.h"

DtTime::DtTime(int _hora,int _minutos,int _segundos) {
    this->hora=_hora;
    this->minutos=_minutos;
    this->segundos=_segundos;
}

DtTime::~DtTime() {
}

int DtTime::gethora(){
    return this->hora;
}

int DtTime::getminutos(){
    return this->minutos;
}

int DtTime::getsegundos(){
    return this->segundos;
}

