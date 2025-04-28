#include <stdio.h>
#include "funciones.h"
#include <stdint.h>
#include <stdlib.h>

char str[] = "hola";

monstruo_t array_de_monstruos[] = {
    {"Milo", 100, 5000, 7000},
    {"Melo", 80, 1000, 9000 },
    {"Rem", 65, 8000, 2500},
    {"Ram",30, 3000, 2000}
};

persona_t* nuevaPersona; 



int main() {

   
    imprimirMonstruo(array_de_monstruos, 4);  
    strMayus(str);
    nuevaPersona = crearPersona("Meelo",35);
    imprimirPersona(nuevaPersona);
    eliminarPersona(nuevaPersona);

    

    return 0;  
}
