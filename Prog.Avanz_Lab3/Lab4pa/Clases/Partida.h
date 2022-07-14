/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Partida.h
 * Author: lucho
 *
 * Created on 23 de junio de 2022, 09:51 AM
 */

#ifndef PARTIDA_H
#define PARTIDA_H
#include "Videojuego.h"
#include "DtDate.h"
#include "DtTime.h"
#include "IDictionary.h"
#include "ICollectible.h"
#include "ICollection.h"


#include <string>
using namespace std;

class Partida : public ICollectible  {
public:
    Partida();
    Partida(const Partida& orig);
    virtual ~Partida();
    
    Videojuego getVideojuego();
    bool getFinalizada();
    int getIdPartida();
    DtDate* getFecha();
    string getHora();
    DtTime* getDuracion();
    void setVideojuego(Videojuego);
    void setFinalizada(bool);
    void setIdPartida(int);
    void setFecha(DtDate);
    void setHora(string);
    void setDuracion(DtTime);
private:
    Videojuego* videojuego;
    bool finalizada;
    int idPartida;
    DtDate* fecha;
    string hora;
    DtTime* duracion;
};
//------------------------------------------------------------------------------
class Mutlijugador : public Partida {
public:
    Mutlijugador();
    Mutlijugador(const Mutlijugador& orig);
    virtual ~Mutlijugador();
    
    DtTime* getHoraSalida();
    bool getEnVivo();
    void setHoraSalida(DtTime);
    void setEnVivo(bool);
    
    IDictionary* ListarInformacionPartida(string);
    IDictionary* ListarInformacion();
    IDictionary* ListarComentarios();
    void EnviarComentario();
private:
    DtTime* horaSalida;
    bool enVivo;
    IDictionary* jugadores; // El mutlijugador tiene una coleccion de jugadores que participan en la partida
    IDictionary* comentarios; // El mutlijugador tiene una coleccion de comentarios que hizo los jugadores
    
};
//------------------------------------------------------------------------------
class Individual : public Partida {
public:
    Individual();
    Individual(const Individual& orig);
    virtual ~Individual();
    
    bool getPartidaNueva();
    void setPartidaNueva(bool);
private:
    bool partidaNueva;
};
#endif /* PARTIDA_H */

