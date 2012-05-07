/* 
 * Programa:    prog13_06
 * Autores:     Jes�s Carretero P�rez, 
 *              F�lix Garc�a Carballeira, 
 *              Javier Fernandez Mu�oz, 
 *              Alejandro Calder�n Mateos
 * Fecha:       06-2001
 * Descripci�n: Ejemplo del Cap�tulo 13:
 *              Programa que usa funciones con un n�mero variable de argumentos
 */
    #include <stdio.h>
    #include <stdarg.h>

    int sumar (int contador, ...);
            /* Suma los n�meros que indica contador*/
    int multiplicar (int contador, ...); 
            /* Multiplica los n�meros que indica contador */

    int main(void)
    {
        int solucion;      /* Soluci�n de la operaci�n */
        char eleccion;     /* Operaci�n elegida por el usuario */
        int parametros;    /* Indica cu�ntos n�meros participan */
        
        printf("\n\nElija la operacion que corresponda:\n");
        printf("A. Sumar B. Multiplicar \n ");
        printf("Su eleccion (A, o B) => ");
        scanf("%c",&eleccion);

        switch(eleccion)
        {
            case 'A' : 
                printf ("Cuantos numeros pares quiere sumar a 2? ");
                printf("Su eleccion entre 1 y 3 =>");        
                scanf("%d",&parametros);
                 switch(parametros)
                {
                    case 1: solucion = sumar(parametros,4);
                            break;
                    case 2: solucion = sumar(parametros,4,6);
                            break;
                    case 3: solucion = sumar(parametros,4,6,8);
                            break;
                    default: printf("Eleccion erronea \n"); 
                            break;
                } /* Fin del switch. */
                printf("\n La suma es  => %d \n", solucion);        
                break;
            case 'B' : 
                printf ("Cuantos numeros pares quiere multiplicar por 2? ");  
                printf("Su eleccion entre 1 y 3 =>");        
                scanf("%d",&parametros);
                switch(parametros)
                {
                    case 1: solucion= multiplicar(parametros,4);
                            break;
                    case 2: solucion= multiplicar(parametros,4,6); 
                            break;
                    case 3: solucion= multiplicar(parametros,4,6,8);
                            break;
                    default: printf("Eleccion erronea \n");
                            break;
                } /* Fin del switch. */
                printf("\n La multiplicacion es  => %d \n", solucion);    
                break;
            default: 
                 printf ("Operacion invalida \n");
                 break;
        }   /* Fin del switch. */
        return (0);
    }

    /* 
     * Funci�n que suma los n�meros que indica contador
     */
    int sumar (int contador, ...) 
    {
        va_list    args;  /* lista de argumentos */
        int        arg;   /* argumento individual */
        int total = 2;    /* variable de almacenamiento de resultados */
        int i;
    
        va_start (args, contador);
        for (i=0; i<contador; i++)
        {
            arg = va_arg(args, int);
            total = total + arg;
        }
        va_end(args);
        return(total);
    }

    /* 
     * Multiplica los n�meros que indica contador 
     */
    int multiplicar (int contador, ...)     
    {
        va_list args;   /* lista de argumentos */
        int     arg;    /* argumento individual */
        int total = 2;  /* variable de almacenamiento de resultados */
        int i;
    
        va_start (args, contador);
        for (i=0; i<contador; i++)
        {
             arg = va_arg(args, int);
             total = total * arg;
        }
        va_end(args);
        return(total);
    }
