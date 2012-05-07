//escuela.h
#ifndef __ESCUELA_H
#define __ESCUELA_H

// Definición de tipos
typedef struct{
    long int DNI;
    char nombre[100];
    char direccion[100];
    int  codPostal;
    char ciudad[30];
    int  campoValido;
}Persona;

typedef struct{
    int  idAsignatura;
    char nombre[100];
    int  campoValido;
}Asignatura;

typedef struct{
    Persona persona;
    int numAsignaturasMatriculadas;
    int listaIdAsignaturas[10];
    int listaNotas[10];
}Alumno;

typedef struct{
    Persona persona;
    int numAsignaturasImpartidas;
    int listaIdAsignaturas[10];
    char areaInvestigacion[100];
}Profesor;

struct AlumnoLista{
    Alumno alumno;
    struct AlumnoLista* alumnoSiguiente;
};

struct ProfesorLista{
    Profesor profesor;
    struct ProfesorLista* profesorSiguiente;
};

struct AsignaturaLista{
    Asignatura asignatura;
    struct AsignaturaLista* asignaturaSiguiente;
};

typedef struct{
    struct AlumnoLista* alumnoBD;
    struct ProfesorLista* profesorBD;
    struct AsignaturaLista* asignaturaBD;
}BaseDeDatos;
#endif
