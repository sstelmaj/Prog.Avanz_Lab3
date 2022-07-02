/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataJuegos.cpp
 * Author: paulo
 * 
 * Created on 22 de junio de 2022, 05:23 PM
 */

#include "DataJuegos.h"

DataJuegos::DataJuegos(string _nombre, string _descripcion) {
    this->NombreJuego=_nombre;
    this->Descripcion=_descripcion;
}

DataJuegos::~DataJuegos() {
}

string DataJuegos::getNombre(){
    return this->NombreJuego;
}

string DataJuegos::getDescripcion(){
    return this->Descripcion;
}

