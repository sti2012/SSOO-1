/*                                                                               * Programa:    entabula
 * Autores:     Jesús Carretero Pérez,
 *              Félix García Carballeira,
 *              Javier Fernández Muñoz,
 *              Alejandro Calderón Mateos
 * Fecha:       06-2001
 * Descripción: Ejemplo del Apendice 9:
 *              Sustituye cadenas de blancos por el número correspondiente
 *              de tabuladores y blancos y viceversa.
 */



#include "misfun.h"

/*
 * entabula.c: Sustituye cadenas de blancos por el n'umero correspondiente
 *             de tabuladores y blancos y viceversa.
 */

int             main (int argc, char *argv[])
{
    char    bufin[SIZEBUF];
    char    bufout[SIZEBUF];
    FILE           *filein = NULL;
    int             initial = 1;
    boolean         exiting = FALSE;
    boolean         desentab = FALSE;
    boolean         stdinend = TRUE;

    while (!exiting && initial < argc) {
        if (strcmp (argv[initial], "-n") == 0) {
            desentab = TRUE;
        } else {
            /* It's a file */
            stdinend = FALSE;
            if (strcmp (argv[initial], "-") == 0) {
                filein = stdin;
            } else {
                filein = fopen (argv[initial], "r");
                if (!filein) {
                    perror (argv[0]);
                }
            }
            if (filein) {
                treat (desentab ? desentabula : entabula, sizeof (bufin),
                       bufin, bufout, filein, stdout);
                if (filein != stdin) {
                    fclose (filein);
                }
            }
        }
        initial++;
    }
    if (stdinend) {
        treat (desentab ? desentabula : entabula, sizeof (bufin),
               bufin, bufout, stdin, stdout);
    }
    exit (0);
}
