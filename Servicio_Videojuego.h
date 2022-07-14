#ifndef SERVICIO_VIDEOJUEGO_H
#define SERVICIO_VIDEOJUEGO_H
#include "string.h"
#include "IDictionary.h"
#include "ICollectible.h"
#include "ICollection.h"
#include "DataVideojuegoCU11.h"
#include "Lista.h"

#include "Usuario.h"

using namespace std;

class Servicio_Videojuego {
public:
    Servicio_Videojuego* getInstance();
    
    void agregarVideoJuego(Videojuego*);
    void ListarTodosVideoJuegos();
    virtual ~Servicio_Videojuego();
    ICollection* mostrar();
    //DataVideojuegoCU11* ElegirVideoJuego(string);
    
    ICollection* ListarVideojuegosSuscripciones(Jugador*);
    ICollection* ListarVideojuegos();
    
    //CU6
    Videojuego* MostrarVideoJuego(string);
    
    void CargarDatosPrueba();
    
    /*
    ICollection* ListarVideojuegosSuscriptos();
    void IngresarNombreVideojuego(string);
    ICollection* ListarVideoJuegos();
    void AsignarPuntaje(string, int);
    ICollection* ListarVideoJuegosJugador();    //set(String)
    ICollection* ListarTodosVideoJuegos();      //set(String)
    void IngresarDatosVideoJuegos();
    void AsociarSuscripcion(tiempoValidez,int);
    void AsociarSuscripcion(int);
    void confirmarEliminacion();
    void SeleccionarVideojuegos();
    void cancelarEliminacion();
    void ElegirVideoJuego(string);
    ICollection* ListarJuego();                 //set(String)*/
    
private:
    Servicio_Videojuego();
    ICollection* videojuegos;
    static Servicio_Videojuego* instance;
};

#endif /* SERVICIO_VIDEOJUEGO_H */