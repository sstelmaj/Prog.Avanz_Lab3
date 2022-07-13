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
#include "ICollectible.h"
#include "Lista.h"
#include "IDictionary.h"
#include "KeyString.h"
#include "ListaDicc.h"

using namespace std;

class ControladorUsuario : public InterfaceInicioSesion{
public:
	
	static ControladorUsuario* getInstance();
	virtual ~ControladorUsuario();
	
        void IngresarDatosUsuario(DataUsuario*);
        void IngresarNickname(DataJugador);
        void CancelarAltaUsuario();
        void ConfirmarAltaUsuario();
        void ObtenerJugadores(string);
        bool buscarJugador(string);
        void agregarPartida(Partida*);
        Jugador* NicknameJugadoresUnirPartida(string);
        
        void setDataUsuarioTemporal(DataUsuario*);
        IDictionary* getUsuarios();
        Usuario* getUsuario();
        
        void CancelarSesion();
        bool IniciarSesion(string,string);
        
        void setUsuario(Usuario*);

private:
        ControladorUsuario();
	static ControladorUsuario* instance;
	IDictionary* usuarios; // controladora tiene una coleccion de usuarios
	Usuario* usu; // un usuario
        DataUsuario* dataUsuarioTemporal;
};

#endif /* CONTROLADOR_INICIOSESION_H */

