#include "Partida.h"
#include "Usuario.h"

Partida::Partida() {
}

Partida::Partida(Videojuego* _juego, DtDate* _fecha, DtTime* _hora, int _id){
    this->videojuego=_juego;
    this->fecha=_fecha;
    this->hora=_hora;
    this->idPartida=_id;
    this->finalizada=false;
}

Partida::Partida(const Partida& orig) {
}

int Partida::getIdPartida(){
    return this->idPartida;
}

DtTime* Partida::getHora(){
    return this->hora;
}

DtDate* Partida::getFecha(){
    return this->fecha;
}

DtDate* Partida::getDuracion(){
    return this->duracion;
}

Videojuego* Partida::getVideojuego(){
    return this->videojuego;
}

bool Partida::getFinalizada(){
    return this->finalizada;
}

void Partida::setVideojuego(Videojuego* _juego){
    this->videojuego=_juego;
}
void Partida::setFinalizada(bool _fin){
    this->finalizada=_fin;
}
void Partida::setIdPartida(int _id){
    this->idPartida=_id;
}
void Partida::setFecha(DtDate* _fecha){
    this->fecha=_fecha;
}
void Partida::setHora(DtTime* _hora){
    this->hora=_hora;
}
void Partida::setDuracion(DtDate* _duracion){
    this->duracion=_duracion;
}
Partida::~Partida() {
}

/*----------------------------------Multijugador-------------------------------------------*/

Mutlijugador::Mutlijugador(Videojuego* _juego, DtDate* _fecha, DtTime* _hora, IDictionary* _unidos, bool _transmitida,int _id, string _host): Partida(_juego,_fecha,_hora,_id){
    this->setVideojuego(_juego);
    this->setFecha(_fecha);
    this->setHora(_hora);
    this->setIdPartida(_id);
    this->jugadores=_unidos;
    this->enVivo=_transmitida;
    this->host=_host;
    
    this->horaSalida= new Lista();
}

Mutlijugador::Mutlijugador(){}
    Mutlijugador::Mutlijugador(const Mutlijugador& orig){}
    Mutlijugador::~Mutlijugador(){}
    
ICollection* Mutlijugador::getHoraSalida() {
    return this->horaSalida;
}
    bool Mutlijugador::getEnVivo(){}
    void Mutlijugador::setHoraSalida(DtTime){}
    void Mutlijugador::setEnVivo(bool){}
    
    IDictionary* Mutlijugador::ListarInformacionPartida(string){}
    
IDictionary* Mutlijugador::ListarInformacion() {
    if (this->getEnVivo() == true) {
        cout << "La partida se esta transmitiendo en vivo" << endl;
    } else {
        cout << "La partida no se esta transmitiendo en vivo" << endl;
    }
    cout << "Jugadores:" << endl;
    IIterator * it = this->jugadores->getIteratorObj();
    while (it->hasNext()) {
        Jugador * J = (Jugador*) (it->getCurrent());
        cout << "   ";
        cout << J->getNickname() << endl;
        it->next();
    }
}
    IDictionary* Mutlijugador::ListarComentarios(){}
    void Mutlijugador::EnviarComentario(){}
    
IDictionary* Mutlijugador::getJugadores(){
    return this->jugadores;
}

string Mutlijugador::getHost() {
    return host;
}

void Mutlijugador::setHost(string host) {
    this->host = host;
}

/*-----------------------------------Individual--------------------------------------------------------*/

Individual::Individual(Videojuego* _juego, DtDate* _fecha, DtTime* _hora,int _id):Partida(_juego,_fecha,_hora,_id){
    this->setVideojuego(_juego);
    this->setFecha(_fecha);
    this->setHora(_hora);
    this->setIdPartida(_id);
}

Individual::Individual(const Individual& orig){}
Individual::~Individual(){}

bool Individual::getPartidaNueva(){}
void Individual::setPartidaNueva(bool){}