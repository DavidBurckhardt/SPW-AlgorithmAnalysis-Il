#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED
#include <set>
#include <vector>

struct PerfilAlumno{
    int PuntajeAcumulado;
    set<string> LibrosAsignados;};

struct Alumnos{
    vector<PerfilAlumno> Informacion;
    int CantidadAprobados;};

#endif // ALUMNOS_H_INCLUDED
