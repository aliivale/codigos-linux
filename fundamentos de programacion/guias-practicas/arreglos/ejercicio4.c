#include <stdio.h>
#include <stdbool.h>

#define NO_OCUPADO -1
#define MAX_FISICO 100
typedef float tvec[MAX_FISICO];

//como la posiciones son >= 0 entonces podemos inicializar en -1. -1 = posicion no ocupada
void inicializar_vec_posicion(tvec vec_posiciones,int* cantidad_numeros);
void solicitar_contenido_posicion(int* cantidad_numeros,int* x, int* i, tvec vec_posiciones);

void inicializar_vec_posicion(tvec vec_posiciones, int* cantidad_numeros){
	int i;
	for (i=0; i < *cantidad_numeros; i++){
		vec_posiciones[i]=NO_OCUPADO;
	}
}

void solicitar_contenido_posicion(int* cantidad_numeros, int* x, int* i, tvec vec_posiciones){
	printf("Ingrese un numero x: ");
	scanf("%d",x);
	printf("Ingrese posicion para el numero, (valores menores a 0 para terminar): ");
	scanf("%d",i);
}

int main(){
	int cantidad_numeros, x, i;

	solicitar_total_numeros(&cantidad_numeros);

	/*creo los vectores con su mf*/
	tvec vector[cantidad_numeros];
	tvec vec_posiciones[cantidad_numeros];

	inicializar_vec_posicion(vec_posiciones,&cantidad_numeros);
	solicitar_contenido_posicion(&cantidad_numeros,&x,&i,vec_posiciones);
	mostrar_vector(vector);	

	return 0;
}

