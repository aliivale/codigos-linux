#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char string[20];
typedef string vstring[4];

void ordenar_alfa(vstring nombres){
    //declarar variables
    int max_logico, cant_iteraciones;
    string aux;
    bool itera;
    
    //inicializamos variables
    max_logico=4-1;
    cant_iteraciones=0;
    itera=true;

    while(itera && cant_iteraciones < max_logico){
        itera=false;
        cant_iteraciones++;
        for(int i=0; i < max_logico ;i++){
            if(strcmp(nombres[i],nombres[i+1]) > 0){
                itera=true;
                strcpy(aux,nombres[i]);
                strcpy(nombres[i],nombres[i+1]);
                strcpy(nombres[i+1],aux);
            }
        }
    }
    
}

void mostrar(vstring nombres){
    for(int i=0; i < 4; i++){
        printf("%s\n",nombres[i]);
    }
}

int main(){
    //almacenamos las variables en el vector
    vstring nombres={"Sanchez","Marques","Anampa","Gonzalez"};
    ordenar_alfa(nombres);
    mostrar(nombres);
    return 0;
}