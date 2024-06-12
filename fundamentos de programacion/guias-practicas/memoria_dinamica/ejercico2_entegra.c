/*
Escribir un programa el cual reserve memoria dinámica para 
almacenar un struct del tipo t_alumno. Luego solicitar al 
usuario que ingrese los datos del alumno y almacenarlos 
en la memoria previamente reservada. Mostrar luego 
todos los datos del alumno. 
Liberar la memoria reservada al finalizar el programa.
typedef struct {
    int padron;
    char nombre[30];
    char apellido[30];
} t_alumno;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int padron;
    char nombre[30];
    char apellido[30];
} t_alumno;

void cargar_alumno(t_alumno *alumno);
void mostrar_datos(t_alumno alumno);

void cargar_alumno(t_alumno *alumno){
    //solicito los datos al usuario
    printf("Ingrese el numero de padron: ");
    scanf("%i",&alumno->padron);
    
    getchar();
    
    printf("Ingrese el nombre: ");
    fgets(alumno->nombre,30,stdin);
    fflush(stdin);
    
    printf("Ingrese el apellido: ");
    fgets(alumno->apellido,30,stdin);
    fflush(stdin);
}

void mostrar_datos(t_alumno alumno){
    printf("ALUMNO GUARDADO CON MEMORIA DINAMICA\n");
    printf("Padron: %d\n",alumno.padron);
    printf("Nombre: %s\n",alumno.nombre);
    printf("Apellido: %s\n",alumno.apellido);
}

int main(){
    //declaro variables
    t_alumno *alumno=NULL;

    //suponiendo que ingresa datos de un solo alumno
    alumno= malloc(sizeof(t_alumno));
    if(alumno != NULL){
        printf("Memoria reservada exitosamente\n");
        cargar_alumno(alumno);
        mostrar_datos(*alumno);

        //libero espacio de memoria
        free(alumno);
    }
    else{
        printf("Ocurrio un error en memoria\n");
    }




}