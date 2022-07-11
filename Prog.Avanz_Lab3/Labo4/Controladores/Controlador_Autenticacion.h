/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controlador_InicioSesion.h
 * Author: sebas
 *
 * Created on 23 de junio de 2022, 01:49 PM
 */

#ifndef CONTROLADOR_INICIOSESION_H
#define CONTROLADOR_INICIOSESION_H

#include "Interface_InicioSesion.h"
#include "Usuario.h"
#include "DataUsuario.h"
#include <string>
#include "ICollection.h"
#include "IColeccionable.h"
#include "List.h"
#include "IDictionary.h"
using namespace std;

class ControladorUsuario : public InterfaceInicioSesion{
public:
	ControladorUsuario();
	ControladorUsuario* getInstance();
	virtual ~ControladorUsuario();
	
	
	void IniciarSesion(string,string);//:bool;
	void CancelarSesion();
	void RegistrarUsuario();
	void IngresarDatosUsuario(DataUsuario);
	void CancelarAltaUsuario();
	void IngresarNickname(DataJugador);
	void ConfirmarAltaUsuario();
	Usuario* getUsuario();


private:
	static ControladorUsuario* instance;
	IDictionary* usuarios; // controladora tiene una coleccion de usuarios
	Usuario * usu; // un usuario
	
	
};

#endif /* CONTROLADOR_INICIOSESION_H */

