/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataUsuario.h
 * Author: paulo
 *
 * Created on 22 de junio de 2022, 05:12 PM
 */

#ifndef DATAUSUARIO_H
#define DATAUSUARIO_H
#include <iostream>
#include "string.h"
#include "ICollectible.h"

using namespace std;

class DataUsuario: public ICollectible{
public:
    DataUsuario(string,string);
    string getEmail();
    string getContrasenia();
    virtual ~DataUsuario();
private:
    string email;
    string contrasenia;
};


class DataJugador: public DataUsuario{
public:
    DataJugador(string,string,string,string);
    string getNickname();
    string getDescripcion();
    virtual ~DataJugador();
private:
    string nickname;
    string descripcion;
};

class DataDesarrollador: public DataUsuario{
public:
    DataDesarrollador(string,string,string);
    string getEmpresa();
    virtual ~DataDesarrollador();
private:
    string empresa;
};
#endif /* DATAUSUARIO_H */

