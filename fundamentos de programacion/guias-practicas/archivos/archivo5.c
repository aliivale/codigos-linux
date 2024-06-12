#include <stdio.h>
#include <string.h>
#define MAX 100
typedef char string[MAX];
typedef string vstring[MAX];

void leer_archivo(FILE *archivo,int* max,vstring vector);
void insercion(string nombre,vstring vector,int* max);

void leer_archivo(FILE *archivo,int* max,vstring vector)
{
    archivo = fopen("archivo5.txt", "rt");
    if (archivo != NULL)
    {
        string nombre;
       while(feof(archivo)==0){
            fgets(nombre,MAX,archivo);
            insercion(nombre,vector,max);
        }
        fclose(archivo);
    }
    else
    {
        printf("Error en la apertura de los archivos\n");
    }
}

void insercion(string nombre,vstring vector,int* max){
    if (*max == 0)
    {
        strcpy(vector[*max],nombre);
        *max=*max+1;
    }
    else
    {
        strcpy(vector[*max],nombre);
        *max = *max + 1;
        for (int i = 0; i < *max; i++)
        {
            int pos = i;
            
            string aux;
            strcpy(aux,vector[i]);
            
            while ((pos > 0) && (strcmp(vector[pos-1],aux) >0))
            {
                strcpy(vector[pos],vector[pos-1]);
                pos--;
            }
            strcpy(vector[pos],aux);
        }
    }
}

void mostrar(vstring vector, int max){
    for(int i=0; i < max; i++){
        printf("%s",vector[i]);
    }
}
int main()
{
    FILE *archivo;
    int max=0;
    vstring vector;

    leer_archivo(archivo,&max,vector);
    mostrar(vector,max);

    return 0;
}