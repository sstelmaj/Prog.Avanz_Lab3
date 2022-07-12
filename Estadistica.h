/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estadistica.h
 * Author: lucho
 *
 * Created on 23 de junio de 2022, 09:29 AM
 */

#ifndef ESTADISTICA_H
#define ESTADISTICA_H
#include "DtTime.h"
#include "ICollectible.h"

#include <string>
class Estadistica : public ICollectible  {
public:
    Estadistica();
    Estadistica(const Estadistica& orig);
    virtual ~Estadistica();
    
    int getPuntaje();
    DtTime* gethorasJugadas();
    void setPuntaje(int);
    void setHorasJugadas(DtTime);
private:
    int puntaje;
    DtTime* horasJugadas;
};

#endif /* ESTADISTICA_H */

