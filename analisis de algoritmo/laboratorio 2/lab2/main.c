#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int n;
int matriz[1000][1000];

int fuente=0, sumidero=0;//valores de fuente y sumidero
bool Visitado [1000];
int posicion ;
int camino[20];
int flag;

void inicializaVisitado(){
    int i;
    for(i=0;i<n;i++){
        Visitado[i]=false;
    }
}

void generaCamino(int nodo){
    int i;
    Visitado[nodo]=true;
    camino[posicion]=nodo;
    posicion++;
    if(nodo==sumidero){
        flag=true;
        return;
    }
    for(i=1;i<=n;i++){
        if(matriz[nodo][i]!=0){
            if(!Visitado[i]){
                generaCamino(i);
                if(flag==true){
                    return;
                }else{
                posicion--;
                }
            }
        }
    }

}
int hayCamino(int nodo){
    posicion =1;
    flag=false;
    inicializaVisitado();
    generaCamino(nodo);
    if(flag!=false){
        return 1;
    }
    return 0;
}




void VerificarFuente(){//importa columna
    int Cerosfil=0;
    int i,j;
    for(j=0;j<n;j++){
        Cerosfil=0;
        for(i=0;i<n;i++){
            if(matriz[i][j] == 0){
                Cerosfil++;
            }
        }
        if(Cerosfil == n){
            fuente = j;
        }

    }
}
void VerificarSumidero(){//importa fila
    int CerosCol=0;
    int i,j;

    for(i=0;i<n;i++){
        CerosCol=0;
        for(j=0;j<n;j++){
            if(matriz[i][j] == 0){
                CerosCol++;
            }
        }
        if(CerosCol == n){
            sumidero = i;
        }

    }
}
void leerArchivo(){
    char buffer[1000];
    int i,j;
    FILE *ptr;
 	ptr = fopen ( "entrada.txt", "r" );
 	fscanf(ptr, "%s" ,buffer);
 	n=atoi(buffer);

 	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            fscanf(ptr,"%s",buffer);
            matriz[i][j]=atoi(buffer);
        }
 	}
 	fclose ( ptr );
}

void imprimir(){
    int i,j;

 	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          printf(" %d ",matriz[i][j]);
        }
        printf("\n");
 	}
}



int main(){
    leerArchivo();


    imprimir;
    VerificarFuente();
    printf("fuente: %d\n", fuente);
    VerificarSumidero();
    printf("sumidero: %d\n", sumidero);
hayCamino(fuente);

    return 0;
}
