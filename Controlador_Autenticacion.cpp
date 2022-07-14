#include "Controlador_Autenticacion.h"
ControladorUsuario* ControladorUsuario::instance = NULL;

//ControladorUsuario::ControladorUsuario(const ControladorUsuario &arg) {
	
//}

ControladorUsuario::~ControladorUsuario() {
	
}

ControladorUsuario* ControladorUsuario::getInstance(){
    if (instance == NULL)
        instance = new ControladorUsuario;
    return instance;
}

IDictionary* ControladorUsuario::getUsuarios(){
    return usuarios;
}

//ESTO ES PARA EL CASO DE USO 1

void ControladorUsuario::setDataUsuarioTemporal(DataUsuario* dataUsuarioTemporal){
        this->dataUsuarioTemporal = dataUsuarioTemporal;
}

ControladorUsuario::ControladorUsuario(){
    this->usuarios=new ListDicc();
}

/*
void ControladorUsuario::RegistrarUsuario(){
}
*/

void ControladorUsuario::IngresarDatosUsuario(DataUsuario* data){
    this->dataUsuarioTemporal = data;
}

void ControladorUsuario::IngresarNickname(DataJugador data){
}

void ControladorUsuario::CancelarAltaUsuario(){
    this->dataUsuarioTemporal=NULL;
}

void ControladorUsuario::ConfirmarAltaUsuario(){
    Usuario* nuevoUsuario;
    DataUsuario* puntero = this->dataUsuarioTemporal;
    
    if (DataDesarrollador * pDD = dynamic_cast<DataDesarrollador*> (puntero) ){
        nuevoUsuario = new Desarrollador(pDD->getEmail(), pDD->getContrasenia(), pDD->getEmpresa());
    }
    else if (DataJugador * pDJ = dynamic_cast<DataJugador*> (puntero) ){
        nuevoUsuario = new Jugador(pDJ->getEmail(), pDJ->getContrasenia(), pDJ->getNickname(), pDJ->getDescripcion());
    }
    
    KeyString* key=new KeyString(nuevoUsuario->getEmail());
    this->usuarios->add(nuevoUsuario, key);
}


bool ControladorUsuario::buscarJugador(string nickname){
    IIterator * it = this->getInstance()->getUsuarios()->getIteratorObj();
        while (it->hasNext()) {
            Usuario * U = (Usuario*) (it->getCurrent());
            if (Jugador * J = dynamic_cast<Jugador*> (U) ){
                if (J->getNickname() == nickname)
                    return true;
            }
        it->next();
    }
    return false;
}


bool ControladorUsuario::IniciarSesion(string mail,string contrasenia){
    KeyString* key = new KeyString(mail);
    if(usuarios->member(key)){
        Usuario* u = (Usuario*)(usuarios->find(key));
        if(u->getContrasenia()==contrasenia){
            this->setUsuario(u);
             return true;
        }
    }
    return false;
}

Usuario* ControladorUsuario::getUsu(){
    return usu;
}

void ControladorUsuario::setUsuario(Usuario* u){
    this->usu = u;
}

void ControladorUsuario::CancelarSesion(){
    this->usu = NULL;
}


//CASO DE USO 6
void ControladorUsuario::ObtenerJugadores(string _juego){
    IIterator * it = this->getInstance()->getUsuarios()->getIteratorObj();
    ICollection* sus;
        while (it->hasNext()) {
            Usuario * U = (Usuario*) (it->getCurrent());
            if (Jugador * J = dynamic_cast<Jugador*> (U) ){
                sus=J->ListarVideojuegosSuscriptos();
                IIterator * it2=sus->iterator();
                while(it2->hasNext()){
                    Suscripcion* actual=(Suscripcion*)it2->getCurrent();
                    if (actual->GetVideojuego()->getNombre() == _juego){
                        cout<<J->getNickname()<<endl;
                    }
                    it2->next();
                }
            }
        it->next();
    }
}

Jugador* ControladorUsuario::NicknameJugadoresUnirPartida(string _nombre){
    /*Jugador* jugador=NULL;
    KeyString* key= new KeyString(_nombre);
    jugador=(Jugador*)this->usuarios->find(key);
    if(!jugador){
        return NULL;
    }
    */
    
    Jugador * jugador = NULL;
    IIterator* it = this->usuarios->getIteratorObj();
    
    while (it->hasNext()) {
            Usuario * U = (Usuario*) (it->getCurrent());
            if (Jugador * J = dynamic_cast<Jugador*> (U) ){
                if (J->getNickname()==_nombre){
                    return J;
                }
            }
        it->next();
    }

    return NULL;
}

void ControladorUsuario::agregarPartida(Partida* _nueva){
    Jugador * J = dynamic_cast<Jugador*>(this->usu);
    J->AltaPartida(_nueva);
    
    if (Mutlijugador * m = dynamic_cast<Mutlijugador*> (_nueva)){
        IIterator* it = m->getJugadores()->getIteratorObj();
        while (it->hasNext()) {
            Jugador * ju = (Jugador*) (it->getCurrent());
                ju->AltaPartida(_nueva);
                it->next();
        }
    } 
}



void ControladorUsuario::cargarDatosPrueba(){
    Desarrollador * d= new Desarrollador("ironhide@mail.com", "123", "Ironhide Game Studio");
    KeyString* key = new KeyString("ironhide@mail.com");
    this->usuarios->add(d,key);
    
    d=new Desarrollador("epic@mail.com", "123", "Epic Games");
    key = new KeyString("epic@mail.com");
    this->usuarios->add(d,key);
    
    d=new Desarrollador("mojang@mail.com", "123", "Mojang Studios");
    key = new KeyString("mojang@mail.com");
    this->usuarios->add(d,key);
    
    d=new Desarrollador("ea@mail.com", "123", "EA Sports");
    key = new KeyString("ea@mail.com");
    this->usuarios->add(d,key);
    
    Jugador * j= new Jugador("gamer@mail.com", "123", "gamer", "descripcion");
    key = new KeyString("gamer@mail.com");
    this->usuarios->add(j,key);
    
    j=new Jugador("ari@mail.com", "123", "ari", "descripcion");
    key = new KeyString("ari@mail.com");
    this->usuarios->add(j,key);
    
    j=new Jugador("ibai@mail.com", "123", "ibai", "descripcion");
    key = new KeyString("ibai@mail.com");
    this->usuarios->add(j,key);
    
    j=new Jugador("camila@mail.com", "123", "camila", "descripcion");
    key = new KeyString("camila@mail.com");
    this->usuarios->add(j,key);
}