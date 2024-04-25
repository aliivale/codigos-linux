#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define COLUMNAS 2
#define FILAS 2
typedef char tmat[FILAS][COLUMNAS];
typedef struct coordenada
{
    int fil;
    int col;
}coordenada_t;

typedef struct personaje{
    char inicial;
    int vida;
    int energia;
    bool camuflado;
    coordenada_t posicion;
} personaje_t;

typedef struct familiar
{
    coordenada_t posicion;
    char inicial_nombre;
} familiar_t;


void imprimir_tablero(tmat tablero);
void inicializar_tablero(tmat tablero);
void cargar_ubicacion(tmat tablero,int* fila, int* columna,char persona);
bool validar_ubicacion(tmat tablero, int* fila, int* columna);

void inicializar_tablero(tmat tablero){
    int fila,columna;

    for(fila=0; fila < FILAS; fila++){
        for(columna=0; columna < COLUMNAS; columna++){
            tablero[fila][columna]=' ';
        }
    }
}
void imprimir_tablero(tmat tablero){
    int fila,columna;

    
    for(fila=0; fila < FILAS; fila++){
        printf("-------------------------------------\n|");
        for(columna=0; columna < COLUMNAS; columna++){
            printf("|  %c  |",tablero[fila][columna]);
        }
        printf("|\n");
    }
    printf("-------------------------------------\n");
}
void cargar_ubicacion(tmat tablero,int* fila, int*columna, char persona){
    // srand sirve con declararlo una sola vez
    srand ((unsigned)time(NULL));
    do{
        *fila = rand() % 4 + 0;
        *columna = rand() % 4 + 0;
    }
    while(validar_ubicacion(tablero,fila,columna)==false);

    tablero[*fila][*columna]=persona;

    
}
bool validar_ubicacion(tmat tablero, int* fila, int* columna){
    bool validado=false;
    if (tablero[*fila][*columna] == ' '){
        // BALDOSA LIBRE
        validado=true;
    }
    return validado;
}

int main(){
    //variables generales
    tmat tablero;
    int fila,columna;

    //INICIALIZAMOS EL TABLERO VACIO
    inicializar_tablero(tablero);

    //1. CREAMOS OBJETO AGENTE
    personaje_t agente;
    familiar_t candace;


    //2. COMPLETAMOS LOS ATRIBUTOS DE PERRY
    agente.inicial='P';
    agente.camuflado=false;
    agente.vida=3;
    agente.energia=100;

    // agregando candace
    candace.inicial_nombre='C';


    // PARA COLOCAR POSICION DEBEMOS LLAMAR A LA FUNCION
    // cargo a perry
    cargar_ubicacion(tablero,&fila,&columna,agente.inicial);
    agente.posicion.fil=fila;
    agente.posicion.col=columna;
    // cargar candace
    cargar_ubicacion(tablero,&fila,&columna,candace.inicial_nombre);
    candace.posicion.fil=fila;
    candace.posicion.col=columna;



    //MOSTRAMOS EL TABLERO CON LOS PERSONAJES
    imprimir_tablero(tablero);


    return 0;
}