#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MF 100
typedef char t_cadena[MF];

void invertir_cadena(t_cadena cadena,t_cadena cad_invertida);

void invertir_cadena(t_cadena cadena,t_cadena cad_invertida){
    //borramos la concatenacion anterior
    strcpy(cad_invertida,"");
    //creamos las varibles
    int i;
    char caracter[1];

    //inicizalimos variable
    i=strlen(cadena) - 1;
    
    //relizamos bucle
    while( i >= 0){
        if(cadena[i] != ' '){
            caracter[0]=cadena[i];
            strcat(cad_invertida,caracter);
        }
        i--;
    }
}

int main(){
    //declaracion de variables
    t_cadena cad_invertida;
    
    invertir_cadena("Hola, me llamo Ana.",cad_invertida);
    printf("cadena invertida: %s\n", cad_invertida);

    invertir_cadena("234561",cad_invertida);
    printf("cadena invertida: %s\n", cad_invertida);

    invertir_cadena("  ",cad_invertida);
    printf("cadena invertida: %s\n", cad_invertida);

    invertir_cadena("Somos o No somos",cad_invertida);
    printf("cadena invertida: %s\n", cad_invertida);


    return 0;
}