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
#include "Lista.h"
#include "Partida.h"

#include "Videojuego.h"
#include "Suscripcion.h"

using namespace std;

class Usuario : public ICollectible {
public:
    Usuario();
    Usuario(string, string);
    Usuario(const Usuario& orig);
    virtual ~Usuario();
    
    string getEmail();
    string getContrasenia();
    ICollection* getListaUsuarios();
    void setEmail(string);
    void setContrasenia(string);
private:
    string email;
    string contrasenia;
    ICollection* listaUsuarios;
};
//------------------------------------------------------------------------------
class Desarrollador : public Usuario {
public:
    Desarrollador();
    Desarrollador(string, string, string);
    Desarrollador(const Desarrollador& orig);
    virtual ~Desarrollador();
    
    string getNombreCompania();
    void setNombreCompania(string);
    
    IDictionary* ListarVideojuegos();
    void EliminarJuego(string);
private:
    string nombreCompania;
    IDictionary * VideojuegosCreados;//El desarrollador tiene una coleccion de juegos que el creo
};
//------------------------------------------------------------------------------
class Jugador : public Usuario {
public:
    Jugador();
    Jugador(string, string, string, string);
    Jugador(const Jugador& orig);
    virtual ~Jugador();
    
    string getNickname();
    string getDescripcion();
    void setNickname(string);
    void setDescripcion(string);
    
    void CancelarSuscripcion(Videojuego*);
    
    IDictionary* ListarPartidasMultijugador();
    
    
    //CASO DE USO 8
    void ListarPartidasSinTerminar();
    void FinalizarPartida(int);
    
    ICollection* ListarVideojuegosSuscriptos();
    ICollection* ListarNombresVideojuegos();
    void ConfirmarAltaSuscripcion(Suscripcion*);
    IDictionary* HistorialPartidasIndividualesFinalizadas(string);
    void ContinuarPartida(int);
    void UnirJugador(Jugador);
    IDictionary* ObtenerJugadorConSuscripcion(string);
    void AltaPartida(Partida*);
    IDictionary* ListarInformacionPartida();
    void KickearJugador(int);
    
    void FinalizarPartida();
    IDictionary* ListarComentariosPartida(int);
    void ElegirComentario(int);
    void EnviarComentario();
    void SeguirJugador(Jugador);
       
    
private:
    string nickname;
    string descripcion;
    IDictionary* jugadores;//Jugadores tiene una lista de jugadores
    IDictionary* partidas;//Jugadores tiene una lista de partidas
    ICollection* suscripciones;//Jugadores tiene una lista de suscripciones
    IDictionary* Historial;//Jugadores tiene una lista de historial de partidas
    };
#endif /* USUARIO_H */

