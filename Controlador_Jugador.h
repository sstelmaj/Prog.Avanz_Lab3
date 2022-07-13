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
#include "ICollection.h"
#include "Usuario.h"
#include "Controlador_Autenticacion.h"
#include "ICollectible.h"
#include "Servicio_Videojuego.h"


#include <string>
using namespace std;

class ControladorJugador :public InterfaceJugador{
public:
	
	static ControladorJugador* getInstance();
        void ListarVideoJuegosJugador();
        void IngresarNombreVideoJuego(string);
        ICollection* HistorialPartidasIndividualesFinalizadas();//:set(DatapartidasCU7);
        void ContinuarPartida(int);
        virtual ~ControladorJugador();	
        void TransmitirPartida(bool);
        void UnirJugador(Jugador*);
        Partida* AltaPartidaM();
        Partida* AltaPartidaI();
	void CancelarPartida();
	
    /*
	IDictionary* ListarVideojuegosSuscriptos();//:set(DataVideojuegosCU5)   
	IDictionary* ListarVideojuegosSuscripciones();//:set(DataVideojuegosCU5)
	void CancelarSuscripcion();
	void IngresarTipoSuscripcion(TipoSuscripcion);
	void IngresarMetodoPago(MetodoPago);
	void CancelarCompra();
	void ConfirmarAltaSuscripcion();
	IDictionary* ListarVideoJuegos();//:set(DatajuegoCU6);
	void AsignarPuntaje(string,int);
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
        ControladorJugador();
	static ControladorJugador* instance;
        ControladorUsuario* controladorusuario;
	IDictionary* usuSeleccionados;
	//IDictionary* jugador;
	Usuario* usu;
        Servicio_Videojuego* InServicio;
        string Tnombre;
        bool TTransmision;
        IDictionary* Tunidos;
        int cantPartidas;
};

#endif /* CONTROLADOR_JUGADOR_H */

