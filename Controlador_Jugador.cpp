#include "Controlador_Jugador.h"
#include "Fabrica.h"
#include "Videojuego.h"
#include "Usuario.h"
#include "Lista.h"
#include "DataPartidas.h"
#include "ListaDicc.h"
#include "Partida.h"
#include "KeyString.h"
#include "Controlador_Autenticacion.h"


ControladorJugador* ControladorJugador::instance = NULL;

ControladorJugador::ControladorJugador() {
    this->cantPartidas=0;
}

void ControladorJugador::ListarVideoJuegosJugador(){
    IDictionary* listajuegos=new ListDicc();
    Jugador* jugador=(Jugador*)this->controladorusuario->getInstance()->getUsuario();
    listajuegos=jugador->ListarVideojuegosSuscriptos();
     cout<<"1"<<endl;
    IIterator * it = listajuegos->getIteratorObj();
    cout<<"2"<<endl;
    while (it->hasNext()) {
        Videojuego* actual=(Videojuego*)it->getCurrent();
        cout<<actual->getNombre()<<endl;
        it->next();
    }
    cout<<"3"<<endl;
    delete it;
}

void ControladorJugador::IngresarNombreVideoJuego(string _nombre){
    this->Tnombre=_nombre;
}

ICollection* ControladorJugador::HistorialPartidasIndividualesFinalizadas(){
    Jugador *jugador=(Jugador*)this->controladorusuario->getUsuario();
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
    KeyString* key= new KeyString(nuevo->getNickname());
    this->Tunidos->add(nuevo,key);
}

Partida * ControladorJugador::AltaPartidaM(){
    int idPartida=this->cantPartidas;
    this->cantPartidas++;
    Videojuego* juego=InServicio->MostrarVideoJuego(this->Tnombre);
    DtDate* _fecha=new DtDate(11,11,11);
    DtTime* _hora=new DtTime(01,01,01);
    Partida* nueva=new Mutlijugador(juego,_fecha,_hora,this->Tunidos,this->TTransmision,idPartida);
    return nueva;
}

Partida * ControladorJugador::AltaPartidaI(){
    int idPartida=this->cantPartidas;
    this->cantPartidas++;
    Videojuego* juego=InServicio->MostrarVideoJuego(this->Tnombre);
    DtDate* _fecha=new DtDate(11,11,11);
    DtTime* _hora=new DtTime(01,01,01);
    Partida* nueva=new Individual(juego,_fecha,_hora,idPartida);
    return nueva;
}

void ControladorJugador::CancelarPartida(){
    this->Tnombre=" ";
    delete this->Tunidos;
    this->TTransmision=false;
}

void ControladorJugador::ContinuarPartida(int _idPartida){
    Jugador* j=(Jugador*)this->controladorusuario->getUsuario();
    j->ContinuarPartida(_idPartida);
}
ControladorJugador::~ControladorJugador() {
	
}

ControladorJugador* ControladorJugador::getInstance() {
    if (instance == NULL)
        instance = new ControladorJugador;
    return instance;
}