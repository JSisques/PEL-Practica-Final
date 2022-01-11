#include <iostream>
#include <list>
#include <string>

using namespace std;

class Vinilo {
   private:
    string titulo;
    bool haSidoUtilizado;
    list<string> instrumentos;

   public:
    Vinilo(/* args */);
    ~Vinilo();
};

class Artista {
   private:
    /* data */
   public:
    Artista(/* args */);
    ~Artista();
};

Artista::Artista(/* args */) {
}

Artista::~Artista() {
}

Vinilo::Vinilo(/* args */) {
}

Vinilo::~Vinilo() {
}

int main(int argc, char const *argv[]) {
    return 0;
}
