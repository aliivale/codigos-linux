#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TAMANIO 5
#define NO_ENCONTRADO -1
/* definimos una estructura alumno */
typedef struct  
{
     char nombre[30];
     int padron;
     char email[50];
     int notas[2] ;
     float promedio;
} alumno;

void mostrar_mejor_promedio(alumno alumno[TAMANIO]);
void calcular_prom_general(float* gprom,alumno alumno[TAMANIO]);
void ordenar_listado_asc(alumno alumno[TAMANIO]);
int buscar_alumno_padron(int padron,alumno alumno[TAMANIO]);
void mostrar_alumno_padron(int padron,alumno alumno[TAMANIO]);
void leer_padron_alumno(int* padron, alumno alumno[TAMANIO]);

void mostrar_mejor_promedio(alumno alumno[TAMANIO]){
    //declaramos variables
    int i;
    float prom_max;
    char mnombre[30];
    //inicializamos variables
    prom_max=alumno[0].promedio;
    strcpy(mnombre,alumno[0].nombre);

    for(i=0; i < TAMANIO;i++){
        if(prom_max<alumno[i].promedio){
            prom_max=alumno[i].promedio;
            strcpy(mnombre,alumno[i].nombre);
        }
    }
    printf("NOMBRE: %s -MAXIMO PROMEDIO: %8.2f\n",mnombre, prom_max);
}

void calcular_prom_general(float* gprom,alumno alumno[TAMANIO]){
    //declaro variable
    int i;
    //inicializo variable
    *gprom=0.0;

    for(i=0; i < TAMANIO; i++){
        *gprom=*gprom + alumno[i].notas[0];
    }

    *gprom=*gprom/TAMANIO;


}

void cargar(alumno vec[TAMANIO])
{
    int i;
    for(i=0;i<TAMANIO;i++)
    {
        printf("\nIngrese el Nombre:\n");
        scanf("%s",vec[i].nombre);

        printf("Ingrese el padron:\n");
        scanf("%d",&vec[i].padron);

        printf("Ingrese el email:\n");
        scanf("%s",vec[i].email);

        printf("Ingrese la nota del Parcial 1:\n");
        scanf("%d",&vec[i].notas[0]);

        printf("Ingrese la nota del Parcial 2:\n");
        scanf("%d",&vec[i].notas[1]);

	vec[i].promedio = (float)(vec[i].notas[0] + vec[i].notas[1])/2;
    }
}

void ordenar_listado_asc(alumno alumno[TAMANIO]){
    int i,j,aux;
    char aux_nombre[30];
    char aux_email[50];
    int aux_notas[2];
    float aux_promedio;

    for(i=0; i < (TAMANIO-1);i++){
        for(j=i+1; j < TAMANIO; j++){
            if(alumno[i].padron > alumno[j].padron){
                aux=alumno[i].padron;
                strcpy(aux_nombre,alumno[i].nombre);
                strcpy(aux_email,alumno[i].email);
                aux_notas[0]=alumno[i].notas[0];
                aux_notas[1]=alumno[i].notas[1];
                aux_promedio=alumno[i].promedio;

                alumno[i].padron=alumno[j].padron;
                strcpy(alumno[i].nombre,alumno[j].nombre);
                strcpy(alumno[i].email,alumno[j].email);
                alumno[i].notas[0]=alumno[j].notas[0];
                alumno[i].notas[1]=alumno[j].notas[1];
                alumno[i].promedio=alumno[j].promedio;



                alumno[j].padron=aux;
                strcpy(alumno[j].nombre,aux_nombre);
                strcpy(alumno[j].email,aux_email);
                alumno[j].notas[0]=aux_notas[0];
                alumno[j].notas[1]=aux_notas[1];
                alumno[j].promedio=aux_promedio;

            }   
        } 
    }
}

int buscar_alumno_padron(int padron,alumno alumno[TAMANIO]){
    //declaramos variables
    int inf,sup,mit;
    bool terminado;
    int posicion;

    //inicializaciones
    inf=0;
    sup=TAMANIO-1;
    terminado=false;

    while(!terminado){
        if(padron > alumno[sup].padron || padron < alumno[inf].padron){
            //no esta
            posicion=NO_ENCONTRADO;
            terminado=true;
        }
        else{
            mit=(inf+sup)/2;
            if(alumno[mit].padron == padron){
                //encontrado
                terminado=true; 
                posicion=mit;
            }
            else{
                if(padron > alumno[mit].padron){
                    inf=mit+1;
                }
                else{
                    sup=mit-1;
                }
            }
        }

    }
    return posicion;
}

void mostrar(alumno vec[TAMANIO])
{
    int i;
    for(i=0;i<TAMANIO;i++)
    {
 	printf("\n\n Alumnos[%d]",i);
	printf("\n nombre: %s ", vec[i].nombre);
	printf("\n padron: %d ", vec[i].padron);	
	printf("\n email: %s ", vec[i].email);
	printf("\n Nota Parcial 1: %d Nota Parcial 2: %d", vec[i].notas[0],vec[i].notas[1]);
	printf("\n promedio Cd: %.2f ", vec[i].promedio);
    }
}


void leer_padron_alumno(int* padron, alumno alumno[TAMANIO]){
    printf("Ingrese un padron para buscar: ");
    scanf("%d",padron);
    mostrar_alumno_padron(*padron,alumno);
}
void mostrar_alumno_padron(int padron,alumno alumno[TAMANIO]){
    int pos=buscar_alumno_padron(padron,alumno);
    if(pos != NO_ENCONTRADO){
        printf("\n\n Alumnos[%d]",pos);
        printf("\n nombre: %s ", alumno[pos].nombre);
        printf("\n padron: %d ", alumno[pos].padron);	
        printf("\n email: %s ", alumno[pos].email);
        printf("\n Nota Parcial 1: %d Nota Parcial 2: %d", alumno[pos].notas[0],alumno[pos].notas[1]);
        printf("\n promedio Cd: %.2f ", alumno[pos].promedio);
        
    }
    
}

int main(void)
{
    alumno Alumnos[TAMANIO];
    float prom_general;
    int padron;
    // cargo los elementos con funcion cargar
    cargar(Alumnos);

 	/* Muestro datos del primer elemento de la tabla*/
    // mostrar(Alumnos);

    mostrar_mejor_promedio(Alumnos);
    //punto 2
    calcular_prom_general(&prom_general,Alumnos);
    printf("El promedio general del primer parcial es: %8.2f\n",prom_general);

    //punto 3
    ordenar_listado_asc(Alumnos);
    mostrar(Alumnos);

    //punto 4
    leer_padron_alumno(&padron, Alumnos);
    
	printf("\n\n");
	return 0;
}