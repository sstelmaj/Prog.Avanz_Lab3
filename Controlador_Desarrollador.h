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

#include "Interface_Desarrollador.h"

#include "IDictionary.h"
#include "Servicio_VideoJuego.h"
#include "ICollection.h"
#include "Suscripcion.h"

class ControladorD : public InterfaceD{
public:
	ControladorD();
	ControladorD(const ControladorD &arg);
	virtual ~ControladorD();
        void IngresarDatosVideojuego(string,string);
        void AsociarSuscripcion(tiempoValidez,int);
	void AsociarSuscripcion(int);
        ICollection* ObtenerCategoriasGeneros();
        void SeleccionarCategoriaG(string);
        ICollection* ObtenerCategoriasPlataformas();
	void SeleccionarCategoriaP(string);
        ICollection* ObtenerCategorias();
	void SeleccionarCategoria(string);
        void ConfirmarPublicacion();
	void CancelarPublicacion();
	ControladorD* getInstance();
        
/*
	void ListarCategorias();//:Set(String)
	void IngresarDatosCategoria(string,string,TipoCategoria);//Falta tipo categoria
	void CancelarOperacion();
	void AgregarCategoria();
	void ListarJuego();//:Set(String)
	void SeleccionarVideoJuego(string);
	void confirmarEliminacion();
	void cancelarEliminacion();
	void ListarTodosVideojuegos();//:Set(String);
	void ElegirVideojuego(string);//:Set(DataVideojuegoCU11);
*/
	
private:
	static ControladorD* instance;	
        ICollection * categorias;
        string Tnombre;
        string Tdescripcion;
        ICollection * Tsuscripcion;
        ICollection * Tcategorias;
        Servicio_Videojuego* InServicio;
        
};

#endif /* CONTROLADOR_DESARROLLADOR_H */

