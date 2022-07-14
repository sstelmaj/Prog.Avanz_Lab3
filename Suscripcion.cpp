/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Suscripcion.cpp
 * Author: lucho
 * 
 * Created on 23 de junio de 2022, 10:14 AM
 */

#include "Suscripcion.h"

Suscripcion::Suscripcion() {
}

Suscripcion::Suscripcion(const Suscripcion& orig) {
}

Suscripcion::~Suscripcion() {
}


Videojuego* Suscripcion::GetVideojuego(){
    return videojuego;
}

void Suscripcion::SetVideojuego(Videojuego* videojuego){
    this->videojuego = videojuego;
}

/*----------------------------VITALICEA--------------------------------------------*/

Vitalicea::Vitalicea(){
}

Vitalicea::Vitalicea(const Vitalicea& orig){

}

Vitalicea::Vitalicea(int _costo){
    this->costo=_costo;
}

int Vitalicea::getCosto(){
    return this->costo;
}

void Vitalicea::setCosto(int _costo){
    this->costo=_costo;
}
Vitalicea::~Vitalicea(){
}

/*--------------------------TEMPORAL------------------------------------*/
Temporal::Temporal(){
}

Temporal::Temporal(tiempoValidez _tiempo, int _costo){
    this->periodoValidez=_tiempo;
    this->costoMensual=_costo;
    this->cancelada=false;
}

Temporal::~Temporal(){
}

bool Temporal::getCancelada(){
    return this->cancelada;
}

void Temporal::setCancelada(bool c){
    this->cancelada=c;
}

tiempoValidez Temporal::getPeriodoValidez(){
    return this->periodoValidez;
}

void Temporal::setPeriodoValidez(tiempoValidez tiempo){
    this->periodoValidez=tiempo;
}

int Temporal::getCostoMensual(){
    return this->costoMensual;
}

void Temporal::setCostoMensual(int costo){
    this->costoMensual=costo;
}
