/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interface_Desarrollador.h
 * Author: sebas
 *
 * Created on 23 de junio de 2022, 01:53 PM
 */

#ifndef INTERFACE_DESARROLLADOR_H
#define INTERFACE_DESARROLLADOR_H

#include <string>
#include "Suscripcion.h"
#include "IDictionary.h"
#include "Servicio_VideoJuego.h"
#include "ICollection.h"
using namespace std;

class InterfaceD {
public:
    virtual void IngresarDatosVideojuego(string,string)=0;
    virtual void AsociarSuscripcion(tiempoValidez,int)=0;
    virtual void AsociarSuscripcion(int)=0;
    virtual ICollection* ObtenerCategoriasGeneros()=0;
    virtual void SeleccionarCategoriaG(string)=0;
    virtual ICollection* ObtenerCategoriasPlataformas()=0;
    virtual void SeleccionarCategoriaP(string)=0;
    virtual ICollection* ObtenerCategorias()=0;
    virtual void SeleccionarCategoria(string)=0;
    virtual void ConfirmarPublicacion()=0;
    virtual void CancelarPublicacion()=0;
    /*
	virtual void ListarCategorias();//:Set(String)
	virtual void IngresarDatosCategoria(string,string,TipoCategoria);
	virtual void CancelarOperacion();
	virtual void AgregarCategoria();
	virtual void AsociarSuscripcion(DtTiempoValidez,int);
	virtual void ListarJuego();//:Set(String)
	virtual void SeleccionarVideoJuego(string);
	virtual void confirmarEliminacion();
	virtual void cancelarEliminacion();
	virtual void ListarTodosVideojuegos();//:Set(string);
	virtual void ElegirVideojuego(string);//:Set(DataVideojuegoCU11);
    */
    

private:
};

#endif /* INTERFACE_DESARROLLADOR_H */

