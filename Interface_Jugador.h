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
#include "IDictionary.h"




using namespace std;

class InterfaceJugador {
public:
    
    virtual IDictionary * ListarPartidasUnidas()=0;
    virtual int ConfirmarAbandono(int)=0;
    /*
	virtual IDictionary* ListarVideojuegosSuscriptos()=0;//:set(DataVideojuegosCU5)   
	virtual IDictionary* ListarVideojuegosSuscripciones()=0;//:set(DataVideojuegosCU5);
	virtual	void IngresarNombreVideojuego(string)=0;
	virtual void CancelarSuscripcion()=0;
	virtual void IngresarTipoSuscripcion(TipoSuscripcion)=0;
	virtual void IngresarMetodoPago(MetodoPago)=0;
	virtual void CancelarCompra()=0;
	virtual void ConfirmarAltaSuscripcion()=0;
	virtual IDictionary* ListarVideoJuegos()=0;//:set(DatajuegoCU6);
	virtual void AsignarPuntaje(string,int)=0;
	virtual IDictionary* ListarVideoJuegosJugador()=0;//:set(stringCU7);
	virtual IDictionary* HistorialPartidasIndividualesFinalizadas(string)=0;//:set(DatapartidasCU7);
	virtual void ContinuarPartida(string,string)=0;
	virtual void TransmitirPartida(bool)=0;
	virtual IDictionary* ObtenerJugadores(string)=0;//:set(stringCU7);
	virtual void UnirJugador(string)=0;
	virtual void AltaPartida()=0;
	virtual void CancelarPartida()=0;
	
	
	virtual ICollectible* ListarPartidasSinTerminar()=0;//:set(partidasSinTerminarCU9);
	virtual void FinalizarPartida()=0;
	virtual ICollectible* ListarPartidasMultijugador()=0;//:set(DataPartidasMultijugadorCU10);
	virtual void ElegirPartida_a_comentar(int)=0;
	virtual IDictionary* ListarComentarios(idPartida)=0;
	virtual void ElegirComentario(int)=0;
	virtual void EscribirMensaje(string)=0;
	virtual void EnviarComentario()=0;
	virtual IDictionary* ListarTodosVideojuegos();//:set(stringCU11)=0;
	virtual void ElegirVideojuego(string);//:set(DataVideoJuegosCU11)=0;
	virtual IDictionary* ObtenerTodosJugadores();//:set(jugadoresCU12)=0;
	virtual void SeguirJugador(string)=0;
    */
    
private:
};

#endif /* INTERFACE_JUGADOR_H */

