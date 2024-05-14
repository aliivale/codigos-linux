#include <stdio.h>

typedef int Tmatriz[2][3];
typedef int Tvector[2];

//firmas de funciones
void informar_minimos(Tmatriz matriz, int fil, int col, Tvector resultados);
int indicar_minimo(Tvector vector, int col);
void mostrar_resultados(Tvector resultados, int fil);

//desarrollamos funciones
void informar_minimos(Tmatriz matriz, int fil, int col, Tvector resultados){
    //declaramos variables
    int i;

    //recorro matriz
    for(i=0; i < fil; i++){
        //recorremos filas
        resultados[i]=indicar_minimo(matriz[i],col);
    }    
}

int indicar_minimo(Tvector vector, int col){
    //declaro variables
    int resultado,minimo,i;

    //inicializo variable 
    minimo=vector[0];

    //recorro vector
    for(i=0; i <col;i++){
        if(minimo > vector[i]){
            minimo=vector[i];
        }
    }
    resultado=minimo;
    return resultado;
}

void mostrar_resultados(Tvector resultados, int fil){
    for(int i=0; i < fil; i++){
        printf("MINIMO: %d\n",resultados[i]);
    }        
}

int main(){
    Tmatriz matriz={{8,5,6},{10,9,1}};
    Tvector resultados;
    int fil,col;

    fil=2;
    col=3;

    informar_minimos(matriz,fil,col,resultados);
    mostrar_resultados(resultados,fil);

}