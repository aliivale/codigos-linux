#include <stdio.h>
#define cantcols 5
#define cantfilas 2

typedef int TvecCols[cantcols];
typedef TvecCols TvecFilas[cantfilas];
typedef float Tresultados[cantfilas];
// podemos usar las constantes directamente sin pasarlos por parametro
void calcular_promedios(TvecFilas datos,int mlf,int mlc, Tresultados promedios);

float promedio(TvecCols numeros, int ml){
    int i;
    int suma=0;
    for(i=0; i < ml;i++){
        suma+=numeros[i];
    }
    float resultado= suma/ml;

    return resultado;
}
void calcular_promedios(TvecFilas datos,int mlf,int mlc, Tresultados promedios){
    int f;
    for(f=0;f < mlf; f++){
        promedios[f]= promedio(datos[f],mlc);
    }
}

int main(){
    TvecCols promedios;
    return 0;
}

