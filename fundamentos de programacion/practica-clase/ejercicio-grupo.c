#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MF 50
typedef char string[MF];


void cargar_datos(int* padron,string alumno);

void cargar_datos(int* padron, string alumno){
    printf("padron, 0 para terminar: ");
    scanf("%d", padron);

    getchar();

    while(*padron != 0){
        printf("alumno: ");
        fgets(alumno,MF,stdin);
        fflush(stdin);
        printf("%s - padron: %d\n",alumno,*padron);
        printf("-------------------------\n");
        printf("padron, 0 para terminar: ");
        scanf("%d", padron);
    }
}

int main(){
    int padron;
    string alumno;
    cargar_datos(&padron,alumno);
    return 0;
}