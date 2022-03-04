#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <list>
#include "Libro.h"
#include "../Alumnos.h"

class Biblioteca
{
    public:
        Biblioteca();
        void Agregar(Libro & LibroNuevo);
        Libro obtenerLibro(int Puntaje);
        void AsignarLibros(Alumnos & Solucion, int CantidadAlumnos, int PuntajeAprobado);
        virtual ~Biblioteca();
    private:
        list<Libro> ContenedorLibros;
        void InsertarOrdenado(list<Libro>::iterator it, Libro & LibroNuevo);
        void InicializarSolucion(Alumnos & Solucion, int CantidadAlumnos);
        void AsignacionHeuristica(Alumnos & Solucion,int CantidadAlumnos, int PuntajeAprobado, int & i);
        bool StockVacio();
        bool Aprobo(Alumnos Solucion, int Alumno, int PuntajeAprobado);
};

#endif // BIBLIOTECA_H
