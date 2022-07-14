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

#include "ICollection.h"
#include "Servicio_Videojuego.h"
#include <string>
using namespace std;

class InterfaceD {
public:
        virtual ICollection* ListarCategorias()=0;
        virtual void ConfirmarCategoria(Categoria*)=0;
        virtual void CancelarOperacion()=0;
        virtual void IngresarDatosCategoria(string,string,TipoCategoria)=0;
        
        
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
        
        virtual void cargarDatosPrueba()=0;
        
    /*
	virtual void IngresarDatosVideojuego(string,string);
	virtual void AsociarSuscripcion(DtTiempoValidez,int);
	virtual void AsociarSuscripcion(int);
	virtual void ObtenerCategoriasGeneros();//:Set(Genero)
	virtual void SeleccionarCategoria(Genero);
	virtual void ObtenerCategoriasPlataformas();//: Set(Plataformas);
	virtual void SeleccionarCategoria(Plataforma);
	virtual void ObtenerCategorias();//:Set(Categoria);
	virtual void SeleccionarCategoria(Categoria);
	virtual void ConfirmarPublicacion();
	virtual void CancelarPublicacion();
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

