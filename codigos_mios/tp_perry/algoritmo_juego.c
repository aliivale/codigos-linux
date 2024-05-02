#include "algoritmo_juego.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "time.h"

void inicializar_perry(juego_t* juego,tvec ufil,tvec ucol, int* max_logico){
    int indice=0;
    juego->perry.vida=3;
    juego->perry.energia=100;
    juego->perry.camuflado=false;
    cargar_posiciones(ufil,ucol,juego,'P', &indice,max_logico);
}

void inicializar_bombas(juego_t* juego,tvec ufil, tvec ucol,int* maximo_logico){
    int indice=0;
     //inicializamos el tope de bombas
    juego->tope_bombas=(MAX_BOMBAS/2);

    //random tiempo para bomba
    srand ((unsigned)time(NULL));

    //se crean 10 bombas
    for (int i=0; i < juego->tope_bombas ;i++){
        juego->bombas[i].desactivada=false;
        juego->bombas[i].timer=rand() % 300 + 50;
        //printf("BOMBA %d:  %d tiempo\n",i,juego->bombas[i].timer);
        cargar_posiciones(ufil,ucol,juego,'B',&indice,maximo_logico);

    }
}

void inicializar_herramientas(juego_t* juego, tvec ufil, tvec ucol, int* maximo_logico){

    int indice=0;
    // 3 --> SOMBREROS, 5 --> GOLOSINAS. TOTAL 8
    juego->tope_herramientas=8;
    for(int i=0; i< juego->tope_herramientas;i++){
        //SOMBREROS 
        if (i<3){
            juego->herramientas[i].tipo='S';
            //printf("SOMBRERO %d iniciado\n",i);
            cargar_posiciones(ufil,ucol,juego,juego->herramientas[i].tipo,&indice,maximo_logico);
        }
        //GOLOSINAS
        else{
            juego->herramientas[i].tipo='G';
            //printf("GOLOSINAS %d iniciado\n",i);
            cargar_posiciones(ufil,ucol,juego,juego->herramientas[i].tipo,&indice,maximo_logico);
        }
        
    }
}

void inicializar_familia(juego_t* juego,tvec ufil,tvec ucol,int* maximo_logico){
    int indice=0;
    juego->tope_familiares=3;
    char familia[3]={phineas,ferb,candace};
    for(int i=0; i < juego->tope_familiares; i++){
        juego->familiares[i].inicial_nombre=familia[i];
        //printf("FAMILIAR %d:  %c \n",i,juego->familiares[i].inicial_nombre);
        cargar_posiciones(ufil,ucol,juego,juego->familiares[i].inicial_nombre,&indice,maximo_logico);
    }
}


void cargar_posiciones(tvec ufil, tvec ucol,juego_t* juego,char id_caracter, int* indice, int* max_logico){
    srand ((unsigned)time(NULL));
    int fila,columna;
    do{
        fila = rand() % (FILAS-1);
        columna = rand() % (COLUMNAS-1);
    }
    while(validar_posiciones(ufil,ucol,max_logico,fila,columna)==false);

    if(id_caracter == 'P'){
        juego->perry.posicion.fil=fila;
        juego->perry.posicion.col=columna;

    }
    else if(id_caracter == 'B'){
        juego->bombas[*indice].posicion.fil=fila;
        juego->bombas[*indice].posicion.col=columna;
        //printf("BOMBA [%d] fil: %d - col: %d\n",*indice,fila,columna);
        *indice=*indice+1;
    }
    else if(id_caracter== 'S' || id_caracter == 'G'){
        juego->herramientas[*indice].posicion.fil=fila;
        juego->herramientas[*indice].posicion.col=columna;
        //printf("HERRAMIENTA [%d] fil: %d - col: %d\n",*indice,fila,columna);
        *indice=*indice+1;

    }
    else{
        juego->familiares[*indice].posicion.fil=fila;
        juego->familiares[*indice].posicion.col=columna;
        //printf("FAMILIA [%d] fil: %d - col: %d\n",*indice,fila,columna);
        *indice=*indice+1;
    }

}

bool validar_posiciones(tvec ufil, tvec ucol, int* max_logico, int fil, int col){
    bool resultado=false;


    if(*max_logico == 0){
        ufil[*max_logico]=fil;
        ucol[*max_logico]=col;
        *max_logico= *max_logico+1;
        //printf("PERRY: maximo_logico: %d\n",*max_logico);
        resultado=true;
    }
    else{
        int indice=0;
        bool encontrado=false;
        while(indice < *max_logico && !encontrado){
            //si lo encuentro devuelve false
            if (ufil[indice]== fil && ucol[indice]==col){
                encontrado=true;
            }
            indice++;
        }
        if (encontrado == false){
            ufil[*max_logico]=fil;
            ucol[*max_logico]=col;
            *max_logico= *max_logico+1;
            //printf("BOMBAS: maximo_logico: %d\n",*max_logico);
            //printf("HERRAMIENTA: %d fil: %d - col: %d\n",*max_logico,fil,col);
            resultado=true;

        }   
    }
    return resultado;
}

void inicializar_mapa(tmat mapa, juego_t* juego, int tipo){
    // 1. inicializamos la matriz con espacios vacios
        for (int f = 0; f < FILAS; f++)
        {
            for (int c = 0; c < COLUMNAS; c++)
            {
                mapa[f][c] = LIBRE;
            }
        }
    //TIPO 0: inicializa el mapa por primera vez
    if (tipo == 0){
        // 1. COLOCAMOS A PERRY
        mapa[juego->perry.posicion.fil][juego->perry.posicion.col] = 'P';
        // 2. COLOCAMOS BOMBAS
        for (int b = 0; b < juego->tope_bombas; b++)
        {
            mapa[juego->bombas[b].posicion.fil][juego->bombas[b].posicion.col] = 'B';
        }
        // 3. COLOCAMOS HERRAMIENTAS
        for (int h = 0; h < juego->tope_herramientas; h++)
        {
            mapa[juego->herramientas[h].posicion.fil][juego->herramientas[h].posicion.col] = juego->herramientas[h].tipo;
        }
        // 4. COLOCAMOS FAMILIARES
        for (int fam = 0; fam < juego->tope_familiares; fam++)
        {
            mapa[juego->familiares[fam].posicion.fil][juego->familiares[fam].posicion.col] = juego->familiares[fam].inicial_nombre;
        }
    }
    //TIPO 1: ACTUALIZA A PERRY
    else{
        printf("TIPO 1 ACTUALIZAMOS PERRY\n");
        // 1. COLOCAMOS BOMBAS
        for (int b = 0; b < juego->tope_bombas; b++)
        {
            mapa[juego->bombas[b].posicion.fil][juego->bombas[b].posicion.col] = 'B';
            
        }
        // 2. COLOCAMOS HERRAMIENTAS
        for (int h = 0; h < juego->tope_herramientas; h++)
        {
            mapa[juego->herramientas[h].posicion.fil][juego->herramientas[h].posicion.col] = juego->herramientas[h].tipo;
        }
        // 3. COLOCAMOS FAMILIARES
        for (int fam = 0; fam < juego->tope_familiares; fam++)
        {
            mapa[juego->familiares[fam].posicion.fil][juego->familiares[fam].posicion.col] = juego->familiares[fam].inicial_nombre;
        }

        /* 
        4. COLOCAMOS A PERRY --> lo coloco ultimo para que cuando se encuentre
        en el lugar de una bomba, al colocarse ultimo SOBREESCRIBA el espacio
        y luego al salir de dicha posicion la BOMBA se siga mostrando */

        mapa[juego->perry.posicion.fil][juego->perry.posicion.col] = 'P';

    }
    
}

void mostrar_mapa(juego_t* juego, int tipo){
    tmat mapa;
    if(tipo == 0){
        ///JUEGO COMIENZA
        inicializar_mapa(mapa,juego,0);
    }
    else{
        //JUEGO COMIENZA
        inicializar_mapa(mapa,juego, 1);
    }
    for (int i=0; i < FILAS; i++){
        printf("-----------------------------------------\n|");
        for(int j=0; j < COLUMNAS; j++){
            if(juego->perry.posicion.fil == i && juego->perry.posicion.col==j){
                printf("\033[0;32m%c\033[0m|", mapa[i][j]);
            }
            else{
                printf("%c|", mapa[i][j]);
            }
            
        }
        printf("\n");
    }
    printf("-----------------------------------------\n");
}


bool analizar_movimientos_perry(juego_t* juego,int nueva_fila, int nueva_columna){
    bool resultado=true;

    //verificamos que PERRY NO salga del mapa
    if (nueva_fila > FILAS || nueva_columna > COLUMNAS || nueva_fila < 0 || nueva_columna < 0){
        resultado=false;
    }
    else{
        // 1. Buscamos si PERRY encontro una bomba
        bool encontrada=false;
        int i=0;
        while(!encontrada && i < juego->tope_bombas){
            //printf("ME REALIZO\n");
            //printf("nueva_fila %d vs bomba fila %d - nueva_col %d vs bom_c %d\n",nueva_fila,juego->bombas[i].posicion.fil,nueva_columna,juego->bombas[i].posicion.col);
            if((juego->bombas[i].posicion.fil == nueva_fila) && (juego->bombas[i].posicion.col == nueva_columna)){
                juego->bombas[i].desactivada=true;
                printf("BOMBA %d DESACTIVADA\n",i);
                encontrada=true;
            }
            i++;
        }

        // 2. Verificamos que PERRY NO pise el campo de familiares
        bool atrapado=false;
        int f=0;
        while(!atrapado && f < juego->tope_familiares){
            if ((juego->familiares[f].posicion.fil == nueva_fila) && (juego->familiares[f].posicion.col== nueva_columna)){
                atrapado=true;
                resultado=false;
            }
            f++;
        }
    }
    


    return resultado;
}

int contar_bombas(juego_t juego){
    int bombas_activadas=0;
    for(int b=0; b < juego.tope_bombas; b++){
        if (juego.bombas[b].desactivada == false){
            bombas_activadas++;
        }
    }
    return bombas_activadas;
}