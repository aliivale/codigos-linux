#ifndef __FERIA_H__
#define __FERIA_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_BOMBAS 20
#define MAX_HERRAMIENTAS 100
#define MAX_FAMILIARES 10

// typedef struct coordenada{
//     int fil;
//     int col;
// } coordenada_t;

// typedef struct personaje{
//     int vida;
//     int energia;
//     bool camuflado;
//     coordenada_t posicion;
// } personaje_t;

// typedef struct bomba
// {
//    coordenada_t posicion;
//     int timer;
//     bool desactivada;
// } bomba_t;


// typedef struct herramienta{
//     coordenada_t posicion;
//     char tipo;
// } herramienta_t;

// typedef struct familiar{
//     coordenada_t posicion;
//     char inicial_nombre;
// } familiar_t;

// typedef struct juego {
//     personaje_t perry;
//     bomba_t bombas[MAX_BOMBAS];
//     int tope_bombas;
//     herramienta_t herramientas[MAX_HERRAMIENTAS];
//     int tope_herramientas;
//     familiar_t familiares[MAX_FAMILIARES];
//     int tope_familiares;
// }juego_t;


void inicializar_juego(int numero);
void realizar_jugada(int numero);
void imprimir_terreno(int numero);
int estado_juego(int numero);

#endif /* __FERIA_H__ */