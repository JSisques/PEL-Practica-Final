#include <iostream>
#include <list>
#include <string>

using namespace std;

//-------------VINILO-------------------

class Vinilo {
   private:
    string titulo;
    bool haSidoUtilizado;
    list<string> instrumentos;

   public:
    Vinilo(/* args */){

    };
    ~Vinilo(){

    };
    void toString() {
        cout << "Prueba" << endl;
    };
    ;
};

//-------------ARTISTA-------------------

class Artista {
   private:
    string nombre;
    string estilo;
    list<string> instrumentosNecesarios;

   public:
    Artista(string nombre, string estilo, list<string> instrumentosNecesarios) {
        this->nombre = nombre;
        this->estilo = estilo;
        this->instrumentosNecesarios = instrumentosNecesarios;
    };
    ~Artista(){

    };
    void toString() {
        cout << "Prueba" << endl;
    };
};

//--------------GRABACION---------------

class Grabacion {
   private:
    Artista artista;
    string estado;
    string fecha;

   public:
    Grabacion(Artista artista, string estado, string fecha) {
        this->artista = artista;
        this->estado = estado;
        this->fecha = fecha;
    };

    ~Grabacion(){

    };
    void toString() {
        cout << "Prueba" << endl;
    };
};

//--------------HISTORICO---------------

class Historico {
   private:
    list<Grabacion> listadoGrabaciones;

   public:
    Historico(){

    };
    ~Historico(){

    };

    Grabacion addGrabacion(Grabacion grabacion) {
        listadoGrabaciones.push_back(grabacion);
    }

    void toString() {
        cout << "Prueba" << endl;
    };
};

int main(int argc, char const *argv[]) {
    Historico historico;

    list<Artista> listadoArtistas;
    list<Vinilo> listadoVinilos;
    list<Grabacion> listadoGrabacion;

    return 0;
}
