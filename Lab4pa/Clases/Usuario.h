/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.h
 * Author: lucho
 *
 * Created on 23 de junio de 2022, 10:18 AM
 */

#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>
#include "IDictionary.h"
#include "ICollectible.h"
#include "ICollection.h"

using namespace std;

class Usuario : public ICollectible {
public:
    Usuario();
    Usuario(const Usuario& orig);
    virtual ~Usuario();
    
    string getEmail();
    string getContraseña();
    ICollection* getListaUsuarios();
    void setEmail(string);
    void setContraseña(string);
private:
    string email;
    string contraseña;
    ICollection* listaUsuarios;

};
//------------------------------------------------------------------------------
class Desarrollador : public Usuario {
public:
    Desarrollador();
    Desarrollador(const Desarrollador& orig);
    virtual ~Desarrollador();
    
    string getNombreCompañia();
    void setNombreCompañia(string);
    
    IDictionary* ListarVideojuegos();
    void EliminarJuego(string);
private:
    string nombreCompañia;
    IDictionary * VideojuegosCreados;//El desarrollador tiene una coleccion de juegos que el creo
};
//------------------------------------------------------------------------------
class Jugador : public Usuario {
public:
    Jugador();
    Jugador(const Jugador& orig);
    virtual ~Jugador();
    
    string getNickname();
    string getDescripcion();
    void setNickname(string);
    void setDescripcion(string);
    
    IDictionary* ListarVideojuegosSuscriptos();
    IDictionary* ListarNombresVideojuegos();
    void ConfirmarAltaSuscripcion();
    void HistorialPartidasIndividualesFinalizadas(string);
    void ContinuarPartida(int);
    void UnirJugador(Jugador);
    IDictionary* ObtenerJugadorConSuscripcion(string);
    void AltaPartida();
    IDictionary* ListarInformacionPartida(string);
    void KickearJugador(int);
    IDictionary* ListarPartidasSinTerminar();
    void FinalizarPartida();
    IDictionary* ListarPartidasMultijugador();
    IDictionary* ListarComentariosPartida(int);
    void ElegirComentario(int);
    void EnviarComentario();
    void SeguirJugador(Jugador);
    
private:
    string nickname;
    string descripcion;
    IDictionary* jugadores;//Jugadores tiene una lista de jugadores
    IDictionary* partidas;//Jugadores tiene una lista de partidas
    IDictionary* suscripciones;//Jugadores tiene una lista de suscripciones
    IDictionary* Historial;//Jugadores tiene una lista de historial de partidas
    };
#endif /* USUARIO_H */

