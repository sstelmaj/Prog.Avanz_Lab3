/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Servicio_Videojuego.h
 * Author: paulo
 *
 * Created on 12 de julio de 2022, 12:55 PM
 */

#ifndef SERVICIO_VIDEOJUEGO_H
#define SERVICIO_VIDEOJUEGO_H
#include "string.h"
#include "Videojuego.h"
#include "IDictionary.h"
#include "ICollectible.h"
#include "ICollection.h"
#include "DataVideojuegoCU11.h"
using namespace std;

class Servicio_Videojuego {
public:
    Servicio_Videojuego* getInstance();
    void agregarVideoJuego(Videojuego*);
    void ListarTodosVideoJuegos();
    virtual ~Servicio_Videojuego();
    IDictionary* mostrar();
    //DataVideojuegoCU11* ElegirVideoJuego(string);
    
    
    /*
    ICollection* ListarVideojuegosSuscripciones();
    ICollection* ListarVideojuegosSuscriptos();
    void IngresarNombreVideojuego(string);
    ICollection* ListarVideoJuegos();
    void AsignarPuntaje(string, int);
    ICollection* ListarVideoJuegosJugador();    //set(String)
    ICollection* ListarTodosVideoJuegos();      //set(String)
    void IngresarDatosVideoJuegos();
    void AsociarSuscripcion(tiempoValidez,int);
    void AsociarSuscripcion(int);
    void confirmarEliminacion();
    void SeleccionarVideojuegos();
    void cancelarEliminacion();
    void ElegirVideoJuego(string);
    ICollection* ListarJuego();                 //set(String)*/
    
private:
    Servicio_Videojuego();
    IDictionary* juegos;
    static Servicio_Videojuego* instance;

};

#endif /* SERVICIO_VIDEOJUEGO_H */

