#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "algoritmo_juego.h"
#include "feria.h"

int main(){
    juego_t juego;
    // char accion;
    // tmat mapa;

    //antes de comenzar el juego
    inicializar_juego(&juego);

    imprimir_terreno(juego);



    // inicializar_mapa(mapa,&juego,0);

    // //juego preparado para jugar
    // mostrar_mapa(mapa);
    // imprimir_terreno(juego);
    
    // do{
    //     printf("W -> ARRIBA  S -> ABAJO  D --> DERECHA  A --> IZQUIERDA. X: para terminar el juego\n");
    //     printf("MOVIMIENTO: ");
    //     scanf(" %c",&accion);
    //     realizar_jugada(&juego,&accion);
    //     inicializar_mapa(mapa,&juego,1);
    //     mostrar_mapa(mapa);
    //     imprimir_terreno(juego);

        
    // }
    // while(accion != 'X' && estado_juego(juego) != 1);

    // if (estado_juego(juego)==1){
    //     printf("FELICIDADES GANASTE EL JUEGO!\n");
    // }
    // else{
    //     printf("JUEGO ABANDONADO!\n");
    // }

    return 0;
}