/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Videojuego.h
 * Author: lucho
 *
 * Created on 23 de junio de 2022, 09:31 AM
 */
#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <string>
#include "Suscripcion.h"
#include "Categoria.h"
#include "IDictionary.h"
#include "ICollectible.h"
#include "ICollection.h"

using namespace std;

class Videojuego : public ICollectible {
public:
    Videojuego();
    Videojuego(string,string);
    Videojuego(const Videojuego& orig);
    virtual ~Videojuego();
    
    string getNombre();
    string getDescripcion();
    int getPromedio();
    void setNombre(string);
    void setDescripcion(string);
    void setPromedio(int);
    
    void AsociarSuscripcion(ICollection *);
    void AgregarCategorias(ICollection *);
    ICollection* ListarInformacionVideojuego();
    ICollection* ObtenerSumaHoras();
private:
    string nombre;
    string descripcion;
    int promedio;
    ICollection* estadisticas ;
    ICollection* categorias ;
    ICollection* suscripciones ;
};

#endif /* VIDEOJUEGO_H */


