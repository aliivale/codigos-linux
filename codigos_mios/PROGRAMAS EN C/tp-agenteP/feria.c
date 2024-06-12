#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "feria.h"
#include "algoritmo_juego.h"


void inicializar_juego(juego_t* juego){
    tvec ufil,ucol;
    int maximo_logico=0;
    inicializar_perry(juego,ufil,ucol,&maximo_logico);
    inicializar_bombas(juego,ufil,ucol,&maximo_logico);
    inicializar_herramientas(juego,ufil,ucol,&maximo_logico);
    inicializar_familia(juego,ufil,ucol,&maximo_logico);
}

void realizar_jugada(juego_t* juego, char* accion){
    int nueva_posicion_fila;
    int nueva_posicion_columna;
    switch (*accion)
    {
    case 'W':
        nueva_posicion_fila=juego->perry.posicion.fil - 1;
        if (analizar_movimientos_perry(juego,nueva_posicion_fila,juego->perry.posicion.col)){
            juego->perry.posicion.fil=nueva_posicion_fila;
        }
        
        break;

    case 'S':
        nueva_posicion_fila=juego->perry.posicion.fil + 1;
        if (analizar_movimientos_perry(juego,nueva_posicion_fila,juego->perry.posicion.col)){
            juego->perry.posicion.fil=nueva_posicion_fila;
        }
        break;
    case 'D':
        nueva_posicion_columna= juego->perry.posicion.col + 1;
        if (analizar_movimientos_perry(juego,juego->perry.posicion.fil,nueva_posicion_columna)){
            juego->perry.posicion.col=nueva_posicion_columna;
        }
        break;
    case 'A':
        nueva_posicion_columna= juego->perry.posicion.col - 1;
        if (analizar_movimientos_perry(juego,juego->perry.posicion.fil,nueva_posicion_columna)){
            juego->perry.posicion.col=nueva_posicion_columna;
        }
        break;
    case 'Q':
        if(juego->perry.camuflado==false){
            juego->perry.camuflado=true;
        }
        else{
            juego->perry.camuflado=false;
        }
        break;
    default:
        break;
    }

    
}

void imprimir_terreno(juego_t juego){
    tmat terreno;
    inicializar_terreno(terreno,juego);
    for (int i=0; i < FILAS; i++){
        printf("-----------------------------------------\n|");
        for(int j=0; j < COLUMNAS; j++){
            printf("%c|", terreno[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------------\n");

    printf("PERRY -->CAMUFLADO: %d  VIDAS: %d   ENERGIA: %d\n",juego.perry.camuflado,juego.perry.vida,juego.perry.energia);
    printf("------------------------------------------\n");
    printf("UBICACION --> fila: %d   - columna: %d\n",juego.perry.posicion.fil,juego.perry.posicion.col);
    printf("------------------------------------------\n");


    printf("BOMBAS ACTIVADAS: %d\n",contar_bombas(juego));
    printf("BOMBAS DESACTIVADAS: %d\n", (juego.tope_bombas-contar_bombas(juego)));

    
}
int estado_juego(juego_t juego){
    int estado=0;
    if (contar_bombas(juego)== 0){
        estado=1;
    }
   
    return estado;
}
