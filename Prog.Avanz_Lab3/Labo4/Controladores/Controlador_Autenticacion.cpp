#include "Controlador_InicioSesion.h"
ControladorUsuario* ControladorUsuario::instance = NULL;

ControladorUsuario::ControladorUsuario() {
	
}

//ControladorUsuario::ControladorUsuario(const ControladorUsuario &arg) {
	
//}

ControladorUsuario::~ControladorUsuario() {
	
}

ControladorUsuario* ControladorUsuario::getInstance() {
    if (instance == NULL)
        instance = new ControladorUsuario;
    return instance;
}
ControladorUsuario :: ControladorUsuario() {
    this->usuarios = new List();
}