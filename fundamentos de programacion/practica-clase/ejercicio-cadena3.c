#include <stdio.h>
#include <string.h>
#define MF 50
typedef char tstring[MF];

void invertir_palabra(tstring palabra);

void invertir_palabra(tstring palabra){
    int largo,i,j;
    char aux;


    largo=strlen(palabra);
    for(i=0; i < (largo/2);i++){
        aux = palabra[i];
        palabra[i]=palabra[largo-i-1];
        palabra[largo-i-1]=aux;
    }

}
int main(){
    tstring palabra;
    printf("Ingrese palabra: ");
    fgets(palabra,MF,stdin);
    fflush(stdin);
    printf("%s\n",palabra);
    invertir_palabra(palabra);
    printf("%s\n",palabra);
}