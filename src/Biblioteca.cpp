#include "Biblioteca.h"

Biblioteca::Biblioteca()
{
    //ctor
}

void Biblioteca::agregar(Libro & LibroNuevo)
{
    string Id = LibroNuevo.obtenerId();
    ContenedorLibros[Id]= LibroNuevo;
}

Libro Biblioteca::obtenerLibro(string Id)
{
    map<string, Libro>::const_iterator it = ContenedorLibros.find(Id);
    return it->second;
}

/*void Biblioteca::mostrar()
{
    map<string,Libro>::iterator it = contenedor_libros.begin();
    while (it != ContenedorLibros.end())
    {
        cout <<"|Id: "<< it->second.obtenerId() <<" |Titulo: " << it->second.obtenerTitulo() << " |Autor: " <<it->second.obtenerAutor() << " |Genero: " << it->second.obtenerGenero() << " |Paginas: " << it->second.obtenerPaginas() << " |Puntaje: " << it->second.obtenerPuntaje() << " |Ejemplares: " << it->second.obtenerEjemplares() << "|" << endl;
        it++;
    }
}*/

bool Biblioteca::LibroAsignado(Alumnos SolucionParcial, int Alumno, string IdLibroActual)
{
    if (SolucionParcial.Informacion[Alumno].LibrosAsignados.find(IdLibroActual) != SolucionParcial.Informacion[Alumno].LibrosAsignados.end())
        return true;
    else
        return false;
}

bool Biblioteca::Poda(int CantidadAlumnos, int PuntajeAprobado, Alumnos SolucionParcial, int Alumno, string IdLibroActual)
{
    if (SolucionParcial.CantidadAprobados < CantidadAlumnos && !LibroAsignado(SolucionParcial,Alumno,IdLibroActual) && !Aprobo(SolucionParcial,Alumno,PuntajeAprobado))
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
    BackAsignacion(CantidadAlumnos,PuntajeAprobado,Solucion, SolucionParcial,LibroActual);
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

void Biblioteca::BackAsignacion(int CantidadAlumnos, int PuntajeAprobado, Alumnos & Solucion, Alumnos SolucionParcial, map<string,Libro>::iterator LibroActual)
{
    if ((StockVacio()) || (SolucionParcial.CantidadAprobados == CantidadAlumnos)){
        if(Solucion.CantidadAprobados < SolucionParcial.CantidadAprobados){
            Solucion.CantidadAprobados = SolucionParcial.CantidadAprobados;
            Solucion.Informacion = SolucionParcial.Informacion;}}
    else{
        int Alumno=0;
        while (Alumno < CantidadAlumnos){
            if (!Poda(CantidadAlumnos,PuntajeAprobado,SolucionParcial,Alumno,(LibroActual->first))){
                SolucionParcial.Informacion[Alumno].LibrosAsignados.insert(LibroActual->first);
                SolucionParcial.Informacion[Alumno].PuntajeAcumulado += (LibroActual->second).obtenerPuntaje();
                (LibroActual->second).EliminarEjemplar();
                bool AlumnoAprobado = Aprobo(SolucionParcial,Alumno,PuntajeAprobado);
                if (AlumnoAprobado)
                    SolucionParcial.CantidadAprobados++;
                if ((LibroActual->second).obtenerEjemplaresDisponibles() > 0 && (Alumno!=CantidadAlumnos-1)) //Se verifica que no queden
                    BackAsignacion(CantidadAlumnos,PuntajeAprobado,Solucion,SolucionParcial,LibroActual);
                else{
                    LibroActual++;
                    BackAsignacion(CantidadAlumnos,PuntajeAprobado,Solucion,SolucionParcial,LibroActual);
                    LibroActual--;}
                if (AlumnoAprobado)
                    SolucionParcial.CantidadAprobados--;
                (LibroActual->second).AgregarEjemplar();
                SolucionParcial.Informacion[Alumno].PuntajeAcumulado -= (LibroActual->second).obtenerPuntaje();
                SolucionParcial.Informacion[Alumno].LibrosAsignados.erase(LibroActual->first);
            }
            Alumno++;
        }
    }
}

Biblioteca::~Biblioteca()
{
    //dtor
}
