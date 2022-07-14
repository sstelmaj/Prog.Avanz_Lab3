/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "CU9.h"
#include "Fabrica.h"

void VerInformacionVideojuego(){
    fabrica* fabrica;
    string juego;
    DataVideojuegoCU11* datos;
    fabrica->getInstance()->getInterfacejugador()->ListarTodosVideojuegos();
    cout<<"Ingrese videojuego para mostrar informacion: ";
    cin>>juego;
    datos=fabrica->getInstance()->getInterfacejugador()->elegirVideojuego(juego);
    cout<<"Datos del videojuego: "<<endl;
    cout<<"Descripcion: "<<datos->getDescripcion()<<endl;
    cout<<"Costo Permanente de la suscripcion: "<<datos->getCostoPermanente()<<endl;
    cout<<"Costo Mensual de la suscripcion: "<<datos->getCostoMensual()<<endl;
    cout<<"Empresa: "<<datos->getEmpresa()<<endl;
    cout<<"Puntaje: "<<datos->getPromPuntaje()<<endl;
}