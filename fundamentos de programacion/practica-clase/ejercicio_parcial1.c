#include <stdio.h>
#include <stdbool.h>

#define cantfilas 4
#define cantcols 3

typedef int Tmatriz[cantfilas][cantcols];

void informar_numeroMin_cantidad(Tmatriz matriz, int ml_fil, int ml_col, int* minimo, int* cont_minimo);

void informar_numeroMin_cantidad(Tmatriz matriz, int ml_fil, int ml_col, int* minimo, int* cont_minimo){
    int f,c;
    *cont_minimo=0;
    //buscamos el minimo
    *minimo=matriz[0][0];
    for(f=0; f <= ml_fil; f++){
        for(c=0; c <= ml_col; c++){
            if(*minimo > matriz[f][c]){
                *cont_minimo=1;
                *minimo=matriz[f][c];
            }
            else if (*minimo == matriz[f][c]){
                *cont_minimo=*cont_minimo+1;
            }
        }
    }

}  

int main(){
    //declaramos variables
    int minimo;
    int cont_minimo;

    //inicializamos variables
    Tmatriz matriz={{20,4,85},{46,65,6},{4,25,6},{46,4,67}};

    informar_numeroMin_cantidad(matriz,(cantfilas-1),(cantcols-1),&minimo,&cont_minimo);
    printf("minimo: %d\n",minimo);
    printf("contador minimo: %d\n",cont_minimo);

}