#include <stdbool.h>
#include <stdint.h>

#ifndef FUNCIONES_H
#define FUNCIONES_H

void hola();
void tipos();
void mensaje_secreto();
void casting();
void operadores();
void incrementadores();
void mascaras( uint32_t word1, uint32_t word2);
void izqAder( int* arr, int tamanio);
void rotar(int* arr, int posInicial, int posFina);
void swap(int* arr, int posInicial, int posFinal) ;
void darVuelta(int* arr, int tamanio);
void imprimirArray(int* arr, int tamanio);
void tirarDados(int time);
void imprimirVar();
int factorial(int n);

#endif
