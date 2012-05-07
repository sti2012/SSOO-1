//ejemplo6_21.c
#include <stdio.h>
#include <stdlib.h>

#define ALUM 40
#define ASIG 8


const char *nombreAsignatura(int num){
    const char *asignaturas[ASIG] ={
            "matemáticas", "lengua", "geografía", "historia",
            "programación", "sistemas operativos", "biología", "geología"};
    const char *res;

    if (num < 0 || num > ASIG){
        res = "que asignatura es esta?";
    }
    else{
        res = asignaturas[num];
    }
    return res;
}

int leeAlumnos(){
    int buf;

    printf("Numero de alumnos en la clase: ");
    scanf("%d", &buf);
    return buf;
}

void leeNotas(int alumnos, double notas[ALUM][ASIG]){
    int i, j;
    double buf;

    for (i=0; i<alumnos; i++){
        for (j=0; j<ASIG; j++){
            printf("Nota del alumno %d de %s: ", i+1, nombreAsignatura(j));
            scanf("%lf", &buf);
            notas[i][j] = buf;
        }
    }
}

void leePonderaciones(int vec[ASIG]){
    int buf, i;

    printf("Ponderaciones de las asignaturas en porcentaje (han de sumar 100).\n");
    for (i=0; i<ASIG; i++){
        printf("Vector de ponderación de %s: ", nombreAsignatura(i));
        scanf("%d", &buf);
        vec[i] = buf;
    }
}

void compruebaPonderaciones(int vec[ASIG]){
    int i, suma=0;

    for (i=0; i<ASIG; i++){
        suma += vec[i];
    }
    if (suma != 100){
        printf("Mal asunto, las ponderaciones no suman 100%.\n");
    }
}

void calculaMedias(int alumnos, double notas[ALUM][ASIG], int ponderaciones[ASIG], double medias[ALUM])
{
    int i, j;
    double suma;

    for (i=0; i<alumnos; i++){
        suma = 0.0;
        for (j=0; j<ASIG; j++){
            suma += notas[i][j] * ponderaciones[j]/100;
        }
        medias[i] = suma;
    }
}

void imprimeMedias(int alumnos, double medias[ALUM]){
    int i;

    for (i=0; i<alumnos; i++){
        printf("Nota media del alumno %d: %lf\n", i, medias[i]);
    }
}

int main (){
    int alumnos;
    double notas[ALUM][ASIG];
    double medias[ALUM];
    int ponderaciones[ASIG];

    alumnos = leeAlumnos();
    leeNotas(alumnos, notas);
    leePonderaciones(ponderaciones);
    compruebaPonderaciones(ponderaciones);
    calculaMedias(alumnos, notas, ponderaciones, medias);
    imprimeMedias(alumnos, medias);
    system("pause");
    return 0;
}
