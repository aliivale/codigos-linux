#include <stdio.h>
#include <stdbool.h>
#define MAX 10
typedef int tvec[MAX];

void insercion(int *max, tvec vector, int numero);
void insercion1(tvec vector, int *max, int numero)
{
    int i, pos, aux;

    // agrego el numero
    vector[*max] = numero;
    *max = *max + 1;
    for (i = 0; i < *max; i++)
    {
        pos = i;
        aux = vector[i];
        printf("aux: %d\n", aux);
        while ((pos > 0) && (vector[pos - 1] > aux))
        {
            printf("pos: %d && vector[%d] > %d\n", pos, pos - 1, aux);
            printf("vector[pos]: %d\n", vector[pos]);
            vector[pos] = vector[pos - 1];
            printf("vector[pos-1]: %d\n", vector[pos - 1]);
            pos--;
        }
        // printf("vector[pos]: %d\n",vector[pos]);
        vector[pos] = aux;
        printf("vector[pos]: %d\n", vector[pos]);
    }
}

void mostrar(tvec vector, int max)
{
    for (int i = 0; i < max; i++)
    {
        printf("%d\n", vector[i]);
    }
}

void insercion(int *max, tvec vector, int numero)
{
    if (*max == 0)
    {
        vector[*max] = numero;
        *max=*max+1;
    }
    else
    {
        vector[*max] = numero;
        *max = *max + 1;
        for (int i = 0; i < *max; i++)
        {
            int pos = i;
            int aux = vector[i];
            while ((pos > 0) && (vector[pos - 1] > aux))
            {
                vector[pos] = vector[pos - 1];
                pos--;
            }
            vector[pos] = aux;
        }
    }
}

int main()
{
    // tvec vector={1,2,4,5,6};
    // int max=5;
    // insertion(vector,&max,3);
    // insercion(vector,&max,3);
    // mostrar(vector, max);
    int num, max;
    tvec vector;
    max = 0;

    do
    {
        printf("numero: ");
        scanf("%d", &num);
        if (num > 0)
        {
            // printf("numero: %d.\n", num);
            insercion(&max,vector,num);
            mostrar(vector,max);
        }
    } while (num > 0);

    return 0;
}