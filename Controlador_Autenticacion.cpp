#include "Controlador_Autenticacion.h"
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
