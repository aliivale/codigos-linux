#include <stdio.h>
#include <stdlib.h>
#define MAX 80
int main(){
    FILE* archivo;
    archivo=fopen("archivo.txt","rt");
    if(archivo !=NULL){
        /*
        CARACTER
        char caracter;
        caracter=fgetc(archivo);
        while(caracter != EOF){
            printf("%c",caracter);
            caracter=fgetc(archivo);
        }
        CADENAAS
        char caracteres[MAX];
        while(feof(archivo)==0){
            fgets(caracteres,MAX,archivo);
            printf("%s\n");
        }
         char cadena[MAX];
       fscanf(archivo,"%s",cadena);
        while(feof(archivo)==0){
            printf("%s\n",cadena);
            fscanf(archivo,"%s",cadena);
        }
        */
       
       /*
        AGREGAR MAS CONTENIDO POR CARACTER
        char caracter;
        printf("texto a agregar: ");
        caracter=getchar();

        while(caracter != '\n'){
            fputc(caracter,archivo);
            caracter=getchar();
        }
        fclose(archivo);
        

        CADENAS
        char cadena[MAX];
      printf("texto agregar: ");
      fgets(cadena,MAX,stdin);
      if(fputs(cadena,archivo)==0){
        printf("El archivo fue actualizado\n");
      }
      else{
        printf("No fue posible agregar el texto al archivo\n");
        fclose(archivo);
      }


      char cadena[MAX];
      int cant_caracteres=0;

      printf("Texto a agregar al archivo: ");
      fgets(cadena,MAX,stdin);

      cant_caracteres=fprintf(archivo,"\n%s",cadena);
      printf("\nse escribieron %i caracteres\n", cant_caracteres);
      fclose(archivo);

       */
      
      

    }
    else{
        printf("Error de apertura del archivo\n");
    }
    return 0;
}