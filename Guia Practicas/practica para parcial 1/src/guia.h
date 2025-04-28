

#ifndef EJS_H
#define EJS_H
/*
Sobre Ifndef
======
ifndef es una construcción de pre compilación que sólo incorpora el texto entre "#ifndef SYMBOL ... #endif sólo si el símbolo SYMBOL aún no fue definido
se suele utilizar esta combinación de 
#ifndef SYMBOL 
#define SYMBOL
para que el pre-procesador sólo evalúe una vez los encabezados antes de comenzar la compilación

Sobre includes
==============
Recuerden que los include son directivas que incluyen,
en este caso, las definiciones y encabezados de las funciones de uso común que queremos 
utilizar en nuestro programa
*/

#pragma once

#include <stdio.h> 		//encabezado de funciones de entrada y salida fopen, fclose, fgetc, printf, fprintf ...
#include <stdlib.h>		//biblioteca estándar, atoi, atof, rand, srand, abort, exit, system, NULL, malloc, calloc, realloc...
#include <stdint.h>		//contiene la definición de tipos enteros ligados a tamaños int8_t, int16_t, uint8_t,...
#include <ctype.h>		//contiene funciones relacionadas a caracteres, isdigit, islower, tolower...
#include <string.h>		//contiene las funciones relacionadas a strings, memcmp, strcat, memset, memmove, strlen,strstr...
#include <math.h>		//define funciones matemáticas como cos, sin, abs, sqrt, log...
#include <stdbool.h>	//contiene las definiciones de datos booleanos, true (1), false (0)
#include <unistd.h>		//define constantes y tipos standard, NULL, R_OK, F_OK, STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO...
#include <assert.h>		//provee la macro assert que evalúa una condición, y si no se cumple provee información diagnóstica y aborta la ejecución


//*************************************
//Declaración de estructuras
//*************************************

#define NAME_LEN 21

typedef struct cliente_str {
	char nombre [NAME_LEN];
	char apellido[NAME_LEN];
	uint64_t compra;
	uint32_t dni;
} cliente_t;

typedef struct __attribute__((__packed__)) packed_cliente_str {
	char nombre [NAME_LEN];
	char apellido[NAME_LEN];
	uint64_t compra;
	uint32_t dni;
} __atribute__((packed)) packed_cliente_t;


char* cesar(char* str);
int prefijo_de(char* str1, char* str2);
client_t* ej3(client_t* clientes, int longitud);


#endif
