//ejemplo7_5.c
#include <stdio.h>

int main ()
{
    union Producto
    {
        char clase;
        int id;
    };

    struct{
        char fabricante[20];
        float coste;
        union Producto descripcion;
    }camisa,blusa;

    printf("%d\n",sizeof(union Producto));

    camisa.descripcion.clase='B';
    printf("%c %d\n", camisa.descripcion.clase, camisa.descripcion.id);
    camisa.descripcion.id=12;
    //aunque s�lo hemos modificado id el miembro clase tambi�n ha cambiado
    printf("%c %d\n", camisa.descripcion.clase, camisa.descripcion.id);
    return 0;
}
