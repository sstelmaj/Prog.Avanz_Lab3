/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "DataPartidasUnidas.h"


DataPartidasUnidas::DataPartidasUnidas(int id,DtDate* _date,DtTime* _time,string _nombreVideoJuego,bool TF,string _nombreinicio,IDictionary* _nombresunidos){
    this->identificador = id;
    this->fecha = _date;
    this->hora = _time;
    this->nombreVideoJuego = _nombreVideoJuego;
    this->transmision = TF;
    this->nicknameInicio = _nombreinicio;
    this->nicknameunidos = _nombresunidos;
}
int DataPartidasUnidas::getId(){
    return this->identificador;
    
}
DtDate *DataPartidasUnidas::getFecha(){
    return this->fecha;
}
DtTime *DataPartidasUnidas::getHora(){
    return this->hora;
    
}
string DataPartidasUnidas::getNombreJuego(){
    return this->nombreVideoJuego;
    
}
bool DataPartidasUnidas::getTransmision(){
    return this->transmision;
}
string DataPartidasUnidas::getNicknameInicio(){
    return this->nicknameInicio;
}
IDictionary *DataPartidasUnidas::getNicknameUnidos(){
    return this->nicknameunidos;
}
/*
void DataPartidasUnidas::setId(int ){
    
}
void DataPartidasUnidas::setFecha(DtDate*);
void DataPartidasUnidas::setHora(DtTime*);
void DataPartidasUnidas::setNombreJuego(string);
void DataPartidasUnidas::setTransmision(bool);
void DataPartidasUnidas::setNicknameInicio(string);
void DataPartidasUnidas::setNicknameUnidos(ICollection*);
*/