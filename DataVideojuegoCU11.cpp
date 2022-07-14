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

DataVideojuegoCU11::DataVideojuegoCU11(string _descripcion, int _costopermanente, int _costomensual, ICollection* _categoria,string _empresa, int _promediopuntaje) {
    this->descripcion=_descripcion;
    this->costopermanente=_costopermanente;
    this->costomensual=_costomensual;
    this->empresa=_empresa;
    this->prom_puntaje=_promediopuntaje;
    this->categorias=_categoria;
}

DataVideojuegoCU11::~DataVideojuegoCU11() {
}

string DataVideojuegoCU11::getDescripcion(){
    return this->descripcion;
}

string DataVideojuegoCU11::getEmpresa(){
    return this->empresa;
}

int DataVideojuegoCU11::getCostoMensual(){
    return this->costomensual;
}

int DataVideojuegoCU11::getCostoPermanente(){
    return this->costopermanente;
}

int DataVideojuegoCU11::getPromPuntaje(){
    return this->prom_puntaje;
}

void DataVideojuegoCU11::CatToString(){
    cout<<"Categorias:"<<endl;
    IIterator* it=this->categorias->iterator();
    while (it->hasNext()) {
            Categoria * C = (Categoria*) (it->getCurrent());
            cout<<C->getNombre()<<endl;
        }
}




