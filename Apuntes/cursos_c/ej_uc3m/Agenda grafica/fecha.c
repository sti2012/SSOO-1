/*
 * Programa: agenda
 * Modulo  : fecha
 * Fichero : fecha.c
 */


/*
 * FICHEROS INCLUDE
 */
#include <string.h>
#include <time.h>
#include "fecha.h"


/*
 * FUNCIONES PUBLICAS 
 */

/*
 * Función obtenerFechaActual()
 */
TipoFecha obtenerFechaActual() 
{
    struct tm *fechaActual;
    time_t tiempo;
    TipoFecha resultado;

    tiempo = time(NULL);
    fechaActual = localtime(&tiempo);
    resultado.dia = fechaActual->tm_mday;
    resultado.mes = (fechaActual->tm_mon + 1);
    resultado.anyo = (fechaActual->tm_year + 1900);

    return(resultado);
}

/*
 * Función componerFecha()
 */
int componerFecha (int dia, int mes, int anyo, TipoFecha *fecha)
{
    int diasMes;

    if ((0 < anyo) && (1 <= mes) && (12 >= mes)) {
        diasMes = obtenerDiasMes(mes,anyo);
        if (( 1 <= dia) && (diasMes >= dia))  {
            fecha->dia = dia;
            fecha->mes = mes;
            fecha->anyo = anyo;
            return (0); /* Todo ha ido bien */
        }
    }
    return (-1); /* Error, fecha no válida */
}

/*
 * Función obtenerDia()
 */
int obtenerDia (TipoFecha fecha)
{
    return (fecha.dia);
}

/*
 * Función obtenerMes()
 */
int obtenerMes (TipoFecha fecha)
{
    return (fecha.mes);
}

/*
 * Función obtenerAnyo()
 */
int obtenerAnyo (TipoFecha fecha)
{
    return (fecha.anyo);
}

/*
 * Función decrementarMes()
 */
void decrementarMes (TipoFecha *fecha, int meses)
{
    int auxMeses = meses; 
   
    while (0 < auxMeses) {

        if (fecha->mes <= auxMeses) {
            decrementarAnyo(fecha,1);
            auxMeses = auxMeses - fecha->mes;
            fecha->mes = 12;
        } else { /* (fecha->mes > auxMeses) */
            fecha->mes = fecha->mes - auxMeses;
            auxMeses = 0;
        }
    }
}

/*
 * Función incrementarMes()
 */
void incrementarMes (TipoFecha *fecha, int meses)
{
    int auxMeses = meses; 
   
    while (0 < auxMeses) {

        if (auxMeses >= (12 - fecha->mes + 1)) {
            incrementarAnyo(fecha,1);
            auxMeses = auxMeses - (12 - fecha->mes +1);
            fecha->mes = 1;
        } else { /* (fecha->mes < (12 - fecha->mes + 1)) */
            fecha->mes = fecha->mes + auxMeses;
            auxMeses = 0;
        }
    }
}

/*
 * Función decrementarAnyo()
 */
void decrementarAnyo (TipoFecha *fecha, int anyos)
{
    fecha->anyo = fecha->anyo - 1;
}

/*
 * Función incrementarAnyo()
 */
void incrementarAnyo (TipoFecha *fecha, int anyos)
{
    fecha->anyo = fecha->anyo + 1;
}

/*
 * Función bisiesto()
 */
int bisiesto(int anyo)
{ 
    int resultado;

    if (0 == (anyo % 100)) {
        if (0 == (anyo % 400)) {
            resultado = 1;
        } else {
            resultado = 0;
        }
    } else if (0 == (anyo % 4)) {  
            resultado = 1;
    } else {
            resultado = 0;
    }
    return(resultado);
}

/*
 * Función obtenerDiasMes()
 */
int obtenerDiasMes (int mes, int anyo)
{
    int resultado;
  
    switch(mes){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        resultado=31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        resultado=30;
        break;
    case 2: 
        if (1 == bisiesto(anyo)) {
            resultado = 29;
        } else {
            resultado = 28;
        }
        break;
    default:
        return(-1); /* Error, mes no válido */
    }
    return(resultado);
}

/*
 * Función obtenerNombreMes()
 */
int obtenerNombreMes (int mes, char nombreMes[])
{
  
    switch(mes){
    case 1:
        strcpy(nombreMes,"Enero");
        break;
    case 2:
        strcpy(nombreMes,"Febrero");
        break;
    case 3:
        strcpy(nombreMes,"Marzo");
        break;
    case 4:
        strcpy(nombreMes,"Abril");
        break;
    case 5:
        strcpy(nombreMes,"Mayo");
        break;
    case 6:
        strcpy(nombreMes,"Junio");
        break;
    case 7:
        strcpy(nombreMes,"Julio");
        break;
    case 8:
        strcpy(nombreMes,"Agosto");
        break;
    case 9:
        strcpy(nombreMes,"Septiembre");
        break;
    case 10:
        strcpy(nombreMes,"Octubre");
        break;
    case 11:
        strcpy(nombreMes,"Noviembre");
        break;
    case 12:
        strcpy(nombreMes,"Diciembre");
        break;
    default:
        return(-1); /* Error, mes no válido */
    }
    return (0);
}


/*
 * Función obtenerDiaSemana()
 */
int obtenerDiaSemana (TipoFecha fecha)
{   
    int dia;
    
    dia = obtenerDiaSemanaPrimerodeMes(fecha) - 1;
    dia = (dia + (fecha.dia - 1)) % DIAS_SEMANA;
    return (dia + 1);
}

/*
 * Función obtenerDiaSemanaPrimerodeMes()
 */
int obtenerDiaSemanaPrimerodeMes(TipoFecha fecha)
{
    int i,dia;

    /* Halla en qué dia cae el 1 de enero del año dado */  
    dia = (obtenerDiaSemanaPrimerodeEnero(fecha.anyo) - 1);
   
    /* Incrementa el resto de dias modulo DIAS_SEMANA*/
    for (i = 1; i < fecha.mes; i++) {
        dia = (dia + obtenerDiasMes(i,fecha.anyo)) % DIAS_SEMANA;     
    }
    /* Devuelve dia de la semana donde comienza ese mes */
    return(dia + 1);
}

/*
 * Función obtenerDiaSemanaPrimerodeEnero()
 */
int obtenerDiaSemanaPrimerodeEnero(int anyo)
{  
    int diaSemana;
    int totalDias;

    diaSemana = 2; /* dia de la semana del 1/1/1800 */ 

    /* total de dias trancurridos desde el 1/1/1800 hasta 1/1/anyo */
    totalDias = (anyo - ANYO_BASE) * DIAS_ANYO + totalBisiestos(anyo); 
    
    diaSemana = (diaSemana + totalDias) % DIAS_SEMANA;

   return (diaSemana+1);
}

/*
 * Función totalBisiestos()
 */
int totalBisiestos(int anyo)
{
    int total = 0;
    int i,ret;

    /* halla el total de años bisiestos desde 1800 hasta el año pedido */

    for (i = ANYO_BASE; i < anyo; i++) {
        ret = bisiesto(i);
        if (1 == ret) {
            total = total + 1;
        } 
    }

   return(total);
}
