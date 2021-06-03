///////////////////
//-JAVIER BRIONES//
//-KURT RIVEROS  //
///////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tam;

int busquedaBinariaIterativa(int *array,int x){
    int inferior,superior,medio;
    inferior=0;
    superior=tam;

    while(inferior<=superior){
        medio=(inferior+superior)/2;
        if(array[medio]==x){
            return medio;
        }else{
            if(x<array[medio]){
                superior=medio-1;
            }else{
                inferior=medio+1;
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
    resultado=busquedaBinariaIterativa(array,x);
    imprimeResultado(resultado);
    //imprimirArray(array);
   return 0;

}
