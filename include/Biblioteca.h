#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <map>
#include <set>
#include "Libro.h"
#include "../Alumnos.h"


class Biblioteca
{
    public:
        Biblioteca();
        void agregar(Libro & libro);
        Libro obtenerLibro(string id);
        //void mostrar();
        void AsignarLibros(Alumnos & Solucion, int CantidadAlumnos, int PuntajeAprobado);
        virtual ~Biblioteca();
    private:
        map<string, Libro> ContenedorLibros;
        bool StockVacio();
        void InicializarSoluciones(Alumnos & Solucion, Alumnos & SolucionParcial, int CantidadAlumnos);
        bool Poda(int CantidadAlumnos, int PuntajeAprobado, Alumnos SolucionParcial, int Alumno, string IdLibroActual);
        bool Aprobo(Alumnos SolucionParcial, int Alumno, int PuntajeAprobado);
        bool LibroAsignado(Alumnos SolucionParcial, int Alumno, string IdLibroActual);
        void BackAsignacion(int CantidadAlumnos, int PuntajeAprobado, Alumnos & Solucion, Alumnos SolucionParcial, map<string,Libro>::iterator LibroActual);
};

#endif // BIBLIOTECA_H
