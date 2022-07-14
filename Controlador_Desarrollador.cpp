#include "Controlador_Desarrollador.h"
ControladorD* ControladorD::instance = NULL;


ControladorD::ControladorD() {
    this->categorias=new Lista();
    this->Tsuscripcion=new Lista();
    this->Tcategorias=new Lista();
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







//CASO DE USO 4

void ControladorD::IngresarDatosVideojuego(string _nombre, string _descripcion){
    this->Tnombre=_nombre;
    this->Tdescripcion=_descripcion;
}

void ControladorD::AsociarSuscripcion(tiempoValidez _tiempo, int _costo){
    Suscripcion *nueva=new Temporal(_tiempo,_costo);
    Tsuscripcion->add(nueva);
}

void ControladorD::AsociarSuscripcion(int _costo){
    Suscripcion *nueva=new Vitalicea(_costo);
    Tsuscripcion->add(nueva);
}

ICollection* ControladorD::ObtenerCategoriasGeneros(){
    ICollection* ListaGenero=new Lista();
    IIterator * it = this->categorias->iterator();
    
    while(it->hasNext()){
        Categoria * actual=(Categoria*)it->getCurrent();
        if (Genero * pG = dynamic_cast<Genero*> (actual) ){
            ListaGenero->add(actual);
        }
        it->next();
    }
    delete it;
    
    return ListaGenero;
}


void ControladorD::SeleccionarCategoriaG(string genero){
    IIterator * it = this->categorias->iterator();
    Genero* _generonuevo;
    while(it->hasNext()){
        Categoria * actual=(Categoria*)it->getCurrent();
        if (Genero * pG = dynamic_cast<Genero*> (actual) ){
            if(pG->getNombre()==genero){
                _generonuevo=pG;
                this->Tcategorias->add(_generonuevo);
                delete it;
                return;
            }
        }
        it->next();
    }
    delete it;
}

ICollection* ControladorD::ObtenerCategoriasPlataformas(){
    ICollection *ListaPlataforma=new Lista();
    IIterator * it = this->categorias->iterator();
    
    while(it->hasNext()){
        Categoria * actual=(Categoria*)it->getCurrent();
        if (Plataforma * pP = dynamic_cast<Plataforma*> (actual)){
            ListaPlataforma->add(actual);
        }
        it->next();
    }
    delete it;
    return ListaPlataforma;
}

void ControladorD::SeleccionarCategoriaP(string plataforma){
    IIterator * it = this->categorias->iterator();
    Plataforma* _plataforma;
    while(it->hasNext()){
        Categoria * actual=(Categoria*)it->getCurrent();
        if (Plataforma * pP = dynamic_cast<Plataforma*> (actual)){
            if(pP->getNombre()==plataforma){
                _plataforma=pP;
                this->Tcategorias->add(_plataforma);
                delete it;
                return;
            }
        }
        it->next();
    }
    delete it;
}

ICollection* ControladorD::ObtenerCategorias(){
    return this->categorias;
}

void ControladorD::SeleccionarCategoria(string _categoria){
    IIterator * it = this->categorias->iterator();
    Categoria * categoria;
    while(it->hasNext()){
        Categoria * actual=(Categoria *)it->getCurrent();       
            if(actual->getNombre()==_categoria){
                categoria=actual;
                this->Tcategorias->add(categoria);
                delete it;
                return;
            }
        it->next();
    }
    delete it;
}

void ControladorD::ConfirmarPublicacion(Usuario* _usu){
    Videojuego *nuevo=new Videojuego(this->Tnombre,this->Tdescripcion);
    Desarrollador * pD = dynamic_cast<Desarrollador*> (_usu);
    nuevo->AgregarCategorias(this->Tcategorias);
    nuevo->AsociarSuscripcion(this->Tsuscripcion);
    nuevo->setEmpresa(pD->getNombreCompania());
    InServicio->getInstance()->agregarVideoJuego(nuevo);
    
    /*
    ICollection* juegos;
    juegos=InServicio->getInstance()->mostrar();
    Videojuego* juego;
    IIterator * it = juegos->iterator();
    while(it->hasNext()){
        juego=(Videojuego*)it->getCurrent();
        cout<<juego->getNombre()<<endl;
        it->next();
    }
    delete it;
   */
    
    
   
    
    ICollection* suscripciones;
    suscripciones=nuevo->listarSuscripciones();
    Suscripcion* S;
    IIterator * it = suscripciones->iterator();
    while(it->hasNext()){
        S=(Suscripcion*)it->getCurrent();
            S->SetVideojuego(nuevo);
        it->next();
    }
    delete(it);
    delete(this->Tsuscripcion);
    this->Tsuscripcion= new Lista();
    delete(this->Tcategorias);
    this->Tcategorias= new Lista();
}

void ControladorD::CancelarPublicacion(){
    delete this->Tcategorias;
    delete this->Tsuscripcion;
}



void ControladorD::cargarDatosPrueba(){
    Categoria* c = new Plataforma();
    c->setNombre("PC");
    c->setDescripcion("computadora");
    this->categorias->add(c);
            
    c = new Plataforma();
    c->setNombre("PS4");
    c->setDescripcion("PlayStation4");
    this->categorias->add(c);
            
    c = new Plataforma();
    c->setNombre("Xbox One");
    c->setDescripcion("Xbox One");
    this->categorias->add(c);
    
    c = new Genero();
    c->setNombre("Deporte");
    c->setDescripcion("Deporte");
    this->categorias->add(c);
    
    c = new Genero();
    c->setNombre("Supervivencia");
    c->setDescripcion("Supervivencia");
    this->categorias->add(c);
    
    c = new Genero();
    c->setNombre("Estrategia");
    c->setDescripcion("Estrategia");
    this->categorias->add(c);
    
    c = new Categoria();
    c->setNombre("Teen");
    c->setDescripcion("Su contenido está dirigido a jóvenes de 13 años en adelante");
    this->categorias->add(c);
    
    c = new Categoria();
    c->setNombre("E");
    c->setDescripcion("Su contenido está dirigido para todo público");
    this->categorias->add(c);

    
    
    ICollection * susc = new Lista();
    
    Videojuego* J = new Videojuego("KingdomRush", "KingdomRush");
    
    Temporal* S = new Temporal();
    S->setCostoMensual(1);
    S->setPeriodoValidez((tiempoValidez)0);
    S->SetVideojuego(J);
    susc->add(S);
    
    S = new Temporal();
    S->setCostoMensual(2);
    S->setPeriodoValidez((tiempoValidez)1);
    S->SetVideojuego(J);
    susc->add(S);
    
    S = new Temporal();
    S->setCostoMensual(7);
    S->setPeriodoValidez((tiempoValidez)2);
    S->SetVideojuego(J);
    susc->add(S);
    
    Vitalicea* V = new Vitalicea();
    V->setCosto(14);
    V->SetVideojuego(J);
    susc->add(V);
    this->SeleccionarCategoriaG("Estrategia");
    this->SeleccionarCategoriaP("PC");
    this->SeleccionarCategoriaP("PC4");
    this->SeleccionarCategoria("E");
    
    
    J->AgregarCategorias(this->Tcategorias);
    delete(this->Tcategorias);
    this->Tcategorias=new Lista();
    
    this->InServicio->getInstance()->agregarVideoJuego(J);
    
    J->AsociarSuscripcion(susc);
    delete(susc);
    susc=new Lista();
    J->setEmpresa("Ironhide Game Studio");
    J = new Videojuego("Fortnite", "Fortnite");
    
    S = new Temporal();
    S->setCostoMensual(3);
    S->setPeriodoValidez((tiempoValidez)0);
    S->SetVideojuego(J);
    susc->add(S);
    
    S = new Temporal();
    S->setCostoMensual(8);
    S->setPeriodoValidez((tiempoValidez)1);
    S->SetVideojuego(J);
    susc->add(S);
    
    S = new Temporal();
    S->setCostoMensual(30);
    S->setPeriodoValidez((tiempoValidez)2);
    S->SetVideojuego(J);
    susc->add(S);
    
    V = new Vitalicea();
    V->setCosto(60);
    V->SetVideojuego(J);
    susc->add(V);
    
    this->SeleccionarCategoriaG("Supervivencia");
    this->SeleccionarCategoriaP("PC");
    this->SeleccionarCategoriaP("PC4");
    this->SeleccionarCategoriaP("Xbox One");
    this->SeleccionarCategoria("Teen");
    
    
    J->AgregarCategorias(this->Tcategorias);
    delete(this->Tcategorias);
    this->Tcategorias=new Lista();
    
    this->InServicio->getInstance()->agregarVideoJuego(J);
    
    J->AsociarSuscripcion(susc);
    delete(susc);
    susc=new Lista();
    
    J->setEmpresa("Epic Games");
    J = new Videojuego("Minecraft", "Minecraft");
    
    S = new Temporal();
    S->setCostoMensual(2);
    S->setPeriodoValidez((tiempoValidez)0);
    S->SetVideojuego(J);
    susc->add(S);
    
    S = new Temporal();
    S->setCostoMensual(5);
    S->setPeriodoValidez((tiempoValidez)1);
    S->SetVideojuego(J);
    susc->add(S);
    
    S = new Temporal();
    S->setCostoMensual(20);
    S->setPeriodoValidez((tiempoValidez)2);
    S->SetVideojuego(J);
    susc->add(S);
    
    V = new Vitalicea();
    V->setCosto(40);
    V->SetVideojuego(J);
    susc->add(V);
    
    this->SeleccionarCategoriaG("Supervivencia");
    this->SeleccionarCategoriaP("PC");
    this->SeleccionarCategoria("E");
    
    
    J->AgregarCategorias(this->Tcategorias);
    delete(this->Tcategorias);
    this->Tcategorias=new Lista();
    
    this->InServicio->getInstance()->agregarVideoJuego(J);
    
    J->AsociarSuscripcion(susc);
    delete(susc);
    susc=new Lista();
    
    J->setEmpresa("Mojang Studios");
    J = new Videojuego("FIFA21", "FIFA21");
    
    S = new Temporal();
    S->setCostoMensual(3);
    S->setPeriodoValidez((tiempoValidez)0);
    S->SetVideojuego(J);
    susc->add(S);
    
    S = new Temporal();
    S->setCostoMensual(8);
    S->setPeriodoValidez((tiempoValidez)1);
    S->SetVideojuego(J);
    susc->add(S);
    
    S = new Temporal();
    S->setCostoMensual(28);
    S->setPeriodoValidez((tiempoValidez)2);
    S->SetVideojuego(J);
    susc->add(S);
    
    V = new Vitalicea();
    V->setCosto(50);
    V->SetVideojuego(J);
    susc->add(V);
    
    this->SeleccionarCategoriaG("Supervivencia");
    this->SeleccionarCategoriaG("Deporte");
    this->SeleccionarCategoriaP("PC");
    this->SeleccionarCategoriaP("PS4");
    this->SeleccionarCategoriaP("Xbox One");
    this->SeleccionarCategoria("E");
    
    
    J->AgregarCategorias(this->Tcategorias);
    delete(this->Tcategorias);
    this->Tcategorias=new Lista();
    
    this->InServicio->getInstance()->agregarVideoJuego(J);
    
    J->AsociarSuscripcion(susc);
    delete(susc);
    susc=new Lista();
    J->setEmpresa("EA Sports");
    
}