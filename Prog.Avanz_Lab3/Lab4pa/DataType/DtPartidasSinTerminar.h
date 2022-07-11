/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtPartidasSinTerminar.h
 * Author: paulo
 *
 * Created on 22 de junio de 2022, 05:49 PM
 */

#ifndef DTPARTIDASSINTERMINAR_H
#define DTPARTIDASSINTERMINAR_H
#include <iostream>
#include "string.h"
#include "dtDate.h"
#include "ICollectible.h"

using namespace std;

class DtPartidasSinTerminar: public ICollectible {
public:
    DtPartidasSinTerminar(int,DtDate*,string);
    int getid();
    string getNombreJuego();
    DtDate *getFecha();
    virtual ~DtPartidasSinTerminar();
private:
    int id;
    DtDate* fecha;
    string NombreJuego;
};

class DtPST_individual:public DtPartidasSinTerminar{
public:
    DtPST_individual(int,DtDate*,string,bool);
    virtual ~DtPST_individual();
    bool getContinuacion();
private:
    bool continuacion;
};

class DtPST_multijugador:public DtPartidasSinTerminar{
public:
    DtPST_multijugador(int,DtDate*,string,bool /*,unidos*/);
    virtual ~DtPST_multijugador();
    bool getTransmitida();
private:
    bool transmitida;
    //unidos
};
    
#endif /* DTPARTIDASSINTERMINAR_H */

