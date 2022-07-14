/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DataPartidasUnidas.h
 * Author: laptopwin
 *
 * Created on 12 de julio de 2022, 22:22
 */

#ifndef DATAPARTIDASUNIDAS_H
#define DATAPARTIDASUNIDAS_H
#include "ICollectible.h"
#include "ICollection.h"
#include "DtTime.h"
#include "DtDate.h"
#include <string>
#include "IDictionary.h"
using namespace std;

class DataPartidasUnidas : public ICollectible{
public :
    DataPartidasUnidas(int,DtDate*,DtTime*,string,bool,string,IDictionary*);
    int getId();
    DtDate *getFecha();
    DtTime *getHora();
    string getNombreJuego();
    bool getTransmision();
    string getNicknameInicio();
    IDictionary *getNicknameUnidos();

    /*void setId(int);
    void setFecha(DtDate*);
    void setHora(DtTime*);
    void setNombreJuego(string);
    void setTransmision(bool);
    void setNicknameInicio(string);
    void setNicknameUnidos(ICollection*);*/


private:
    int identificador;
    DtDate* fecha;
    DtTime* hora;
    string nombreVideoJuego;
    bool transmision;
    string nicknameInicio;
    IDictionary* nicknameunidos;

};

#endif /* DATAPARTIDASUNIDAS_H */

