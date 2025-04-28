// Ejercicio 1:


int ord(char c){
    int res;
    if((int)c < 95){
       // mayusculas
       res = (int)c % 65; 
    }else{
       // minusculas -> mayus
       int res = (int)c % 95;
    }

    return res;
}

char chr(int n){
    // Restrinjo n al rango de letras mayúsculas (0 <= n < 26)
    int mayus = (n % 26)+65; 
    char res = (char) mayus;
    return res;
};

char* cesar(char* c, int n){
    
    char* res = malloc(strlen(c) + 1); // +1 para el carácter nulo
    char* inicio = res; // Guardamos el puntero al inicio para devolverlo al final

    char* res = "";
    while(*c){
         *res = chr( ord(*c) + n);
         res++;
         c++;
    }
    res = '/0';
    return inicio;
}



