/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtTime.h
 * Author: paulo
 *
 * Created on 22 de junio de 2022, 04:46 PM
 */

#ifndef DTTIME_H
#define DTTIME_H
#include <iostream>
#include "ICollectible.h"

using namespace std;

class DtTime: public ICollectible{
public:
    DtTime(int,int,int);
    int gethora();
    int getminutos();
    int getsegundos();
    virtual ~DtTime();
private:
    int hora,minutos,segundos;
};

#endif /* DTTIME_H */

