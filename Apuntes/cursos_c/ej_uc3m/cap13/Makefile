# 
# Makefile
# Autores:     Jesús Carretero Pérez, 
#              Félix García Carballeira, 
#              Javier Fernandez Mu'noz, 
#              Alejandro Calderón Mateos
# Fecha:       06-2001
# Descripción: Makefile para los ejemplo del Capítulo 13:
#


#--------------------------
# Configuración
#--------------------------

CC             = gcc
ASM            = as
LIB_PATH       = -L/usr/lib
INCLUDE_PATH   = -I/usr/include
SOURCE_PATH    = .
#CFLAGS         = -O2 -Wall -ansi
CFLAGS         = -Wall -DDEBUG -DSUMAVARIABLE 
LIBLINK        = 
CAP_13_EXE     = prog13_01.exe prog13_02.exe prog13_03.exe prog13_04.exe \
	prog13_05.exe prog13_06.exe prog13_07.exe prog13_08.exe  prog13_09.exe \
	prog13_10.exe prog13_11.exe prog13_12.exe prog13_13.exe


#--------------------------
# Reglas de compilación
#--------------------------

all: $(CAP_13_EXE)


%.o: %.s
	@echo "     $< ..."
	@$(ASM) $< -o $@

%.o: %.c
	@echo "     $< ..."
	@$(CC)  $(CFLAGS) $(INCLUDE_PATH) -c $< -o $@

%.exe: %.o
	@echo "     $@ ..." 
	@$(CC)  $(CFLAGS) $(LIB_PATH) -o $@  $<  $(LIBLINK)

clean:
	@echo "   rm *.o ..."
	@rm -fr *.o

cleane:
	@echo "   rm *.o ..."
	@echo "   rm *.exe ..."
	@rm -fr *.o
	@rm -fr *.exe


