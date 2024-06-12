/*
Asumiendo que ya existe un puntero que apuntan a un bloque de memoria
previamente reservada con malloc de tamaño (n * int), redimensionar dicha
memoria a un tamaño de (2 * n *int).
*/
#include <stdio.h>
#include <stdlib.h>

// firmas de funciones

// funciones

int main(){
    int n=4;
    int* numeros=NULL;
    numeros=malloc(n*sizeof(int));
    if(numeros != NULL){
        printf("Memoria asignada exitosamente\n");
        printf("t: %i\n",sizeof(numeros));
        // reasignamos tamaño
        numeros=realloc(numeros,(2*n)*sizeof(int));
        printf("tamaño: %i\n",sizeof(numeros));
        free(numeros);
    }
    else{
        printf("Ocurrio un error en memoria\n");
    }
    return 0;
}