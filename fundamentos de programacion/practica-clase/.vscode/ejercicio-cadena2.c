#include<stdio.h>
#include<string.h>
#define MF 40
typedef char string[MF];


int main(){
    string nombre;
    //asignamos contenido a una variable, NO SE USA =
    strcpy(nombre,"David");
    printf("%s\n",nombre);


    char* posicion;
    posicion=strstr(nombre,"vid");
    if (posicion !=NULL){
        printf("ENCONTRADO");
    }
    

    return 0;
}