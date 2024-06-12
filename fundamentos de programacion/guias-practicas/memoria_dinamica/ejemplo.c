#include <stdio.h>
// 1. Incluir la librería stdlib para poder trabajar con las funciones de memoria dinámica
#include <stdlib.h>
int main()
{
    // 2. Declaramos un puntero para almacenar la dirección de inicio del espacio que
    // vamos a reservar
    int *enteros = NULL;
    // 3. Solicitamos el ingreso de un numero para indicar la cantidad de valores a almacenar
    int cantidad_enteros;
    printf("Indique la cantidad de valores enteros a almacenar: ");
    scanf("%i", &cantidad_enteros);

    // 4. Reservamos espacio usando la función malloc que nos devuelve la dirección de inicio
    enteros = malloc(cantidad_enteros * sizeof(int));

    // 5. Evaluamos si la reserva del espacio fue existosa
    if (enteros != NULL)
    {
        printf("Espacio de memoria reservado exitosamente.\n");

        // 6. Asignamos valores al espacio reservado, recorriendolo como si fuera un arreglo
        int posicion;
        for (posicion = 0; posicion < cantidad_enteros; posicion++)
            enteros[posicion] = 2 * posicion;

        // 7. Mostramos los valores almacenados en cada uno de los espacios y su dirección
        for (posicion = 0; posicion < cantidad_enteros; posicion++)
            printf("Direccion: H:%x Valor en posicion %d: %d \n", enteros + posicion, posicion, enteros[posicion]);

        fflush(stdin);
        getchar();

        // 8. Liberamos el espacio de memoria reservado
        free(enteros);
        printf("Memoria liberada\n");

        fflush(stdin);
        getchar();
    }
    else
        printf("Error al reservar espacio de memoria.");
    return 0;
}