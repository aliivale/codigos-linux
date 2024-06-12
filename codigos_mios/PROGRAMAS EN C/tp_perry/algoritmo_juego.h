#ifndef algoritmo_juego
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include "feria.h"

#define COLUMNAS 20
#define FILAS 20
#define LIBRE ' '
#define phineas 'H'
#define ferb 'F'
#define candace 'C'
#define TMAX 22

typedef char tmat[FILAS][COLUMNAS];
typedef int tvec[TMAX];

void mostrar_mapa(juego_t* juego, int tipo);

void inicializar_mapa(tmat mapa, juego_t* juego, int tipo);

void inicializar_perry(juego_t* juego,tvec ufil,tvec ucol,int* maximo_logico);

void inicializar_bombas(juego_t* juego,tvec ufil, tvec ucol,int* maximo_logico);

void inicializar_herramientas(juego_t* juego, tvec ufil, tvec ucol, int* maximo_logico);

void inicializar_familia(juego_t* juego,tvec ufil,tvec ucol,int* maximo_logico);

void cargar_posiciones(tvec ufil, tvec ucol,juego_t* juego,char id_personaje,int* indice, int* max_logico);

bool validar_posiciones(tvec ufil, tvec ucol, int* max_logico, int fil, int col);

bool analizar_movimientos_perry(juego_t* juego,int nueva_fila, int nueva_columna);

int contar_bombas(juego_t juego);

#endif