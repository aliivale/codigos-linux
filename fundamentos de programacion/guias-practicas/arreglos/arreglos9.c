#include <stdio.h>
#include <stdbool.h>
#define NO_ENCONTRADO -1
typedef int Tvector[50];

void insertar(Tvector vector, int numero, int* max_log);
int posicionar_numero(Tvector nuevo_vector,Tvector vector,int max_log,int numero);
void mostrar(Tvector vector, int tam);

void mostrar(Tvector vector, int tam){
    for(int i=0; i < tam; i++){
        printf("%d\n",vector[i]);
    }
}

void insertar(Tvector vector, int numero, int* max_log){
    //declaramos variables
    Tvector nuevo_vector;
    int i,posicion_nuevo_numero;

    //inicializamos variables
    posicion_nuevo_numero=posicionar_numero(nuevo_vector,vector,*max_log,numero);
    *max_log=*max_log+1;

    for(i=0; i < *max_log; i++){
        if(i == posicion_nuevo_numero){
            nuevo_vector[i]= numero;
            printf("nuevo_vector[i]: %d\n",nuevo_vector[i]);
        }
        else{
            nuevo_vector[i]=vector[i-1];
            printf("nuevo_vector[i]: %d\n",nuevo_vector[i]);
        }
    }

}
int posicionar_numero(Tvector nuevo_vector,Tvector vector,int max_log,int numero){
    //declaramos variables
    int posicion, primer_numero, ultimo_numero;

    //inicializamos variables
    primer_numero=vector[0];
    ultimo_numero=vector[max_log-1];

    if(numero < primer_numero){
        posicion=0;
    }
    else if(numero > ultimo_numero){
        posicion= max_log-1;
    }
    else{
        printf("NO CODIFICADO\n");
    }
    return posicion;
}


int main(){
    Tvector vector={3,4,5,6,7,10,11};
    //mlog --> 7
    int max_log=7;
    int numero=2;
    insertar(vector, numero, &max_log);
    mostrar(vector, max_log);

    return 0;
}