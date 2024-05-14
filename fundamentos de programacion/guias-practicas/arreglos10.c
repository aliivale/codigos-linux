#include <stdio.h>
typedef int Tmatriz[3][2];
typedef int Tvector[10];

void imprimir_matriz(Tmatriz m1, int f1, int c1, Tmatriz m2, int f2, int c2,Tmatriz resultados);
int multiplicar(Tvector fila, int c1,int c2, Tmatriz m2);

void imprimir_matriz(Tmatriz m1, int f1, int c1, Tmatriz m2, int f2, int c2,Tmatriz resultados)
{
    // //columnas
    // for(int c=0; c < c1; c++ ){
    //     for(int f=0; f < f1; f++){
    //         printf("%d ",m1[f][c]);
    //     }
    //     printf("\n");
    // }

    // filas

    // c1 = f2
    for (int f = 0; f < f1; f++)
    {
        for(int c=0; c < c2; c++){
            resultados[f][c]=multiplicar(m1[f],c1,c2,m2);
            printf("RESULTADO: %d\n", resultados[f][c]);
        }
    }
}

int multiplicar(Tvector fila, int c1,int c2, Tmatriz m2){
    int resultado=0;
    for(int i=0; i < c2;i++){
        //recorremos fila x columna
        for(int j=0; j < c1; j++){
            resultado=resultado+fila[j]*m2[i][j];
        }
    }
    return resultado;
}


int main()
{
    Tmatriz matriz1 = {{1, 2}, {3, 4}, {5, 6}};
    Tmatriz matriz2 = {{10,8}};
    Tmatriz resultados;
    imprimir_matriz(matriz1, 3, 2, matriz2, 2, 1,resultados);
}