/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "fabrica.h"
#include "Controlador_Jugador.h"
#include "Controlador_InicioSesion.h"
#include "Controlador_Desarrollador.h"
#include<iostream>
#include<string>


using namespace std;
fabrica* fabrica::instance = NULL;

InterfaceJugador* fabrica::getInterfacejugador() {
	ControladorJugador* cont;
	return cont->getInstance();
}

InterfaceInicioSesion* fabrica::getInterfaceusuario() {
	ControladorUsuario* cont;
	return cont->getInstance();
}

InterfaceD* fabrica::getInterfaceD(){
	ControladorD* cont;
	return cont->getInstance();
}

fabrica::fabrica() {
	
}
fabrica* fabrica::getInstance() {
	if (instance == NULL)
		instance = new fabrica();
	return instance;
}
