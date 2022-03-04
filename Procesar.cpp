#include "Procesar.h"

void ImprimirLibros(set<string> LibrosAsignados)
{
    set<string>::iterator it = LibrosAsignados.begin();
    cout<< "Libros: ";
    while (it != LibrosAsignados.end()){
        cout << (*it) << ", ";
        it++;}
    cout << endl;
}

void MostrarSolucion(Alumnos MejorAsignacion, int CantidadAlumnos )
{
    for (int i=0; i < CantidadAlumnos; i++){
        cout << "Alumno " << i+1 << " -> " << "Puntaje: " << MejorAsignacion.Informacion[i].PuntajeAcumulado << " | ";
        ImprimirLibros(MejorAsignacion.Informacion[i].LibrosAsignados);}
    cout << endl;
}

void ProcesarArchivoEntrada(string origen, Biblioteca & BibliotecaAlumnos)
{
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_libros = atoi(linea.c_str());

        cout << "Se cargaran " << cantidad_libros << " libros." << endl;

        int posicion = 0;
        //Leemos de una linea completa por vez (getline).
        while (getline(archivo, linea)) {
            //Primer posición del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(';');

            //Informacion entre pos_inicial y pos_final
            string Id = linea.substr(pos_inicial, pos_final);

            //Segunda posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string Titulo = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string Autor = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Cuarta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string Genero = linea.substr(pos_inicial, pos_final - pos_inicial);

             //Quinta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            int Paginas = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Sexta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            int Puntaje =atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Sexta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            int Ejemplares = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            Libro Nuevo = Libro(Id, Titulo, Autor, Genero, Paginas, Puntaje, Ejemplares, Ejemplares);

            BibliotecaAlumnos.agregar(Nuevo);
        }
    }
}
