/*
Javier Briones
Francisco Miranda
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>



int largoGrafo;
int Grafo[1000][1000];
int redGrafo[1000][1000];
int camino[1000];
bool visited[1000];


typedef struct Nodo{
    int info;
    struct Nodo *sig;
}tNodo;

typedef tNodo *Lista;

Lista crearNodo(int valor)
{
    Lista aux;
    aux = (Lista)malloc(sizeof(tNodo));
    if (aux != NULL)
    {
        aux->info = valor;
        aux->sig = NULL;
    }
    else
    {
        system("cls");
        printf("\n\tERROR: No hay memoria suficiente para generar un nuevo Nodo.");
        printf("\n\tEste programa se cerrar%c.", 160);
        exit(-2);
    }
    return aux;
}


Lista insertar(Lista L, int x)
{
    Lista pNodo, aux;

    pNodo = crearNodo(x);
    if (L == NULL)
        L = pNodo;
    else
    {
        aux = L;
        while (aux->sig != NULL)
            aux = aux->sig;
        aux->sig = pNodo;
        aux = NULL;
    }
    pNodo = NULL;
    return L;
}

Lista eliminar(Lista L)
{

    Lista aux;
    aux = L;
    L = L->sig;
    aux->sig = NULL;
    free(aux);
    return L;
}

void inicializaVisitado(){
    int i;

    for(i=0;i<largoGrafo;i++){
        visited[i]=false;
    }
}
bool hayCamino( int sumidero, int fuente )
{
    Lista revisa;
	inicializaVisitado();


	revisa=insertar(NULL,sumidero);

	visited[sumidero] = true;
	camino[sumidero] = -1;

	while (revisa!=NULL)
	{
		int v,u = revisa->info;
		revisa=eliminar(revisa);


		for ( v=0; v<largoGrafo; v++)
		{
			if (visited[v]==false && redGrafo[u][v] > 0)
			{
			    revisa=insertar(revisa,v);
				camino[v] = u;
				visited[v] = true;
			}
		}
	}

	return (visited[fuente] == true);
}

int fordFulkerson( int sumidero, int fuente)
{
	int u, v;


	for (u = 0; u < largoGrafo; u++)
		for (v = 0; v < largoGrafo; v++)
			redGrafo[u][v] = Grafo[u][v];


	int flujo_max = 0;


	while (hayCamino( sumidero, fuente))
	{

		int flujo_aum = 99999;
		for (v=fuente; v!=sumidero; v=camino[v])
		{
			u = camino[v];
			if(flujo_aum>redGrafo[u][v]){
                flujo_aum=redGrafo[u][v];
			}
		}

		for (v=fuente; v != sumidero; v=camino[v])
		{
			u = camino[v];
			redGrafo[u][v] -= flujo_aum;
			redGrafo[v][u] += flujo_aum;
			printf("|%d %d| ",v,u);
		}

		flujo_max += flujo_aum;
		printf("flujo de aumento %d  \n",flujo_aum );
	}

	return flujo_max;
}



int VerificarFuente(){//importa columna
    int Cerosfil=0;
    int i=0,j=0;

    while(j<largoGrafo){
        i=0;
        while(i<largoGrafo){
            if(Grafo[i][j] == 0){
                Cerosfil++;
            }
            i++;
        }
        if(Cerosfil == largoGrafo){
            return j;
        }
        Cerosfil=0;
        j++;
    }
    return -1;
}
int VerificarSumidero(){//importa fila
    int CerosCol=0;
    int i=0,j=0;

    while(i<largoGrafo){
        j=0;
        while(j<largoGrafo){
            if(Grafo[i][j] == 0){
                CerosCol++;
            }
            j++;
        }
        if(CerosCol == largoGrafo){
            return   i;
        }
        CerosCol=0;
        i++;
    }
    return-1;
}

void leerArchivo(){
    char buffer[1000];
    int i,j;
    FILE *ptr;
 	ptr = fopen ( "entrada.txt", "r" );
 	if(ptr!=NULL){
        fscanf(ptr, "%s" ,buffer);
        largoGrafo=atoi(buffer);
        for(i=0;i<largoGrafo;i++){
            for(j=0;j<largoGrafo;j++){
                fscanf(ptr,"%s",buffer);
                Grafo[i][j]=atoi(buffer);
            }
        }
        fclose ( ptr );
    }else{
        printf("Error al leer eL archivo!\n");
        exit(-2);
    }
}

int main()
{
    int sumidero=0,fuente=0;
    leerArchivo();

    fuente=VerificarFuente();
    sumidero=VerificarSumidero();
    printf("nodo fuente: %d  nodo sumidero : %d\n",fuente,sumidero);
    printf("el flujo maximo es %d",fordFulkerson( fuente, sumidero));
	return 0;
}
