#include 'arregloDinamico.h'

//typedef struct str_array {
//  uint8_t size;
//  uint8_t capacity;
//  char** data;
//} str_array_t;

str_array_t* strArrayNew(uint8_t capacity){
    str_array_t* arreglo = (str_array_t*) malloc(sizeof(str_array_t));
    arreglo -> capacity = capacity;
    arreglo -> data = NULL;
    arreglo -> size = 0;
    return arreglo;
}

uint8_t strArrayGetSize(str_array_t* a){
    return a -> size
}

char* strArrayGet(str_array_t* a, uint8_t i){
    return a -> data[i]
}

char* strArrayRemove(str_array_t* a, uint8_t i) {

    if (i >= a->size) return NULL;

    char* res = a->data[i];

    uint8_t new_size = a->size - 1;
    uint8_t new_capacity = new_size;
    char** new_data = (char**) malloc(new_capacity * sizeof(char*));

    // Copiar los elementos antes del índice i
    for (uint8_t j = 0; j < i; j++) {
        new_data[j] = a->data[j];

    for (uint8_t j = i; j < new_size; j++) {
        new_data[j] = a->data[j + 1];

    free(a->data);

    // Actualizar la estructura
    a->data = new_data;
    a->size = new_size;
    a->capacity = new_capacity;

    return res;
}

void strArrayDelete(str_array_t* a){
    uint8_t size = a->size;
    for(int8_t i=0; i<size; i++)
       free(a->data[i]);
    free(a->size);
    free(a->capacity);
    free(a->data);
}
