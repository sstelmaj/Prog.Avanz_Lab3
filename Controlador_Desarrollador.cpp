#include "Controlador_Desarrollador.h"
ControladorD* ControladorD::instance = NULL;


ControladorD::ControladorD() {
    this->categorias=new Lista();
}

ControladorD::ControladorD(const ControladorD &arg) {
}

ControladorD::~ControladorD() {
}

ControladorD* ControladorD::getInstance() {
    if (instance == NULL)
        instance = new ControladorD;
    return instance;
}


//CASO DE USO 3 - AGRGAR CATEGORIA

void ControladorD::ConfirmarCategoria(Categoria* nuevaCategoria){
    this->categorias->add(nuevaCategoria);
    
    IIterator * it = this->categorias->iterator();
    
    while (it->hasNext()) {
        Categoria * C = (Categoria*) (it->getCurrent());
        cout<<C->getNombre()<<endl;
        it->next();
    }
}

/*
void ControladorD::IngresarDatosCategoria(string,string,TipoCategoria){
}
*/

ICollection* ControladorD::ListarCategorias(){
 
    ICollection* aux_categorias = new Lista();
    IIterator * it = this->categorias->iterator();
    while (it->hasNext()) {
        Categoria * C = (Categoria*) (it->getCurrent());
        aux_categorias->add(C);
        it->next();
    }
    return aux_categorias;
}

void ControladorD::IngresarDatosCategoria(string,string,TipoCategoria){
    
}
void ControladorD::CancelarOperacion(){
    
}


/*
void IngresarDatosCategoria(string,string,TipoCategoria){
}
*/
