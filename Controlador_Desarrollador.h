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
#include "ICollection.h"
#include "Usuario.h"
#include "DataUsuario.h"
#include <string>
#include "ICollection.h"
#include "ICollectible.h"
#include "Lista.h"
#include "IDictionary.h"
#include "KeyString.h"
#include "ListaDicc.h"
#include "Categoria.h"
#include "Suscripcion.h"
#include "Servicio_Videojuego.h"

class ControladorD : public InterfaceD{
public:
	
	ControladorD(const ControladorD &arg);
	virtual ~ControladorD();

	static ControladorD* getInstance();
        
        //caso de uso 3
        void ConfirmarCategoria(Categoria*); // se cambió, antes era "AgregarCategoria()"
        void IngresarDatosCategoria(string,string,TipoCategoria);//Falta tipo categoria
        void CancelarOperacion();
        ICollection* ListarCategorias();
        
        //caso de uso 4
        void IngresarDatosVideojuego(string,string);
        void AsociarSuscripcion(tiempoValidez,int);
	void AsociarSuscripcion(int);
        ICollection* ObtenerCategoriasGeneros();
        void SeleccionarCategoriaG(string);
        ICollection* ObtenerCategoriasPlataformas();
	void SeleccionarCategoriaP(string);
        ICollection* ObtenerCategorias();
	void SeleccionarCategoria(string);
        void ConfirmarPublicacion(Usuario*);
	void CancelarPublicacion();
        
        void cargarDatosPrueba();
/*


	void IngresarDatosVideojuego(string,string);
	void AsociarSuscripcion(TiempoValidez,int);
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
*/
	
	
private:
        ControladorD();
	static ControladorD* instance;
        ICollection* categorias;
       
        string Tnombre;
        string Tdescripcion;
        ICollection * Tsuscripcion;
        ICollection * Tcategorias;
        Servicio_Videojuego* InServicio;
};

#endif /* CONTROLADOR_DESARROLLADOR_H */

