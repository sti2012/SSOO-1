#include "mistdef.h"

#ifndef _MISFUN_H
#define _MISFUN_H

PUBLIC void     entabula (char *strin, char *strout);

PUBLIC void     desentabula (char *strin, char *strout);
PUBLIC void     treat (void (*fun) (char *, char *),
                       int sizein,
                       char bufin[],
                       char bufout[],
                       FILE * filein,
                       FILE * fileout);

#endif
