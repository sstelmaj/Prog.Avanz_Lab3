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

IDictionary* ControladorUsuario::getUsuarios() {
    return usuarios;
}

//ESTO ES PARA EL CASO DE USO 1

void ControladorUsuario::setDataUsuarioTemporal(DataUsuario* dataUsuarioTemporal) {
        this->dataUsuarioTemporal = dataUsuarioTemporal;
}

ControladorUsuario::ControladorUsuario() {
    this->usuarios=new ListDicc();
}

/*
void ControladorUsuario::RegistrarUsuario(){
}
*/

void ControladorUsuario::IngresarDatosUsuario(DataUsuario* data){
    this->dataUsuarioTemporal = data;
}

void ControladorUsuario::IngresarNickname(DataJugador){
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

//CU2

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

void ControladorUsuario::CancelarSesion(){
    this->usu = NULL;
}