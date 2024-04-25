#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MF 50
typedef int t_padron[MF];
typedef char t_nombre[MF];
typedef t_nombre t_alumnos[MF];

void cargar_datos(t_nombre nombre, t_padron padrones, t_alumnos info_alumnos);

bool validar_datos(t_nombre nombre);

bool validar_datos(t_nombre nombre){
    bool valido=false;
    char* posicion;
    posicion= strstr(nombre,",");
    if (posicion != NULL){
        valido=true;
    }
    return valido;

}
void cargar_datos(t_nombre nombre, t_padron padrones, t_alumnos info_alumnos, int* padron){
    int i=0;
    printf("Ingrese padron, 0 para terminar: ");
    scanf("%i",padron);
    while(*padron !=0 && i < MF){
        printf("Ingrese nombre,apellido: ");
        fgets(nombre,MF,stdin);
        fflush(stdin);
        while(validar_datos(nombre)){
            printf("Ingrese nombre,apellido: ");
            fgets(nombre,MF,stdin);
            fflush(stdin);
        }
        strcpy(info_alumnos[i],nombre);



    }
}


int main(){
    t_nombre nombre;
    t_padron padrones;
    t_alumnos info_alumnos;
    int padron;
    cargar_datos(nombre, padrones, info_alumnos,&padron);

}