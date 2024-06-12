#include <stdio.h>

int f_recursivo(int numero);

int f_recursivo(int numero){
    if(numero == 0)
            return 0;
    else{
        if(numero == 1)
            return 1;
        else
            return f_recursivo(numero-1) + f_recursivo(numero-2) ;
    }
}


int main(){
    for(int i=0; i < 6; i++){
        printf("%d\n",f_recursivo(i));
    }
    
    return 0;
}