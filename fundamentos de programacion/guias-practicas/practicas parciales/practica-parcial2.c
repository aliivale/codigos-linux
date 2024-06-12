#include <stdio.h>
#define cantfilas 2
#define cantcols 3

typedef int Tmatriz[cantfilas][cantcols];

void analizar(Tmatriz matriz,int filas,int cols,int* maximo, int* minimo,int* cont_max, int* contador);

void analizar(Tmatriz matriz,int filas,int cols,int* maximo, int* minimo,int* cont_max, int* contador){
    int f,c;
    *minimo=matriz[0][0];
    *maximo=matriz[0][0];
    for(f=0; f < filas; f++){
        for(c=0; c < cols; c++){
            if(*minimo > matriz[f][c]){
                *contador=0;
                *minimo=matriz[f][c];
                *contador=*contador+1;
            }
            else if(*minimo == matriz[f][c]){
                *contador=*contador+1;
            }
            else if(*maximo < matriz[f][c]){
                *cont_max=0;
                *maximo=matriz[f][c];
                *cont_max=*cont_max+1;
            }
            else if(*maximo == matriz[f][c]){
                *cont_max=*cont_max+1;
            }
        }
    }

    printf("maximo: %d repetido: %d\nminimo: %d repetido: %d\n",*maximo,*cont_max,*minimo,*contador);
}


int main(){
    int contador,cont_max,minimo,maximo;
    Tmatriz matriz={{1,1,8},{2,8,1}};
    analizar(matriz,cantfilas,cantcols,&maximo,&minimo,&cont_max,&contador);
    return 0;
}