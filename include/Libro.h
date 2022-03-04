#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>

using namespace std;

class Libro
{
    public:
        Libro();
        virtual ~Libro();
        Libro(string Id, string Titulo, string Autor, string Genero, int Paginas, int Puntaje, int EjemplaresExistentes, int EjemplaresDisponibles);
        string obtenerId() const;
        string obtenerTitulo() const;
        string obtenerAutor() const;
        string obtenerGenero() const;
        int obtenerPaginas() const;
        int obtenerPuntaje() const;
        int obtenerEjemplaresExistentes() const;
        int obtenerEjemplaresDisponibles() const;
        void AgregarEjemplar();
        void EliminarEjemplar();
    private:
        string Id;
        string Titulo;
        string Autor;
        string Genero;
        int Paginas;
        int Puntaje;
        int EjemplaresExistentes;
        int EjemplaresDisponibles;
};

#endif // LIBRO_H
