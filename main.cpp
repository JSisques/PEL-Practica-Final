#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void Bienvenida();
int MenuInicial();
int MenuCalendario();
int MenuArtistas();
int MenuVinilos();

//-------------VINILO-------------------

class Vinilo {
   private:
    string titulo;
    string haSidoUtilizado;
    vector<string> instrumentos;

   public:
    Vinilo(string titulo, string haSidoUtilizado, vector<string> instrumentos) {
        this->titulo = titulo;
        this->haSidoUtilizado = haSidoUtilizado;
        this->instrumentos = instrumentos;
    };
    ~Vinilo(){

    };

    string getTitulo() {
        return titulo;
    }

    void toString() {
        cout << "Titulo: " << titulo << endl;
        cout << "Ha sido utilizado?: " << haSidoUtilizado << endl;

        for (int i = 0; i < instrumentos.size(); i++) {
            cout << "Instrumento #" << i + 1 << ": " << instrumentos.at(i) << endl;
        }
    };
    ;
};

//-------------ARTISTA-------------------

class Artista {
   private:
    string nombre;
    string estilo;
    vector<string> instrumentosNecesarios;

   public:
    Artista(){

    };
    Artista(string nombre, string estilo, vector<string> instrumentosNecesarios) {
        this->nombre = nombre;
        this->estilo = estilo;
        this->instrumentosNecesarios = instrumentosNecesarios;
    };
    ~Artista(){

    };

    string getNombre() {
        return nombre;
    }

    void toString() {
        cout << "Nombre: " << nombre << endl;
        cout << "Estilo: " << estilo << endl;

        for (int i = 0; i < instrumentosNecesarios.size(); i++) {
            cout << "Instrumento #" << i + 1 << ": " << instrumentosNecesarios.at(i) << endl;
        }
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
        cout << "Artista: " << endl;
        artista.toString();
        cout << "Estado: " << estado << endl;
        cout << "Fecha: " << fecha << endl;
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
        return grabacion;
    }

    void toString() {
        for (Grabacion g : listadoGrabaciones) {
            cout << "------------------------------------------" << endl;
            g.toString();
            cout << "------------------------------------------" << endl;
        }
    };
};

int main(int argc, char const *argv[]) {
    Historico historico;

    list<Vinilo> listadoVinilos;
    list<Artista> listadoArtistas;

    queue<Grabacion> calendario;

    int opcionmenuinicial = -1;
    do {
        Bienvenida();
        opcionmenuinicial = MenuInicial();

        switch (opcionmenuinicial) {
            case 1: {  // Calendario
                opcionmenuinicial = -1;
                int opcioncalendario;
                do {
                    opcioncalendario = MenuCalendario();
                    switch (opcioncalendario) {
                        case 1: {  // Ver cola
                            queue<Grabacion> auxCalendario = calendario;

                            for (int i = 0; i < auxCalendario.size(); i++) {
                                Grabacion g = auxCalendario.front();
                                auxCalendario.pop();
                                cout << "------------------------------------------" << endl;
                                g.toString();
                                cout << "------------------------------------------" << endl;
                                i--;
                            }
                            break;
                        }
                        case 2: {  // Agregar grabaciones a la cola

                            cin.ignore();
                            string nombre;
                            cout << "Indique el nombre del artista: " << endl;
                            getline(cin, nombre);

                            Artista artista;

                            for (Artista a : listadoArtistas) {
                                if (a.getNombre().compare(nombre) == 0) {
                                    artista = a;
                                }
                            }

                            string estado;
                            cout << "Indique el estado: " << endl;
                            getline(cin, estado);

                            string fecha;
                            cout << "Indique la fecha (dd-mm-aaaa): " << endl;
                            getline(cin, fecha);

                            Grabacion g(artista, estado, fecha);
                            calendario.push(g);

                            break;
                        }
                        case 3: {  // Eliminar grabaciones de la cola
                            Grabacion g = calendario.front();
                            calendario.pop();
                            historico.addGrabacion(g);
                            break;
                        }
                        default:
                            cout << "Opcion no valida" << endl;
                            break;
                    }
                } while (opcioncalendario != 0);
                break;
            }
            case 2: {  // Artistas
                opcionmenuinicial = -1;
                int opcionartistas;
                do {
                    opcionartistas = MenuArtistas();
                    switch (opcionartistas) {
                        case 1: {  // Crear nuevo artista

                            cin.ignore();
                            string nombre;
                            cout << "Indique el nombre del artista: " << endl;
                            getline(cin, nombre);

                            string estilo;
                            cout << "Indique el estilo: ";
                            getline(cin, estilo);

                            int numInstrumentos;
                            vector<string> listadoInstrumentos;
                            cout << "Indique cuantos instrumentos necesita: ";
                            cin >> numInstrumentos;
                            cin.ignore();

                            for (int i = 0; i < numInstrumentos; i++) {
                                string nombreInstrumento;
                                cout << "Indique el nombre del instrumento: " << endl;
                                getline(cin, nombreInstrumento);
                                listadoInstrumentos.push_back(nombreInstrumento);
                            }

                            Artista artista(nombre, estilo, listadoInstrumentos);
                            listadoArtistas.push_back(artista);

                            break;
                        }
                        case 2: {  // Buscar artista
                            cin.ignore();
                            string nombre;
                            cout << "Indique el nombre del artista: " << endl;
                            getline(cin, nombre);

                            for (Artista a : listadoArtistas) {
                                if (a.getNombre().compare(nombre) == 0) {
                                    cout << "------------------------------------------" << endl;
                                    a.toString();
                                    cout << "------------------------------------------" << endl;
                                }
                            }
                            break;
                        }
                        case 3:  {// Eliminar artistas
                            break;
                        }
                        case 4: {

                            for (Artista a : listadoArtistas) {
                                cout << "------------------------------------------" << endl;
                                a.toString();
                                cout << "------------------------------------------" << endl;
                            }

                            break;
                        }
                        default:
                            cout << "Opcion no valida" << endl;
                            break;
                    }
                } while (opcionartistas != 0);
                break;
            }
            case 3: {
                // Vinilos
                opcionmenuinicial = -1;
                int opcionvinilos;
                do {
                    opcionvinilos = MenuVinilos();

                    switch (opcionvinilos) {
                        case 1: {  // Ver todos los Vinilos
                            for (Vinilo v : listadoVinilos) {
                                cout << "------------------------------------------" << endl;
                                v.toString();
                                cout << "------------------------------------------" << endl;
                            }
                            break;
                        }
                        case 2: {  // Agregar Vinilos
                            cin.ignore();
                            string titulo;
                            cout << "Indique el titulo del vinilo: " << endl;
                            getline(cin, titulo);

                            string haSidoUtilizado;
                            cout << "Indique si ha sido utilizado (S/N): ";
                            getline(cin, haSidoUtilizado);

                            int numInstrumentos;
                            vector<string> listadoInstrumentos;
                            cout << "Indique cuantos instrumentos tiene: ";
                            cin >> numInstrumentos;
                            cin.ignore();

                            for (int i = 0; i < numInstrumentos; i++) {
                                string nombreInstrumento;
                                cout << "Indique el nombre del instrumento: " << endl;
                                getline(cin, nombreInstrumento);
                                listadoInstrumentos.push_back(nombreInstrumento);
                            }

                            Vinilo vinilo(titulo, haSidoUtilizado, listadoInstrumentos);
                            listadoVinilos.push_back(vinilo);
                            break;
                        }
                        case 3: {  // Buscar Vinilo

                            cin.ignore();
                            string titulo;
                            cout << "Indique el titulo del vinilo: " << endl;
                            getline(cin, titulo);

                            for (Vinilo v : listadoVinilos) {
                                if (v.getTitulo().compare(titulo) == 0) {
                                    cout << "------------------------------------------" << endl;
                                    v.toString();
                                    cout << "------------------------------------------" << endl;
                                }
                            }
                            break;
                        }
                        default:
                            cout << "Opcion no valida" << endl;
                            break;
                    }
                } while (opcionvinilos != 0);
                break;
            }
            case 4: {  // Historico Grabaciones
                historico.toString();
                break;
            }
            default: {
                break;
            }
        }
    } while (opcionmenuinicial != 0);

    return 0;
}

void Bienvenida() {
    /*Bienvenida del documento*/
    cout << "------------------------------------------";
    cout << "\n  Bienvenido a tu gestor discografico! \n";
    cout << "------------------------------------------" << endl;
}

int MenuInicial() {
    /*Menu de la aplicación*/
    int opcion;
    cout << "1. Calendario \n";
    cout << "2. Artistas \n";
    cout << "3. Vinilos \n";
    cout << "4. Historico Grabaciones \n";
    cout << "0. Salir \n";
    cout << "Elige una opcion: \n";
    cin >> opcion;
    return opcion;
}

int MenuCalendario() {
    /*Menu del calendario*/
    int opcion;
    cout << "1. Ver cola \n";
    cout << "2. Agregar artistas a la cola \n";
    cout << "3. Eliminar artistas de la cola \n";
    cout << "0. Salir \n";
    cout << "Elige una opcion: \n";
    cin >> opcion;
    return opcion;
}

int MenuArtistas() {
    /*Menu de los artistas*/
    int opcion;
    cout << "1. Crear nuevo artista \n";
    cout << "2. Buscar artista \n";
    cout << "3. Eliminar artista \n";
    cout << "4. Mostrar artistas \n";
    cout << "0. Salir \n";
    cout << "Elige una opcion: \n";
    cin >> opcion;
    return opcion;
}

int MenuVinilos() {
    /*Menu de los vinilos*/
    int opcion;
    cout << "1. Ver todos los Vinilos \n";
    cout << "2. Agregar Vinilos \n";
    cout << "3. Buscar Vinilo \n";
    cout << "0. Salir \n";
    cout << "Elige una opcion: \n";
    cin >> opcion;
    return opcion;
}