#include <stdio.h>
#include <stdbool.h>
#define MF 50
#define NO_ENCONTRADO -1

//definimos nuevo tipo de dato
typedef int ivec[MF];
typedef float fvec[MF];

//firmas de las funciones a usar
void menu(ivec padrones,int* padron,fvec notas,float* nota,int* cantidad,int* opcion,int* posicion);
void cargar_datos_alumnos(ivec padrones,int* padron,fvec notas,float* nota,int* cantidad);
bool agregar_alumno_listado(ivec padrones,fvec notas,int* padron,float* nota,int* pos);
void mostrar_listado_alumno(ivec padrones,fvec notas,int* cantidad);
void ordenar_listado_alumnos(ivec padrones, fvec notas, int* cantidad,int tipo);
int buscar_padron_nota(ivec padrones, fvec notas, int* cantidad,int* padron, int* posicion);

void menu(ivec padrones,int* padron,fvec notas,float* nota,int* cantidad,int* opcion, int* posicion){
    do{
        printf("1 --> Cargar alumnos\n");
        printf("2 --> Mostrar listado de alumnos aprobados\n");
        printf("3 --> Buscar nota de un alumno segun el padron\n");
        printf("4 --> Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d",opcion);
        if (*opcion == 1)
        {
            cargar_datos_alumnos(padrones,padron,notas,nota,cantidad);
        }
        else{
            if(*opcion == 2){
                //muestra listado de alumnos aprobamos, tipo 0 ordenado por nota
                ordenar_listado_alumnos(padrones,notas,cantidad,0);
                mostrar_listado_alumno(padrones,notas,cantidad);
            }
            else{
                if(*opcion == 3){
                    printf("Ingrese el padron para buscar nota del alumno: ");
                    scanf("%d",padron);
                    //Buscar padron para mostrar nota
                    // 1 . tipo 1 ordenar por padron
                    ordenar_listado_alumnos(padrones,notas,cantidad,1);
                    // 2 . buscar de forma binaria
                    if (buscar_padron_nota(padrones,notas,cantidad,padron,posicion)!= -1){
                        printf("La nota del alumno es: %8.2f\n",notas[*posicion]);
                    }
                    else{
                        printf("El alumno no se encuentra en el listado.\n");
                    }
                    
                }
            }
        }
    }
    while(*opcion != 4);
    
}
void cargar_datos_alumnos(ivec padrones,int* padron,fvec notas,float* nota,int* cantidad){
    // solicitamos padron del usuario
    printf("Ingresar un nuevo padron, 0 para terminar: ");
    scanf("%d",padron);
    
    while(*padron != 0){
        printf("Ingrese la nota del alumno: ");
        scanf("%f",nota);

        if(agregar_alumno_listado(padrones,notas,padron,nota,cantidad)==true){
            *cantidad = *cantidad + 1;
            //actualizamos el pedido del padron
            printf("Ingresar un nuevo padron: ");
            scanf("%d",padron);
            
        }
        else{
            printf("AVISO: MAXIMO DE ALUMNOS ALCANZADOS.\n");
            *padron=0;
        }
    }
}

bool agregar_alumno_listado(ivec padrones,fvec notas,int* padron,float* nota,int* cantidad){
    bool resultado=false;

    if (*cantidad < MF){
        //no se alcanzo el tope de alumnos, puede agregarlo
        padrones[*cantidad]=*padron;
        notas[*cantidad]=*nota;
        
        resultado=true;
    }

    return resultado;
}

void mostrar_listado_alumno(ivec padrones,fvec notas,int* cantidad){
    int i;
    printf("-------------------------------\n");
    printf("| LISTADO DE ALUMNOS APROBADOS\n");
    for(i=0; i < *cantidad; i++){
        if (notas[i] > 3){
            printf("| PADRON: %d  - NOTA: %0.2f  \n",padrones[i],notas[i]);
        }
    }
    printf("-------------------------------\n");
}

void ordenar_listado_alumnos(ivec padrones, fvec notas, int* cantidad, int tipo){
    //declaracion de variables
    int i,j,naux,paux;

    //algoritmo seleccion
    for(i=0; i < (*cantidad-1); i++ ){
        for(j= (i+1); j < *cantidad; j++){
            // tipo 0 --> ordenado por notas
            if (tipo == 0){
                if (notas[i] > notas[j])
                {
                    naux = notas[i];
                    paux = padrones[i];

                    notas[i] = notas[j];
                    padrones[i] = padrones[j];

                    notas[j] = naux;
                    padrones[j] = paux;
                }
            }
            // tipo 1 --> ordenar por padron
            else{
                if (padrones[i] > padrones[j])
                {
                    naux = notas[i];
                    paux = padrones[i];

                    notas[i] = notas[j];
                    padrones[i] = padrones[j];

                    notas[j] = naux;
                    padrones[j] = paux;
                }

            }
            

        }
    }
}

int buscar_padron_nota(ivec padrones, fvec notas, int* cantidad,int* padron, int* posicion){
    int i=0;
    *posicion=NO_ENCONTRADO;
    bool encontrado=false;

    while(!encontrado && i < *cantidad){
        if (padrones[i] == *padron){
            encontrado=true;
            *posicion=i;
        }
        i++;
    }
    return *posicion;
}

int main(){
    //declaraciones
    ivec padrones;
    fvec notas;
    int opcion,cantidad,padron,posicion;
    float nota;

    //inicializaciones
    cantidad=0;
    
    //llamado de funcion
    printf("-----------------------------------------------------------\n");
    menu(padrones,&padron,notas,&nota,&cantidad,&opcion,&posicion);
    printf("-----------------------------------------------------------\n");
    
    return 0;
}