// funciones.c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define TRES_BITS_MAS_ALTOS(x) (((x) >> 29) & 0x7)
#define TRES_BITS_MAS_BAJOS(x) ((x) & 0x7)



int variableC;

void hola(){
   printf("Hola Orga!\n"); // imprime en pantalla
   return;
}

void tipos(){

   // Enteros: char, short, int, long, long long

    char caracter_entero = 'A'; // Un byte, puede almacenar caracteres o enteros pequeños
    short entero_corto = 100; // Entero corto
    int entero = 1000; // Entero estándar
    long entero_largo = 100000L; // Entero largo (la 'L' indica que es un literal long)
    long long entero_muy_largo = 10000000000LL;

   // Reales: float, double, long double

    float real_simple = 3.14f; // Precisión simple (la 'f' indica que es un literal float)
    double real_doble = 3.141592653589793; // Precisión doble
    long double real_largo_doble = 3.14159265358979323846L; // Precisión extendida (la 'L' indica que es un literal long double)

    // Caracteres
    char caracter = 'Z'; // Un solo carácter

    // Punteros
    int numero = 5;
    int *puntero_entero = &numero; // Puntero a un entero
    char cadena[] = "Hola";
    char *puntero_caracter = cadena; // Puntero a un carácter (o cadena)
    void *puntero_generico = &numero; // Puntero genérico (puede apuntar a cualquier tipo)

    // Void
    void funcion_void(void); // Declaración de una función que no devuelve nada y no recibe argumentos

    // Booleanos
    bool booleano_verdadero = true; // Verdadero
    bool booleano_falso = false; // Falso

    printf("Enteros:\n");
    printf("  char(%lubyte): %c (o %d)\n", sizeof(caracter_entero),caracter_entero, caracter_entero);
    printf("  short(%lubyte): %hd\n", sizeof(entero_corto) ,entero_corto);
    printf("  int(%lubyte): %d\n", sizeof(entero),entero);
    printf("  long(%lubyte): %ld\n", sizeof(entero_largo),entero_largo);
    printf("  long long(%lu): %lld\n", sizeof(entero_muy_largo),entero_muy_largo);

    printf("\nReales:\n");
    printf("  float(%lubyte): %f\n", sizeof(real_simple), real_simple);
    printf("  double(%lubyte): %lf\n", sizeof(real_doble), real_doble);
    printf("  long double(%lubyte): %Lf\n", sizeof(real_largo_doble), real_largo_doble);

    printf("\nCaracter(%lubyte):\n");
    printf("  char(%lubyte): %c\n", sizeof(caracter), caracter);

    printf("\nPunteros:\n");
    printf("  int*(%lubyte): %p (apunta a %d)\n", sizeof(puntero_entero), puntero_entero, *puntero_entero);
    printf("  char*(%lubyte): %p (apunta a \"%s\")\n", sizeof(puntero_caracter), puntero_caracter, puntero_caracter);
    printf("  void*(%lubyte): %p\n", sizeof(puntero_generico), puntero_generico);

    printf("\nBooleanos:\n");
    printf("  bool verdadero(%lubyte): %s\n", sizeof(booleano_verdadero), booleano_verdadero ? "true" : "false");
    printf("  bool falso(%lubyte): %s\n", sizeof(booleano_falso), booleano_falso ? "true" : "false");

    printf("\n");
}

void mensaje_secreto () {

    int mensaje_secreto[] = {116, 104, 101, 32, 103, 105, 102, 116, 32, 111, 102, 32, 119, 111, 114, 100, 115, 32, 105, 115, 32, 116, 104, 101, 32, 103, 105, 102, 116, 32, 111, 102, 32, 100, 101, 99, 101, 112, 116, 105, 111, 110, 32, 97, 110, 100, 32, 105, 108, 108, 117, 115, 105, 111, 110};

   size_t length = sizeof(mensaje_secreto) / sizeof(int);
   char decoded[length];

   for (int i = 0; i < length; i++) {
      decoded[i] = (char) (mensaje_secreto[i]); // casting de int a char
   }
   for (int i = 0; i < length; i++) {
      printf("%c", decoded[i]);
   }

   printf("\n \n");
}

void casting(){

   float  float_n = 0.1;
   double double_n =  3.141592653589793;

   printf("float: %f \n", 0.1 );
   printf("double: %lf \n", 0.1 );

   // float a int  
   int entero_float = (int) float_n;
   // double a int
   int entero_doble = (double) double_n;
   
   printf("float: %f a int: %d \n", float_n, entero_float);
   printf("double: %lf a int: %d \n", double_n, entero_doble);

   printf("\n");
}


void operadores(){

    int a = 5, b = 3, c = 2, d = 1;

    printf("Operadores :: x -> hex(x) \n");
    printf("a=%d, b=%d, c=%d, d=%d \n \n", a,b,c,d);
    printf("a + b * c / d  ->  %x\n", a + b * c / d);
    printf("a %% b -> %x\n", a % b);
    printf("a == b -> %x\na != b -> %x\n", a == b, a != b);
    printf("a & b -> %x\na | b -> %x\n", a & b, a | b);
    printf("~a: %x\n", ~a);
    printf("a && b -> %x\na || b -> %x\n", a && b, a || b);
    printf("a << 1 -> %x\n", a << 1);
    printf("a >> 1 -> %x\n", a >> 1);

    printf("a += b -> %x\n", a += b);
    printf("a -= b -> %x\n", a -= b);
    printf("a *= b -> %x\n", a *= b);
    printf("a /= b -> %x\n", a /= b);
    printf("a %%= b -> %x\n", a %= b);

    printf("\n");
}

void incrementadores(){
    
    int i=0, j=0;   
    
    printf("i++ devuelve i y incrementa: \n"); 
    while(i<5){
       printf("si i = %d -> ", i);
       printf("(i++) = %d\n",i++);
    }

    printf("\n");

    printf("++i incrementa y devuelve i: \n");
    while(j<5){
       printf("si i = %d -> ", j);
       printf("(++i) = %d\n",++j);
    }
    printf("\n");

}

void mascaras(uint32_t a, uint32_t b) {

    if (TRES_BITS_MAS_ALTOS(a) == TRES_BITS_MAS_BAJOS(b)) {
        printf("Son iguales!");
    } else {
        printf("No son iguales!");
    }
    printf("\n \n");
}


void imprimirArray(int* arr, int tamanio){
   int i=0;
   printf("{ ");
   while (i<tamanio){
      if(i==tamanio-1){
         printf("%d", arr[i]);
      }else{
         printf("%d, ", arr[i] );
      }
      i++;
   }
   printf(" }");
}


void swap(int* arr, int posInicial, int posFinal) {

    int valorInicial = arr[posInicial];
    int valorFinal = arr[posFinal];

    arr[posInicial] = valorFinal;
    arr[posFinal] = valorInicial;

}


void darVuelta(int* arr, int tamanio){

    int i = 0;
    int mitad = tamanio / 2;

    while (i < mitad) {
        swap(arr, i, tamanio - 1 - i);
        i++;
    }
}


void izqAder(int* arr, int tamanio){

   printf("izqAder :: ");
   imprimirArray(arr, tamanio);
   printf(" -> ");
   darVuelta(arr, tamanio);
   imprimirArray(arr, tamanio);
   printf("\n");
}


void rotar(int* arr, int pos,int tamanio){

   printf("rotar %d :: ", pos);
   imprimirArray(arr, tamanio);  
   printf(" -> ");
   darVuelta(arr, tamanio);
   swap(arr , pos, tamanio-1); 
   imprimirArray(arr, tamanio);
   printf("\n \n");

}


void tirarDados(int time){

   int count[5];
   int dado;
    
   for(int i=0; i< time; i++ ){
      dado = (rand() % 6)+1;
      count[dado-1] ++;
   };

  printf("dado 1 salio %ld \n", count[0]);
  printf("dado 2 salio %ld \n", count[1]);
  printf("dado 3 salio %ld \n", count[2]);
  printf("dado 4 salio %ld \n", count[3]);
  printf("dado 5 salio %ld \n", count[4]);
  printf("dado 6 salio %ld \n", count[5]);
  printf("\n"); 

}

void imprimirVar(){
   int variableC = 2;
   printf("imprime Desde Local: %d \n\n",variableC);
}

int factorial(int n){
   if(n==0){
      return 1;
   }
   return n * factorial(n-1);
}