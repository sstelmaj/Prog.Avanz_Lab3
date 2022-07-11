/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.cpp
 * Author: lucho
 * 
 * Created on 23 de junio de 2022, 10:18 AM
 */

#include "Usuario.h"

Usuario::Usuario() {
}

Usuario::Usuario(const Usuario& orig) {
}

Usuario::~Usuario() {
}

ICollection* Usuario::getListaUsuarios() {
    return this->listaUsuarios;
}

