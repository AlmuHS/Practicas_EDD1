struct NodoLetra {
    char letra;
    NodoLetra *sig;
};

struct NodoBase {
    NodoLetra *col;
    NodoBase *sig;
};

class Letrix {
    private:
        NodoBase *inicio;
        int numletras;
        int velocidad;
    public:
        Letrix();
        char letra(int f, int c);
        void insertar(int col, char let);
        void dibujar(int vel);
        int totalletras();
        int colMax();
        ~Letrix();

};
