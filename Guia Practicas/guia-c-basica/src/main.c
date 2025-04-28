#include <stdio.h>
#include "funciones.h"
#include <stdint.h>

int main() {

    int array[] = {1, 2, 3, 4, 5}; 

    hola();            // Ejercicio 1
    tipos();           // Ejercicio 3
    casting();         // Ejercicio 5
    mensaje_secreto(); // Ejercicio 6
    operadores();      // Ejercicio 7
    incrementadores(); // Ejercicio 8
    mascaras( (uint32_t) 0x00000007,  (uint32_t) 0xFF000000 );        // Ejercicio 9
    izqAder( array, 5);  // Ejercicio 11
    rotar(array, 2, 5);  // Ejercicio 12:
    tirarDados(60000000);  // Ejercicio 13
    imprimirVar();        // Ejercicio 14
    printf("factorial 5: %d\n", factorial(5));         // Ejercicio 15
    // Ejercicio 16
    

    return 0;  
}
