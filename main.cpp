#include <iostream>
#include <fstream>
#include "Biblioteca.h"
#include "Procesar.h"
#include "Alumnos.h"

using namespace std;

int main()
{
    int NumeroDataset;
    string dataset;
    int CantidadAlumnos, PuntajeAprobado;
    char Opcion='S';
    cout << "BIENVENIDO A LA BIBLIOTECA!!!" << endl;
    while (Opcion=='S'){
        cout << endl;
        cout << "Ingrese numero del dataset: ";
        cin >> NumeroDataset;
        switch(NumeroDataset){
            case 1: {dataset= "dataset1.csv";
                    break;}
            case 2: {dataset= "dataset2.csv";
                    break;}
            case 3: {dataset= "dataset3.csv";
                    break;}}
        cout << "Ingrese los parametros: " << endl;
        cout << "Cantidad de alumnos: ";
        cin >> CantidadAlumnos;
        cout << "Puntaje minimo para aprobar: ";
        cin >> PuntajeAprobado;
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
