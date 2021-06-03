///////////////////
//-JAVIER BRIONES//
//-KURT RIVEROS  //
///////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tam;

int  busquedaTernariaRecursiva(int *array,int x,int primero, int ultimo ){
    int inicio,fin,intermedio;
    inicio=primero;
    fin=ultimo;

    if(inicio>=fin){
        if(array[fin]==x){
            return fin;
        }
        return -1;
    }
    intermedio=(fin-inicio+1)/3;

    if(x==array[inicio+intermedio]){
        return (inicio +intermedio);
    }else
    {
        if(x<array[inicio+intermedio]){
            return busquedaTernariaRecursiva(array,x,inicio,inicio+intermedio-1);
        }
        else{
            if(x==array[fin-intermedio]){
                return (fin-intermedio);
            }
            else{
                if(x<array[fin-intermedio]){
                    return busquedaTernariaRecursiva(array,x,inicio+intermedio+1,fin-intermedio-1);
                }
                else{

                    return busquedaTernariaRecursiva(array,x,fin-intermedio+1,fin);
                }
            }
        }
    }
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
    resultado=busquedaTernariaRecursiva(array,x,0,tam);
    imprimeResultado(resultado);
    //imprimirArray(array);
   return 0;

}
