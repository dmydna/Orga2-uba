CC=cc
CFLAGS= -std=c11 -Wall -Wextra -pedantic -O0 -g -lm -Wno-unused-variable -Wno-unused-parameter -no-pie -z noexecstack
NASM=nasm
NASMFLAGS=-f elf64 -g -F DWARF

all: main tester

OBJS :=  ej1_asm.o ej2_asm.o ej3_asm.o

main: main.c $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

ej1_c.o: main.c ejs.h
	$(CC) $(CFLAGS) -c $< -o $@

ej2_c.o: main.c ejs.h
	$(CC) $(CFLAGS) -c $< -o $@

ej3_c.o: main.c ejs.h
	$(CC) $(CFLAGS) -c $< -o $@

ej1_asm.o: ej1.asm
	$(NASM) $(NASMFLAGS) $< -o $@

ej2_asm.o: ej2.asm
	$(NASM) $(NASMFLAGS) $< -o $@

ej3_asm.o: ej3.asm
	$(NASM) $(NASMFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f main tester
	rm -f salida.propios.*

