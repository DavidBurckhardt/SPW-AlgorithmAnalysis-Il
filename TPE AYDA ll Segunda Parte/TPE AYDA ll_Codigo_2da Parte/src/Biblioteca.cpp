#include "Biblioteca.h"

Biblioteca::Biblioteca()
{
    //ctor
}

void Biblioteca::Agregar(Libro & LibroNuevo)
{
    list<Libro>::iterator it = ContenedorLibros.begin();
    InsertarOrdenado(it,LibroNuevo);
}

void Biblioteca::InsertarOrdenado(list<Libro>::iterator it, Libro & LibroNuevo)
{
    if (it == ContenedorLibros.end() || (*it).obtenerPuntaje() > (LibroNuevo).obtenerPuntaje())
        ContenedorLibros.insert(it,LibroNuevo);
    else{
        it++;
        InsertarOrdenado(it,LibroNuevo);
    }
}

void Biblioteca::InicializarSolucion(Alumnos & Solucion, int CantidadAlumnos)
{
    Solucion.Informacion.resize(CantidadAlumnos);
    for(int i=0; i<CantidadAlumnos; i++)
        Solucion.Informacion[i].PuntajeAcumulado=0;
    Solucion.CantidadAprobados=0;
}

void Biblioteca::AsignarLibros(Alumnos & Solucion, int CantidadAlumnos, int PuntajeAprobado)
{
    InicializarSolucion(Solucion,CantidadAlumnos);
    int i = 0;
    AsignacionHeuristica(Solucion,CantidadAlumnos,PuntajeAprobado,i);
    cout << "Cantidad de iteraciones: " << i << endl; //Utilizado para ver el total de iteraciones
}

bool Biblioteca::Aprobo(Alumnos Solucion, int Alumno, int PuntajeAprobado)
{
    if (Solucion.Informacion[Alumno].PuntajeAcumulado >= PuntajeAprobado)
        return true;
    else
        return false;
}

bool Biblioteca::StockVacio()
{
    list<Libro>::iterator it = ContenedorLibros.end();
    it--;
    if ((*it).obtenerEjemplaresDisponibles() > 0)
        return false;
    else
        return true;
}

void Biblioteca::AsignacionHeuristica(Alumnos & Solucion, int CantidadAlumnos, int PuntajeAprobado, int & i)
{
    int Alumno= 0;
    list<Libro>::iterator LibroActual = ContenedorLibros.begin();
    while (!StockVacio() && Solucion.CantidadAprobados < CantidadAlumnos && LibroActual != ContenedorLibros.end()){
        if ((*LibroActual).obtenerEjemplaresDisponibles() > 0){
            if (!Aprobo(Solucion,Alumno,PuntajeAprobado)){
                i++; //Permite llevar un conteo de las iteraciones
                Solucion.Informacion[Alumno].LibrosAsignados.insert((*LibroActual).obtenerId());
                Solucion.Informacion[Alumno].PuntajeAcumulado += (*LibroActual).obtenerPuntaje();
                (*LibroActual).EliminarEjemplar();
                LibroActual++;}
            if (Aprobo(Solucion,Alumno,PuntajeAprobado)){
                Solucion.CantidadAprobados++;
                LibroActual = ContenedorLibros.begin();
                Alumno++;}
        }
        else
            LibroActual++;
    }
}

Biblioteca::~Biblioteca()
{
    //dtor
}
