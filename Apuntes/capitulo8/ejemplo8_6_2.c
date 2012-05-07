//ejemplo8_6_2.c
#include <stdio.h>

int main (){
    FILE* f;
    char c;
    f=fopen("mifichero.dat","w");
    if (f == NULL){
        printf ("Error al abrir el fichero");
    }
    else{  //si se abri� correctamente escribimos el texto al fichero
        do{
            c=getchar();
            putc(toupper(c),f);
        }while (c != '\n'); //mientras no encontremos el car�cter de nueva l�nea
        //ahora estas sentencias s�lo se ejecutan si se abri� el fichero
        fflush (f);
        fclose(f);
    }

    //ahora mostramos el contenido del fichero
    f=fopen("mifichero.dat","r");
    if (f == NULL){
        printf ("El al abrir el fichero");
    }
    else{  //si se abri� correctamente leemos el texto
        c = getc(f);
        while (c != EOF){ //mientras no lleguemos al final del fichero
            putchar (c);
            c = getc(f);
        }
        //ahora estas sentencias s�lo se ejecutan si se abri� el fichero
        fclose(f);
    }
    return 0;
}
