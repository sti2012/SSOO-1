//escuela.c
#include "escuela.h"

struct AsignaturaLista* buscarUltimaAsignatura(const BaseDeDatos *bd){
    struct AsignaturaLista* asignaturaActual=bd->asignaturaBD;
    if (asignaturaActual==NULL) return NULL;
    while (asignaturaActual->asignaturaSiguiente!=NULL){
        asignaturaActual=asignaturaActual->asignaturaSiguiente;
    }
    return asignaturaActual;
}

Asignatura* buscarAsignatura(const BaseDeDatos *bd, int idAsignatura){
    struct AsignaturaLista* asignaturaActual=bd->asignaturaBD;
    while (asignaturaActual!=NULL){
        if (asignaturaActual->asignatura.idAsignatura==idAsignatura &&
                asignaturaActual->asignatura.campoValido){
            return &(asignaturaActual->asignatura);
        }
        else{
            asignaturaActual=asignaturaActual->asignaturaSiguiente;
        }
    }
    return NULL;
}

int appendAsignatura(BaseDeDatos *bd, Asignatura *asignatura){
    if (buscarAsignatura(bd,asignatura->idAsignatura)==NULL){
        struct AsignaturaLista* nuevaAsignatura=
              (struct AsignaturaLista*) malloc(sizeof(struct AsignaturaLista));
        nuevaAsignatura->asignatura=*asignatura;
        nuevaAsignatura->asignatura.campoValido=1;
        nuevaAsignatura->asignaturaSiguiente=NULL;
        if (bd->asignaturaBD==NULL) bd->asignaturaBD=nuevaAsignatura;
        else{
            struct AsignaturaLista* ultimaAsignatura=buscarUltimaAsignatura(bd);
            ultimaAsignatura->asignaturaSiguiente=nuevaAsignatura;
        }
        return 0;
    }
    else{
        return 1;
    }
}

int deleteAsignatura(BaseDeDatos *bd, int idAsignatura){
    Asignatura* asignatura=buscarAsignatura(bd,idAsignatura);
    if (asignatura!=NULL){
        asignatura->campoValido=0;
        return 0;
    }
    else{
        return 1;
    }
}

struct ProfesorLista* buscarUltimoProfesor(const BaseDeDatos *bd){
    struct ProfesorLista* profesorActual=bd->profesorBD;
    if (profesorActual==NULL) return NULL;
    while (profesorActual->profesorSiguiente!=NULL){
        profesorActual=profesorActual->profesorSiguiente;
    }
    return profesorActual;
}

Profesor* buscarProfesor(const BaseDeDatos *bd, long int DNI){
    struct ProfesorLista* profesorActual=bd->profesorBD;
    while (profesorActual!=NULL){
        if (profesorActual->profesor.persona.DNI==DNI &&
                profesorActual->profesor.persona.campoValido){
            return &(profesorActual->profesor);
        }
        else{
            profesorActual=profesorActual->profesorSiguiente;
        }
    }
    return NULL;
}

int appendProfesor(BaseDeDatos *bd, Profesor *profesor){
    if (buscarProfesor(bd,profesor->persona.DNI)==NULL){
        struct ProfesorLista* nuevoProfesor=
               (struct ProfesorLista*) malloc(sizeof(struct ProfesorLista));
        nuevoProfesor->profesor=*profesor;
        nuevoProfesor->profesor.persona.campoValido=1;
        nuevoProfesor->profesorSiguiente=NULL;
        if (bd->profesorBD==NULL) bd->profesorBD=nuevoProfesor;
        else{
            struct ProfesorLista* ultimoProfesor = buscarUltimoProfesor(bd);
            ultimoProfesor->profesorSiguiente = nuevoProfesor;
        }
        return 0;
    }
    else{
        return 1;
    }
}

int deleteProfesor(BaseDeDatos *bd, long int DNI){
    Profesor* profesor=buscarProfesor(bd,DNI);
    if (profesor!=NULL){
        profesor->persona.campoValido=0;
        return 0;
    }
    else{
        return 1;
    }
}

struct AlumnoLista* buscarUltimoAlumno(const BaseDeDatos *bd){
    struct AlumnoLista* alumnoActual=bd->alumnoBD;
    if (alumnoActual==NULL) return NULL;
    while (alumnoActual->alumnoSiguiente!=NULL){
        alumnoActual=alumnoActual->alumnoSiguiente;
    }
    return alumnoActual;
}

Alumno* buscarAlumno(const BaseDeDatos *bd, long int DNI){
    struct AlumnoLista* alumnoActual=bd->alumnoBD;
    while (alumnoActual!=NULL){
        if (alumnoActual->alumno.persona.DNI==DNI &&
                alumnoActual->alumno.persona.campoValido){
            return &(alumnoActual->alumno);
        }
        else{
            alumnoActual=alumnoActual->alumnoSiguiente;
        }
    }
    return NULL;
}

int appendAlumno(BaseDeDatos *bd, Alumno *alumno){
    if (buscarAlumno(bd,alumno->persona.DNI)==NULL){
        struct AlumnoLista* nuevoAlumno=
               (struct AlumnoLista*) malloc(sizeof(struct AlumnoLista));
        nuevoAlumno->alumno=*alumno;
        nuevoAlumno->alumno.persona.campoValido=1;
        nuevoAlumno->alumnoSiguiente=NULL;
        if (bd->alumnoBD==NULL) bd->alumnoBD=nuevoAlumno;
        else{
            struct AlumnoLista* ultimoAlumno = buscarUltimoAlumno(bd);
            ultimoAlumno->alumnoSiguiente=nuevoAlumno;
        }
        return 0;
    }
    else{
        return 1;
    }
}

int deleteAlumno(BaseDeDatos *bd, long int DNI){
    Alumno* alumno=buscarAlumno(bd,DNI);
    if (alumno!=NULL){
        alumno->persona.campoValido=0;
        return 0;
    }
    else{
        return 1;
    }
}

void inicializaBD(BaseDeDatos *bd){
    bd->alumnoBD=NULL;
    bd->profesorBD=NULL;
    bd->asignaturaBD=NULL;
}

void imprimirPersona(const BaseDeDatos *bd, const Persona *persona){
    if (persona==NULL) return;
    printf("DNI=%ld\n"
           "Nombre=%s\n"
           "Dirección=%s\n"
           "C.P.=%05d\n"
           "Ciudad=%s\n",
           persona->DNI,persona->nombre,persona->direccion,
           persona->codPostal, persona->ciudad);
}

void imprimirAlumno(const BaseDeDatos *bd, const Alumno *alumno){
    int i;
    if (alumno==NULL) return;
    imprimirPersona(bd,&(alumno->persona));
    printf("Asignaturas en las que se encuentra matriculado\n");
    for (i=0; i<alumno->numAsignaturasMatriculadas; i++){
        Asignatura *asignatura=
            buscarAsignatura(bd,alumno->listaIdAsignaturas[i]);
        if (asignatura!=NULL){
            printf("%s Nota: %d\n",asignatura->nombre,alumno->listaNotas[i]);
        }
    }
    printf("\n");
}

void imprimirProfesor(const BaseDeDatos *bd, const Profesor *profesor){
    int i;
    if (profesor==NULL) return;
    imprimirPersona(bd,&(profesor->persona));
    printf("Asignaturas que imparte\n");
    for (i=0; i<profesor->numAsignaturasImpartidas; i++){
      Asignatura *asignatura=buscarAsignatura(bd,profesor->listaIdAsignaturas[i]);
      if (asignatura!=NULL){
          printf("%s\n",asignatura->nombre);
      }
    }
    printf("Area de investigación: %s\n\n",profesor->areaInvestigacion);
}

void imprimirAsignatura(const BaseDeDatos *bd, const Asignatura *asignatura){
    if (asignatura==NULL) return;
    printf("Código: %d \t Nombre: %s\n",
           asignatura->idAsignatura,asignatura->nombre);
}

void imprimirBaseDeDatos(const BaseDeDatos *bd){
    printf("\n\nListado de asignaturas\n");
    struct AsignaturaLista* asignaturaActual=bd->asignaturaBD;
    while (asignaturaActual!=NULL){
        if (asignaturaActual->asignatura.campoValido)
            imprimirAsignatura(bd,&(asignaturaActual->asignatura));
        asignaturaActual=asignaturaActual->asignaturaSiguiente;
    }

    printf("\n\nListado de profesores\n");
    struct ProfesorLista* profesorActual=bd->profesorBD;
    while (profesorActual!=NULL){
        if (profesorActual->profesor.persona.campoValido)
            imprimirProfesor(bd,&(profesorActual->profesor));
        profesorActual=profesorActual->profesorSiguiente;
    }

    printf("\n\nListado de alumnos\n");
    struct AlumnoLista* alumnoActual=bd->alumnoBD;
    while (alumnoActual!=NULL){
        if (alumnoActual->alumno.persona.campoValido)
            imprimirAlumno(bd,&(alumnoActual->alumno));
        alumnoActual=alumnoActual->alumnoSiguiente;
    }
}

void solicitarAsignatura(BaseDeDatos *bd){
    Asignatura asignatura;
    system("CLS");
    printf("Introduzca el código de la asignatura: ");
    scanf("%d",&asignatura.idAsignatura);
    if (buscarAsignatura(bd,asignatura.idAsignatura)!=NULL){
        printf("Ya hay una asignatura con este código\n");
        system("PAUSE");
        return;
    }

    printf("Introduzca el nombre de la asignatura: ");
    scanf(" %[^\n]",&asignatura.nombre);
    if (appendAsignatura(bd,&asignatura)){
        printf("Error al introducir la asignatura en la BD\n");
        system("PAUSE");
        return;
    }
}

Persona solicitarPersona(const BaseDeDatos* bd){
    Persona persona;
    system("CLS");
    printf("Introduzca el DNI: ");
    scanf("%ld",&persona.DNI);

    if (buscarProfesor(bd,persona.DNI)!=NULL ||buscarAlumno(bd,persona.DNI)!=NULL){
        printf("Ya hay una persona con este DNI\n");
        system("PAUSE");
        return;
    }
    printf("Introduzca el nombre: ");
    scanf(" %[^\n]",&persona.nombre);
    printf("Introduzca la dirección: ");
    scanf(" %[^\n]",&persona.direccion);
    printf("Introduzca el código postal: ");
    scanf("%d",&persona.codPostal);
    printf("Introduzca la ciudad: ");
    scanf(" %[^\n]",&persona.ciudad);
    persona.campoValido=1;
    return persona;
}

void solicitarProfesor(BaseDeDatos *bd){
    int i, asignaturaValida;
    Profesor profesor;
    profesor.persona=solicitarPersona(bd);
    printf("Número de asignaturas impartidas: ");
    scanf("%d",&profesor.numAsignaturasImpartidas);
    for (i=0; i<profesor.numAsignaturasImpartidas; ++i){
        do{
            asignaturaValida=0;
            printf("Introduzca el código de la asignatura %d:",i);
            scanf("%d",&(profesor.listaIdAsignaturas[i]));
            asignaturaValida=
                buscarAsignatura(bd,profesor.listaIdAsignaturas[i])!=NULL;
        }
        while (!asignaturaValida);
    }

    printf("Introduzca area de investigación:");
    scanf(" %[^\n]",&profesor.areaInvestigacion);
    if (appendProfesor(bd,&profesor)){
        printf("Error al introducir el profesor en la BD\n");
        system("PAUSE");
        return;
    }
}

void solicitarAlumno(BaseDeDatos *bd){
    int i, asignaturaValida, notaValida;
    Alumno alumno;
    alumno.persona=solicitarPersona(bd);
    printf("Número de asignaturas matriculadas: ");
    scanf("%d",&alumno.numAsignaturasMatriculadas);
    for (i=0; i<alumno.numAsignaturasMatriculadas; ++i){
        do{
            asignaturaValida=0;
            printf("Introduzca el código de la asignatura %d:",i);
            scanf("%d",&(alumno.listaIdAsignaturas[i]));
            asignaturaValida=
                buscarAsignatura(bd,alumno.listaIdAsignaturas[i])!=NULL;
        }
        while (!asignaturaValida);

        do{
            notaValida=0;
            printf("Introduzca la nota en esta asignatura:");
            scanf("%d",&(alumno.listaNotas[i]));
            notaValida=(alumno.listaNotas[i]>=0) && (alumno.listaNotas[i]<=10);
        }
        while (!asignaturaValida);
    }

    if (appendAlumno(bd,&alumno)){
        printf("Error al introducir el alumno en la BD\n");
        system("PAUSE");
        return;
    }
}

void borrarAsignatura(BaseDeDatos *bd){
    int idAsignatura;
    system("CLS");
    printf("Introduzca el código de la asignatura a borrar:");
    scanf("%d",&idAsignatura);
    if (deleteAsignatura(bd,idAsignatura)){
        printf("La asignatura no ha podido ser borrada");
        system("PAUSE");
    }
}

void borrarProfesor(BaseDeDatos *bd){
    int DNI;
    system("CLS");
    printf("Introduzca el DNI del profesor a borrar:");
    scanf("%ld",&DNI);
    if (deleteProfesor(bd,DNI)){
        printf("El profesor no ha podido ser borrado");
        system("PAUSE");
    }
}

void borrarAlumno(BaseDeDatos *bd){
    int DNI;
    system("CLS");
    printf("Introduzca el DNI del alumno a borrar:");
    scanf("%ld",&DNI);
    if (deleteAlumno(bd,DNI)){
        printf("El alumno no ha podido ser borrado");
        system("PAUSE");
    }
}
