#ifndef PROCESAR_H_INCLUDED
#define PROCESAR_H_INCLUDED
#include <iostream>
#include <fstream>
#include <set>
#include "Biblioteca.h"
#include "Libro.h"

using namespace std;

void ProcesarArchivoEntrada(string origen, Biblioteca & BibliotecaAlumnos);
void MostrarSolucion(Alumnos Solucion, int cantidadAlumnos);
void ImprimirLibros(set<Libro> LibrosAsignados);

#endif // PROCESAR_H_INCLUDED
