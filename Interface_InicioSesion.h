/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interface_InicioSesion.h
 * Author: sebas
 *
 * Created on 23 de junio de 2022, 01:54 PM
 */

#ifndef INTERFACE_INICIOSESION_H
#define INTERFACE_INICIOSESION_H


#include "IDictionary.h"
#include "DataUsuario.h"
#include "Usuario.h"
using namespace std;

class InterfaceInicioSesion {
public:

	virtual bool IniciarSesion(string,string)=0;//:bool;
	virtual void CancelarSesion()=0;
	//virtual void RegistrarUsuario()=0;
	virtual void IngresarDatosUsuario(DataUsuario*)=0;//falta el datatype
	virtual void CancelarAltaUsuario()=0;
	virtual void IngresarNickname(DataJugador)=0;//falta el datatype
	virtual void ConfirmarAltaUsuario()=0;

  
private:
    
};

#endif /* INTERFACE_INICIOSESION_H */

