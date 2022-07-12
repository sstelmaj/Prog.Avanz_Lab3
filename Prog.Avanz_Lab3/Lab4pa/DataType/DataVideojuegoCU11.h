/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataVideojuegoCU11.h
 * Author: paulo
 *
 * Created on 22 de junio de 2022, 06:11 PM
 */

#ifndef DATAVIDEOJUEGOCU11_H
#define DATAVIDEOJUEGOCU11_H
#include <iostream>
#include "string.h"
#include "ICollectible.h"

using namespace std;

class DataVideojuegoCU11: public ICollectible {
public:
    DataVideojuegoCU11(string,float,float,string,float /*,vector de categorias*/);
    string getDescripcion();
    string getEmpresa();
    float getCostoPermanente();
    float getCostoMensual();
    float getPromPuntaje();
    virtual ~DataVideojuegoCU11();
private:
    string descripcion;
    float costopermanente;
    float costomensual;
    string empresa;
    float prom_puntaje;
};

#endif /* DATAVIDEOJUEGOCU11_H */

