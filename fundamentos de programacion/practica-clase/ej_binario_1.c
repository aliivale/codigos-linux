#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct{
	int codigo;
	char descripcion[30];
	float cantidad;
}t_regProducto;

void solicitar_codigo(FILE *archivo,int* codigo);
void buscar_producto(FILE* archivo, int codigo);
void mostrar_producto(t_regProducto producto,bool* encontrado);

void solicitar_codigo(FILE *archivo,int* codigo){
    printf("Ingrese codigo de producto a buscar: ");
    scanf("%d",codigo);
    while(*codigo != 0){
        buscar_producto(archivo,*codigo);
        printf("Ingrese codigo de producto a buscar: ");
        scanf("%d",codigo);
    }
}
void buscar_producto(FILE* archivo, int codigo){
    t_regProducto producto;
    bool encontrado;

    encontrado=false;
    archivo=fopen("productos.dat","rb");
    fread(&producto,sizeof(producto),1,archivo);

    //primer if para cotejar comparar la primer linea
    if(producto.cantidad==codigo){
        mostrar_producto(producto,&encontrado);
    }
    else{
        while(!feof(archivo) && !encontrado){
            if(producto.codigo == codigo){
                mostrar_producto(producto,&encontrado);
            }
            fread(&producto,sizeof(producto),1,archivo);
        }
        if(encontrado==false){
            printf("Código de producto inexistente\n");
        }   
    }
    
    
}
void mostrar_producto(t_regProducto producto,bool* encontrado){
    printf("Código \tDescripcion \t\t\tCantidad\n");
    printf("%d \t%-30s %8.2f\n",producto.codigo,producto.descripcion,producto.cantidad);
    *encontrado=true;
}

int main(){
    FILE *archivo;
    int codigo;

    archivo=fopen("productos.dat","rb");
    if(archivo != NULL){
        solicitar_codigo(archivo,&codigo);
        fclose(archivo);
    }
    return 0;
}