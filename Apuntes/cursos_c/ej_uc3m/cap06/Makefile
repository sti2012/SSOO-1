# 
# Makefile
# Autores:     Jesús Carretero Pérez, 
#              Félix García Carballeira, 
#              Javier Fernandez Mu'noz, 
#              Alejandro Calderón Mateos
# Fecha:       06-2001
# Descripción: Makefile para los ejemplo del Capítulo 1:
#


#--------------------------
# Configuración
#--------------------------

CC             = gcc
LIB_PATH       = -L/usr/lib
INCLUDE_PATH   = -I/usr/include
SOURCE_PATH    = .
CFLAGS         = -O2 -Wall -ansi
LIBLINK        = 
CAP_06_EXE     = prog06_01.exe \
		prog06_02.exe \
		prog06_03.exe \
		prog06_04.exe \
		prog06_05.exe \
		prog06_06.exe \
		prog06_07.exe \
		prog06_08.exe \
		prog06_09.exe  \
		prog06_10.exe 


#--------------------------
# Reglas de compilación
#--------------------------

all: $(CAP_06_EXE)

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



