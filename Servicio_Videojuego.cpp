/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Servicio_Videojuego.h"
#include "Videojuego.h"
#include "ListaDicc.h"
#include "KeyString.h"
#include "Usuario.h"
Servicio_Videojuego* Servicio_Videojuego::instance=NULL;

Servicio_Videojuego::Servicio_Videojuego() {
    this->videojuegos = new Lista();
}

Servicio_Videojuego* Servicio_Videojuego::getInstance(){
    if(instance==NULL)
        instance=new Servicio_Videojuego();
    return instance;
}

void Servicio_Videojuego::agregarVideoJuego(Videojuego* nuevo){
    //KeyString* key=new KeyString(nuevo->getNombre());
    
    this->videojuegos->add(nuevo);
}

ICollection* Servicio_Videojuego::mostrar(){
    return this->videojuegos;
}

void Servicio_Videojuego::ListarTodosVideoJuegos(){
    IIterator * it = videojuegos->iterator();
    Videojuego* juego;
    while(it->hasNext()){
        juego=(Videojuego*)it->getCurrent();
        cout<<juego->getNombre()<<endl;
        it->next();
    }
    delete it;
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

ICollection* Servicio_Videojuego::ListarVideojuegosSuscripciones(Jugador* mijugador){ //retorna una coleccion de videojuegos
    bool estaSuscripto;
    
    ICollection* aux_videojuegosSuscripciones = new Lista();
    
    IIterator* it_juegos = this->videojuegos->iterator();
    
    ICollection* YaSuscriptos = mijugador->ListarVideojuegosSuscriptos();
    IIterator* it_suscriptos = YaSuscriptos->iterator();
    
    while (it_juegos->hasNext()) {
        estaSuscripto=false;
        it_suscriptos=YaSuscriptos->iterator();
        Videojuego* V = (Videojuego*) (it_juegos->getCurrent());
        while(it_suscriptos->hasNext()){
            Suscripcion* S = (Suscripcion*) (it_suscriptos->getCurrent());
            if (V->getNombre() == S->GetVideojuego()->getNombre()){
                estaSuscripto=true;
            }
            it_suscriptos->next();
        }
        if (estaSuscripto==false){
            aux_videojuegosSuscripciones->add(V);
        }
        it_juegos->next();
    }
    
    return aux_videojuegosSuscripciones;
}

ICollection* Servicio_Videojuego::ListarVideojuegos(){
    ICollection* aux_videojuegos = new Lista();
    IIterator * it = this->videojuegos->iterator();
    while (it->hasNext()) {
        Videojuego * V = (Videojuego*) (it->getCurrent());
        aux_videojuegos->add(V);
        it->next();
    }
    return aux_videojuegos;
}


Videojuego* Servicio_Videojuego::MostrarVideoJuego(string _nombre){
    Videojuego* J;
    
    IIterator * it = this->videojuegos->iterator();
    while (it->hasNext()) {
        Videojuego * V = (Videojuego*) (it->getCurrent());
        if (V->getNombre()==_nombre)
            J=V;
        it->next();
    }
    return J;
}


void Servicio_Videojuego::CargarDatosPrueba(){

}