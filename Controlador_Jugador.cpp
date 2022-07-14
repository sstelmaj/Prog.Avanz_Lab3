#include "Controlador_Jugador.h"
#include "Fabrica.h"
#include "Controlador_Autenticacion.h"
#include "DataPartidas.h"
#include "ListaDicc.h"
#include "KeyInt.h"
#include "DataPartidasUnidas.h"
#include <ctime>


ControladorJugador* ControladorJugador::instance = NULL;

ControladorJugador::ControladorJugador() {
    this->Tunidos=new ListDicc();
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


ICollection* ControladorJugador::ListarVideojuegosSuscriptos(){
    ICollection* videojuegos;
    Jugador * mijugador = dynamic_cast<Jugador*> (this->controladorU->getInstance()->getUsu());
    videojuegos = mijugador->ListarVideojuegosSuscriptos();
    return videojuegos;
} 
ICollection* ControladorJugador::ListarVideojuegosSuscripciones(){
    ICollection* videojuegosSuscripciones;
    Jugador * mijugador = dynamic_cast<Jugador*> (this->controladorU->getInstance()->getUsu());
    videojuegosSuscripciones = this->servicio->getInstance()->ListarVideojuegosSuscripciones(mijugador);
    return videojuegosSuscripciones;
}
void ControladorJugador::IngresarNombreVideojuegoCU5(string nombre){
    this->nombreJuegoTemporal=nombre;
}
void ControladorJugador::CancelarSuscripcion(Videojuego* videojuego){
    Jugador * mijugador = dynamic_cast<Jugador*> (this->controladorU->getInstance()->getUsu());
    mijugador->CancelarSuscripcion(videojuego);
}
void ControladorJugador::IngresarTipoSuscripcion(TipoSuscripcion tipo){
    this->tipoSuscripcionTemporal=tipo;
}
void ControladorJugador::IngresarMetodoPago(MetodoPago metodo){
    this->metodoPagoTemporal=metodo;
}
void ControladorJugador::IngresarTiempoValidez(TiempoValidez tiempo){
    this->duracionSuscripcionTemporal=tiempo;
}
void ControladorJugador::CancelarCompra(){
    
}
void ControladorJugador::ConfirmarAltaSuscripcion(){
    Suscripcion* sus;
    
    ICollection* juegos = this->servicio->getInstance()->ListarVideojuegos();
    IIterator * it = juegos->iterator();
    while(it->hasNext()){
        Videojuego * V =(Videojuego *)it->getCurrent();       
        if(V->getNombre()==this->nombreJuegoTemporal){
            ICollection* aux_suscripciones = V->listarSuscripciones();
            IIterator* it_suscripciones = aux_suscripciones->iterator();
            while(it_suscripciones->hasNext()){
                Suscripcion* S = (Suscripcion *)it_suscripciones->getCurrent();
                if (Vitalicea * vit = dynamic_cast<Vitalicea*> (S)){
                    if ((int)this->tipoSuscripcionTemporal==1){
                        Jugador* jugadorActual = dynamic_cast<Jugador*> (this->controladorU->getInstance()->getUsu());
                        jugadorActual->ConfirmarAltaSuscripcion(S);
                    }
                }
                else if (Temporal * temp = dynamic_cast<Temporal*> (S)){
                    if (temp->getPeriodoValidez()==this->duracionSuscripcionTemporal && (int)this->tipoSuscripcionTemporal==0){
                        Jugador* jugadorActual = dynamic_cast<Jugador*> (this->controladorU->getInstance()->getUsu());
                        jugadorActual->ConfirmarAltaSuscripcion(S); 
                    }
                }
                
                    it_suscripciones->next();
                }

            }
        it->next();
        }
}


//CASO DE USO 6

bool ControladorJugador::ListarVideoJuegosJugador(){
    ICollection* listajuegos=new Lista();
    Jugador* jugador=(Jugador*)this->controladorU->getInstance()->getUsu();
    listajuegos=jugador->ListarVideojuegosSuscriptos();
    if(!listajuegos){
        cout<<"No tiene suscripciones";
        return false;
    }
    IIterator * it = listajuegos->iterator();
    while (it->hasNext()) {
        Suscripcion* actual=(Suscripcion*)it->getCurrent();
        cout<<actual->GetVideojuego()->getNombre()<<endl;
        it->next();
    }
    delete it;
    return true;
}

void ControladorJugador::IngresarNombreVideoJuego(string _nombre){
    this->Tnombre=_nombre;
}

ICollection* ControladorJugador::HistorialPartidasIndividualesFinalizadas(){
    Jugador *jugador=(Jugador*)this->controladorU->getInstance()->getUsu();
    IDictionary* listaPartidas=new ListDicc();
    ICollection* listadatos=new Lista();
    listaPartidas=jugador->HistorialPartidasIndividualesFinalizadas(this->Tnombre);
    
    IIterator * it = listaPartidas->getIteratorObj();
    
    while (it->hasNext()) {
        Partida* actual=(Partida*)it->getCurrent();
        DataPartidas* datos=new DataPartidas(actual->getIdPartida(),actual->getHora(),actual->getFecha(),actual->getDuracion());
        listadatos->add(datos);
        it->next();
    }
    delete it;   
    return listadatos;
}

void ControladorJugador::TransmitirPartida(bool _transmitida){
    this->TTransmision=_transmitida;
}

void ControladorJugador::UnirJugador(Jugador* nuevo){
    KeyString* key= new KeyString(nuevo->getEmail());
    this->Tunidos->add(nuevo,key);
}

Partida * ControladorJugador::AltaPartidaM(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int idPartida=this->cantPartidas;
    this->cantPartidas++;
    Videojuego* juego=this->servicio->getInstance()->MostrarVideoJuego(this->Tnombre);
    int anio = 1900 + ltm->tm_year;
    int mes = 1 + ltm->tm_mon;
    int dia = ltm->tm_mday;
    int hora = 5 + ltm->tm_hour;
    int minutos = 30 + ltm->tm_min;
    int segundos = ltm->tm_sec;
    DtDate* _fecha=new DtDate(dia,mes,anio);
    DtTime* _hora=new DtTime(hora,minutos,segundos);
    Jugador* host = (Jugador*)this->controladorU->getInstance()->getUsu();

    Partida* nueva=new Mutlijugador(juego,_fecha,_hora,this->Tunidos,this->TTransmision,idPartida, host->getNickname());
    nueva->setDuracion(new DtDate(0,0,0));
    return nueva;
}

Partida * ControladorJugador::AltaPartidaI(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int idPartida=this->cantPartidas;
    this->cantPartidas++;
    Videojuego* juego=this->servicio->getInstance()->MostrarVideoJuego(this->Tnombre);
    int anio = 1900 + ltm->tm_year;
    int mes = 1 + ltm->tm_mon;
    int dia = ltm->tm_mday;
    int hora = 5 + ltm->tm_hour;
    int minutos = 30 + ltm->tm_min;
    int segundos = ltm->tm_sec;
    DtDate* _fecha=new DtDate(dia,mes,anio);
    DtTime* _hora=new DtTime(hora,minutos,segundos);
    Partida* nueva=new Individual(juego,_fecha,_hora,idPartida);
    nueva->setDuracion(new DtDate(0,0,0));
    return nueva;
}

void ControladorJugador::CancelarPartida(){
    this->Tnombre=" ";
    delete this->Tunidos;
    this->TTransmision=false;
}

void ControladorJugador::ContinuarPartida(int _idPartida){
    Jugador* j=(Jugador*)this->controladorU->getInstance()->getUsu();
    j->ContinuarPartida(_idPartida);
}



//CASO DE USO 7
IDictionary* ControladorJugador::ListarPartidasUnidas(){
    
    Jugador* u = (Jugador*) (this->controladorU->getInstance()->getUsu());
    IDictionary* partidas = u->ListarPartidasMultijugador();//ListarPartidasMultijugador() retorna una coleccion de partidas;
    IDictionary* unidas = new ListDicc();//creo una coleccion para copiar
    IIterator* it = u->ListarPartidasMultijugador()->getIteratorObj();
    while(it->hasNext()){
        Mutlijugador* m = (Mutlijugador*) (it->getCurrent());
        if(m->getFinalizada() == false){
            KeyInt* key = new KeyInt(m->getIdPartida());
            //Videojuego* j = m->getVideojuego();

            DataPartidasUnidas * d = new DataPartidasUnidas(m->getIdPartida(),m->getFecha(),m->getHora(),m->getVideojuego()->getNombre(),m->getEnVivo(),m->getHost(),m->getJugadores());

            unidas->add(d,key);
        }
        it->next();
    }
    delete it;
    if (unidas->size() == 0){
         cout<<"El usuario no tiene partidas multijugadores \n";
         unidas = NULL;
         return unidas;
    }
       
    else{
        return unidas;
    } 
}

int ControladorJugador::ConfirmarAbandono(int id){
    KeyInt * ID = new KeyInt(id);
    Jugador* u = (Jugador*) (this->controladorU->getInstance()->getUsu());
    IIterator* it = u->ListarPartidasMultijugador()->getIteratorObj();
    if (u->ListarPartidasMultijugador()->member(ID)){//si esta la partida
        while (it->hasNext()){ 
            Mutlijugador* m = (Mutlijugador*)(it->getCurrent()); // convierto en multijugador
            IIterator* iter = m->getJugadores()->getIteratorObj(); //iterador de la coleccion de jugadores
            while(iter->hasNext()){ // recorre jugador por jugador
                Jugador* j = (Jugador*) (iter->getCurrent());
                KeyString * name = new KeyString(j->getNickname());
                if(j->getNickname() == u->getNickname()){
                    m->getJugadores()->removeKey(name);
                    m->getJugadores()->removeObj(j);
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
}


//CASO DE USO 8
void ControladorJugador::ListarPartidasSinTerminar(){
    Jugador * mijugador = dynamic_cast<Jugador*> (this->controladorU->getInstance()->getUsu()); 
    mijugador->ListarPartidasSinTerminar();
}

void ControladorJugador::FinalizarPartida(int idPartida){
    Jugador * mijugador = dynamic_cast<Jugador*> (this->controladorU->getInstance()->getUsu()); 
    mijugador->FinalizarPartida(idPartida);
}







///////////////////////////CARGAR DATOS DE PRUEBA
void ControladorJugador::cargarDatosPrueba(){
    
    Jugador* jugador;
    IDictionary* usuarios = this->controladorU->getInstance()->getUsuarios();
    
    //PRIMERA SUSCRIPCION
    IIterator* it = usuarios->getIteratorObj();
    while(it->hasNext()){ // recorre jugador por jugador
        Jugador* j = (Jugador*) (it->getCurrent());
        if (j->getNickname()=="gamer")
            jugador=j;
        it->next();
    }
    this->controladorU->getInstance()->setUsuario(jugador);
    this->IngresarNombreVideojuegoCU5("KingdomRush");
    this->IngresarTipoSuscripcion((TipoSuscripcion)0);
    this->IngresarTiempoValidez((TiempoValidez)1);
    this->IngresarMetodoPago((MetodoPago)1);
    this->ConfirmarAltaSuscripcion();
    
    
    
    
    //SEGUNDA SUSCRIPCION
    it = usuarios->getIteratorObj();
    while(it->hasNext()){ // recorre jugador por jugador
        Jugador* j = (Jugador*) (it->getCurrent());
        if (j->getNickname()=="gamer")
            jugador=j;
        it->next();
    }
    this->controladorU->getInstance()->setUsuario(jugador);
    this->IngresarNombreVideojuegoCU5("Fortnite");
    this->IngresarTipoSuscripcion((TipoSuscripcion)0);
    this->IngresarTiempoValidez((TiempoValidez)1);
    this->IngresarMetodoPago((MetodoPago)0);
    this->ConfirmarAltaSuscripcion();
    
    
    //TERCERA SUSCRIPCION
    it = usuarios->getIteratorObj();
    while(it->hasNext()){ // recorre jugador por jugador
        Jugador* j = (Jugador*) (it->getCurrent());
        if (j->getNickname()=="ari")
            jugador=j;
        it->next();
    }
    this->controladorU->getInstance()->setUsuario(jugador);
    this->IngresarNombreVideojuegoCU5("Fortnite");
    this->IngresarTipoSuscripcion((TipoSuscripcion)0);
    this->IngresarTiempoValidez((TiempoValidez)0);
    this->IngresarMetodoPago((MetodoPago)1);
    this->ConfirmarAltaSuscripcion();
    
    
    
    
    //CUARTA SUSCRIPCION
    it = usuarios->getIteratorObj();
    while(it->hasNext()){ // recorre jugador por jugador
        Jugador* j = (Jugador*) (it->getCurrent());
        if (j->getNickname()=="ari")
            jugador=j;
        it->next();
    }
    this->controladorU->getInstance()->setUsuario(jugador);
    this->IngresarNombreVideojuegoCU5("Minecraft");
    this->IngresarTipoSuscripcion((TipoSuscripcion)0);
    this->IngresarTiempoValidez((TiempoValidez)2);
    this->IngresarMetodoPago((MetodoPago)0);
    this->ConfirmarAltaSuscripcion();
    
    
    
    //QUINTA SUSCRIPCION
    it = usuarios->getIteratorObj();
    while(it->hasNext()){ // recorre jugador por jugador
        Jugador* j = (Jugador*) (it->getCurrent());
        if (j->getNickname()=="ibai")
            jugador=j;
        it->next();
    }
    this->controladorU->getInstance()->setUsuario(jugador);
    this->IngresarNombreVideojuegoCU5("Fortnite");
    this->IngresarTipoSuscripcion((TipoSuscripcion)0);
    this->IngresarTiempoValidez((TiempoValidez)2);
    this->IngresarMetodoPago((MetodoPago)0);
    this->ConfirmarAltaSuscripcion();
    
    
    //SEXTA SUSCRIPCION
    it = usuarios->getIteratorObj();
    while(it->hasNext()){ // recorre jugador por jugador
        Jugador* j = (Jugador*) (it->getCurrent());
        if (j->getNickname()=="ibai")
            jugador=j;
        it->next();
    }
    this->controladorU->getInstance()->setUsuario(jugador);
    this->IngresarNombreVideojuegoCU5("Minecraft");
    this->IngresarTipoSuscripcion((TipoSuscripcion)1);
    this->IngresarTiempoValidez((TiempoValidez)999);
    this->IngresarMetodoPago((MetodoPago)0);
    this->ConfirmarAltaSuscripcion();
    
    
    
    //PARTIDAS INDIVIDUALES DE PRUEBA
    it = usuarios->getIteratorObj();
    while(it->hasNext()){ // recorre jugador por jugador
        Jugador* j = (Jugador*) (it->getCurrent());
        if (j->getNickname()=="gamer")
            jugador=j;
        it->next();
    }
    
    
    
}