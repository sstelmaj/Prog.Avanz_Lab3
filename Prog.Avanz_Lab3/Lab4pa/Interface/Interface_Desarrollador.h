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
using namespace std;

class InterfaceD {
public:
    
	virtual void ListarCategorias();//:Set(String)
	virtual void IngresarDatosCategoria(string,string,TipoCategoria);
	virtual void CancelarOperacion();
	virtual void AgregarCategoria();
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
    

private:
};

#endif /* INTERFACE_DESARROLLADOR_H */

