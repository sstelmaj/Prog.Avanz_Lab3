/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fabrica.h
 * Author: sebas
 *
 * Created on 23 de junio de 2022, 01:57 PM
 */

#ifndef FABRICA_H
#define FABRICA_H

#include "Interface_Jugador.h"
#include "Interface_InicioSesion.h"
#include "Interface_Desarrollador.h"

using namespace std;

class fabrica{
private:
	static fabrica* instance;
	fabrica();
	InterfaceD* interfacedesa;
	InterfaceJugador* interfacejugador;
	InterfaceInicioSesion* interfaceusuario;
public:
	static fabrica* getInstance();
	InterfaceD* getInterfaceD();
	InterfaceJugador* getInterfacejugador();
	InterfaceInicioSesion* getInterfaceusuario();
};

#endif /* FABRICA_H */

