/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria.h
 * Author: lucho
 *
 * Created on 23 de junio de 2022, 09:45 AM
 */

#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>
#include "ICollectible.h"
using namespace std;

typedef enum TipoCategoria{
    GENERO,PLATAFORMA ,OTROS
}TipoCategoria;


class Categoria : public ICollectible {
public:
    Categoria();
    Categoria(const Categoria& orig);
    virtual ~Categoria();
    
    string getNombre(); //Aca sera que tenemos que hacer que retorne  el tipo de categoria
    string getDescripcion();
    void setNombre(string);//y aca recibir de tipo categoria                         
    void setDescripcion(string);
private:
    string nombre;
    string descripcion;
};
//------------------------------------------------------------------------------
class Genero : public Categoria {
public:
    Genero();
    Genero(const Genero& orig);
    virtual ~Genero();
    
                      
private:
                             
};
//------------------------------------------------------------------------------
class Plataforma : public Categoria {
public:
    Plataforma();
    Plataforma(const Plataforma& orig);
    virtual ~Plataforma();
    

private:

};
#endif /* CATEGORIA_H */