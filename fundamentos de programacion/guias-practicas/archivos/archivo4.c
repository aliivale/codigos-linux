#include <stdio.h>
#include <stdbool.h>
#define MAX 20
typedef int tvec[MAX];

void agregar(int *max, tvec vector, int numero);
void leer_archivos(FILE *a1, FILE *a2, tvec vector, int *max_logico)
{
    int n1, n2;

    *max_logico = 0;

    a1 = fopen("a4_1.txt", "rt");
    a2 = fopen("a4_2.txt", "rt");
    if (a1 != NULL)
    {
        fscanf(a1, "%d", &n1);
        while (feof(a1)== 0)
        {

            agregar(max_logico, vector, n1);

            fscanf(a1, "%d", &n1);
        }
        fclose(a1);
    }
    else
    {
        printf("Hubo un error en la apertura\n");
    }
    if (a2 != NULL)
    {
        fscanf(a2, "%d", &n1);
        while (feof(a2)== 0)
        {

            agregar(max_logico, vector, n2);

            fscanf(a2, "%d", &n2);
        }
        fclose(a2);
    }
    else
    {
        printf("Hubo un error en la apertura\n");
    }
}

void agregar(int *max, tvec vector, int numero)
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

void mostrar(tvec vector, int max_logico)
{
    for (int i = 0; i < max_logico; i++)
    {
        printf("%d\n", vector[i]);
    }
}

int main()
{
    FILE *a1, *a2;
    tvec vector;
    int max_logico;
    leer_archivos(a1, a2, vector, &max_logico);
    mostrar(vector, max_logico);
    return 0;
}