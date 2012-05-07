/*
 * Programa: agenda
 * Modulo  : fecha
 * Fichero : fecha.h
 */
#ifndef _FECHA_H_
#define _FECHA_H_


/*
 * FICHEROS INCLUDES
 */
#include "util.h"


/*
 *  CONSTANTES
 */
#define ANYO_BASE 1800
#define DIAS_SEMANA 7
#define DIAS_ANYO 365


/*
 * TIPOS DE DATOS 
 */
enum DiasSemana { lunes, martes, miercoles, jueves, viernes, sabado, domingo};
enum MesesAnyo { enero, febrero, marzo, abril, mayo, junio, julio, agosto, septiembre, octubre, noviembre, diciembre };


struct Fecha
{
    int anyo; 
    int mes;  
    int dia;
};

typedef enum DiasSemana TipoDia;
typedef enum MesesAnyo TipoMes;
typedef struct Fecha TipoFecha;


/*
 * PROTOTIPOS DE FUNCIONES P�BLICAS
 */

/* 
 * Funci�n: obtenerFechaActual()
 * 
 * Par�metros de entrada:
 *      Ninguno
 *      
 * Par�metros de salida:
 *      Devuelve la fecha actual (TipoFecha)
 *
 * Descripci�n: 
 *      Devuelve la fecha actual
 */
TipoFecha obtenerFechaActual();

/* 
 * Funci�n: componerFecha()
 * 
 * Par�metros de entrada:
 *      int dia:       dia de la fecha
 *      int mes:       mes de la fecha
 *      int anyo:      a�o de la fecha
 *      
 * Par�metros de salida:
 *      TipoFecha * fecha: Fecha compuesta
 *      Devuelve 0 si ha ido bien, -1 en caso contrario
 *
 * Descripci�n: 
 *      Compone una nueva fecha a partir del dia, mes y a�o
 */
int componerFecha (int dia, int mes, int anyo, TipoFecha *fecha);

/* 
 * Funci�n: obtenerDia()
 * 
 * Par�metros de entrada:
 *      TipoFecha * fecha: Fecha compuesta
 *      
 * Par�metros de salida:
 *      Devuelve el dia correspondiente a la Fecha (int)
 *
 * Descripci�n: 
 *      Devuelve el dia correspondiente a la fecha 
 */
int obtenerDia (TipoFecha fecha);

/* 
 * Funci�n: obtenerMes()
 * 
 * Par�metros de entrada:
 *      TipoFecha * fecha: Fecha compuesta
 *      
 * Par�metros de salida:
 *      Devuelve el mes correspondiente a la Fecha (int)
 *
 * Descripci�n: 
 *      Devuelve el mes correspondiente a la fecha 
 */
int obtenerMes (TipoFecha fecha);

/* 
 * Funci�n: obtenerAnyo()
 * 
 * Par�metros de entrada:
 *      TipoFecha * fecha: Fecha compuesta
 *      
 * Par�metros de salida:
 *      Devuelve el a�o correspondiente a la Fecha (int)
 *
 * Descripci�n: 
 *      Devuelve el a�o correspondiente a la fecha 
 */
int obtenerAnyo (TipoFecha fecha);

/* 
 * Funci�n: decrementarMes()
 * 
 * Par�metros de entrada:
 *      TipoFecha * fecha: Fecha original
 *      int meses: numero de meses a decrementar
 *      
 * Par�metros de salida:
 *      TipoFecha * fecha: Fecha decrementada
 *
 * Descripci�n: 
 *      Devuelve la fecha con los meses decrementados
 */
void decrementarMes (TipoFecha *fecha, int meses);

/* 
 * Funci�n: incrementarMes()
 * 
 * Par�metros de entrada:
 *      TipoFecha * fecha: Fecha original
 *      int meses: numero de meses a incrementar
 *      
 * Par�metros de salida:
 *      TipoFecha * fecha: Fecha incrementada
 *
 * Descripci�n: 
 *      Devuelve la fecha con los meses incrementados
 */
void incrementarMes (TipoFecha *fecha, int meses);

/* 
 * Funci�n: decrementarAnyo()
 * 
 * Par�metros de entrada:
 *      TipoFecha * fecha: Fecha original
 *      int anyos: numero de a�os a decrementar
 *      
 * Par�metros de salida:
 *      TipoFecha * fecha: Fecha decrementada
 *
 * Descripci�n: 
 *      Devuelve la fecha con los a�os decrementados
 */
void decrementarAnyo (TipoFecha *fecha, int anyos);

/* 
 * Funci�n: incrementarAnyo()
 * 
 * Par�metros de entrada:
 *      TipoFecha * fecha: Fecha original
 *      int anyos: numero de a�os a incrementar
 *      
 * Par�metros de salida:
 *      TipoFecha * fecha: Fecha incrementada
 *
 * Descripci�n: 
 *      Devuelve la fecha con los a�os incrementados
 */
void incrementarAnyo (TipoFecha *fecha, int anyos);

/* 
 * Funci�n: obtenerDiasMes()
 * 
 * Par�metros de entrada:
 *      int mes: mes correspondiente
 *      int anyo: a�o correspondiente
 *      
 * Par�metros de salida:
 *      Devuelve el numero de dias de un mes en un a�o correspondiente (int)
 *
 * Descripci�n: 
 *      Calcula el numero de dias de un mes en un a�o correspondiente
 */
int obtenerDiasMes (int mes, int anyo);

/* 
 * Funci�n: obtenerNombreMes()
 * 
 * Par�metros de entrada:
 *      int mes: mes correspondiente
 *      
 * Par�metros de salida:
 *      char nombreMes[]: nombre del mes
 *      Devuelve 0 si ha ido bien, -1 en caso contrario
 *
 * Descripci�n: 
 *      Devuelve el nombre de un mes
 */
int obtenerNombreMes (int mes, char nombreMes[]);

/* 
 * Funci�n: obtenerDiaSemana()
 * 
 * Par�metros de entrada:
 *      TipoFecha * fecha: Fecha original
 *      
 * Par�metros de salida:
 *      Devuelve el numero de dia de la semana que corresponde (int)
 *          (1=lunes; 7=Domingo)
 *
 * Descripci�n: 
 *      Devuelve el numero de dia de la semana que corresponde con esa fecha
 */
int obtenerDiaSemana (TipoFecha fecha);

/* 
 * Funci�n: obtenerDiaSemanaPrimerodeMes()
 * 
 * Par�metros de entrada:
 *      TipoFecha * fecha: Fecha original
 *      
 * Par�metros de salida:
 *      Devuelve el numero de dia de la semana que corresponde (int)
 *          (1=lunes; 7=Domingo)
 *
 * Descripci�n: 
 *      Devuelve el numero de dia de la semana que corresponde con el 1� de mes
 *      de la fecha que se suministra
 */
int obtenerDiaSemanaPrimerodeMes(TipoFecha fecha);

/* 
 * Funci�n: obtenerDiaSemanaPrimerodeEnero()
 * 
 * Par�metros de entrada:
 *      int anyo: a�o correspondiente
 *      
 * Par�metros de salida:
 *      Devuelve el numero de dia de la semana que corresponde (int)
 *          (1=lunes; 7=Domingo)
 *
 * Descripci�n: 
 *      Devuelve el numero de dia de la semana que corresponde con el 1� de
 *      Enero del a�o suministrado
 */
int obtenerDiaSemanaPrimerodeEnero(int anyo);

/* 
 * Funci�n: bisiesto()
 * 
 * Par�metros de entrada:
 *      int anyo: a�o correspondiente
 *      
 * Par�metros de salida:
 *      Devuelve 1 si a�o bisiesto, 0 si no
 *
 * Descripci�n: 
 *      Calcula si un a�o es bisiesto
 */
int bisiestos(int anyo);

/* 
 * Funci�n: totalBisiestos()
 * 
 * Par�metros de entrada:
 *      int anyo: a�o correspondiente
 *      
 * Par�metros de salida:
 *      Devuelve el numero de a�os bisiestos
 *
 * Descripci�n: 
 *      Devuelve el numero de a�os bisiestos que hay entre ANYO_BASE (1800) 
 *      y el a�o suministrado
 */
int totalBisiestos(int anyo);




#endif /* _FECHA_H_ */
