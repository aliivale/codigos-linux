/*1) Escribir un programa el cual reserve memoria dinámica 
para almacenar un número entero (int), le solicite al usuario 
el ingreso de un número y se asigna dicho valor en la memoria reservada
, luego mostrar dicho valor por pantalla
Liberar la memoria reservada al finalizar el programa.*/

#include <stdio.h>
#include <stdlib.h>

// Firmas de funciones
void solicitar_numero(int* numero);


// Funciones
void solicitar_numero(int* numero){
    printf("Ingrese un numero: ");
    scanf("%i",numero);
}

int main(){
    int* numero=NULL;
    numero=malloc(sizeof(int));
    if(numero !=NULL){
        printf("Memoria reservada exitosamente.\n");
        solicitar_numero(numero);
        printf("numero: %d\n",*numero);

        // liberamos espacio de memoria
        free(numero);
    }
    else{
        printf("Ocurrio un error en la memoria.\n");
    }
    return 0;
}