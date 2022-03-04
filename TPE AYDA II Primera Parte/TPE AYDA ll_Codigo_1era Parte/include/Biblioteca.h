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
        void Agregar(Libro & LibroNuevo);
        Libro obtenerLibro(string Id);
        void AsignarLibros(Alumnos & Solucion, int CantidadAlumnos, int PuntajeAprobado);
        virtual ~Biblioteca();
    private:
        map<string, Libro> ContenedorLibros;
        bool StockVacio();
        void InicializarSoluciones(Alumnos & Solucion, Alumnos & SolucionParcial, int CantidadAlumnos);
        bool Poda(int CantidadAlumnos, int PuntajeAprobado, Alumnos SolucionParcial, int Alumno);
        bool Aprobo(Alumnos SolucionParcial, int Alumno, int PuntajeAprobado);
        bool LibroAsignado(Alumnos SolucionParcial, int Alumno, string IdLibroActual);
        void BackAsignacion(int CantidadAlumnos, int PuntajeAprobado, Alumnos & Solucion, Alumnos SolucionParcial, map<string,Libro>::iterator LibroActual,long int  & i);
        bool AproboRecien(Alumnos SolucionParcial,int Alumno, int PuntajeAprobado, map<string,Libro>::iterator LibroActual);
};

#endif // BIBLIOTECA_H
