#include <stdio.h>
#include <stdlib.h>

struct nodo
{
	int dato;
	struct nodo *sgt;
};

typedef struct nodo cola;
typedef cola *ptrCola;

void insertar(ptrCola*,ptrCola*,int);
int eliminar(ptrCola*, ptrCola*);

int main()
{
	int x;
	ptrCola inicio = NULL;
	ptrCola fin    = NULL;

	insertar(&inicio,&fin,1);
	x = eliminar(&inicio,&fin);
	printf("%d\n",x );
	insertar(&inicio,&fin,2);
	x = eliminar(&inicio,&fin);
	printf("%d\n",x );
	x = eliminar(&inicio,&fin);
	return 0;
}

void insertar(ptrCola *ini, ptrCola *fin,int valor)
{
	ptrCola nuevo, aux;
	nuevo=(cola*)malloc(sizeof(cola));
	if (nuevo != NULL)
	{
		nuevo -> dato = valor;
		nuevo -> sgt  = NULL;
		if (*ini == NULL)
		{
			*ini = nuevo;
			*fin = nuevo;
		}else{
			aux = *fin;
			aux -> sgt = nuevo;
			*fin = nuevo;
		}
	}
}

int eliminar(ptrCola *ini,ptrCola *fin)
{
	int valor = 0;
	ptrCola aux;
	if (*ini == NULL)
	{
		printf("Esta Vacia\n");
	}else{
		if (*ini == *fin)
		{
			aux = *ini;
			valor = aux -> dato;
			*ini = NULL;
			*fin = NULL;
			free(aux);
		}else{
			aux = *ini;
			valor = aux -> dato;
			*ini = aux -> sgt;
			free(aux);
		}
	}
	return valor;
}
