/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria.cpp
 * Author: lucho
 * 
 * Created on 23 de junio de 2022, 09:45 AM
 */

#include "Categoria.h"

Categoria::Categoria(){
}

Categoria::Categoria(const Categoria& orig){
}

Categoria::~Categoria(){
}

Plataforma::Plataforma(){
}

Genero::Genero(){
}

Plataforma::~Plataforma(){
}

Genero::~Genero(){
}

//GETTERS Y SETTERS CATEGORIA
string Categoria::getNombre(){
    return this->nombre;
}
string Categoria::getDescripcion(){
    return this->descripcion;
}
void Categoria::setNombre(string nombre){
    this->nombre = nombre;
}                       
void Categoria::setDescripcion(string desc){
    this->descripcion = desc;
}





/*

//GETTERS Y SETTERS GENERO
TipoG Genero::getTipoGenero(){
    return this->tipoGenero;
}
void Genero::setTipoGenero(TipoG tipo){
    this->tipoGenero=tipo;
}



//GETTERS Y SETTERS PLATAFORMA
TipoP Plataforma::getTipoPlataforma(){
    return this->tipoPlataforma;
}

void Plataforma::setTipoPlataforma(TipoP tipo){
    this->tipoPlataforma=tipo;
}

*/

