/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Usuario.h"
#include "Controlador_Jugador.h"
#include "Fabrica.h"
#include "CU8.h"

using namespace std ;

void FinalizarPartida(){
    
    int idPartida;
    
    fabrica * fabrica;
    
    fabrica->getInstance()->getInterfacejugador()->ListarPartidasSinTerminar();
    
    cout<< "Ingrese identificador de partida a finalizar" << endl;
    cin>>idPartida;
    
    fabrica->getInstance()->getInterfacejugador()->FinalizarPartida(idPartida);
    
}