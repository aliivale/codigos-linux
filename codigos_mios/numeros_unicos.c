#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
// programa que permita al usuario ingresar cuantos numeros
    // puede contener un cierto vector.
    // indicarle un rango de numeros. numero minimo - numero maximo
    // en el vector solo se van a almacenar numeros unicos

//firmas de las funciones
void solicitar_datos(int* max_array, int* minimo, int* maximo);
void cargar_vector(int array[], int max_array, int minimo, int maximon,int* numero);
bool validar_numero(int i,int numero,int array[]);
void mostrar(int array[],int max_array);

//desarrollamos funciones
void solicitar_datos(int* max_array, int* minimo, int* maximo){
    printf("ingrese maximo contenido: ");
    scanf("%d",max_array);
    printf("ingrese numero minimo: ");
    scanf("%d",minimo);
    printf("ingrese numero maximo: ");
    scanf("%d",maximo);
}

void cargar_vector(int array[], int max_array, int minimo, int maximo,int* numero){
    srand ((unsigned)time(NULL));
    //fila = rand() % 4 + 0;
    for(int i=0; i < max_array; i++){
        *numero = rand() % maximo + minimo;
        if (i==0){
            array[i]=*numero;
        }
        else{
            while(validar_numero(i,*numero,array)==false){
                *numero = rand() % maximo + minimo;
            }
            array[i]=*numero;
            
        }
    }
}

bool validar_numero(int i,int numero,int array[]){
    bool valido=false;
    int contador=0;
    // verifica que no se repita
    for(int j=0; j < i; j++){
        if (array[j] != numero){
            contador+=1;
        }
    }
    if(contador == i){
        valido=true;
    }

    return valido;
}
void mostrar(int array[], int max_array){
    for (int i=0; i < max_array; i++){
        printf("%d\n",array[i]);
    }
}

int main(){
    // 1. declaramos variables
    int max_array, minimo, maximo, numero;
    solicitar_datos(&max_array, &minimo, &maximo);

    int array[max_array];
    cargar_vector(array,max_array,minimo, maximo, &numero);
    mostrar(array,max_array);



    return 0;
}