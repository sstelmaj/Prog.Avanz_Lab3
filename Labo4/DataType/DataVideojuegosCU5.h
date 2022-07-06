/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataVideojuegosCU5.h
 * Author: paulo
 *
 * Created on 22 de junio de 2022, 05:35 PM
 */

#ifndef DATAVIDEOJUEGOSCU5_H
#define DATAVIDEOJUEGOSCU5_H
#include <iostream>
#include "string.h"
#include "ICollectible.h"
#include "Suscripcion.h"

using namespace std;

class DataVideojuegosCU5: public ICollectible {
public:
    DataVideojuegosCU5(string,float,TipoSuscripcion);
    string getNombre();
    float getCosto();
    TipoSuscripcion getTipoSuscripcion();
    virtual ~DataVideojuegosCU5();
private:
    string nombre;
    float costo;
    TipoSuscripcion suscripcion ; //enum TipoSuscripcion {TEMPORAL, VITALICEA};
};

#endif /* DATAVIDEOJUEGOSCU5_H */

