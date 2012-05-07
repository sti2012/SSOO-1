#include "listausuarios.h"
void entrar(ListaUsuarios *listausuarios,ListaDatos **listadatos,ListaCitas **listacitas,ListaNotas **listanotas);
/* ***************************************************** 
 *
 *  Funci�n: entrar
 *
 * ***************************************************** 
 *  Autor: Alberto Miedes Fern�ndez
 *
 *  Organizaci�n: Universidad Carlos III de Madrid
 *  Fecha: 22-04-2001
 *
 *  Actualizaci�n:
 *   
 *  Descripcion:
 *  Con esta funci�n se permite a un usuario acceder a sus datos 
 *  dentro de la agenda. En primer lugar se pide al usuario que se 
 *  autentique dando su login y password. Se verifica que est� dado de alta
 *  como usuario. Si es as� se presenta un men� con todas las operaciones 
 *  que puede acceder dentro de la agenda: list�n telef�nico, notas diarias, 
 *  calendario, libro de direcciones y citas y reuniones. Y en caso de que 
 *  los datos dados de la persona no constaran como los correspondientes a
 *  un usuario ya dado de alta se mostraria un mensaje indicando el tipo de 
 *  error y se volver�a al men� incial.
 *
 *  Par�metros de entrada:
 *  listausuarios
 *
 *  Par�metros de entrada/salida:
 *  listadatos
 *  listacitas
 *  listanotas
 *
 *  Salida:
 *  No tiene
 *
 *  Llamadas a funciones de otros m�dulos:
 *  FALTAAAAAAAAAAAAA
 *
 *  Llamadas a funciones privadas:
 *  No hay
 *
 ****************************************************** */

void crear(ListaUsuarios **listausuarios);
/* ***************************************************** 
 *
 *  Funci�n: crear
 *
 * ***************************************************** 
 *  Autor: Alberto Miedes Fern�ndez
 *
 *  Organizaci�n: Universidad Carlos III de Madrid
 *  Fecha: 22-04-2001
 *
 *  Actualizaci�n:
 *   
 *  Descripcion:
 *  Funci�n dise�ada para permitir la inserci�n de nuevos usuarios en la
 *  agenda. Se pide al usuario que introduzca sus datos (login, passsword y 
 *  direcci�n de correo), se comprueba que no exista ya otro usuario con 
 *  esos mismos datos (asi conseguimos mantener la privacidad) y si es asi se 
 *  le inserta. En caso contrario se muestra un mensaje indicando que ya 
 *  existe un usuario con ese login y se volver�a la men� principal.
 *
 *  Par�metros de entrada:
 *  No tiene
 *
 *  Par�metros de entrada/salida:
 *  listausuarios
 *
 *  Salida:
 *  No tiene
 *
 *  Llamadas a funciones de otros m�dulos:
 *  FALTAAAAAAAAAAAAA
 *
 *  Llamadas a funciones privadas:
 *  No hay
 *
 ****************************************************** */

void borrar(ListaUsuarios **listausuarios,ListaDatos **listadatos,ListaCitas **listacitas,ListaNotas **listanotas);
/* ***************************************************** 
 *
 *  Funci�n: borrar
 *
 * ***************************************************** 
 *  Autor: Alberto Miedes Fern�ndez
 *
 *  Organizaci�n: Universidad Carlos III de Madrid
 *  Fecha: 22-04-2001
 *
 *  Actualizaci�n:
 *   
 *  Descripcion:
 *  Con esta funci�n se consigue borrar a un usuario, junto con todos sus 
 *  datos, de la agenda. Para ello se pide que se autentique introduciendo su 
 *  login y password, se comprueba que efectivamente exista y sean esos los  
 *  datos correctos y a continuaci�n se borran todos sus datos: tel�fonicos,  
 *  notas y citas, y por �ltimo se borra de la base de datos de usuarios. 
 *
 *  Par�metros de entrada:
 *  No tiene
 *
 *  Par�metros de entrada/salida:
 *  listausuarios
 *  listacitas
 *  listanotas
 *  listadatos
 *
 *  Salida:
 *  No tiene
 *
 *  Llamadas a funciones de otros m�dulos:
 *  FALTAAAAAAAAAAAAA
 *
 *  Llamadas a funciones privadas:
 *  No hay
 *
 ****************************************************** */
