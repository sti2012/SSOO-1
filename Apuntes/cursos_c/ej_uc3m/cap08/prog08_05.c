/*
 * Programa:    prog_08_05
 * Autores:     Jes�s Carretero P�rez,
 *              F�lix Garc�a Carballeira,
 *              Javier Fern�ndez Mu�oz,
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 8:
 *              Programa que lee e imprime un list�n telef�nico
 */
#include <stdio.h>
#include <stdlib.h>

struct TelefonoPersonal
{
    char nombre[256];
    long telefono;
};
typedef struct TelefonoPersonal ListinTelefonico;

/*
 * Funci�n que lee un list�n telef�nico
 * La funci�n devuelve 1 si se ejecut� con �xito y 0 en 
 * caso de error al introducir alg�n dato
 */
int leerListinTelefonico(ListinTelefonico listin[], int n)
{
    short leidos;
    int j;

    for (j = 0; j < n; j++) {
        printf("Introduzca el nombre: ");
        leidos = scanf("%s", listin[j].nombre);
        if (leidos < 1)
                return (0);  

        printf("Introduzca el telefono: ");
        leidos = scanf("%ld", &(listin[j].telefono));
        if (leidos < 1)
                return (0);  
    }

    /*
     * Salida con �xito 
     */
    return (1);
}

/* 
 * Funci�n que imprime un list�n telef�nico
 */
void imprimirListinTelefonico(const ListinTelefonico listin[], int n)
{
    int j;

    for (j = 0; j < n; j++) {
        printf("Nombre: %s\n", listin[j].nombre);
        printf("Telefono: %ld\n\n", listin[j].telefono);
    }
    return;
}

int main(void)
{
    int numeroTelefonos = 0;
    short leidos;
    int error;
    ListinTelefonico * listin;


    printf("�Cu�ntos tel�fonos desea introducir? ");
    leidos = scanf("%d", &numeroTelefonos);
    if (leidos < 1) {
        printf("Error al introducir el n�mero de tel�fonos\n");
        return(0);
    }
    listin = (ListinTelefonico *) malloc(numeroTelefonos * 
                                         sizeof(ListinTelefonico));
    if (listin == NULL) {
            printf("No se puede reservar espacio para el list�n\n");
            return(0);
    }

    error = leerListinTelefonico(listin, numeroTelefonos);
    if (error == 0)
        printf("Error al introducir los datos\n");
    else
        imprimirListinTelefonico(listin, numeroTelefonos);

    return (0);
}


