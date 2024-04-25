#include <stdio.h>
#define MF 40
typedef char string[MF];

int main(){
    //declaramos variables e inicializamos
    string nombre_completo;
    int i=0,contador_consonantes=0;
    
    printf("Ingrese nombre y apellido: ");
    fgets(nombre_completo,MF,stdin);
    fflush(stdin);

    while (nombre_completo[i] != '\0'){
        int letra=nombre_completo[i];
        if (letra != 97 && letra != 101 && letra != 105 && letra != 111 && letra !=117 && letra != 65
         && letra != 69 && letra != 73 && letra != 79 && letra != 85 && letra != 32 && letra!= '\n'){
            printf("letra: %c\n", letra);
            contador_consonantes++;
        }
        i++;
    }
    printf("Consonantes totales: %d\n",contador_consonantes);

}