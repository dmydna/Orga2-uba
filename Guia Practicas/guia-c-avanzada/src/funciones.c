// funciones.c
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "funciones.h"



void imprimirMonstruo(monstruo_t* lista_mostruos, int tam){
    for(int i=0; i < tam; i++ ){
        printf("{ %s, %d }\n", lista_mostruos->nombre, 
                               lista_mostruos->vida );

        lista_mostruos++;
    }
}

void imprimirMonstruo_alt(monstruo_t* lista_mostruos, int tam){
    for(int i=0; i < tam; i++ ){
        printf("{ %s, %d }\n", (*lista_mostruos).nombre, 
                               (*lista_mostruos).vida );

        lista_mostruos++;
    }
}

void imprimirMonstruo_alt2(monstruo_t* lista_mostruos, int tam){

    for(int i=0; i < tam; i++ ){
        printf("{ %s, %d }\n", lista_mostruos[i].nombre, 
                               lista_mostruos[i].vida );
    }
}


void imprimirMonstruo_alt2(monstruo_t* lista_mostruos, int tam){

    for(int i=0; i < tam; i++ ){
        printf("{ %s, %d }\n", lista_mostruos[i][0], 
                               lista_mostruos[i][1] );
    }
}


void strMayus(char* str){
    char* tmp = str;

    while(*tmp != NULL){
        *tmp += ('A'-'a'); 
         tmp++;
    }
    printf("%s\n", str);
}



persona_t* crearPersona(char* nombre, int edad){
    persona_t* nuevaPersona = (persona_t*) malloc( strlen(nombre) * sizeof(char) + sizeof(int) );

    char* nombreCpy = (char*) malloc(strlen(nombre) * sizeof(char));

    nuevaPersona->nombre = strcpy(nombreCpy, nombre);
    nuevaPersona->edad = edad;

    return nuevaPersona; 
}

void imprimirPersona(persona_t* persona){
    printf("{ nombre: %s, edad: %d } \n", persona[0], persona[1]);
}

void eliminarPersona(persona_t* persona){
    free(persona);
}