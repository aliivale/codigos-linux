#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char Tstring[100];

void palabra_sin_espacios(Tstring frase, int largo, int* cant);
void esCapicua(Tstring frase,int cant,bool* capicua);

void palabra_sin_espacios(Tstring frase, int largo, int* cant){
    int i=0;
    Tstring palabra_nueva,caracter;

    strcpy(palabra_nueva,"");
    while(frase[i]!= '\0'){
        if(frase[i] != ' '){
            caracter[0]=frase[i];
            strcat(palabra_nueva,caracter);
            *cant=*cant+1;
        }
        i++;
    }
    strcpy(frase,palabra_nueva);
}
void esCapicua(Tstring frase,int cant,bool* capicua){
    int mitad_pal;

    mitad_pal=cant/2;

    for(int i=0; i < mitad_pal;i++){
       char aux=frase[i];
       frase[i]=frase[cant-1-i];
       frase[cant-1-i]=aux;
    }



}

void invertir_palabra(Tstring palabra,Tstring palabra_invertida){
    //Tstring palabra_invertida;
    int i,largo;
    Tstring caracter;
    
    strcpy(palabra_invertida,"");
    largo=strlen(palabra);
    i=largo-1;

    while( i >= 0){
        if(palabra[i] != ' '){
            caracter[0]=palabra[i];
            strcat(palabra_invertida,caracter);
        }
        i--;
    }

    
}

int main(){
    Tstring frase,invertido;

    strcpy(frase,"Hola, me llamo Ana.");
    invertir_palabra(frase,invertido);
    printf("invertido:%s\n",invertido);

    strcpy(frase,"234561");
    invertir_palabra(frase,invertido);
    printf("invertido:%s\n",invertido);

    strcpy(frase,"  ");
    invertir_palabra(frase,invertido);
    printf("invertido:%s\n",invertido);

    strcpy(frase,"Somos o No somos");
    invertir_palabra(frase,invertido);
    printf("invertido:%s\n",invertido);
    
    return 0;
}