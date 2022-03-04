#include <iostream>
#include <fstream>
#include "Biblioteca.h"
#include "Procesar.h"
#include "Alumnos.h"

using namespace std;

int main()
{
    string dataset;
    int CantidadAlumnos, PuntajeAprobado;
    char Opcion='S';
    cout << "BIENVENIDO A LA BIBLIOTECA!!!" << endl;
    while (Opcion=='S'){
        Menu(dataset,CantidadAlumnos,PuntajeAprobado);
        Biblioteca BibliotecaAlumnos;
        ProcesarArchivoEntrada("./datasets/" + dataset, BibliotecaAlumnos);
        Alumnos MejorAsignacion;
        BibliotecaAlumnos.AsignarLibros(MejorAsignacion,CantidadAlumnos,PuntajeAprobado);
        cout << endl;
        cout << "Pueden completar el puntaje minimo " << MejorAsignacion.CantidadAprobados <<  " alumnos, con la siguiente asignacion: " << endl;
        MostrarSolucion(MejorAsignacion,CantidadAlumnos);
        cout << "Desea volver a realizar una simulacion (S/N)?: " << endl;
        cin >> Opcion;}
    cout << endl;
    cout << "HASTA LA PROXIMA!!!" << endl;
    return 0;
}
