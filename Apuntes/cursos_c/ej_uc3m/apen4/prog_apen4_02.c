/*
 * Programa:    prog_apen4_02
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Apendice 9:
 *              Aplicación miPrintf, emula la función de biblioteca printf de C.
 */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

static char ppbuf[1024];

/* 
 * Funciones de utilidad diversas para convertir partes de formatos.
 * Se usan desde las funciones principales de la aplicacion.
 */

static int miAtoi(const char **s)
{
    int i=0;

    while (isdigit(**s))
        i = i*10 + *((*s)++) - '0';
    return (i);
}


#define PONCERO    1        /* rellena con cero */
#define SIGNO      2        /* largo con y sin signo */
#define PLUS       4        /* muestra mas */
#define ESPACIO    8        /* espacio si hay mas */
#define IZQUIERDA 16        /* justificado a la izquierda */
#define ESPECIAL  32        /* 0x */
#define LARGO     64        /* usar 'ABCDEF' en lugar de 'abcdef' */


#define dividir(n,base) ({ \
    int __res; \
    __res = ((unsigned long) n) % (unsigned) base; \
    n = ((unsigned long) n) / (unsigned) base; \
    __res; })


/*
 *  Funcion de utilidad para convertir formatos numericos.
 */ 

static char * numero(char * str, long num, int base, int tamanyo, 
    int precision,int type)
{
    char c,sign,tmp[66];
    const char *digitos="0123456789abcdefghijklmnopqrstuvwxyz";
    int i;

    if (type & LARGO)
        digitos = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (type & IZQUIERDA)
        type &= ~PONCERO;
    if (base < 2 || base > 36)
        return 0;

    c = (type & PONCERO) ? '0' : ' ';
    sign = 0;
    if (type & SIGNO) 
    {
        if (num < 0) 
        {
            sign = '-';
            num = -num;
            tamanyo--;
        } else if (type & PLUS) 
        {
            sign = '+';
            tamanyo--;
        } else if (type & ESPACIO) 
        {
            sign = ' ';
            tamanyo--;
        }
    }

    if (type & ESPECIAL) 
    {
        if (base == 16)
            tamanyo -= 2;
        else if (base == 8)
            tamanyo--;
    }

    i = 0;
    if (num == 0)
        tmp[i++]='0';
    else while (num != 0)
        tmp[i++] = digitos[dividir(num,base)];

    if (i > precision)
        precision = i;
    tamanyo -= precision;
    if (!(type&(PONCERO+IZQUIERDA)))
        while(tamanyo-->0)
            *str++ = ' ';

    if (sign)
        *str++ = sign;
    if (type & ESPECIAL) {

        if (base==8)
            *str++ = '0';
        else if (base==16) 
        {
            *str++ = '0';
            *str++ = digitos[33];
        }
    }

    if (!(type & IZQUIERDA))
        while (tamanyo-- > 0)
            *str++ = c;
    while (i < precision--)
        *str++ = '0';
    while (i-- > 0)
        *str++ = tmp[i];
    while (tamanyo-- > 0)
        *str++ = ' ';
    return (str);
}

/*
 *  Funcion procesaPrintf  con el cuerpo principal del tratamiento del 
 *  conversión de formato de los argumentos variables.
 *  Se apoya en la utilidad numero que es la que hace el
 *  trabajo de procesamiento de los numeros.
 */

int procesaPrintf (char *buf, const char *fmt, va_list args)
{
    int len;
    unsigned long num;
    int i, base;
    char * str;
    const char *s;
    int flags;        /* flags para numero() */
    int anchoCampo;  /* ancho del campo de salida */
    int precision;    /* min. # de digitos para enteros; 
                         max.  numero de caracteres para cadenas */
    int calificador;  /* 'h', 'l', o 'L' para campos enteros */


    for (str=buf ; *fmt ; ++fmt) 
    {
        if (*fmt != '%') {
            *str++ = *fmt;
            continue;
        }
        /* flags del proceso*/
        flags = 0;
        /* Etiqueta para goto. Solo para demostrar que se puede usar
     * en C. Nunca lo use. El mismo bucle se podría estrucuturar
     * mediante un bucle de repetición.
     * Sirve para saltar los flags.
     */
        repeat:
            ++fmt;        /* salta el primer '%' */
            switch (*fmt) {
                case '-': flags |= IZQUIERDA; goto repeat;
               case '+': flags |= PLUS; goto repeat;
                case ' ': flags |= ESPACIO; goto repeat;
                case '#': flags |= ESPECIAL; goto repeat;
                case '0': flags |= PONCERO; goto repeat;
                }
        /* obtener anchura del campo */
        anchoCampo = -1;
        if (isdigit(*fmt))
            anchoCampo = miAtoi(&fmt);
        else if (*fmt == '*') 
        {
            ++fmt;
            /* es el proximo argumento */
            anchoCampo = va_arg(args, int);
            if (anchoCampo < 0) 
            {
                anchoCampo = -anchoCampo;
                flags |= IZQUIERDA;
            }
        }

        /* obtener la precision */
        precision = -1;
        if (*fmt == '.') 
        {
            ++fmt;    
            if (isdigit(*fmt))
                precision = miAtoi(&fmt);
            else if (*fmt == '*') 
            {
                ++fmt;
                /* es el siguiente argumento */
                precision = va_arg(args, int);
            }
            if (precision < 0)
                precision = 0;
        }

        /* obtener el calificador de conversion*/
        calificador = -1;
        if (*fmt == 'h' || *fmt == 'l' || *fmt == 'L') 
        {
            calificador = *fmt;
            ++fmt;
        }

        /* base numerica por defecto*/
        base = 10;

        switch (*fmt) 
        {
        case 'c':
            if (!(flags & IZQUIERDA))
                while (--anchoCampo > 0)
                    *str++ = ' ';
            *str++ = (unsigned char) va_arg(args, int);
            while (--anchoCampo > 0)
                *str++ = ' ';
            continue;
        case 's':
            s = va_arg(args, char *);
            if (!s)
                s = "<NULL>";
            len = strlen(s);
            if (!(flags & IZQUIERDA))
                while (len < anchoCampo--)
                    *str++ = ' ';
            for (i = 0; i < len; ++i)
                *str++ = *s++;
            while (len < anchoCampo--)
                *str++ = ' ';
            continue;
        case 'p':
            if (anchoCampo == -1) 
            {
                anchoCampo = 2*sizeof(void *);
                flags |= PONCERO;
            }
            str = numero(str,
                (unsigned long) va_arg(args, void *), 16,
                anchoCampo, precision, flags);
            continue;
        case 'n':
            if (calificador == 'l') 
            {
                long * ip = va_arg(args, long *);
                *ip = (str - buf);
            } else {
                int * ip = va_arg(args, int *);
                *ip = (str - buf);
            }
            continue;
        /* formato de numero entero - activar el flag y terminar */
        case 'o':
            base = 8;
            break;
        case 'X':
            flags |= LARGO;
        case 'x':
            base = 16;
            break;
        case 'd':
        case 'i':
            flags |= SIGNO;
        case 'u':
            break;
        default:
            if (*fmt != '%')
                *str++ = '%';
            if (*fmt)
                *str++ = *fmt;
            else
                --fmt;
            continue;
        }

        if (calificador == 'l')
            num = va_arg(args, unsigned long);
        else if (calificador == 'h')
            if (flags & SIGNO)
                num = va_arg(args, short);
            else
                num = va_arg(args, unsigned short);
        else if (flags & SIGNO)
            num = va_arg(args, int);
        else
            num = va_arg(args, unsigned int);
        str = numero(str, num, base, anchoCampo, precision, flags);
    }
    *str = '\0';
    return str-buf;
}

/*      
 *  Funcion con el cuerpo principal de la rutina printf.
 *  Se apoya en la utilidad procesaPrintf  que es la que hace el
 *  trabajo real.
 */
void miPrintf(char *fmt, ...)
{  
    va_list args;
    char ch, *bptr;
    int i;

    /* extraccion de la lista de argumentos */
    va_start(args, fmt);
    /* procesamiento de la lista de argumentos */
    i = procesaPrintf (ppbuf, fmt, args);
    bptr = ppbuf;
    /* impresion de  argumentos */
    while((ch = *(bptr++)) != 0) 
    {
        if(ch == '\n')
            putchar('\r');
        putchar(ch);    
    }
    va_end(args);
    return;
}                     

/*
 *  Programa principal para demostrar como funciona la 
 *  utilidad printf programada.
 */
int  main(int argc, char ** argv)
{
    miPrintf("Esta es una prueba de argumentos variables con %s \n", 
        argv[0]);
    miPrintf("Se imprime un entero %4d, un hexadecimal %x y un octal %o\n", 
        12, 0xbd34, 16 );
    return (0);
}


