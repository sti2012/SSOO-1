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
 * Funci�n solicitarMesyAnyo()
 *
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      TipoFecha * fecha: Fecha insertada po el usuario
 *
 * Descripci�n: 
 *      Solicita el mes y el a�o al usuario
 */
static void solicitarMesyAnyo(TipoFecha *fecha) 
{
    int mes, anyo;
    int ret;

    printf ("\nIntroduzca el mes: ");
    scanf ("%i",&mes);
    printf ("Introduzca el a�o: ");
    scanf ("%i",&anyo);
    printf ("\n");
    ret = componerFecha( 1, mes, anyo, fecha);
    if (0 != ret) {
        printf("Error, fecha no v�lida\n");
    }
    
}
    
/*
 * Funci�n imprimirCalendario()
 *
 * Par�metros de entrada:
 *      int mes: Mes que se va a mostrar
 *      int a�o: A�o que se va a mostrar
 *      
 * Par�metros de salida:
 *      Ninguno
 *
 * Descripci�n: 
 *      Imprime el calendario del mes y el a�o solicitados
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

    /* Escribir los n�meros de los dias*/
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
 * FUNCIONES P�BLICAS
 */

/*
 * Funci�n menuCalendario
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
        printf(" 3.- Seleccionar a�o anterior\n");
        printf(" 4.- Seleccionar a�o siguiente\n");
        printf(" 5.- Seleccionar mes y a�o\n");
        printf(" 0.- Volver al menu anterior\n\n");
        printf("\n");
        printf("\n");
        printf("Introduzca su opci�n: ");
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
            /* la opci�n elegida no esta dentro de las indicadas */
            printf("La opcion elegida es incorrecta\n\n");
        }  
   }while (0 == final);  
}

