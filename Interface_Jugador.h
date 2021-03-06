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
#include "ICollectible.h"
#include "Historial.h"
#include "Suscripcion.h"
#include "Usuario.h"

using namespace std;

class InterfaceJugador {
public:
    
    
        virtual ICollection* ListarVideojuegosSuscriptos()=0;//:set(DataVideojuegosCU5)   
	virtual ICollection* ListarVideojuegosSuscripciones()=0;//:set(DataVideojuegosCU5);
	virtual	void IngresarNombreVideojuegoCU5(string)=0;
	virtual void CancelarSuscripcion(Videojuego*)=0;
	virtual void IngresarTipoSuscripcion(TipoSuscripcion)=0;
	virtual void IngresarMetodoPago(MetodoPago)=0;
        virtual void IngresarTiempoValidez(TiempoValidez)=0;
	virtual void CancelarCompra()=0;
	virtual void ConfirmarAltaSuscripcion()=0;
        
        //CU6
        virtual bool ListarVideoJuegosJugador()=0;
        virtual void IngresarNombreVideoJuego(string)=0;
        virtual ICollection* HistorialPartidasIndividualesFinalizadas()=0;//:set(DatapartidasCU7);
        virtual void ContinuarPartida(int)=0;	
        virtual void TransmitirPartida(bool)=0;
        virtual void UnirJugador(Jugador*)=0;
        virtual Partida* AltaPartidaM()=0;
        virtual Partida* AltaPartidaI()=0;
        virtual void CancelarPartida()=0;
        
        //CU7
        virtual IDictionary* ListarPartidasUnidas()=0;
        virtual int ConfirmarAbandono(int)=0;
        
        //CU8
        virtual void FinalizarPartida(int)=0;
        virtual void ListarPartidasSinTerminar()=0;
        
        
        //CARGAR DATUS PRUEBA
        virtual void cargarDatosPrueba()=0;
    /*
	
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
	
	
	virtual ICollectible* ListarPartidasMultijugador();//:set(DataPartidasMultijugadorCU10);
	virtual void ElegirPartida_a_comentar(int);
	virtual IDictionary* ListarComentarios(idPartida);
	virtual void ElegirComentario(int);
	virtual void EscribirMensaje(string);
	virtual void EnviarComentario();
	virtual IDictionary* ListarTodosVideojuegos();//:set(stringCU11);
	virtual void ElegirVideojuego(string);//:set(DataVideoJuegosCU11);
	virtual IDictionary* ObtenerTodosJugadores();//:set(jugadoresCU12);
	virtual void SeguirJugador(string);
    */
    
private:
    
};

#endif /* INTERFACE_JUGADOR_H */

