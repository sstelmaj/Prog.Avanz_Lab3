#include "Controlador_Desarrollador.h"
ControladorD* ControladorD::instance = NULL;


ControladorD::ControladorD() {
	
}

ControladorD::ControladorD(const ControladorD &arg) {
	
}

ControladorD::~ControladorD() {
	
}

ControladorD* ControladorD::getInstance() {
    if (instance == NULL)
        instance = new ControladorD;
    return instance;
}

