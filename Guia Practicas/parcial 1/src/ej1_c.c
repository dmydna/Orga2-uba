#include <stdio.h>


// EJERCICIO 1

char* cesar(char* str, int n){
	char* res = str;
	int i=0;

	if(i>25) i=25;
	if(i<0) i=1;

	while(*str){
		if(str > 'Z'){
			res[i] = (char) ((int) 'A' + n - 1);
		}else{
			res[i] = (char) ((int) str[i] + n);
	   }
		str++;
		i++;
	}
	return res;
}


// EJERCICIO 2

int prefijo_de(char* str1, char* str2){
	int i = 0;
	while(*str1 && *str2){
		if(str1 != str2 )
			return i;
		i++; str1++;
	}
	return  i;
}


// EJERCICIO 3


cliente_t* client_rand(client_t* clientes, int longitud){
	int i = rand % longitud;
	client_t* res = &clientes[i]
	return res;
}
