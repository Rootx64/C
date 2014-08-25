/*
Utilizando el archivo lista.c  facilitado gentilmente por la docente, realizar la siguiente funcion:
	-Funcion de tipo entero que retorne la cantidad de nodos de la lista.
*/

#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
	char Dato;
	struct Nodo *sgte;
};

typedef struct Nodo Lista;
typedef Lista *PtrLista;

void Insertar (PtrLista *,char);
void ImprimirLista(PtrLista);
void Eliminar(PtrLista*);
int Contador(PtrLista);

main()
{
	PtrLista PtrInicio=NULL;
	char Dato;

	Dato='c';

	Insertar(&PtrInicio,Dato);
	Dato='w';
	Insertar(&PtrInicio,Dato);
	Dato='b';
	Insertar(&PtrInicio,Dato);
	ImprimirLista(PtrInicio);
	Eliminar(&PtrInicio);
	ImprimirLista(PtrInicio);
	Contador(PtrInicio);
	getche();
}

void Insertar(PtrLista *PIni,char Valor)
{
	PtrLista PtrNuevo,PtrActual;

	PtrNuevo =(Lista *) malloc(sizeof(Lista));

	if(PtrNuevo != NULL)
	{
		PtrNuevo->Dato=Valor;
		PtrNuevo->sgte=NULL;
        //EN EL CASO QUE LA LISTA ESTA VACIA

		PtrActual=*PIni;
        if (PtrActual==NULL)
		{
			PtrNuevo->sgte=NULL;
			*PIni=PtrNuevo;
		}
        else
		{
            while (PtrActual->sgte!=NULL )
			      PtrActual=PtrActual->sgte;
            PtrActual->sgte=PtrNuevo;

		}
	}
}
void Eliminar(PtrLista *PIni)
{
     	PtrLista PtrActual,PtrAux;
        PtrActual=*PIni;
        if (PtrActual->sgte==NULL)
        {
           *PIni=NULL;
           free(PtrActual);
        }
        else
        {
		    while (PtrActual->sgte->sgte!=NULL )
			            PtrActual=PtrActual->sgte;
            PtrAux=PtrActual->sgte;
            PtrActual->sgte=NULL;
            free(PtrAux);
		}
}

int Contador (PtrLista PtrActual){
	int contador1=0;
	while (PtrActual!=NULL)
	{
			contador1++;
			PtrActual=PtrActual->sgte;
	}
	printf("La cantidad de nodos es: %d",contador1);
	return 0;
}

void ImprimirLista(PtrLista PtrActual)
{
	if (PtrActual==NULL)
		printf("La lista esta vacia");
	else
	{
		printf ("La lista es la siguiente:\n\n");

		while (PtrActual!=NULL)
		{
			printf("[%c]-->",PtrActual->Dato );
			PtrActual=PtrActual->sgte;
		}
	}


}
