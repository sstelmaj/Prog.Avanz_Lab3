/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controlador_Jugador.h
 * Author: sebas
 *
 * Created on 23 de junio de 2022, 01:49 PM
 */

#ifndef CONTROLADOR_JUGADOR_H
#define CONTROLADOR_JUGADOR_H


#include "Interface_Jugador.h"
#include "IDictionary.h"
#include "Usuario.h"
#include "ICollectible.h"

#include <string>
using namespace std;

class ControladorJugador :public InterfaceJugador{
public:
	ControladorJugador();
	ControladorJugador* getInstance();
    virtual ~ControladorJugador();	
	
	IDictionary* ListarVideojuegosSuscriptos();//:set(DataVideojuegosCU5)   
	IDictionary* ListarVideojuegosSuscripciones();//:set(DataVideojuegosCU5);
	void IngresarNombreVideojuego(string);
	void CancelarSuscripcion();
	void IngresarTipoSuscripcion(/*TipoSuscripcion*/);
	void IngresarMetodoPago(/*MetodoPago*/);
	void CancelarCompra();
	void ConfirmarAltaSuscripcion();
	IDictionary* ListarVideoJuegos();//:set(DatajuegoCU6);
	void AsignarPuntaje(string,int);
	IDictionary* ListarVideoJuegosJugador();//:set(stringCU7);
	IDictionary* HistorialPartidasIndividualesFinalizadas(string);//:set(DatapartidasCU7);
	void ContinuarPartida(string,string);
	void TransmitirPartida(bool);
	IDictionary* ObtenerJugadores(string);//:set(stringCU7);
	void UnirJugador(string);
	void AltaPartida();
	void CancelarPartida();
	ICollectible* ListarPartidasUnidas();
	void ConfirmarAbandono(int);
	ICollectible* ListarPartidasSinTerminar();//:set(partidasSinTerminarCU9);
	void FinalizarPartida();
	ICollectible* ListarPartidasMultijugador();//:set(DataPartidasMultijugadorCU10);
	void ElegirPartida_a_comentar(int);
	IDictionary* ListarComentarios(/*idPartida*/);
	void ElegirComentario(int);
	void EscribirMensaje(string);
	void EnviarComentario();
	IDictionary* ListarTodosVideojuegos();//:set(stringCU11);
	void ElegirVideojuego(string);//:set(DataVideoJuegosCU11);
	IDictionary* ObtenerTodosJugadores();//:set(jugadoresCU12);
	void SeguirJugador(string);

	
	
	
private:
	static ControladorJugador* instance;
	IDictionary* usuSeleccionados;
	IDictionary* jugador;
	Usuario* usu;
};

#endif /* CONTROLADOR_JUGADOR_H */

