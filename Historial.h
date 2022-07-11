/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Historial.h
 * Author: lucho
 *
 * Created on 23 de junio de 2022, 10:47 AM
 */

#ifndef HISTORIAL_H
#define HISTORIAL_H
#include "DtDate.h"
#include "DtTime.h"
#include "ICollectible.h"
#include <string>

typedef enum MetodoPago{
    TARJETA,PAYPAL
}MetodoPago;


class Historial : public ICollectible  {
public:
    Historial();
    Historial(const Historial& orig);
    virtual ~Historial();
    
    DtTime* getHora();
    DtDate* getFecha();
    //metodoPago getMetodoPago();
    void setHora(DtTime);
    void setFecha(DtDate);
    //void setMetodoPago(metodoPago);
private:
    DtTime* hora;
    DtDate* fecha;
    //metodoPago metodoPago;
};

#endif /* HISTORIAL_H */

