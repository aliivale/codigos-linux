#include <stdio.h>
#include <stdbool.h>
#define ml 5
#define mf 6
typedef int tvec[mf];

void ordenar(tvec vec){
    int aux,j,i=0;

    bool validar=true;
    while (validar && i < mf)
    {
        validar=false;
        //para contar iteraciones desde 1
        i++;
        for (j = 0; j < ml; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                validar=true;
                aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }  
    }
    printf("Iteracion se corta en %d porque no hubieron mas cambios.\n",i);
}

void mostrar(tvec vec){
    int i;
    for (i=0;i<mf;i++){
        printf("%d ",vec[i]);
    }
    printf("\n");
}

int main(){
    tvec vec={1,2,3,4,6,5};
    ordenar(vec);
    mostrar(vec);
    return 0;
}