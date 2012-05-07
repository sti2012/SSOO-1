# 
# Makefile
# Autores:     Jesús Carretero Pérez, 
#              Félix García Carballeira, 
#              Javier Fernandez Mu'noz, 
#              Alejandro Calderón Mateos
# Fecha:       06-2001
# Descripción: Makefile para los ejemplo del Capítulo 14:
#


#--------------------------
# Configuración
#--------------------------

CC             = gcc
LIB_PATH       = -L/usr/lib
GTK_LIB_PATH = `/usr/bin/gtk-config --libs`
INCLUDE_PATH   = -I/usr/include
GTK_INCLUDE_PATH = `/usr/bin/gtk-config --cflags`
SOURCE_PATH    = .
CFLAGS         = -O2 -Wall -ansi
LIBLINK        = 
CAP_14_EXE     = prog14_01.exe prog14_02.exe prog14_03.exe prog14_04.exe

#--------------------------
# Reglas de compilación
#--------------------------

all: $(CAP_14_EXE)

%.exe: %.c
	@echo "     $< ..."
	@$(CC)  $(CFLAGS) $(INCLUDE_PATH) $(GTK_INCLUDE_PATH) \
	$(LIB_PATH) $(GTK_LIB_PATH) $< -o $@

clean:
	@echo "   rm *.o ..."
	@rm -fr *.o

cleane:
	@echo "   rm *.o ..."
	@echo "   rm *.exe ..."
	@rm -fr *.o
	@rm -fr *.exe


