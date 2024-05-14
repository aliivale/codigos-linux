#include <stdbool.h>
#include <stdio.h>

void analizar_numero(int numero, int* producto,int* contador);
bool esPar(int numero);

void analizar_numero(int numero, int* producto, int* contador){
    //declaro variables
    int resto;
    bool terminado;

    //instancio variables
    *producto=1;
    *contador=0;
    terminado=false;

    while(!terminado){
        if((numero/10) != 0){
            resto=numero%10;
            if(esPar(resto)){
                *contador=*contador+1;
                *producto=*producto * resto;
            }
            numero=numero/10;
        }
        else{
            resto=numero%10;
            if(esPar(resto)){
                *contador=*contador+1;
                *producto=*producto * resto;
            }
            terminado=true;
        }
    }
}

bool esPar(int numero){
    bool resultado;
    resultado=false;

    if((numero%2)==0){
        resultado=true;
    }
    return resultado;
}

bool validar_primo(int numero){
    bool primo;
    int i;

    primo=true;
    i=2;

    while(primo && (i < numero)){
        if((numero%i)==0){
            primo=false;
        }
        else{
            i++;
        }
    }
    return primo;
}


int invertir_numero(int numero){
    int aux, ultimo_numero;

    ultimo_numero=numero%10;
    aux=numero;
    while(aux>9){
        aux=aux/10;
        ultimo_numero=ultimo_numero*10 + aux%10;
    }

    return ultimo_numero;
}


int main(){
    int contador,producto,numero;

    numero=25831;

    analizar_numero(numero,&producto,&contador);
    printf("Producto: %d Numeros operados: %d\n",producto,contador);

    printf("numero invertido: %d\n",invertir_numero(187));

    return 0;
}