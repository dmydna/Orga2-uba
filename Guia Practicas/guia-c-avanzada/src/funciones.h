#include <stdbool.h>
#include <stdint.h>


#ifndef FUNCIONES_H
#define FUNCIONES_H



typedef struct{
    char* nombre;
    int vida;
    double ataque;
    double defensa;
} monstruo_t;

typedef struct{
    char* nombre;
    int edad;
} persona_t;



void imprimirMonstruo(monstruo_t* lista_mostruos, int tam);
void strMayus(char* str);
persona_t* crearPersona(char* nombre, int edad);
void imprimirPersona(persona_t* persona);
void eliminarPersona(persona_t* persona)


#endif
