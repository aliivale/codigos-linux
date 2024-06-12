#include <stdio.h>
#include <string.h>
#define MAX 100
typedef char t_string[MAX];
// practica con archivo binario

// firmas de funciones
void gestionar_archivo(FILE *archivo, t_string accion, t_string nombre_file);
void sacarEspacio(t_string palabra);
void insercion(int tipo, FILE *archivo, t_string accion, t_string nombre_file);
void leer(int tipo, FILE *archivo, t_string accion, t_string nombre_file);

// funciones
void gestionar_archivo(FILE *archivo, t_string accion, t_string nombre_file)
{
    int opcion;
    printf("1 --> Insertar datos\n");
    printf("2 --> Leer datos\n");
    printf("3 --> Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    getchar();
    while (opcion != 3)
    {
        printf("Ingrese el nombre del archivo: ");
        fgets(nombre_file, MAX, stdin);
        fflush(stdin);
        sacarEspacio(nombre_file);
        // printf("%s\n",nombre_file);
        if (opcion == 1)
        {
            printf("OPCIONES DE INSERCION\n");
            printf(". wb --> write binary\n");
            printf(". w --> write text\n");
            printf("Ingrese alguna de las opciones: ");
            fgets(accion, MAX, stdin);
            fflush(stdin);
            sacarEspacio(accion);
            // printf("%s\n",accion);
            insercion(111, archivo, accion, nombre_file);
        }
        else if (opcion == 2)
        {
            printf("OPCIONES DE LECTURA\n");
            printf(". rb --> read binary\n");
            printf(". rt --> read text\n");
            printf("Ingrese alguna de las opciones: ");
            fgets(accion, MAX, stdin);
            fflush(stdin);
            sacarEspacio(accion);
            // printf("%s\n",accion);
            leer(111, archivo, accion, nombre_file);
        }
        else
        {
            printf("Numero inválido, intente de nuevo.\n");
        }
        printf("1 --> Insertar datos\n");
        printf("2 --> Leer datos\n");
        printf("3 --> Salir\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        getchar();
    }
}

void insercion(int tipo, FILE *archivo, t_string accion, t_string nombre_file)
{
    // 111 --> write text
    archivo = fopen(nombre_file, accion);
    if (archivo != NULL)
    {
        if (tipo == 111)
        {
            int numero;

            // ingreso de numeros
            printf("Ingrese numero: ");
            scanf("%d", &numero);
            while (numero > 0)
            {
                fprintf(archivo, "%d\n", numero);

                printf("Ingrese numero: ");
                scanf("%d", &numero);
            }
            
        }
        fclose(archivo);
    }
    else
    {
        printf("insercion: ha ocurrido un error en la apertura del archivo\n");
    }
}

void leer(int tipo, FILE *archivo, t_string accion, t_string nombre_file)
{
    archivo = fopen(nombre_file, accion);

    if (archivo != NULL)
    {
        // tipo 111
        if (tipo == 111)
        {
            int numero;

            fscanf(archivo, "%d", &numero);
            while (feof(archivo) == 0)
            {
                printf("%d\n", numero);
                fscanf(archivo, "%d", &numero);
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("leer: hubo un error en apertura de archivo\n");
    }
}

void sacarEspacio(t_string palabra)
{
    int posicion;
    posicion = strcspn(palabra, "\n");
    palabra[posicion] = '\0';
}

int main()
{
    // declaro variables
    FILE *archivo;
    t_string accion;
    t_string nombre_file;

    // llamar funciones
    gestionar_archivo(archivo, accion, nombre_file);

    return 0;
}