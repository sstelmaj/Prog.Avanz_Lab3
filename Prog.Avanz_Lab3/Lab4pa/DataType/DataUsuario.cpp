/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataUsuario.cpp
 * Author: paulo
 * 
 * Created on 22 de junio de 2022, 05:12 PM
 */

#include "DataUsuario.h"

DataUsuario::DataUsuario(string _email, string _contrasenia) {
    this->email=_email;
    this->contrasenia=_contrasenia;
}

DataUsuario::~DataUsuario() {
}

string DataUsuario::getContrasenia(){
    return this->contrasenia;
}

string DataUsuario::getEmail(){
    return this->email;
}

DataJugador::DataJugador(string _email, string _contrasenia, string _nickname, string _descripcion) : DataUsuario(_email, _contrasenia){
    this->nickname = _nickname;
    this->descripcion = _descripcion;     
}

DataJugador::~DataJugador(){
}

string DataJugador::getNickname(){
    return this->nickname;
}

string DataJugador::getDescripcion(){
    return this->descripcion;
}

DataDesarrollador::DataDesarrollador(string _email, string _contrasenia, string _empresa) : DataUsuario(_email, _contrasenia){
    this->empresa=_empresa;
}

DataDesarrollador::~DataDesarrollador(){
}
string DataDesarrollador::getEmpresa(){
    return this->empresa;
}
