#include <stdio.h>
#include <stdiobool.h>

/*definimos tipo de vector*/
typedef float tvec;

void solicitar_total_numeros(int* cantidad_numeros){
	printf("Ingrese la cantidad total de numeros a ingresar: ");
	scanf("%d",cantidad_numeros);
	printf("%d",*cantidad_numeros);
}

void solicitar_contenido_posicion(int* cantidad_numeros,int* x, int* i,vec_posiciones){
	printf("Inserte posicion donde guardar el numero: ");
	scanf("%d",i);
	while(i>0 && i<cantidad_numeros && listar_vec_posicion(vec_posiciones,i,cantidad_numeros)){
		printf("Inserte posicion donde guardar el numero: ");
		scanf("%d",i);
	
	
	
	}
}

bool listar_vec_posicion(tvec vec_posiciones,int* i, int* cantidad_numeros){
	validar=true;
	int iterador=0;
	while (iterador<cantidad_numeros && validar){
		if(vec_posiciones[iterador] == i){
			validar=false;
		}
		iterador++;
	}

	return validar;
}
void inicializar_vec_posicion(tvec vec_posiciones, int* cantidad_numeros){
	int i;
	for(i=0; i<cantidad_numeros; i++){
		vec_posiciones[i]=-1;
	}
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

