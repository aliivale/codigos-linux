#include <stdio.h>


int dividir_iterativo(int numero, int divisor);
int dividir_recursivo(int numero, int divisor, int* contador);

int dividir_recursivo(int numero, int divisor, int* contador){
    if(divisor !=0){
        if(numero <= 0){
            return *contador;
        }
        else{
            *contador=*contador+1;
            
            return dividir_recursivo((numero-divisor),divisor,contador);
        }
    }
    return *contador;
}

int dividir_iterativo(int numero, int divisor)
{   int contador=0;
    if(divisor !=0){
        numero=numero - divisor;
        while((numero) >= 0){
            contador++;
            numero=numero-divisor;
        }
    }
    return contador;
}

int main(){
    int contador;
    contador=0;
    int numero= dividir_iterativo(8,2);
    printf("%d\n",numero);

    int recursivo= dividir_recursivo(8,2,&contador);
    printf("%d\n",recursivo);

    return 0;
}