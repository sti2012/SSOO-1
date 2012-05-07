#include "mistdef.h"

#define _SPACES_PER_TAB()	8

PUBLIC void     entabula (char *strin, char *strout)
{
    int             blancos = 0;

    /* int             posicion = 0; */
    int             i, c;
    int             indexin = 0;
    int             indexout = 0;
    boolean         pontab = TRUE;

    while ((c = strin[indexin++]) != '\0') {
        switch (c) {
            case '\n':
                /* posicion = 0; */
                blancos = 0;
                strout[indexout++] = c;
                pontab = TRUE;
                break;
            case ' ':
                /* if ((++blancos + posicion) % _SPACES_PER_TAB() == 0) */
                if (++blancos == _SPACES_PER_TAB () && pontab) {
                    strout[indexout++] = '\t';
                    /* posicion += blancos; */
                    blancos = 0;
                }
                break;
            default:
                for (i = 0; i < blancos; i++)
                    strout[indexout++] = ' ';
                /* posicion += blancos; */
                blancos = 0;
                strout[indexout++] = c;
                pontab = FALSE;
        }
    }
    strout[indexout++] = '\0';
}

PUBLIC void     desentabula (char *strin, char *strout)
{
    int             i, c;
    int             posicion = 0;
    int             indexin = 0;
    int             indexout = 0;


    while ((c = strin[indexin++]) != '\0') {
        switch (c) {
            case '\n':
                posicion = 0;
                strout[indexout++] = c;
                break;
            case '\t':
                for (i = 0;
                     i < _SPACES_PER_TAB () &&
                     (((posicion + i) % _SPACES_PER_TAB ()) || i == 0);
                     i++)
                    strout[indexout++] = ' ';
                posicion += i;
                break;
            default:
                strout[indexout++] = c;
                posicion++;
        }
    }
    strout[indexout++] = '\0';
}

PUBLIC void     treat (void (*fun) (char *, char *),
                       int sizein,
                       char bufin[],
                       char bufout[],
                       FILE * filein,
                       FILE * fileout)
{
    while (fgets (bufin, sizein, filein)) {
        (*fun) (bufin, bufout);
        (void) fputs (bufout, fileout);
    }
}

