#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MF 50
#define PADRON_MF 500
typedef char string[MF];
typedef int ivec[PADRON_MF];
typedef string svec[PADRON_MF];


void cargar_datos(int* indice,int* padron,string alumno,ivec padrones,svec alumnos);
bool validar_ingreso(string alumno);
void guardar_alumno(int* indice,ivec padrones, svec alumnos, int padron, string alumno);
void mostrar_menu(int* opcion,int indice,ivec padrones,svec alumnos);
void eliminar_salto_linea(string caracteres);
void mostrar_busqueda_alumnos(int tipo,int indice,string caracteres,svec alumnos);

void cargar_datos(int* indice,int* padron, string alumno,ivec padrones, svec alumnos){
    *indice=0;
    printf("padron, 0 para terminar: ");
    scanf("%d", padron);

    //para que tome el salto en linea
    getchar();

    while(*padron != 0 && *indice < PADRON_MF){
        printf("Ingrese nombre,apellido del alumno: ");
        fgets(alumno,MF,stdin);
        fflush(stdin);

        // debemos verificar nombre,apellido
        if(validar_ingreso(alumno)==true){
            //guardamos la informacion
            guardar_alumno(indice,padrones,alumnos,*padron,alumno);
            //actualizamos indice al padron
            *indice=*indice+1;
            printf("Alumno ingresado exitosamente\n");

        }
        else{
            printf("Alumno rechazado, intente de nuevo.\n");
        }
        printf("Ingrese el padron, 0 para finalizar: ");
        scanf("%d", padron);
        //para que tome el salto en linea
        getchar();
    }
}

bool validar_ingreso(string alumno){
    bool resultado=false;
    //debo buscar que existe una coma
    char* posicion;
    posicion=strstr(alumno,",");
    if(posicion != NULL){
        resultado=true;
    }
    return resultado;
}

void guardar_alumno(int* indice,ivec padrones, svec alumnos, int padron, string alumno){
    padrones[*indice]=padron;
    strcpy(alumnos[*indice],alumno);
}

void mostrar_menu(int* opcion,int indice,ivec padrones, svec alumnos){
    printf("--------------------------------------------------------\n");
    printf("MENU \n");
    printf("1. Buscar nombre y apellido de alumnos por 2 letras.\n");
    printf("2. Buscar todos los alumnos con un mismo apellido.\n");
    printf("3. Buscar padron del alumno con nombre y apellido\n");
    printf("4. Salir\n");
    printf("--------------------------------------------------------\n");
    printf("Seleccione una opcion: ");
    scanf("%d",opcion);
    getchar();
    while (*opcion != 4)
    {
        if (*opcion == 1)
        {
            //declaramos variable a usar
            string caracteres;
            //buscar nombre,apellido por dos letras
            printf("Ingrese dos letras para buscar alumnos: ");
            fgets(caracteres,10,stdin);
            fflush(stdin);
            //eliminamos salto de linea con funcion
            eliminar_salto_linea(caracteres);
            if((strlen(caracteres)) == 2){
                mostrar_busqueda_alumnos(*opcion,indice,caracteres,alumnos);
                // printf("caracteres: %s\n",caracteres);
            }
            else{
                printf("Caracteres invalidos.\n");
            }


        }
        else if (*opcion == 2)
        {
            printf("2");
        }
        else if (*opcion == 3)
        {
            printf("3");
        }
        else
        {
            printf("Opcion invalida\n");
        }
        printf("--------------------------------------------------------\n");
        printf("MENU \n");
        printf("1. Buscar nombre y apellido de alumnos por 2 letras.\n");
        printf("2. Buscar todos los alumnos con un mismo apellido.\n");
        printf("3. Buscar padron del alumno con nombre y apellido\n");
        printf("4. Salir\n");
        printf("--------------------------------------------------------\n");
        printf("Seleccione una opcion: ");
        scanf("%d",opcion);
        getchar();
    }
}


void eliminar_salto_linea(string caracteres){
    string nueva_cadena;

    //guardamos contenido de caracteres en nueva cadena
    strcpy(nueva_cadena,caracteres);
    //sacamos el salto de linea
    int pos;
    pos=strcspn(nueva_cadena,"\n");
    //modificamos el salto en linea
    nueva_cadena[pos]='\0';

    //asignamos el nuevo contenido a caracteres
    strcpy(caracteres,nueva_cadena);

}

void mostrar_busqueda_alumnos(int tipo,int indice,string caracteres,svec alumnos){
    if(tipo == 1){
        // buscamos nombre,apellido por caracteres ingresados
        int i;
        char* pos;
        printf("Alumnos encontrados, caracteres: %s\n",caracteres);
        for(i=0; i < indice; i++){
            pos=strstr(alumnos[i],caracteres);
            if(pos !=NULL){
                printf("%s",alumnos[i]);
            }
        }
    }
}

int main(){
    //declaramos variables
    int padron, indice,opcion;
    ivec padrones;
    string alumno;
    svec alumnos;
    // listado


    // 3. buscar todos los alumnos por apellido
    // 4. nombre apellido y mostrar el padron
    cargar_datos(&indice,&padron,alumno,padrones,alumnos);
    mostrar_menu(&opcion,indice,padrones,alumnos);
    return 0;
}