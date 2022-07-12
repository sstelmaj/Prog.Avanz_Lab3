/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "CU3.h"

void AgregarCategoria(){
    string nombre, descripcion;
    int tipo;  
    Categoria* nuevaCategoria;
    fabrica* Fabrica;
    ICollection* aux_categorias;
    
    aux_categorias = Fabrica->getInterfaceD()->ListarCategorias();
    
    IIterator * it = aux_categorias->iterator();
        while (it->hasNext()) {
            Categoria * C = (Categoria*) (it->getCurrent());
            cout<<endl<<C->getNombre()<<endl;
        it->next();
    }
    
    cout<<"Ingrese nombre de la categoria: ";
    cin>>nombre;
    cout<<"Ingrese descripcion de la categoria: ";
    cin>>descripcion;
    cout<<"Ingrese tipo de categoria\n[0] Genero\n[1] Plataforma\n[2] otro"<<endl;
    cin>>tipo;
    
    if (tipo==0){
        nuevaCategoria = new Genero();
    }
    else if (tipo==1){
        nuevaCategoria = new Plataforma();
    }
    else if (tipo==2){
        nuevaCategoria = new Categoria();
    }
    
    nuevaCategoria->setNombre(nombre);
    nuevaCategoria->setDescripcion(descripcion);
    
    Fabrica->getInterfaceD()->ConfirmarCategoria(nuevaCategoria);
}