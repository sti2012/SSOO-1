#include "listausuarios.h"
void entrar(ListaUsuarios *listausuarios,ListaDatos **listadatos,ListaCitas **listacitas,ListaNotas **listanotas);
/* ***************************************************** 
 *
 *  Función: entrar
 *
 * ***************************************************** 
 *  Autor: Alberto Miedes Fernández
 *
 *  Organización: Universidad Carlos III de Madrid
 *  Fecha: 22-04-2001
 *
 *  Actualización:
 *   
 *  Descripcion:
 *  Con esta función se permite a un usuario acceder a sus datos 
 *  dentro de la agenda. En primer lugar se pide al usuario que se 
 *  autentique dando su login y password. Se verifica que esté dado de alta
 *  como usuario. Si es así se presenta un menú con todas las operaciones 
 *  que puede acceder dentro de la agenda: listín telefónico, notas diarias, 
 *  calendario, libro de direcciones y citas y reuniones. Y en caso de que 
 *  los datos dados de la persona no constaran como los correspondientes a
 *  un usuario ya dado de alta se mostraria un mensaje indicando el tipo de 
 *  error y se volvería al menú incial.
 *
 *  Parámetros de entrada:
 *  listausuarios
 *
 *  Parámetros de entrada/salida:
 *  listadatos
 *  listacitas
 *  listanotas
 *
 *  Salida:
 *  No tiene
 *
 *  Llamadas a funciones de otros módulos:
 *  FALTAAAAAAAAAAAAA
 *
 *  Llamadas a funciones privadas:
 *  No hay
 *
 ****************************************************** */

void crear(ListaUsuarios **listausuarios);
/* ***************************************************** 
 *
 *  Función: crear
 *
 * ***************************************************** 
 *  Autor: Alberto Miedes Fernández
 *
 *  Organización: Universidad Carlos III de Madrid
 *  Fecha: 22-04-2001
 *
 *  Actualización:
 *   
 *  Descripcion:
 *  Función diseñada para permitir la inserción de nuevos usuarios en la
 *  agenda. Se pide al usuario que introduzca sus datos (login, passsword y 
 *  dirección de correo), se comprueba que no exista ya otro usuario con 
 *  esos mismos datos (asi conseguimos mantener la privacidad) y si es asi se 
 *  le inserta. En caso contrario se muestra un mensaje indicando que ya 
 *  existe un usuario con ese login y se volvería la menú principal.
 *
 *  Parámetros de entrada:
 *  No tiene
 *
 *  Parámetros de entrada/salida:
 *  listausuarios
 *
 *  Salida:
 *  No tiene
 *
 *  Llamadas a funciones de otros módulos:
 *  FALTAAAAAAAAAAAAA
 *
 *  Llamadas a funciones privadas:
 *  No hay
 *
 ****************************************************** */

void borrar(ListaUsuarios **listausuarios,ListaDatos **listadatos,ListaCitas **listacitas,ListaNotas **listanotas);
/* ***************************************************** 
 *
 *  Función: borrar
 *
 * ***************************************************** 
 *  Autor: Alberto Miedes Fernández
 *
 *  Organización: Universidad Carlos III de Madrid
 *  Fecha: 22-04-2001
 *
 *  Actualización:
 *   
 *  Descripcion:
 *  Con esta función se consigue borrar a un usuario, junto con todos sus 
 *  datos, de la agenda. Para ello se pide que se autentique introduciendo su 
 *  login y password, se comprueba que efectivamente exista y sean esos los  
 *  datos correctos y a continuación se borran todos sus datos: teléfonicos,  
 *  notas y citas, y por último se borra de la base de datos de usuarios. 
 *
 *  Parámetros de entrada:
 *  No tiene
 *
 *  Parámetros de entrada/salida:
 *  listausuarios
 *  listacitas
 *  listanotas
 *  listadatos
 *
 *  Salida:
 *  No tiene
 *
 *  Llamadas a funciones de otros módulos:
 *  FALTAAAAAAAAAAAAA
 *
 *  Llamadas a funciones privadas:
 *  No hay
 *
 ****************************************************** */
