#ifndef _MISTDEF_H
#define _MISTDEF_H

#include <stdio.h>	/* for fprintf, FILE */
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>	/* for malloc, calloc */
#include <string.h>	/* for strdup */
#include <errno.h>	/* for perror, errno */
#include <memory.h>     /* for memset */
#include <ctype.h>      /* for tolower */
#include <time.h>      	/* for strftime */
#include <limits.h>     /* for INT_MAX, INT_MIN */
#include <unistd.h>     /* for unlink */
#include <sys/types.h>  /* for mkdir */
#include <sys/stat.h>   /* for mkdir */

#define EXTERN extern

#define PRIVATE static
#define PUBLIC

typedef unsigned int boolean;
typedef int pseudobool;		/* -1 == error | 0 == FALSE | 1 == TRUE */

#define	FALSE	0

#define	TRUE	1

#define OK 0

#define ANY	(-1)

#define MAX_STR         256

#define SIZEBUF         1024000

#define MIN(a,b)	((a)<(b)? (a): (b))

#define MAX(a,b)	((a)>(b)? (a): (b))

#define MISTRLEN(str)	((str)? strlen(str) : 0)

#ifdef __MSDOS__
	#define CHRPATHLIM	'\\'+
	
	#define STRICASECMP(str1, str2)		(stricmp((str1), (str2)))
	
#else
	#define CHRPATHLIM	'/'
	
	#define STRICASECMP(str1, str2)		(strcasecmp((str1), (str2)))
	
#endif

#define FREENULL(ptr) { if (ptr) free(ptr); ptr = NULL;}


#define DOIF(cond, fun, args) \
{\
	if (cond args)	fun args; \
}

#define CHECKEXITSYS(cond, msg) \
{\
	if (!(cond)) \
	{\
		perror(msg);\
		exit(errno);\
	}\
}

#define CHECKEXITNOSYS(cond, msg, status) \
{\
	if (!(cond)) \
	{\
		fprintf(stderr, "%s\n", msg);\
		exit(status);\
	}\
}

#define CHECK(res, cast,funcion, args, chk, msg) \
{\
	res = (cast) funcion args;\
	CHECKEXITSYS(chk(res), msg);\
}

#define NONULL(arg) ((arg) != NULL)

#define NOTHING(arg) TRUE

#define POSITIVE(arg) ((arg) >0)

#define NOFERROR(arg) (NONULL(arg) && !ferror(arg))

#define EQOK(arg) ((arg) == OK)

#define MKDIROK(arg) (EQOK(arg) || (arg == EEXIST))



#define MALLOC(ptr, cast, arg) \
{\
	CHECK(ptr, cast, malloc, (arg), NONULL, "malloc");\
}

#define STRDUP(ptr, arg) \
{\
	CHECKEXITNOSYS(arg, "strdup: Null input string", 2);\
	CHECK(ptr, char *, strdup, (arg), NONULL, "strdup");\
}

#define CALLOC(ptr, cast, num, size) \
{\
	CHECK(ptr, cast, calloc, (num, size), NONULL, "calloc");\
}

#define REALLOC(ptr, cast, old, size) \
{\
	CHECK(ptr, cast, realloc, (old, size), NONULL, "realloc");\
}

#define FOPEN(ptr, name, mode) \
{\
	CHECK(ptr, FILE *, fopen, (name, mode), NONULL, name);\
}

#define FREOPEN(ptr, name, mode, stream) \
{\
	CHECK(ptr, FILE *, freopen, (name, mode, stream), NONULL, "freopen");\
}

#define FGETS(ptr, buf, size, stream) \
{\
	CHECK(ptr, char *, fgets, (buf, size, stream), NOTHING, "fgets");\
	CHECKEXITSYS(NOFERROR(stream), "fgets");\
}

#define FREAD(res, buf, size, nobjs, stream) \
{\
	CHECK(res, int, fread, (buf, size, nobjs, stream), POSITIVE, "fread");\
	CHECKEXITSYS(NOFERROR(stream), "fread");\
}

#define STRFTIME(buf, len, format) \
{\
	time_t t_now;\
	struct tm *tm_ptr;\
\
	t_now = time(NULL);\
	tm_ptr = localtime(&t_now);\
	CHECKEXITNOSYS(POSITIVE(strftime(buf, len, format, tm_ptr)), \
		"strftime <= 0 !", 1); \
}

#define MKDIR(path) \
{\
	int _aux;\
	CHECK(_aux, int, mkdir, ((path), 0777), MKDIROK, "mkdir");\
}


#endif			/* _MISTDEF_H */
