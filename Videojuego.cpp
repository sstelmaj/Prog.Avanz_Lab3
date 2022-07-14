#include "Videojuego.h"
#include "Lista.h"
#include "Suscripcion.h"

Videojuego::Videojuego() {
}

Videojuego::Videojuego(string _nombre,string _descripcion) {
    this->nombre=_nombre;
    this->descripcion=_descripcion;
    
}

Videojuego::Videojuego(const Videojuego& orig) {
}

Videojuego::~Videojuego() {
}

string Videojuego::getNombre(){
    return this->nombre;
}
string Videojuego::getDescripcion(){
    return this->descripcion;
}
int Videojuego::getPromedio(){
    return this->promedio;
}
void Videojuego::setNombre(string _nombre){
    this->nombre=_nombre;
}
void Videojuego::setDescripcion(string _descripcion){
    this->descripcion=_descripcion;
}
void Videojuego::setPromedio(int promedio){

}

void Videojuego::AsociarSuscripcion(ICollection * _suscripciones){
    this->suscripciones=new Lista();
    IIterator * it = _suscripciones->iterator();
    
    while(it->hasNext()){
        Suscripcion * actual=(Suscripcion*)it->getCurrent();
        suscripciones->add(actual);
        it->next();
    }
    
}
void Videojuego::AgregarCategorias(ICollection * _categorias){
    this->categorias=new Lista();
    IIterator * it = _categorias->iterator();
    
    while(it->hasNext()){
        Categoria * actual=(Categoria*)it->getCurrent();
        categorias->add(actual);
        it->next();
    }
    
}

ICollection* Videojuego::listarSuscripciones(){
    ICollection* aux_suscripciones = new Lista();
    IIterator * it = this->suscripciones->iterator();
    while (it->hasNext()) {
        Suscripcion * S = (Suscripcion*) (it->getCurrent());
        aux_suscripciones->add(S);
        it->next();
    }
    return aux_suscripciones;
}

ICollection* Videojuego::ListarInformacionVideojuego(){}
ICollection* Videojuego::ObtenerSumaHoras(){}