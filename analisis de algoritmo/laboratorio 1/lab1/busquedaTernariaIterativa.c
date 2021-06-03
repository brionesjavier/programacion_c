///////////////////
//-JAVIER BRIONES//
//-KURT RIVEROS  //
///////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tam;

int busquedaTernariaIterativa(int *array,int x){
    int principio = 0;
    int fin = tam - 1;
    int medio1,medio2;

    while (fin > principio +2) {
        medio1 = principio + (fin - principio) / 3;
        medio2 = principio + (fin - principio) * 2 / 3;

        if(x <= array[medio1]){
                fin = medio1;
        }
        else {
            if(x <= array[medio2]) {
                principio = medio1;
                fin = medio2;
            }else {
                principio = medio2;

            }
        }
    }

        if(array[principio]==x){
            return principio;
        }else{
            if(array[fin]==x){
                return fin;
            }else{
                if(array[(principio+fin)/2]==x){
                    return (principio+fin)/2;
                }
            }
        }

    return -1;
}


int *llenadoArray(){
    int *arrayllenado,i;


    arrayllenado=(int*)malloc(tam*sizeof(int));
    for(i=0;i<tam;i++){
        arrayllenado[i]=(2*i)+1;
    }
    return arrayllenado;
}

void imprimirArray(int *array){
    int i;
    for(i=0;i<tam;i++){
        printf(" %d ",array[i]);
    }
}

void imprimeResultado(int resultado){
    if(resultado!=-1){
    printf("el numero esta en la posicion %d\n ",resultado);
    }else{
        printf("el numero no esta\n");
    }
}

int main()
{

    int x,resultado;
    int *array;

    printf("ingrese el tama%co del arreglo\n",164);
    scanf("%d",&tam);
    printf("ingrese el numero a buscar\n");
    scanf("%d",&x);
    //tam=100000000;
    //x=74253951;
    array=llenadoArray();
    resultado=busquedaTernariaIterativa(array,x);
    imprimeResultado(resultado);
    //imprimirArray(array);
   return 0;

}
