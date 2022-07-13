/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Servicio_Videojuego.h"
#include "Videojuego.h"
#include "ListaDicc.h"
#include "KeyString.h"
Servicio_Videojuego* Servicio_Videojuego::instance=NULL;

Servicio_Videojuego::Servicio_Videojuego() {
    this->juegos=new ListDicc();
}

Servicio_Videojuego* Servicio_Videojuego::getInstance(){
    if(instance==NULL)
        instance=new Servicio_Videojuego();
    return instance;
}

void Servicio_Videojuego::agregarVideoJuego(Videojuego* nuevo){
    KeyString* key=new KeyString(nuevo->getNombre());
    
    this->juegos->add(nuevo,key);
}

IDictionary* Servicio_Videojuego::mostrar(){
    return this->juegos;
}

void Servicio_Videojuego::ListarTodosVideoJuegos(){
    IIterator * it = juegos->getIteratorObj();
    Videojuego* juego;
    while(it->hasNext()){
        juego=(Videojuego*)it->getCurrent();
        cout<<juego->getNombre()<<endl;
        it->next();
    }
    delete it;
}

Videojuego* Servicio_Videojuego::MostrarVideoJuego(string _nombre){
    KeyString* key= new KeyString(_nombre);
    Videojuego* J=(Videojuego*)this->juegos->find(key);
    return J;
}
/*
DataVideojuegoCU11* Servicio_Videojuego::ElegirVideoJuego(string Nombjuego){
    string descripcion,empresa=" ";
    float costopermanente, costomensual,promedio;  
    Videojuego* juego;
    KeyString* key=new KeyString(Nombjuego);
    juego=juegos->find(key);
    
}*/

Servicio_Videojuego::~Servicio_Videojuego() {
}