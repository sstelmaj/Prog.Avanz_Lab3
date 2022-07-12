#include <iostream>
#include "CU4.h"
#include "Controlador_Desarrollador.h"
#include "Suscripcion.h"
#include "Categoria.h"

using namespace std;
ControladorD* controladora=new ControladorD();

void PublicarVideoJuego(){
    string nombre,descripcion,cat;
    int opcion,costo,tipo,opc;
    tiempoValidez tiempo;
    ICollection *categorias;
    IIterator * it;
    
    cout<<"Ingrese Nombre del Juego a Publicar: ";
    cin>>nombre;
    cout<<"Ingrese Descripcion del Juego a Publicar: ";
    cin>>descripcion;
    controladora->IngresarDatosVideojuego(nombre,descripcion);
        cout<<"Ingrese Tipo de Suscripcion: "<<endl;
        cout<<"1.Temporal\n"
              "2.Vitalicea\n";
        cin>>opcion;
        switch(opcion){
            case 1:
                do{
                cout<<"Ingrese Duracion de la suscripcion: "<<endl;
                cout<<"1.Mensual\n"
                      "2.Trimestral\n"
                      "3.Anual\n";
                cin>>tipo;
                tiempo=(tiempoValidez)tipo;
                cout<<"Ingrese costo de la suscripcion";
                cin>>costo;
                controladora->AsociarSuscripcion(tiempo,costo);
                cout<<"Ingrese 0 para seguir ingresando suscripciones";
                cin>>opc;
                }while(opc==0);
                break;
            case 2:
                cout<<"Ingrese costo de la suscripcion";
                cin>>costo;
                controladora->AsociarSuscripcion(costo);
                break;
        }
    cout<<"Ingrese categoria de Genero: ";
    categorias=controladora->ObtenerCategoriasGeneros();
    it = categorias->iterator();
    
    while(it->hasNext()){
        Categoria * actual=(Categoria*)it->getCurrent();
        cout<<actual->getNombre()<<endl;
        it->next();
    }
    cin>>cat;
    controladora->SeleccionarCategoriaG(cat);
    delete categorias;
    delete it;
    
    cout<<"Ingrese categoria de Plataforma: ";
    categorias=controladora->ObtenerCategoriasPlataformas();
    it = categorias->iterator();
    
    while(it->hasNext()){
        Categoria * actual=(Categoria*)it->getCurrent();
        cout<<actual->getNombre()<<endl;
        it->next();
    }
    cin>>cat;
    controladora->SeleccionarCategoriaP(cat);
    delete categorias;
    delete it;
    
    cout<<"Ingresar 0 para agregar mas categorias";
    cin>>opcion;
    while(opcion==0){
        cout<<"Ingrese Categoria: "<<endl;
        categorias=controladora->ObtenerCategorias();
        it = categorias->iterator();
    
        while(it->hasNext()){
            Categoria * actual=(Categoria*)it->getCurrent();
            cout<<actual->getNombre()<<endl;
            it->next();
        }
        cin>>cat;
        controladora->SeleccionarCategoria(cat);
        cout<<"Ingresar 0 para agregar mas categorias";
        cin>>opcion;
    }
    cout<<"1. Confirmar Publicacion\n"
          "2. Cancelar Publicacion";
    cin>>opcion;
    switch(opcion){
        case 1:
            controladora->ConfirmarPublicacion();
            break;
        case 2:
            controladora->CancelarPublicacion();
            break;
    }
}
