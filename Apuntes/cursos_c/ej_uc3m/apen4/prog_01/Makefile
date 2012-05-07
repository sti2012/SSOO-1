CC=gcc

.SUFFIXES: .o

.c.o:
	$(CC) -c $<

PROGS= entabula

all: $(PROGS)

entabula:entabula.o misfun.o
	$(CC) entabula.o misfun.o -o entabula

clean:
	rm -f *.o $(PROGS)
