/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controlador_Desarrollador.h
 * Author: sebas
 *
 * Created on 23 de junio de 2022, 01:49 PM
 */

#ifndef CONTROLADOR_DESARROLLADOR_H
#define CONTROLADOR_DESARROLLADOR_H

#include "InterfaceD.h"

#include "IDictionary.h"
#include "ICollection.h"

class ControladorD : public InterfaceD{
public:
	ControladorD();
	ControladorD(const ControladorD &arg);
	virtual ~ControladorD();

	ControladorD* getInstance();
        

	void ListarCategorias();//:Set(String)
	void IngresarDatosCategoria(string,string,TipoCategoria);//Falta tipo categoria
	void CancelarOperacion();
	void AgregarCategoria();
	void IngresarDatosVideojuego(string,string);
	void AsociarSuscripcion(DtTiempoValidez,int);//Falta DtTiempoValidez
	void AsociarSuscripcion(int);
	void ObtenerCategoriasGeneros();//:Set(Genero)
	void SeleccionarCategoria(Genero);//Falta Genero
	void ObtenerCategoriasPlataformas();//: Set(Plataformas);
	void SeleccionarCategoria(Plataforma);
	void ObtenerCategorias();//:Set(Categoria);
	void SeleccionarCategoria(Categoria);
	void ConfirmarPublicacion();
	void CancelarPublicacion();
	void ListarJuego();//:Set(String)
	void SeleccionarVideoJuego(string);
	void confirmarEliminacion();
	void cancelarEliminacion();
	void ListarTodosVideojuegos();//:Set(String);
	void ElegirVideojuego(string);//:Set(DataVideojuegoCU11);

	
	
	
private:
	static ControladorD* instance;	
};

#endif /* CONTROLADOR_DESARROLLADOR_H */

