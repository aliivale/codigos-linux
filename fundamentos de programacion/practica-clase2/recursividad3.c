#include <stdio.h>
#define MAX 10

typedef int Tvector[MAX];

int busqueda_recursiva(Tvector vector, int inicio, int fin, int buscado){
    int posicion,mit;
    if(buscado < vector[inicio] || buscado > vector[fin-1]){
        return -1;
    }
    else{
        mit=(inicio+fin)/2;
        if(buscado == vector[mit]){
            return mit;
        }
        else{
            if(buscado > vector[mit]){
                return busqueda_recursiva(vector,mit+1,fin,buscado);
            }
            else{
                return busqueda_recursiva(vector,inicio,mit-1,buscado);
            }
        }
    }


}

int main(){
    Tvector vector={1,2,3,4,5,6,7,8,9,10};
    printf("%d\n",busqueda_recursiva(vector,0,MAX,7));
    return 0;
}