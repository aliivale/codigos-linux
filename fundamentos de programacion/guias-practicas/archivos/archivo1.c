#include <stdio.h>

// FIRMAS
void leer_numeros(FILE* archivo);
void factoriar(int numero, FILE* archivo);

// FUNCIONES
void leer_numeros(FILE* archivo){
    archivo=fopen("archivo1.txt","rt");
    FILE* farchivo=fopen("archivo1_factorial.txt","w");
    if (archivo != NULL && farchivo != NULL){
        int numero;
        fscanf(archivo, "%d", &numero);
        while (feof(archivo) == 0)
        {
            factoriar(numero,farchivo);
            fscanf(archivo, "%d", &numero);
        }

        fclose(farchivo);
        fclose(archivo);
    }
    else{
        printf("Hubo un error en la apertura del archivo.\n");
    }
}

void factoriar(int numero, FILE* farchivo){
    int resultado;

    resultado=1;
    for(int i=1; i <= numero; i++){
        resultado=resultado*i;
    }
    fprintf(farchivo, "%d\n", resultado);
    // printf("resultado:%d\n",resultado);
    
}

int main(){
    FILE* archivo;
    leer_numeros(archivo);
    return 0;
}