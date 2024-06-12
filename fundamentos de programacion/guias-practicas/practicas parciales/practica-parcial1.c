#include <stdio.h>
#define cantcols 3
#define cantfilas 2

typedef int TvecCols[cantcols];
typedef TvecCols TvecFilas[cantfilas];
typedef float tpromedio[cantfilas];


void calcular_promedios(TvecFilas datos, tpromedio promedios);
float promedio_columna(TvecCols notas);
void mostrar_promedios(tpromedio promedios);

float promedio_columna(TvecCols notas){
    //declaro variables
    int c;
    float promedio,suma_notas;

    //inicializo variables
    promedio=0.0;
    suma_notas=0.0;

    for(c=0; c < cantcols;c++){
        suma_notas=suma_notas+notas[c];
    }
    promedio=suma_notas/cantcols;

    return promedio;

}


void calcular_promedios(TvecFilas datos, tpromedio promedios){
    //declaro variables
    int f;
    //lleno el vector de promedios con los resultados obtenidos de la funcion
    for(f=0; f < cantfilas; f++){
        promedios[f]=promedio_columna(datos[f]);
    }
}

void mostrar_promedios(tpromedio promedios){
    int i;

    for(i=0; i < cantfilas; i++){
        printf("promedio: %8.2f\n", promedios[i]);
    }
}
int main(){
    TvecFilas datos={{8,7,10},{4,5,9}};
    tpromedio promedios;

    calcular_promedios(datos,promedios);
    mostrar_promedios(promedios);
}