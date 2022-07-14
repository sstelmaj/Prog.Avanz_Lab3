/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "CU5.h"
#include "Fabrica.h"
#include "Videojuego.h"
#include "Suscripcion.h"



void SuscribirseAVideojuego(){
    
    string juego;
    fabrica* fabrica;
    ICollection* suscriptos;
    ICollection* videojuegos;
    ICollection* suscripciones;
    bool estaSuscripto;
    int opcion;
    //listo lis videojuegos suscriptos por el jugador
    
    suscriptos = fabrica->getInterfacejugador()->ListarVideojuegosSuscriptos();
    
    cout<<"|Videojuegos-Suscriptos|"<<endl<<endl;
    IIterator * it = suscriptos->iterator();
        while (it->hasNext()) {
        Suscripcion * S = (Suscripcion*) (it->getCurrent());
        if (Temporal* temp = dynamic_cast<Temporal*> (S)) {
            if (temp->getCancelada()==false)
                cout<<temp->GetVideojuego()->getNombre()<<endl;
        }
        else{    
            cout<<S->GetVideojuego()->getNombre()<<endl;
        }
        it->next();
    }
    
    //listo todos los videojuegos con sus suscripciones
    
    videojuegos = fabrica->getInterfacejugador()->ListarVideojuegosSuscripciones();
    
    cout<<"\n\n|Videojuegos-Suscripciones disponibles|";
    it = videojuegos->iterator();
    while (it->hasNext()){
        Videojuego * V = (Videojuego*) (it->getCurrent());
        cout<<endl<<"Videojuego: "<<V->getNombre()<<" - Suscripciones disponibles"<<endl;
        suscripciones = V->listarSuscripciones();
        IIterator* it_suscripciones = suscripciones->iterator();
        while (it_suscripciones->hasNext()){
            Suscripcion * S = (Suscripcion*) (it_suscripciones->getCurrent());
            if (Temporal * temp = dynamic_cast<Temporal*> (S)){
                if (temp->getPeriodoValidez()==0)
                    cout<<"costo mensual: "<<temp->getCostoMensual()<<endl;
                else if (temp->getPeriodoValidez()==1)
                    cout<<"costo trimestral: "<<temp->getCostoMensual()<<endl;
                else if (temp->getPeriodoValidez()==2)
                    cout<<"costo anual: "<<temp->getCostoMensual()<<endl;
            }
            else if (Vitalicea * vit = dynamic_cast<Vitalicea*> (S)){
                cout<<"costo vitalicea: "<<vit->getCosto()<<endl;
            }
            it_suscripciones->next();
        }
        it->next();
    }
    
    cout<<"\n\nIngrese el nombre del videojuego: "<<endl;
    cin>>juego;
    fabrica->getInterfacejugador()->IngresarNombreVideojuego(juego);
    
    it = suscriptos->iterator();
    while (it->hasNext()) {
        Suscripcion * S = (Suscripcion*) (it->getCurrent());
        if (S->GetVideojuego()->getNombre()==juego){
            if (Vitalicea * vit = dynamic_cast<Vitalicea*> (S)){
                cout<<"Ya posees una suscripcion de tipo vitalicea para este juego"<<endl;
                return;
            }
            else if (Temporal * temp = dynamic_cast<Temporal*> (S)){    
                cout<<"Ya posees una suscripcion temporal para este juego"<<endl;
                cout<<"Deseas cancelar esta suscripción?\n[0] si\n[1] no"<<endl;
                cin>>opcion;
                if (opcion==1){
                    return;
                }else{
                    fabrica->getInterfacejugador()->CancelarSuscripcion(S->GetVideojuego());
                    //acá tendria que agregar la suscripcion a "Historial"
                }
            }
        }
        it->next();
    }
    
    cout<<"Ingrese tipo de suscripcion:\n[0] Temporal\n[1] Vitalicea";
    cin>>opcion;
    TipoSuscripcion tipo =(TipoSuscripcion)opcion;
    fabrica->getInterfacejugador()->IngresarTipoSuscripcion(tipo);
    
    if (opcion==0){
        cout<<"Ingrese tiempo de validez de suscripcion:\n[0] mensual\n[1] trimestral\n[2] anual";
        cin>>opcion;
        tiempoValidez tiempo=(tiempoValidez)opcion;
        fabrica->getInterfacejugador()->IngresarTiempoValidez(tiempo);
    }else
        tiempoValidez tiempo=(tiempoValidez)100;
    cout<<"Ingrese metodo de pago:\n[0] Tarjeta\n[1] Paypal";
    cin>>opcion;
    MetodoPago pago=(MetodoPago)opcion;
    fabrica->getInterfacejugador()->IngresarMetodoPago(pago);
    
    fabrica->getInterfacejugador()->ConfirmarAltaSuscripcion();
    
}