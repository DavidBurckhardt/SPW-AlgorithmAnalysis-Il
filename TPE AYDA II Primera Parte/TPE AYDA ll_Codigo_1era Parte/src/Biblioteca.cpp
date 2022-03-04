#include "Biblioteca.h"

Biblioteca::Biblioteca()
{
    //ctor
}

void Biblioteca::Agregar(Libro & LibroNuevo)
{
    string Id = LibroNuevo.obtenerId();
    ContenedorLibros[Id]= LibroNuevo;
}

Libro Biblioteca::obtenerLibro(string Id)
{
    map<string, Libro>::const_iterator it = ContenedorLibros.find(Id);
    return it->second;
}

bool Biblioteca::LibroAsignado(Alumnos SolucionParcial, int Alumno, string IdLibroActual)
{
    if (SolucionParcial.Informacion[Alumno].LibrosAsignados.find(IdLibroActual) != SolucionParcial.Informacion[Alumno].LibrosAsignados.end())
        return true;
    else
        return false;
}

bool Biblioteca::Poda(int CantidadAlumnos, int PuntajeAprobado, Alumnos SolucionParcial, int Alumno)
{
    if (!Aprobo(SolucionParcial,Alumno,PuntajeAprobado))
        if (Alumno == 0)
                return false;
        else if (SolucionParcial.Informacion[Alumno-1].PuntajeAcumulado > 0) //Se verifica que no hay un alumno anterior sin libros
                return false;
            else
                return true;
    else
        return true;
}

bool Biblioteca::Aprobo(Alumnos SolucionParcial, int Alumno, int PuntajeAprobado)
{
    if (SolucionParcial.Informacion[Alumno].PuntajeAcumulado >= PuntajeAprobado)
        return true;
    else
        return false;
}

void Biblioteca::InicializarSoluciones(Alumnos & Solucion, Alumnos & SolucionParcial, int CantidadAlumnos)
{
    Solucion.Informacion.resize(CantidadAlumnos);
    SolucionParcial.Informacion.resize(CantidadAlumnos);
    for(int i=0; i<CantidadAlumnos; i++){
        Solucion.Informacion[i].PuntajeAcumulado=0;
        SolucionParcial.Informacion[i].PuntajeAcumulado=0;}
    Solucion.CantidadAprobados=0;
    SolucionParcial.CantidadAprobados=0;
}

void Biblioteca::AsignarLibros(Alumnos & Solucion, int CantidadAlumnos, int PuntajeAprobado)
{
    Alumnos SolucionParcial;
    InicializarSoluciones(Solucion,SolucionParcial,CantidadAlumnos);
    map<string,Libro>::iterator LibroActual = ContenedorLibros.begin();
    long int  i = 0;
    BackAsignacion(CantidadAlumnos,PuntajeAprobado,Solucion, SolucionParcial,LibroActual,i);
    cout << "cantidad de iteraciones: " << i << endl; //Utilizado para ver el total de iteraciones
}

bool Biblioteca::StockVacio()
{
    map<string,Libro>::iterator it = ContenedorLibros.end();
    it--;
    if ((it->second).obtenerEjemplaresDisponibles() > 0)
        return false;
    else
        return true;
}

void Biblioteca::BackAsignacion(int CantidadAlumnos, int PuntajeAprobado, Alumnos & Solucion, Alumnos SolucionParcial, map<string,Libro>::iterator LibroActual, long int & i)
{
    if (StockVacio() || (SolucionParcial.CantidadAprobados == CantidadAlumnos)){
        if(Solucion.CantidadAprobados < SolucionParcial.CantidadAprobados){
            Solucion.CantidadAprobados = SolucionParcial.CantidadAprobados;
            Solucion.Informacion = SolucionParcial.Informacion;}}
    else{
        int Alumno=0;
        while (Alumno < CantidadAlumnos && (LibroActual != ContenedorLibros.end())){
            i++; //Permite llevar un conteo de las iteraciones
            if (!LibroAsignado(SolucionParcial,Alumno,(LibroActual->first))){ // Una de las restricciones del problema.
                if (!Poda(CantidadAlumnos,PuntajeAprobado,SolucionParcial,Alumno)){
                    SolucionParcial.Informacion[Alumno].LibrosAsignados.insert(LibroActual->first);
                    SolucionParcial.Informacion[Alumno].PuntajeAcumulado += (LibroActual->second).obtenerPuntaje();
                    bool AproboConEsteLibro = AproboRecien(SolucionParcial,Alumno,PuntajeAprobado,LibroActual);
                    (LibroActual->second).EliminarEjemplar();
                    if (AproboConEsteLibro){
                            SolucionParcial.CantidadAprobados++;}
                    if ((LibroActual->second).obtenerEjemplaresDisponibles() > 0 && (Alumno!=CantidadAlumnos-1))//Se verifica que no queden libros de ese tipo por asignar.
                        BackAsignacion(CantidadAlumnos,PuntajeAprobado,Solucion,SolucionParcial,LibroActual,i);
                    else{ //Si la cantidad de ejemplares de ese libro es 0 se avanza de libro. Es otra restricción del problema.
                        LibroActual++;
                        BackAsignacion(CantidadAlumnos,PuntajeAprobado,Solucion,SolucionParcial,LibroActual,i);
                        LibroActual--;}
                    if (AproboConEsteLibro){
                        SolucionParcial.CantidadAprobados--;}
                    (LibroActual->second).AgregarEjemplar();
                    SolucionParcial.Informacion[Alumno].PuntajeAcumulado -= (LibroActual->second).obtenerPuntaje();
                    SolucionParcial.Informacion[Alumno].LibrosAsignados.erase(LibroActual->first);
            }}
            Alumno++;
        }
    }
}

bool Biblioteca::AproboRecien(Alumnos SolucionParcial,int Alumno, int PuntajeAprobado, map<string,Libro>::iterator LibroActual)
{
    if (Aprobo(SolucionParcial,Alumno,PuntajeAprobado)){
        int PunatajeSinLibro = SolucionParcial.Informacion[Alumno].PuntajeAcumulado - (LibroActual->second).obtenerPuntaje();
        if (PunatajeSinLibro >= PuntajeAprobado)
            return false;
        else
            return true;}
    else
        return false;
}

Biblioteca::~Biblioteca()
{
    //dtor
}
