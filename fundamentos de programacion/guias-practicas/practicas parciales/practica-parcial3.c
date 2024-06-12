#include <stdbool.h>
#include <stdio.h>

#define max 5
typedef int tmat[max][max];

void sumar(tmat mat1, tmat mat2, tmat resultado);
void mostrar(tmat resultado);

void sumar(tmat mat1, tmat mat2, tmat resultado){
    int f,c;
    for(f=0; f < max;f++){
        for(c=0; c < max;c++){
            resultado[f][c]=mat1[f][c]+mat2[f][c];
        }
    }

}
void mostrar(tmat resultado){
    int f,c;
    for(f=0; f < max;f++){
        for(c=0; c < max;c++){
            printf("%d ",resultado[f][c]);
        }
        printf("\n");
    }

}

int main(){
    tmat mat1={{56,23,45,78,90},{99,11,43,55,76},{8,14,21,56,22},{66,7,5,3,78},{17,42,3,2,8}};
    tmat mat2={{11,24,67,43,77},{8,55,43,78,54},{12,46,32,57,88},{69,23,4,5,1},{6,66,13,8,0}};
    tmat resultado;

    sumar(mat1,mat2,resultado);
    mostrar(resultado);

    return 0;
}