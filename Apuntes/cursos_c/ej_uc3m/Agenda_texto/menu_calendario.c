/*
 * Programa: agenda
 * Modulo  : menu_calendario
 * Fichero : menu_calendario.c
 */

/*
 * FICHEROS INCLUDES
 */
#include "menu_calendario.h"

/*
 * FUNCIONES PRIVADAS
 */

/*
 * Función solicitarMesyAnyo()
 *
 * Parámetros de entrada:
 *      Ninguno
 *      
 * Parámetros de salida:
 *      TipoFecha * fecha: Fecha insertada po el usuario
 *
 * Descripción: 
 *      Solicita el mes y el año al usuario
 */
static void solicitarMesyAnyo(TipoFecha *fecha) 
{
    int mes, anyo;
    int ret;

    printf ("\nIntroduzca el mes: ");
    scanf ("%i",&mes);
    printf ("Introduzca el año: ");
    scanf ("%i",&anyo);
    printf ("\n");
    ret = componerFecha( 1, mes, anyo, fecha);
    if (0 != ret) {
        printf("Error, fecha no válida\n");
    }
    
}
    
/*
 * Función imprimirCalendario()
 *
 * Parámetros de entrada:
 *      int mes: Mes que se va a mostrar
 *      int año: Año que se va a mostrar
 *      
 * Parámetros de salida:
 *      Ninguno
 *
 * Descripción: 
 *      Imprime el calendario del mes y el año solicitados
 */
static void imprimirCalendario(int mes, int anyo)
{
    TipoFecha fecha;
    int diaSemana;
    int diasMes;
    int contador;
    int diaActual;
    int diaInicio;
    char nombreMes[100];

    /* calcular los datos de dicho mes*/
    diasMes = obtenerDiasMes(mes,anyo);
    componerFecha( 1, mes, anyo, &fecha);
    diaSemana = obtenerDiaSemana(fecha);
    

    /* imprimir la cabecera */
    

    obtenerNombreMes(mes,nombreMes);
    printf ("\t\t%s  %d\n\n",nombreMes,anyo);
    printf(" L\t M\t X\t J\t V\t S\t D\n");
    printf("---------------------------------------------------\n");

    /* saltarse los blancos */
    for (contador = 1; contador < diaSemana; contador++) {
        printf ("\t");
    }

    /* Escribir los números de los dias*/
    diaActual = 1;
    diaInicio = diaSemana;
    while (diaActual <= diasMes) {
        contador = diaInicio; 
        while ((DIAS_SEMANA >= contador) && (diaActual <= diasMes)) { 
            printf ("%2d\t",diaActual); 
            diaActual = diaActual + 1;
            contador = contador + 1;
        }
        printf ("\n"); /* salto de linea */
        diaInicio = 1;
    }
}

/*
 * FUNCIONES PÚBLICAS
 */

/*
 * Función menuCalendario
 */
void menuCalendario (void)
{
    int opcion;
    int mesElegido;
    int anyoElegido;
    TipoFecha fecha;
    int final = 0;

   
    /* Obtener fecha actual*/
    fecha = obtenerFechaActual();
    do{         
        /* Mostrar el calendario */
        printf("\n\n");
        mesElegido = obtenerMes(fecha);
        anyoElegido = obtenerAnyo(fecha);
        imprimirCalendario(mesElegido,anyoElegido);

        /* Mostrar el menu de opciones */
        opcion = -1;
        printf("\n");
        printf("Calendario\n");
        printf("----------\n");
        printf("\n");
        printf(" 1.- Seleccionar mes anterior\n");
        printf(" 2.- Seleccionar mes siguiente\n");
        printf(" 3.- Seleccionar año anterior\n");
        printf(" 4.- Seleccionar año siguiente\n");
        printf(" 5.- Seleccionar mes y año\n");
        printf(" 0.- Volver al menu anterior\n\n");
        printf("\n");
        printf("\n");
        printf("Introduzca su opción: ");
        scanf ("%d",&opcion);

        switch(opcion){
        case 1:
            /* Calcular mes anterior */
            decrementarMes(&fecha,1);
            break;
        case 2: 
            /* Calcular mes siguiente */
            incrementarMes(&fecha,1);
            break;
        case 3:
            /* Calcular anyo anterior */
            decrementarAnyo(&fecha,1);
            break;
        case 4:
            /* Calcular anyo siguiente */
            incrementarAnyo(&fecha,1);
            break;
        case 5:
            /* Solicitar una fecha al usuario */
            solicitarMesyAnyo(&fecha);
            break;
        case 0:
            /* Salir del menu */
            final=1;
            break;
        default:
            /* la opción elegida no esta dentro de las indicadas */
            printf("La opcion elegida es incorrecta\n\n");
        }  
   }while (0 == final);  
}

