#include <stdio.h>
// Escriba un programa modular que permita dar de alta registros de tipo t_regAlumno.
// El usuario debe poder continuar ingresando datos hasta que ingrese un padron igual a 0.
// Asuma que el archivo es inexistente.
// Deberá subir el archivo generado, con al menos 5 datos de alumnos.
typedef struct{
	int padron;
	char ape_nom[30];
	float nota;
}t_regAlumno;

void dar_alta_alumno(FILE* archivo);

void dar_alta_alumno(FILE* archivo){
    t_regAlumno alumno;
    printf("Ingrese el numero de padron: ");
    scanf("%d",&alumno.padron);
    fflush(stdin);
    while(alumno.padron!= 0){
        getchar();
        printf("Ingrese el apellido y nombre: ");
        scanf("%30[^\n]s",alumno.ape_nom);
        fflush(stdin);
        
        printf("Ingrese la nota: ");
        scanf("%f",&alumno.nota);
        fflush(stdin);


        fwrite(&alumno,sizeof(alumno),1,archivo);


        printf("Ingrese el numero de padron: ");
        scanf("%d",&alumno.padron);
        fflush(stdin);
    }
}

void mostrar(){
    FILE* archivo;
    t_regAlumno alumno;
    archivo=fopen("alumnos.dat","rb");
    if (archivo != NULL)
    {
        fread(&alumno,sizeof(alumno),1,archivo);
        while(!feof(archivo)){
            printf("%d  %s  %f\n",alumno.padron,alumno.ape_nom,alumno.nota);
            fread(&alumno,sizeof(alumno),1,archivo);
        }
    }
    
}

int main(){
    FILE* archivo;

    archivo=fopen("alumnos.dat","wb");

    if(archivo!=NULL){
        dar_alta_alumno(archivo);
        fclose(archivo);
    }
    else{
        printf("Hubo un error de apertura del archivo\n");
    }
    mostrar();
    return 0;
}