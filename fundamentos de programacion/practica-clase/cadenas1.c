#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MF 300
typedef char string[MF];

//Firmas de las funciones
void solicitar_datos(string nombre, char* letra);
int contar_caracter(string nombre, char letra);


//Desarrollo de funciones
void solicitar_datos(string nombre, char* letra){
    printf("Ingresa tu nombre: ");
    // longitud: solo se va a guardar hasta llegar a la longitud
    // ej: alisson --> (8), (7) -->  alisso
    fgets(nombre,MF,stdin);
    fflush(stdin);
    printf("Ingresa la letra a contar: ");
    scanf("%c",letra);
}

int contar_caracter(string nombre, char letra){
    // 1. Declaramos variables
    int contador,i;
    // 2. Inicializamos variables
    contador=0,i=0;

    //recorremos con un while
    while(nombre[i] != '\n'){
        if (nombre[i] == letra){
            contador++;
        }
        i++;
    } 
    return contador;
}


int main(){
    //declaramos variables
    string nombre,otroNombre;
    char letra;

    //cargamos los datos
    //solicitar_datos(nombre,&letra);
    
    getchar();
    //probando metodos de libreria string
    // printf("strlen: %d\n",strlen(nombre));
    // printf("strcpy: %s\n",strcpy(otroNombre));
    //retornamos resultados
    //printf("La letra %c aparece: %d veces.\n",letra, contar_caracter(nombre,letra));

    return 0;
}

