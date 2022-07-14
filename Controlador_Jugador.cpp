#include "Controlador_Jugador.h"
#include "Fabrica.h"
#include "IIterator.h"
#include "ICollectible.h"
#include "ICollection.h"
#include "Partida.h"
#include "Videojuego.h"
#include "ListaDicc.h"
#include "DataPartidasUnidas.h"
#include "KeyString.h"
#include "KeyInt.h"
#include <string>


ControladorJugador* ControladorJugador::instance = NULL;

ControladorJugador::ControladorJugador() {
	
}

//ControladorJugador::ControladorJugador(const ControladorJugador &arg) {
	
//}

ControladorJugador::~ControladorJugador() {
	
}


ControladorJugador* ControladorJugador::getInstance() {
    if (instance == NULL)
        instance = new ControladorJugador;
    return instance;
}

//Caso de uso 8
IDictionary* ControladorJugador::ListarPartidasUnidas(){
   // if(usu == NULL){ cout<<"No hay una sesion activa"<<endl}else{
    
    string k;
    Jugador* u = (Jugador*) (this->usu);
    IDictionary* partidas = u->ListarPartidasMultijugador();//ListarPartidasMultijugador() retorna una coleccion de partidas;
    IDictionary* unidas = new ListDicc();//creo una coleccion para copiar
    IIterator* it = u->ListarPartidasMultijugador()->getIteratorKey();
    while(it->hasNext()){
        Partida* p = (Partida*) (it->getCurrent());
        if(p->getFinalizada() == false){
            Multiijugador* m = (Multiijugador*) (p);
            k = to_string(m->getIdPartida());
            KeyString * key = new KeyString(k);
            //Videojuego* j = m->getVideojuego();
            DataPartidasUnidas * d = new DataPartidasUnidas(m->getIdPartida(),m->getFecha(),m->getDuracion(),m->getVideojuego()->getNombre(),m->getEnVivo(),m->getHost(),m->getjugadores());
            //me falta agregar al nombre del que creo la partida
            unidas->add(d,key);
        }
        it->next();
    }
    delete it;
    if (unidas->size() == 0){
         throw std::invalid_argument("El usuario no tiene partidas multijugadores \n");
         unidas = NULL;
         return unidas;
    }
       
    else{
        return unidas;
    } 
}

int ControladorJugador::ConfirmarAbandono(int id){
    KeyInt * ID = new KeyInt(id);
    Jugador* u = (Jugador*) (this->usu);
    IIterator* it = u->ListarPartidasMultijugador()->getIteratorKey();
    if (u->ListarPartidasMultijugador()->member(ID)){//si esta la partida
        while (it->hasNext()){ 
            Multiijugador* m = (Multiijugador*)(it->getCurrent()); // convierto en multijugador
            IIterator* iter = m->getjugadores()->getIteratorKey(); //iterador de la coleccion de jugadores
            while(iter->hasNext()){ // recorre jugador por jugador
                Jugador* j = (Jugador*) (iter->getCurrent());
                KeyString * name = new KeyString(j->getNickname());
                if(j->getNickname() == u->getNickname()){
                    m->getjugadores()->removeKey(name);
                    m->getjugadores()->removeObj(j);
                    
                    return 2;
                }
                iter->next();
            }
            delete iter;
            it->next();
        }
        delete it;
        
    }else{
        
        return 1; 
    }
   /* Retornos 
     [1] El id no existe
     [2] Partida abandonada exitosamente 
    */
}
