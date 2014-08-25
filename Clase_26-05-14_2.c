#include <stdio.h>
#include <stdlib.h>

struct nodo
{
	char dato;
	struct nodo *sgt;
	struct nodo *ant;
};

typedef struct nodo listaDoble;
typedef listaDoble *ptrListaDoble;

void insertar(ptrListaDoble *, char);
void imprimir(ptrListaDoble);

int main()
{
	ptrListaDoble inicio=NULL;
	insertar(&inicio,'a');
	insertar(&inicio,'b');
	insertar(&inicio,'c');
	imprimir(inicio);

	return 0;
}

void insertar (ptrListaDoble *ini, char valor)
{
	ptrListaDoble nuevo,actual;
	nuevo = (listaDoble *)malloc(sizeof(listaDoble));
	if (nuevo != NULL)
	{
		nuevo -> dato = valor;
		nuevo -> sgt  = NULL;
		nuevo -> ant  = NULL;
		actual = *ini;
		if (actual == NULL)
		{
			*ini = nuevo;
		}else{
			while(actual -> sgt != NULL){
				actual = actual -> sgt;
			}
			actual -> sgt = nuevo;
			nuevo -> ant = actual;
		}
	}
}

void imprimir(ptrListaDoble ptrActual)
{
	printf ("\n\nLa lista es la siguiente: ");
	while (ptrActual -> sgt !=NULL)
	{
		printf("[%c]-->",ptrActual->dato );
		ptrActual=ptrActual->sgt;
	}
	while(ptrActual!= NULL)
	{
		printf("[%c]-->",ptrActual->dato );
		ptrActual=ptrActual->ant;
	}
	printf("\n");
}
