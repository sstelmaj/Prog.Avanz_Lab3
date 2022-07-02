/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataComentario.h
 * Author: paulo
 *
 * Created on 22 de junio de 2022, 06:06 PM
 */

#ifndef DATACOMENTARIO_H
#define DATACOMENTARIO_H

#include <iostream>
#include "string.h"
#include "DtTime.h"
#include "DtDate.h"
#include "ICollectible.h"

using namespace std;
class DataComentario: public ICollectible {
public:
    DataComentario(string, int, DtDate*, DtTime*);
    string getNombreJugador();
    int getIdentificador();
    DtTime* getTiempo();
    DtDate* getFecha();
    virtual ~DataComentario();
private:
    string nombreJugador;
    int identificador;
    DtTime* tiempo;
    DtDate* fecha;
};

#endif /* DATACOMENTARIO_H */

