/*
 * Programa:    prog_08_05
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Capítulo 8:
 *              Programa que lee e imprime un listín telefónico
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
 * Función que lee un listín telefónico
 * La función devuelve 1 si se ejecutó con éxito y 0 en 
 * caso de error al introducir algún dato
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
     * Salida con éxito 
     */
    return (1);
}

/* 
 * Función que imprime un listín telefónico
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


    printf("¿Cuántos teléfonos desea introducir? ");
    leidos = scanf("%d", &numeroTelefonos);
    if (leidos < 1) {
        printf("Error al introducir el número de teléfonos\n");
        return(0);
    }
    listin = (ListinTelefonico *) malloc(numeroTelefonos * 
                                         sizeof(ListinTelefonico));
    if (listin == NULL) {
            printf("No se puede reservar espacio para el listón\n");
            return(0);
    }

    error = leerListinTelefonico(listin, numeroTelefonos);
    if (error == 0)
        printf("Error al introducir los datos\n");
    else
        imprimirListinTelefonico(listin, numeroTelefonos);

    return (0);
}


