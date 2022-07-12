/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataJuegos.h
 * Author: paulo
 *
 * Created on 22 de junio de 2022, 05:23 PM
 */

#ifndef DATAJUEGOS_H
#define DATAJUEGOS_H
#include <iostream>
#include "string.h"
#include "ICollectible.h"

using namespace std;

class DataJuegos: public ICollectible {
public:
    DataJuegos(string,string);
    string getNombre();
    string getDescripcion();
    virtual ~DataJuegos();
private:
    string NombreJuego;
    string Descripcion;
};

#endif /* DATAJUEGOS_H */

