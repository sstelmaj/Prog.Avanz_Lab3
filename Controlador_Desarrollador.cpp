#include "Controlador_Desarrollador.h"
#include "Suscripcion.h"
#include "ListaDicc.h"
#include "Lista.h"
#include "Videojuego.h"
#include "Categoria.h"
#include <iostream>
using namespace std;
ControladorD* ControladorD::instance = NULL;


ControladorD::ControladorD() {	
    this->Tsuscripcion=new Lista();
    this->Tcategorias=new Lista();
    this->categorias=new Lista();
}

ControladorD::ControladorD(const ControladorD &arg) {
	
}

void ControladorD::IngresarDatosVideojuego(string _nombre, string _descripcion){
    this->Tnombre=_nombre;
    this->Tdescripcion=_descripcion;
}

void ControladorD::AsociarSuscripcion(tiempoValidez _tiempo, int _costo){
    Suscripcion *nueva=new Temporal(_tiempo,_costo);
    Tsuscripcion->add(nueva);
}

void ControladorD::AsociarSuscripcion(int _costo){
    Suscripcion *nueva=new Vitalicea(_costo);
    Tsuscripcion->add(nueva);
}

ICollection* ControladorD::ObtenerCategoriasGeneros(){
    ICollection* ListaGenero=new Lista();
    IIterator * it = this->categorias->iterator();
    
    while(it->hasNext()){
        Categoria * actual=(Categoria*)it->getCurrent();
        if (Genero * pG = dynamic_cast<Genero*> (actual) ){
            ListaGenero->add(actual);
        }
        it->next();
    }
    delete it;
    
    return ListaGenero;
}


void ControladorD::SeleccionarCategoriaG(string genero){
    IIterator * it = this->categorias->iterator();
    Genero* _generonuevo;
    while(it->hasNext()){
        Categoria * actual=(Categoria*)it->getCurrent();
        if (Genero * pG = dynamic_cast<Genero*> (actual) ){
            if(pG->getNombre()==genero){
                _generonuevo=pG;
                this->Tcategorias->add(_generonuevo);
                delete it;
                return;
            }
        }
        it->next();
    }
    delete it;
}

ICollection* ControladorD::ObtenerCategoriasPlataformas(){
    ICollection *ListaPlataforma=new Lista();
    IIterator * it = this->categorias->iterator();
    
    while(it->hasNext()){
        Categoria * actual=(Categoria*)it->getCurrent();
        if (Plataforma * pP = dynamic_cast<Plataforma*> (actual)){
            ListaPlataforma->add(actual);
        }
        it->next();
    }
    delete it;
    return ListaPlataforma;
}

void ControladorD::SeleccionarCategoriaP(string plataforma){
    IIterator * it = this->categorias->iterator();
    Plataforma* _plataforma;
    while(it->hasNext()){
        Categoria * actual=(Categoria*)it->getCurrent();
        if (Plataforma * pP = dynamic_cast<Plataforma*> (actual)){
            if(pP->getNombre()==plataforma){
                _plataforma=pP;
                this->Tcategorias->add(_plataforma);
                delete it;
                return;
            }
        }
        it->next();
    }
    delete it;
}

ICollection* ControladorD::ObtenerCategorias(){
    return this->categorias;
}

void ControladorD::SeleccionarCategoria(string _categoria){
    IIterator * it = this->categorias->iterator();
    Categoria * categoria;
    while(it->hasNext()){
        Categoria * actual=(Categoria *)it->getCurrent();       
            if(actual->getNombre()==_categoria){
                categoria=actual;
                this->Tcategorias->add(categoria);
                delete it;
                return;
            }
        it->next();
    }
    delete it;
}

void ControladorD::ConfirmarPublicacion(){
    Videojuego *nuevo=new Videojuego(this->Tnombre,this->Tdescripcion);
    nuevo->AgregarCategorias(this->Tcategorias);
    nuevo->AsociarSuscripcion(this->Tsuscripcion);
    InServicio->getInstance()->agregarVideoJuego(nuevo);
    
    
    
    
   /* 
    IDictionary* juegos;
    juegos=InServicio->getInstance()->mostrar();
    Videojuego* juego;
    IIterator * it = juegos->getIteratorObj();
    while(it->hasNext()){
        juego=(Videojuego*)it->getCurrent();
        cout<<juego->getNombre()<<endl;
        it->next();
    }
    delete it;*/
}

void ControladorD::CancelarPublicacion(){
    delete this->Tcategorias;
    delete this->Tsuscripcion;
}

ControladorD::~ControladorD() {
	
}

ControladorD* ControladorD::getInstance() {
    if (instance == NULL)
        instance = new ControladorD;
    return instance;
}

