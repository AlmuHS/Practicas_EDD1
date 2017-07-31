/* Copyright 2013 Almudena García Jurado-Centurión
    This file is part of Practica2

    Practica2 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Practica2 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Practica2.  If not, see <http://www.gnu.org/licenses/>.
*/

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
