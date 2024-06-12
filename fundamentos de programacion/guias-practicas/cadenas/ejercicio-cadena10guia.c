#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CARACT 15
typedef char tstring[MAX_CARACT];

void leer_palabras(tstring p1,tstring p2){
    printf("Ingrese palabra 1: ");
    fgets(p1, MAX_CARACT, stdin);
    fflush(stdin);
    printf("Ingrese palabra 1: ");
    fgets(p2, MAX_CARACT, stdin);
    fflush(stdin);
}
void analizar_palabras(tstring p1, tstring p2){
    int largo1,largo2,resultado;

    largo1=strlen(p1);
    largo2=strlen(p2);

    if(largo1 > largo2){
        printf("%s - %s\n",p2,p1);
    }
    else if(largo1 < largo2){
        printf("%s - %s\n",p1,p2);
    }
    else{
        resultado=strcmp(p1,p2);
        if(resultado < 0){
            printf("%s - %s\n",p1,p2);
        }
        else if(resultado > 0){
             printf("%s - %s\n",p2,p1);
        }
        else{
            printf("son iguales\n");
        }
    }

}

int main(){
    tstring p1,p2;
    leer_palabras(p1,p2);
    analizar_palabras(p1,p2);
    return 0;
}