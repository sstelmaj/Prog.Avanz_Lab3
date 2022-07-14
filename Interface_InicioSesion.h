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

#include <string>
#include "IDictionary.h"
#include "DataUsuario.h"
#include "Usuario.h"
using namespace std;

class InterfaceInicioSesion {
public:
    
        virtual void IngresarDatosUsuario(DataUsuario*)=0;
        virtual void IngresarNickname(DataJugador)=0;
        virtual void CancelarAltaUsuario()=0;
        virtual void ConfirmarAltaUsuario()=0;
        virtual bool buscarJugador(string)=0;
        
        virtual bool IniciarSesion(string,string)=0;
	virtual void CancelarSesion()=0;
	//virtual void RegistrarUsuario()=0;
        
        virtual void ObtenerJugadores(string)=0;
        virtual void agregarPartida(Partida*)=0;
        virtual Jugador* NicknameJugadoresUnirPartida(string)=0;
        
        virtual void cargarDatosPrueba()=0;
/*
	
	virtual Usuario* getUsuario()=0;
*/
  
private:
    
};

#endif /* INTERFACE_INICIOSESION_H */

