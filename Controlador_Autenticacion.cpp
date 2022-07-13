#include "Controlador_Autenticacion.h"
#include "Suscripcion.h"
#include <iostream>
ControladorUsuario* ControladorUsuario::instance = NULL;

//ControladorUsuario::ControladorUsuario(const ControladorUsuario &arg) {
	
//}

ControladorUsuario::~ControladorUsuario() {
	
}

ControladorUsuario* ControladorUsuario::getInstance(){
    if (instance == NULL)
        instance = new ControladorUsuario;
    return instance;
}

IDictionary* ControladorUsuario::getUsuarios(){
    return usuarios;
}

Usuario* ControladorUsuario::getUsuario(){
    return this->usu;
}
//ESTO ES PARA EL CASO DE USO 1

void ControladorUsuario::setDataUsuarioTemporal(DataUsuario* dataUsuarioTemporal){
        this->dataUsuarioTemporal = dataUsuarioTemporal;
}

ControladorUsuario::ControladorUsuario(){
    this->usuarios=new ListDicc();
}

/*
void ControladorUsuario::RegistrarUsuario(){
}
*/

void ControladorUsuario::IngresarDatosUsuario(DataUsuario* data){
    this->dataUsuarioTemporal = data;
}

void ControladorUsuario::IngresarNickname(DataJugador data){
}

void ControladorUsuario::CancelarAltaUsuario(){
    this->dataUsuarioTemporal=NULL;
}

void ControladorUsuario::ConfirmarAltaUsuario(){
    Usuario* nuevoUsuario;
    DataUsuario* puntero = this->dataUsuarioTemporal;
    
    if (DataDesarrollador * pDD = dynamic_cast<DataDesarrollador*> (puntero) ){
        nuevoUsuario = new Desarrollador(pDD->getEmail(), pDD->getContrasenia(), pDD->getEmpresa());
    }
    else if (DataJugador * pDJ = dynamic_cast<DataJugador*> (puntero) ){
        nuevoUsuario = new Jugador(pDJ->getEmail(), pDJ->getContrasenia(), pDJ->getNickname(), pDJ->getDescripcion());
    }
    
    KeyString* key=new KeyString(nuevoUsuario->getEmail());
    this->usuarios->add(nuevoUsuario, key);
}


bool ControladorUsuario::buscarJugador(string nickname){
    IIterator * it = this->getInstance()->getUsuarios()->getIteratorObj();
        while (it->hasNext()) {
            Usuario * U = (Usuario*) (it->getCurrent());
            if (Jugador * J = dynamic_cast<Jugador*> (U) ){
                if (J->getNickname() == nickname)
                    return true;
            }
        it->next();
    }
    return false;
}


bool ControladorUsuario::IniciarSesion(string mail,string contrasenia){
    KeyString* key = new KeyString(mail);
    if(usuarios->member(key)){
        Usuario* u = (Usuario*)(usuarios->find(key));
        if(u->getContrasenia()==contrasenia){
            this->setUsuario(u);
            return true;
        }
    }
    return false;
}

void ControladorUsuario::setUsuario(Usuario* u){
    this->usu = u;
}

void ControladorUsuario::ObtenerJugadores(string _juego){
    IIterator * it = this->getInstance()->getUsuarios()->getIteratorObj();
    IDictionary* sus;
        while (it->hasNext()) {
            Usuario * U = (Usuario*) (it->getCurrent());
            if (Jugador * J = dynamic_cast<Jugador*> (U) ){
                sus=J->ListarVideojuegosSuscriptos();
                IIterator * it2=sus->getIteratorObj();
                while(it2->hasNext()){
                    Suscripcion* actual=(Suscripcion*)it2->getCurrent();
                    if (actual->ObtenerNombreJuego() == _juego){
                        cout<<J->getNickname()<<endl;
                    }
                    it2->next();
                }
            }
        it->next();
    }
}

Jugador* ControladorUsuario::NicknameJugadoresUnirPartida(string _nombre){
    Jugador* jugador=NULL;
    KeyString* key= new KeyString(_nombre);
    jugador=(Jugador*)this->usuarios->find(key);
    if(!jugador){
        return NULL;
    }
    return jugador;
}

void ControladorUsuario::agregarPartida(Partida* _nueva){
    Jugador * J = dynamic_cast<Jugador*>(this->usu);
    J->AltaPartida(_nueva);
}
void ControladorUsuario::CancelarSesion(){
    this->usu = NULL;
}
