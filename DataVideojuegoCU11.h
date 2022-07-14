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
#include "Categoria.h"
#include "ICollection.h"

using namespace std;

class DataVideojuegoCU11: public ICollectible {
public:
    DataVideojuegoCU11(string,int,int,ICollection*,string, int);
    string getDescripcion();
    string getEmpresa();
    int getCostoPermanente();
    int getCostoMensual();
    int getPromPuntaje();
    void CatToString();
    virtual ~DataVideojuegoCU11();
private:
    string descripcion;
    string empresa;
    int costopermanente;
    int costomensual;
    int prom_puntaje;
    ICollection* categorias;
};

#endif/* DATAVIDEOJUEGOCU11_H */