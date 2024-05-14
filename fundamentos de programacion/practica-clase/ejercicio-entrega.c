#include <stdio.h>
#include <stdbool.h>
#define MAX 1000
typedef int Tvector[MAX];


//firma de funciones
void informar_datos_vector(Tvector vector, int max_log, bool* orden_asc, int* menor_dif);
void restar_componentes(int num1, int num2,bool* orden_asc, int* aux_menor);

//recibe todos los parametros que va a usar y devolver
void informar_datos_vector(Tvector vector, int max_log, bool* orden_asc, int* menor_dif){
    int j,aux_menor;

    //inicializar variables
    *orden_asc=true;

    for(j=0; j < max_log; j++){
        if(j==0){
            //guardamos la primer minima diferencia posible para inicializar menor_dif
            restar_componentes(vector[j],vector[j+1],orden_asc,&aux_menor);
            *menor_dif=aux_menor;
        }
        else{
            restar_componentes(vector[j],vector[j+1],orden_asc,&aux_menor);
            if(*menor_dif > aux_menor){
                *menor_dif=aux_menor;
            }
        }   
    }
}

/*evita que la resta me cause un numero negativo,debido a que el vector
NO este ordenado ascendente, es decir num[j] > num[j+1]
por lo cual si PRECISA hacer dicho cambio para restar, TAMBIEN significa que 
el vector NO respetaba condicion de ordenado ASCENDENTEMENTE*/
void restar_componentes(int num1, int num2,bool* orden_asc, int* aux_menor){
    if(num1 > num2){
        //NO ESTABA ORDENADO
        *aux_menor=num1-num2;
        *orden_asc=false;
    }
    else{
        *aux_menor=num2 - num1;
    }
}



int main(){
    //declaramos variables
    bool orden_asc;
    int menor_dif, ml;
    //inicializamos variables
    ml=7;
    Tvector vector={15,18,20,27,28,46,70};
    informar_datos_vector(vector,ml,&orden_asc,&menor_dif);
    printf("ORDEN ASC: %d\n",orden_asc);
    printf("MENOR DIF: %d\n", menor_dif);

    return 0;
}