#include <stdio.h>
#include <stdbool.h>
#define MAX  20
typedef struct
{
    int localidad;
    int central;
    int numero;
} r_telefonico;

void leemos_telefonos_desordenado(FILE *archivo,FILE* telarchivo, int localidad);
void leemos_telefonos_ordenados(FILE *archivo,FILE* telarchivo, int localidad);
void solicitamos_localidad(int *localidad);
void guardar_telefonos(FILE* telarchivo, r_telefonico registro);


void solicitamos_localidad(int *localidad)
{
    printf("Ingrese localidad: ");
    scanf("%d", localidad);
}
void leemos_telefonos_desordenado(FILE *archivo,FILE* telarchivo, int localidad)
{
    r_telefonico registro;

    printf("Localidad \tCentral \t\t\tNumero\n");
    archivo = fopen("registro_telefonico.dat", "rb");
    fread(&registro, sizeof(registro), 1, archivo);
    if (localidad == registro.localidad)
    {
        printf("%d \t%-30s %8.2f\n", registro.localidad, registro.central, registro.numero);
    }

    while (!feof(archivo))
    {
        if (localidad == registro.localidad)
        {
            printf("%d \t%-30s %8.2f\n", registro.localidad, registro.central, registro.numero);
            guardar_telefonos(telarchivo,registro);
        }

        fread(&registro, sizeof(registro), 1, archivo);
    }
}
void leemos_telefonos_ordenados(FILE *archivo,FILE* telarchivo, int localidad)
{
    r_telefonico registro;
    bool valido;


    valido=false;
    printf("Localidad \tCentral \t\t\tNumero\n");
    archivo = fopen("registro_telefonico.dat", "rb");
    fread(&registro, sizeof(registro), 1, archivo);
    if (localidad == registro.localidad)
    {
        printf("%d \t%-30s %8.2f\n", registro.localidad, registro.central, registro.numero);
    }

    while (!feof(archivo) && !valido)
    {
        while (registro.localidad == localidad)
        {
            printf("%d \t%-30s %8.2f\n", registro.localidad, registro.central, registro.numero);
            guardar_telefonos(telarchivo,registro);
            valido=true;
        }
        fread(&registro, sizeof(registro), 1, archivo);
    }
}
void guardar_telefonos(FILE* telarchivo,r_telefonico registro){
    fprintf(telarchivo,"\n%d - %d - %d",registro.localidad,registro.central,registro.numero);
   
}

int main()
{
    FILE *archivo,*telarchivo;
    int localidad;

    archivo = fopen("registro_telefonico.dat", "rb");
    telarchivo= fopen("telefonos.text","w");
    if (archivo != NULL)
    {
        solicitamos_localidad(&localidad);
        leemos_telefonos_desordenado(archivo,telarchivo,localidad);
        leemos_telefonos_ordenados(archivo,telarchivo,localidad);

        fclose(telarchivo);
        fclose(archivo);
    }
    else
    {
        printf("Hubo un error en apertura\n");
    }
    return 0;
}