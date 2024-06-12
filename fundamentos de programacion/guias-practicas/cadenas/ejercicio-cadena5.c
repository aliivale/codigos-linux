#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MF 50
typedef char t_cadena[MF];
typedef char t_char[2];

// condiciones:
// 1. entre 6 y 12 caracteres
// 2. cantidad de digitos pares debe ser mayor a la de los impares

bool validar(t_cadena clave);
//void recorrer_letra(int numero, int* cont_par, int* cont_impar);
void contar_par_impar(int resto, int* cont_par, int* cont_impar);
bool encontrar_snumero(t_char snumero, t_cadena snum);

bool validar(t_cadena clave)
{
    // declaramos variables
    int i, cpares, cimpares;
    t_cadena snum;
    bool resultado, caracter_invalido;
    // creamos el caracter que va a guardar clave[i]
    t_char caracter;

    // creamos un string que guarda los valores numericos
    strcpy(snum, "1234567890");
    // creamos un vector int para poder contar los numeros
    int inum[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    // inicilizamos todos los valores
    resultado = false;
    caracter_invalido = false;
    i = 0;
    cpares = 0;
    cimpares = 0;

    if (strlen(clave) >= 6 && strlen(clave) <= 12)
    {
        while (clave[i] != '\0' && !caracter_invalido)
        {
            // guardamos en caracter[0] lo que hay en el caracter
            caracter[0] = clave[i];
            if (encontrar_snumero(caracter, snum))
            {
                // buscamos la posicion dentro del string num que coincide con pos de int vec
                int pos = strcspn(snum, caracter);
                contar_par_impar(inum[pos], &cpares, &cimpares);
            }
            else
            {
                caracter_invalido = true;
            }
            i++;
        }
        if (cpares > cimpares && caracter_invalido==false)
        {
            resultado = true;
        }
        
    }
    return resultado;
}
void contar_par_impar(int resto, int* cont_par, int* cont_impar){
    if(resto % 2 == 0){
        *cont_par=*cont_par+1;
    }
    else{
        *cont_impar=*cont_impar+1;
    }
}
bool encontrar_snumero(t_char snumero, t_cadena snum){
    bool resultado=false;
    char* posicion;

    posicion=strstr(snum,snumero);
    if(posicion != NULL){
        resultado=true;
    }
    return resultado;
}

void recorrer_letra(int numero, int* cont_par, int* cont_impar){
    bool terminado;
    int resto;

    terminado=false;

    while(!terminado){
        if((numero/10) != 0){
            resto=numero%10;
            contar_par_impar(resto,cont_par,cont_impar);
            numero=numero/10;
        }
        else{
            resto=numero%10;
            contar_par_impar(resto,cont_par,cont_impar);
            terminado=true;
        }
    }
    


}



int main(){
    t_cadena clave;

    printf("resultado: %d\n",validar("j20893"));
    printf("resultado: %d\n",validar("20893a"));
    printf("resultado: %d\n",validar("208X930"));
    printf("resultado: %d\n",validar("20201"));
    printf("resultado: %d\n",validar("23445776"));
    printf("resultado: %d\n",validar("089010"));
    printf("resultado: %d\n",validar("02784532132567"));
    printf("resultado: %d\n",validar("027845320011"));

    return 0;
}