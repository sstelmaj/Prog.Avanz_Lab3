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
#include "Servicio_Videojuego.h"
#include "Historial.h"
#include "Controlador_Autenticacion.h"


#include <string>
using namespace std;

class ControladorJugador : public InterfaceJugador{
public:
	
	static ControladorJugador* getInstance();
        virtual ~ControladorJugador();	
        
        ICollection* ListarVideojuegosSuscriptos();//:set(DataVideojuegosCU5)   
	ICollection* ListarVideojuegosSuscripciones();//:set(DataVideojuegosCU5);
	void IngresarNombreVideojuego(string);
	void CancelarSuscripcion(Videojuego*);
	void IngresarTipoSuscripcion(TipoSuscripcion);
	void IngresarMetodoPago(MetodoPago);
        void IngresarTiempoValidez(TiempoValidez);
	void CancelarCompra();
	void ConfirmarAltaSuscripcion();
        
        //CASO DE USO 6
        bool ListarVideoJuegosJugador();
        void IngresarNombreVideoJuego(string);
        ICollection* HistorialPartidasIndividualesFinalizadas();//:set(DatapartidasCU7);
        void ContinuarPartida(int);
        void TransmitirPartida(bool);
        void UnirJugador(Jugador*);
        Partida* AltaPartidaM();
        Partida* AltaPartidaI();
	void CancelarPartida();
        
        //CASO DE USO 7
        IDictionary* ListarPartidasUnidas();
        int ConfirmarAbandono(int);
        
        //CASO DE USO 8
        ICollectible* ListarPartidasSinTerminar();
        void FinalizarPartida(int);
	
    /*
	IDictionary* ListarVideojuegosSuscriptos();//:set(DataVideojuegosCU5)   
	IDictionary* ListarVideojuegosSuscripciones();//:set(DataVideojuegosCU5);
	void IngresarNombreVideojuego(string);
	void CancelarSuscripcion();
	void IngresarTipoSuscripcion(TipoSuscripcion);
	void IngresarMetodoPago(MetodoPago);
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
	IDictionary* ListarComentarios(idPartida);
	void ElegirComentario(int);
	void EscribirMensaje(string);
	void EnviarComentario();
	IDictionary* ListarTodosVideojuegos();//:set(stringCU11);
	void ElegirVideojuego(string);//:set(DataVideoJuegosCU11);
	IDictionary* ObtenerTodosJugadores();//:set(jugadoresCU12);
	void SeguirJugador(string);
    */
	
	
	
private:
        Servicio_Videojuego* servicio;
        ControladorUsuario* controladorU;
    
        ControladorJugador();
	static ControladorJugador* instance;
	IDictionary* usuSeleccionados;
	//IDictionary* jugador;
        
        //TEMPORTALES CU5
        string nombreJuegoTemporal;
        TipoSuscripcion tipoSuscripcionTemporal;
        MetodoPago metodoPagoTemporal;
        TiempoValidez duracionSuscripcionTemporal;
        
        //TEMPORALES CU6
        string Tnombre;
        bool TTransmision;
        IDictionary* Tunidos;
        int cantPartidas;
};

#endif /* CONTROLADOR_JUGADOR_H */

