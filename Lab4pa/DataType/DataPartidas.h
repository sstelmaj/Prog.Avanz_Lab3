/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataPartidas.h
 * Author: paulo
 *
 * Created on 22 de junio de 2022, 05:27 PM
 */

#ifndef DATAPARTIDAS_H
#define DATAPARTIDAS_H
#include <iostream>
#include "string.h"
#include "DtTime.h"
#include "DtDate.h"
#include "ICollectible.h"

using namespace std;

class DataPartidas: public ICollectible{
public:
    DataPartidas(string,DtTime*,DtDate*, float);
    string getID();
    float getDuracion();
    DtTime* getTiempo();
    DtDate* getFecha();
    virtual ~DataPartidas();
private:
    string ID;
    float duracion;
    // El DataParida tiene una hora y una fecha como un DataTime dia,mes,año,hora,minutos,segundos    
    DtTime* hora; 
    DtDate* fecha;
};

#endif /* DATAPARTIDAS_H */

