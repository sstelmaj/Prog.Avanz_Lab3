/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CU8.h"
#include "Controlador_Jugador.h"
#include "Fabrica.h"
#include "DataPartidasUnidas.h"
#include "Usuario.h"
#include "IDictionary.h"

void AbandonarPartidaMultijugador(){
    fabrica*fabrica;
    int id,abandonar,intenar;
    int i=1;
    
    IDictionary* partida = fabrica->getInterfacejugador()->ListarPartidasUnidas();
    if(partida != NULL){
        IIterator* it = fabrica->getInterfacejugador()->ListarPartidasUnidas()->getIteratorKey();
        DataPartidasUnidas * dp ;
        Jugador * j;
        while(it->hasNext()){
            cout<<"--------Partida------------------------------------------"<<endl;
            dp = (DataPartidasUnidas*)(it->getCurrent());
            cout<<"Id de partida -> "<<dp->getId()<<endl;
            cout<<"Fecha -> "<<dp->getFecha()<<endl;
            cout<<"Hora -> "<<dp->getHora()<<endl;
            cout<<"Nombre del Juego -> "<<dp->getNombreJuego()<<endl;
            cout<<"Jugador que inicio la partida -> "<<dp->getNicknameInicio()<<endl;
            if(dp->getTransmision() == true){
                 cout<<" Transmisin -> En Vivo"<<endl;
            }else{
                 cout<<" Transmisin -> No es en Vivo"<<endl;
            }
            IIterator* iter = dp->getNicknameUnidos()->getIteratorKey();
            cout<<"Nickname de Jugadores unidos "<<endl;
            while(iter->hasNext()){
                j = (Jugador*)(iter->getCurrent());
                cout<<"["<<i<<"]-> "<<j->getNickname()<<endl;
                i++;
                iter->next();
            }
            delete iter;
            it->next();
        }
        delete it;
        do{
            cout<<"Ingrese ID de la partida : ";
            cin>>id;
            abandonar = fabrica->getInterfacejugador()->ConfirmarAbandono(id);
            if(abandonar == 2){
                 cout<<"Has abandonado la partida exitosamente "<<endl;
            }else{
                cout<<"El ID ingresado no existe "<<endl;
                cout<<"Desea volver a intentarlo"<<endl;
                cout<<"[1] si"<<endl;
                cout<<"[2] no"<<endl;
                cout<<"Digite opcion : ";
                cin>>intenar;
            }
        }while(intenar == 1);
        
    }else{
        cout<<"EL jugador no tiene partidas Multijugador"<<endl;
        return;
    }
    
}