/* 
 * Programa:    prog12_10
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 12:
 *              Ejemplo de gesti�n del buffer de un stream.
 */


#include <stdio.h>
#define TAM_BUFFER 256

int main(void)
{
    char car;
    int i = 0;
    int j = 0;
    char buffer[TAM_BUFFER];

    /* Fijar para stdout el alamacen en buf, con buffering
     * completo y tama�o de buffer 256
     */
    i = setvbuf(stdout, buffer, _IOFBF, TAM_BUFFER);
    if ( i != 0)
        fprintf(stderr, "Error al definir el nuevo buffer \n");

    /* Lectura de la entrada est�ndar y escritura en la salida est�ndar. 
     * Se hace volcado del {\it stream} cada 10 caracteres usando fflush.
     */
    while (fscanf(stdin, "%c", &car) != EOF)
    {
       fprintf(stdout, "%c", car);
       i ++;
       if ((i % 10)== 0)
       {
           j = fflush(stdout);
           if ( j != 0)
               fprintf(stderr, "Error al volcar el buffer \n");
       }
    }
    return(0);
}

