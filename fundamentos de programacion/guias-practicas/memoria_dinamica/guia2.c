/*
2) Escribir un programa el cual reserve memoria dinámica para almacenar una
cierta cantidad de números enteros (n * int), este valor n debe ser ingresado por
el usuario. Luego solicitarle que ingresé n valores enteros ingresados de a uno y
almacenarlos en la memoria previamente reservada. Mostrar luego todos los
valores ingresados. Liberar la memoria reservada al finalizar el programa.
*/
#include <stdio.h>
#include <stdlib.h>

void solicitar_datos(int n,int* numeros);

void solicitar_datos(int n,int* numeros){
    for(int i=0; i < n; i++){
        printf("Ingrese un numero: ");
        scanf("%d",&numeros[i]);
    }
}
void mostrar(int n,int* numeros){
    printf("NUMEROS DE FORMA DINAMICA\n");
    for(int i=0; i < n; i++){
        printf("Numero: %d\n",numeros[i]);
    }
}

int main(){
    int n,*numeros;

    numeros=NULL;

    printf("Ingrese una cantidad n: ");
    scanf("%d",&n);

    numeros=malloc(n*sizeof(int));
    if(numeros !=NULL){
        solicitar_datos(n,numeros);
        mostrar(n,numeros);
        free(numeros);
    }
    else{
        printf("\n");
    }



    return 0;
}