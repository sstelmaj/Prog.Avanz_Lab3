/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interface_Jugador.h
 * Author: sebas
 *
 * Created on 23 de junio de 2022, 01:54 PM
 */

#ifndef INTERFACE_JUGADOR_H
#define INTERFACE_JUGADOR_H

#include <string>
using namespace std;

class InterfaceJugador {
public:
    
	virtual IDictionary* ListarVideojuegosSuscriptos();//:set(DataVideojuegosCU5)   
	virtual IDictionary* ListarVideojuegosSuscripciones();//:set(DataVideojuegosCU5);
	virtual	void IngresarNombreVideojuego(string);
	virtual void CancelarSuscripcion();
	virtual void IngresarTipoSuscripcion(/*TipoSuscripcion*/);
	virtual void IngresarMetodoPago(/*MetodoPago*/);
	virtual void CancelarCompra();
	virtual void ConfirmarAltaSuscripcion();
	virtual IDictionary* ListarVideoJuegos();//:set(DatajuegoCU6);
	virtual void AsignarPuntaje(string,int);
	virtual IDictionary* ListarVideoJuegosJugador();//:set(stringCU7);
	virtual IDictionary* HistorialPartidasIndividualesFinalizadas(string);//:set(DatapartidasCU7);
	virtual void ContinuarPartida(string,string);
	virtual void TransmitirPartida(bool);
	virtual IDictionary* ObtenerJugadores(string);//:set(stringCU7);
	virtual void UnirJugador(string);
	virtual void AltaPartida();
	virtual void CancelarPartida();
	virtual ICollectible* ListarPartidasUnidas();
	virtual void ConfirmarAbandono(int);
	virtual ICollectible* ListarPartidasSinTerminar();//:set(partidasSinTerminarCU9);
	virtual void FinalizarPartida();
	virtual ICollectible* ListarPartidasMultijugador();//:set(DataPartidasMultijugadorCU10);
	virtual void ElegirPartida_a_comentar(int);
	virtual IDictionary* ListarComentarios(/*idPartida*/);
	virtual void ElegirComentario(int);
	virtual void EscribirMensaje(string);
	virtual void EnviarComentario();
	virtual IDictionary* ListarTodosVideojuegos();//:set(stringCU11);
	virtual void ElegirVideojuego(string);//:set(DataVideoJuegosCU11);
	virtual IDictionary* ObtenerTodosJugadores();//:set(jugadoresCU12);
	virtual void SeguirJugador(string);
    
private:
};

#endif /* INTERFACE_JUGADOR_H */

