#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MIN_LEN 4
#define MAX_LEN 8

typedef char t_cadena[50];
typedef char t_char[2];
typedef int t_int[10];

bool validar(t_cadena clave);
bool esNumerico(t_cadena string_numerico,t_char caracter);
bool validar_repeticion(t_int contador_numerico,int numero, int ml_clave);
void inicializar_vec_contador(t_int contador_unicos);

bool validar(t_cadena clave)
{
    //declaramos variables
    bool resultado,caracter_invalido;
    int i,pos;
    t_char caracter;
    t_cadena string_numerico;
    t_int int_numerico={0,1,2,3,4,5,6,7,8,9};
    t_int contador_unicos;
    int indice;

    //inicializamos variables
    inicializar_vec_contador(contador_unicos);
    resultado=false;
    caracter_invalido=false;
    i=0;
    indice=0;

    strcpy(string_numerico,"0123456789");

    if(strlen(clave) >= MIN_LEN && strlen(clave)<= MAX_LEN){
        while(clave[i] != '\0' && !caracter_invalido){
            //conseguimos el caracter y lo guardamos
            caracter[0]=clave[i];
            if(esNumerico(string_numerico,caracter)){
                pos=strcspn(string_numerico,caracter);
                if(!validar_repeticion(contador_unicos, int_numerico[pos], strlen(clave))){
                   caracter_invalido=true; 
                }
            }
            else{
                caracter_invalido=true;
            }

            i++;
        }
        if(caracter_invalido==false){
            resultado=true;        
        }

    }
    return resultado;
}

bool esNumerico(t_cadena string_numerico,t_char caracter){
    bool resultado=false;

    char* posicion;
    posicion=strstr(string_numerico,caracter);
    
    if(posicion != NULL){
        resultado=true;
    }
    return resultado;
}
bool validar_repeticion(t_int contador_unicos,int numero,int len_clave){
    bool valido=false;
    
    //traigo el contador del numero
    int contador_numero=contador_unicos[numero];
    if((contador_numero+1) != len_clave){
        contador_unicos[numero]=contador_numero+1;
        //printf("numero %d repetido --> %d\n",numero,contador_unicos[numero]);
        valido=true;
    }
    
    return valido;
}
void inicializar_vec_contador(t_int contador_unicos){
    int i;
    for(i=0; i < 10; i++){
        contador_unicos[i]=0;
    }
}

int main(){

    printf("Resultado: %d\n",validar("j2020"));
    printf("Resultado: %d\n",validar("2021a"));
    printf("Resultado: %d\n",validar("20X21"));
    printf("Resultado: %d\n",validar("2220"));
    printf("Resultado: %d\n",validar("23445776"));
    printf("Resultado: %d\n",validar("089"));
    printf("Resultado: %d\n",validar("027845321"));
    printf("Resultado: %d\n",validar("02784532"));
    printf("Resultado: %d\n",validar("333333"));


    return 0;
}