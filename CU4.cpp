#include <iostream>
#include "CU4.h"
#include "Controlador_Desarrollador.h"
#include "Suscripcion.h"
#include "Categoria.h"
#include "Fabrica.h"

using namespace std;

void PublicarVideoJuego(){
    fabrica * fabrica;
    string nombre,descripcion,cat;
    int opcion,costo,tipo,opc;
    tiempoValidez tiempo;
    ICollection *categorias;
    IIterator * it;
    
    cout<<"Ingrese Nombre del Juego a Publicar: ";
    cin>>nombre;
    cout<<"Ingrese Descripcion del Juego a Publicar: ";
    cin>>descripcion;
    fabrica->getInterfaceD()->IngresarDatosVideojuego(nombre,descripcion);
    cout<<"Ingrese Costo mensual "<<endl;
    cin>>costo;
    tiempo=(tiempoValidez)0;
    fabrica->getInterfaceD()->AsociarSuscripcion(tiempo,costo);
    cout<<"Ingrese Costo trimestral "<<endl;
    cin>>costo;
    tiempo=(tiempoValidez)1;
    fabrica->getInterfaceD()->AsociarSuscripcion(tiempo,costo);
    cout<<"Ingrese Costo anual "<<endl;
    cin>>costo;
    tiempo=(tiempoValidez)2;
    fabrica->getInterfaceD()->AsociarSuscripcion(tiempo,costo);
    cout<<"Ingrese Costo de la suscripcion vitalicea "<<endl;
    cin>>costo;
    fabrica->getInterfaceD()->AsociarSuscripcion(costo);
    cout<<"Ingrese categoria de Genero: ";
    categorias=fabrica->getInterfaceD()->ObtenerCategoriasGeneros();
    it = categorias->iterator();
    
    while(it->hasNext()){
        Categoria * actual=(Categoria*)it->getCurrent();
        cout<<actual->getNombre()<<endl;
        it->next();
    }
    cin>>cat;
    fabrica->getInterfaceD()->SeleccionarCategoriaG(cat);
    delete categorias;
    delete it;
    
    cout<<"Ingrese categoria de Plataforma: ";
    categorias=fabrica->getInterfaceD()->ObtenerCategoriasPlataformas();
    it = categorias->iterator();
    
    while(it->hasNext()){
        Categoria * actual=(Categoria*)it->getCurrent();
        cout<<actual->getNombre()<<endl;
        it->next();
    }
    cin>>cat;
    fabrica->getInterfaceD()->SeleccionarCategoriaP(cat);
    delete categorias;
    delete it;
    
    cout<<"Ingresar 0 para agregar mas categorias";
    cin>>opcion;
    while(opcion==0){
        cout<<"Ingrese Categoria: "<<endl;
        categorias=fabrica->getInterfaceD()->ObtenerCategorias();
        it = categorias->iterator();
    
        while(it->hasNext()){
            Categoria * actual=(Categoria*)it->getCurrent();
            cout<<actual->getNombre()<<endl;
            it->next();
        }
        cin>>cat;
        fabrica->getInterfaceD()->SeleccionarCategoria(cat);
        cout<<"Ingresar 0 para agregar mas categorias";
        cin>>opcion;
    }
    cout<<"1. Confirmar Publicacion\n"
          "2. Cancelar Publicacion";
    cin>>opcion;
    switch(opcion){
        case 1:
            fabrica->getInterfaceD()->ConfirmarPublicacion();
            break;
        case 2:
            fabrica->getInterfaceD()->CancelarPublicacion();
            break;
    }
}