#include "Libro.h"

using namespace std;

Libro::Libro()
{
    //ctor
}

Libro::Libro(string Id, string Titulo, string Autor, string Genero, int Paginas, int Puntaje, int EjemplaresExistentes, int EjemplaresDisponibles)
{
    this->Id = Id;
    this->Titulo = Titulo;
    this->Autor = Autor;
    this->Genero = Genero;
    this->Paginas = Paginas;
    this->Puntaje = Puntaje;
    this->EjemplaresExistentes = EjemplaresExistentes;
    this->EjemplaresDisponibles = EjemplaresDisponibles;
}

string Libro::obtenerId() const
{
    return Id;
}

string Libro::obtenerTitulo() const
{
    return Titulo;
}

string Libro::obtenerAutor() const
{
    return Autor;
}

string Libro::obtenerGenero() const
{
    return Genero;
}

int Libro::obtenerPaginas() const
{
    return Paginas;
}

int Libro::obtenerPuntaje() const
{
    return Puntaje;
}

int Libro::obtenerEjemplaresExistentes() const
{
    return EjemplaresExistentes;
}

int Libro::obtenerEjemplaresDisponibles() const
{
    return EjemplaresDisponibles;
}

void Libro::EliminarEjemplar()
{
    EjemplaresDisponibles -= 1;
}

void Libro::AgregarEjemplar()
{
    EjemplaresDisponibles += 1;
}

Libro::~Libro()
{
    //dtor
}
