//ejemplo7_10.c
#include <stdio.h>
#include <stdlib.h>
#include "escuela.h"
#define NUMFACULTADES 2

void menuPrincipal(BaseDeDatos bd[NUMFACULTADES],
                   char nombreFacultad[NUMFACULTADES][100]){
    int bdActiva=0, bdActivaValida;
    enum Opcion {opCambiarBaseDeDatosActiva=1, opSolicitarAsignatura,
          opBorrarAsignatura, opSolicitarProfesor,opBorrarProfesor,
          opSolicitarAlumno, opBorrarAlumno, opMostrarBD, opTerminar} opcion;
    do{
        system("CLS");
        printf("Base de datos activa: %d %s\n\n",
        bdActiva,nombreFacultad[bdActiva]);
        printf("1.- Cambiar de base de datos activa\n"
               "2.- Introducir nueva asignatura\n"
               "3.- Borrar asignatura\n"
               "4.- Introducir nuevo profesor\n"
               "5.- Borrar profesor\n"
               "6.- Introducir nuevo alumno\n"
               "7.- Borrar alumno\n"
               "8.- Mostrar base de datos\n"
               "9.- Salir\n\n"
               "Introduzca opción: ");
        scanf("%d",&opcion);
        switch (opcion){
        case opCambiarBaseDeDatosActiva:
            do{
                bdActivaValida=0;
                printf("Introduzca el número de la nueva BD:");
                scanf("%d",&bdActiva);
                bdActivaValida=bdActiva>=0 && bdActiva<NUMFACULTADES;
            }
            while (!bdActivaValida);
            break;
        case opSolicitarAsignatura:
            solicitarAsignatura(&(bd[bdActiva]));
            break;
        case opBorrarAsignatura:
            borrarAsignatura(&(bd[bdActiva]));
            break;
        case opSolicitarProfesor:
            solicitarProfesor(&(bd[bdActiva]));
            break;
        case opBorrarProfesor:
            borrarProfesor(&(bd[bdActiva]));
            break;
        case opSolicitarAlumno:
            solicitarAlumno(&(bd[bdActiva]));
            break;
        case opBorrarAlumno:
            borrarAlumno(&(bd[bdActiva]));
            break;
        case opMostrarBD:
            system("CLS");
            imprimirBaseDeDatos(&(bd[bdActiva]));
            system("PAUSE");
            break;
        }
    }
    while (opcion!=opTerminar);
}

// Funciones de prueba
void prueba1(BaseDeDatos *bd, int numbase, char *cadbase){
    Asignatura asignatura;
    asignatura.idAsignatura=numbase*10;
    strcpy(asignatura.nombre,cadbase);
    strcat(asignatura.nombre,"_0");
    appendAsignatura(bd,&asignatura);

    asignatura.idAsignatura=numbase*10+1;
    strcpy(asignatura.nombre,cadbase);
    strcat(asignatura.nombre,"_1");
    appendAsignatura(bd,&asignatura);

    Profesor profesor;
    profesor.persona.DNI=10000000*numbase;
    strcpy(profesor.persona.nombre,cadbase);
    strcat(profesor.persona.nombre,"_profesor");
    strcpy(profesor.persona.direccion,cadbase);
    strcat(profesor.persona.direccion,"_direccion_profesor");
    profesor.persona.codPostal=28000+numbase;
    strcpy(profesor.persona.ciudad,"Madrid");
    profesor.numAsignaturasImpartidas=2;
    profesor.listaIdAsignaturas[0]=numbase*10;
    profesor.listaIdAsignaturas[1]=numbase*10+1;
    strcpy(profesor.areaInvestigacion,cadbase);
    strcat(profesor.areaInvestigacion,"_investigacion");
    appendProfesor(bd,&profesor);

    Alumno alumno;
    alumno.persona.DNI=20000000*numbase;
    strcpy(alumno.persona.nombre,cadbase);
    strcat(alumno.persona.nombre,"_alumno");
    strcpy(alumno.persona.direccion,cadbase);
    strcat(alumno.persona.nombre,"_direccion_alumno");
    alumno.persona.codPostal=28000+numbase;
    strcpy(alumno.persona.ciudad,"Madrid");
    alumno.numAsignaturasMatriculadas=2;
    alumno.listaIdAsignaturas[0]=numbase*10;
    alumno.listaIdAsignaturas[1]=numbase*10+1;
    alumno.listaNotas[0]=9;
    alumno.listaNotas[1]=10;
    appendAlumno(bd,&alumno);
}

// Comentar esta linea para compilar sin modo prueba
#define PRUEBA
int main(){
    BaseDeDatos bd[NUMFACULTADES];
    char nombreFacultad[NUMFACULTADES][100]={"Escuela Politécnica Superior",
                                             "Facultad de Farmacia"};
    int i;
    for (i=0; i<NUMFACULTADES; ++i)
        inicializaBD(&(bd[i]));

#ifdef PRUEBA
    /* El modo prueba sirve para rellenar la base de datos con
       datos ficticios de forma que no haya que introducirlos
       manualmente cada vez que se desea probar el programa */
    prueba1(&(bd[0]),1,"EPS_base_1_");
    prueba1(&(bd[0]),2,"EPS_base_2_");
    prueba1(&(bd[1]),1,"Farmacia_base_1_");
    prueba1(&(bd[1]),2,"Farmacia_base_2_");
#endif

    menuPrincipal(bd,nombreFacultad);
    return 0;
}
#undef PRUEBA
