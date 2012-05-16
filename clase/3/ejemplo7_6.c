//ejemplo7_6.c
#include <stdio.h>
#include <string.h>

int main()
{
    enum diasemana {lunes, martes, miercoles, jueves, viernes, sabado, domingo};
    int dia;

    for (dia = lunes; dia <= domingo; dia++ ){
        if (dia != sabado && dia != domingo ){
            printf("El dia %d es laborable\n", dia);
        }
        else{
            printf("El dia %d no es laborable\n", dia);
        }
    }
    return 0;
}
