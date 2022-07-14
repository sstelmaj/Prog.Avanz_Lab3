
#include <cstdlib>
#include "CU1.h"
#include "CU3.h"
#include "CU2.h"
#include "CU4.h"
#include "CU5.h"
#include "CU6.h"
#include "CU7.h"
#include "CU8.h"
#include "CU9.h"
#include "Fabrica.h"

using namespace std;

void menuUsuario();
void menuJugador();
void menuDesarrollador();


int main(int argc, char** argv) {
    fabrica* Fabrica;
    int opcionU;
    int opcionJD;
    int opcionJ;
    int opcionD;
    bool sesion;
    
   
    
    do {
         menuUsuario();
        cout << "Ingrese opcion: ";
        cin>>opcionU;
        cout<<endl;
        switch (opcionU) {
            case 1:
            {
                AltaDeUsuario();
                break;
            }
            case 2:
                 system("clear");
            {
                sesion = IniciarSesion();
                if(sesion == true){
                  Usuario* U = (Usuario*)Fabrica->getInterfaceusuario()->getUsu();
                    if(Jugador* j = dynamic_cast<Jugador*>(U)){
                        do{
                            menuJugador();
                            cin>>opcionJ;
                            switch (opcionJ){
                                case 1: 
                                {
                                    SuscribirseAVideojuego();
                                    break;
                                }
                                case 2:
                                {
                                    //Asignar puntaje a video juego
                                    break;
                                }
                                case 3:
                                {
                                    iniciarPartida();
                                    break;
                                }
                                case 4:
                                {
                                    AbandonarPartidaMultijugador();
                                    break;
                                }
                                case 5:
                                {
                                    FinalizarPartida();
                                    break;
                                }
                                case 6:
                                {
                                    VerInformacionVideojuego();
                                    break;
                                }
                            }
                        }while(opcionJ != 8);
                    }else if(Desarrollador* D = dynamic_cast<Desarrollador*> (U)){
                        do{
                            menuDesarrollador();
                            cin>>opcionD;
                            switch(opcionD){
                                case 1:
                                {   
                                    AgregarCategoria();
                                    break;
                                }
                                case 2:
                                {
                                    PublicarVideoJuego();
                                    break;
                                }
                                case 3:
                                {
                                  //  EliminarVideoJuego();
                                    break;
                                }
                                case 6:
                                {
                                    VerInformacionVideojuego();
                                    break;
                                }
                            }
                        }while(opcionD != 8);
                    }
                    
                }
                break;
            }
            case 3:
               
            {
                Fabrica->getInterfaceusuario()->cargarDatosPrueba();
                Fabrica->getInterfaceD()->cargarDatosPrueba();
                Fabrica->getInterfacejugador()->cargarDatosPrueba();
                
                break;
            }
            case 4:
                system("clear");
            {
                break;
            }
        }
    } while (opcionU != 4);
    

    return 0;
}


void menuUsuario(){
    cout<<"--------Inicio---------------------------"<<endl;
    cout<<" [1] Alta de usuario "<<endl;
    cout<<" [2] Iniciar sesión"<<endl;
    cout<<" [3] Cargar datos de prueba "<<endl;
    cout<<" [4] Salir"<<endl;
}


void menuJugador(){
    cout<<"----------Menu Jugador------------------------"<<endl;
    cout<<" [1] Suscribirse a videojuego "<<endl;
    cout<<" [2] Asignar puntaje a videojuego"<<endl;
    cout<<" [3] Iniciar partida"<<endl;
    cout<<" [4] Abandonar partida multijugador"<<endl;
    cout<<" [5] Finalizar partida"<<endl;
    cout<<" [6] Ver información de videojuego"<<endl;
    cout<<" [8] Salir"<<endl;
 
}



void menuDesarrollador(){
    cout<<"----------Menu Desarrollador------------------------"<<endl;
    cout<<" [1] Agregar categoría "<<endl;
    cout<<" [2] Publicar videojuego"<<endl;
    cout<<" [3] Eliminar videojuego"<<endl;
    cout<<" [6] Ver información de videojuego"<<endl;
    cout<<" [8] Salir"<<endl;
}
