/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtDate.h
 * Author: paulo
 *
 * Created on 22 de junio de 2022, 05:05 PM
 */

#ifndef DTDATE_H
#define DTDATE_H
#include <iostream>
#include "ICollectible.h"

using namespace std;

class DtDate : public ICollectible {
public:
    DtDate(int,int,int);
    virtual ~DtDate();
    int getDia();
    int getMes();
    int getAnio();
private:
    int dia,mes,anio;
};

#endif /* DTDATE_H */

