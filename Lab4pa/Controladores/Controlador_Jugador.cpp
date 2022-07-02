#include "Controlador_Jugador.h"
#include "Fabrica.h"


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