/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Comentario.h
 * Author: lucho
 *
 * Created on 23 de junio de 2022, 10:13 AM
 */

#ifndef COMENTARIO_H
#define COMENTARIO_H
#include "DtDate.h"
#include "DtTime.h"
#include "IDictionary.h"
#include "ICollectible.h"

#include <string>
using namespace std;

class Comentario : public ICollectible  {
public:
    Comentario();
    Comentario(const Comentario& orig);
    virtual ~Comentario();
    int getRespuestaDe();
    int getIdComentario();
    DtDate getFecha();
    DtTime getHora();
    string getTexto();
    void setRespuestaDe(int);
    void setIdComentario(int);
    void setFecha(DtDate);
    void setHora(DtTime);
    void setTexto(string);
private:
    int respuestaDe;
    int idComentario;
    DtDate* fecha;
    DtTime* hora;
    string texto;
};

#endif /* COMENTARIO_H */

