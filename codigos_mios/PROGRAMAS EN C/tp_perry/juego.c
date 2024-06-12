#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "algoritmo_juego.h"
#include "feria.h"

int main(){
    juego_t juego;
    char accion;

    //CARGAMOS TODOS LOS DATOS DE LOS PERSONAJES
    inicializar_juego(&juego);

    //JUEGO PREPARADO
    mostrar_mapa(&juego,0);
    imprimir_terreno(juego);

    //EMPIEZA EL JUEGO
    realizar_jugada(&juego,&accion);

    return 0;
}