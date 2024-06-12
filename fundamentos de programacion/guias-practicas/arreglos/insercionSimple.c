#include <stdio.h>
#include <stdbool.h>
#define MAX 10
typedef int tvec[MAX];

void insercion(tvec vector, int* max, int numero){
    int i,pos,aux;

    // agrego el numero
    vector[*max]=numero;
    *max=*max+1;
    for(i=0; i <*max;i++){
        pos=i;
        aux=vector[i];

        while((pos>0) && (vector[pos-1]> aux)){
            vector[pos]=vector[pos-1];
            pos--;
        }
        vector[pos]=aux;
    }
}

void mostrar(tvec vector, int max){
    for(int i=0; i < max; i++){
        printf("%d\n",vector[i]);
    }
}

int main(){
    tvec vector={1,2,3,4,6,7,8};
    int max=7;
    insercion(vector,&max,-4);
    mostrar(vector, max);


    return 0;
}