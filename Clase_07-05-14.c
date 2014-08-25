/* 
En el archivo lista.c agregar la siguientes funciones
1) crear la funcion "esta vacia", esta funcion identifica si hay elementos en la lista, devuelve un 1 si esta vacia y 0 si tiene contenido
2) crear una funcion "insertar al inicio"
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
void insertarInicio(PtrLista *,char);
void isEmpty(PtrLista);

main()
{
	PtrLista PtrInicio=NULL;
	char Dato;

	Dato='c';

	isEmpty(PtrInicio);
	Insertar(&PtrInicio,Dato);
	Dato='w';
	Insertar(&PtrInicio,Dato);
	Dato='b';
	Insertar(&PtrInicio,Dato);
	Dato='1';
	insertarInicio(&PtrInicio,Dato);
	Dato='3';
	insertarInicio(&PtrInicio,Dato);
	Dato='9';
	insertarInicio(&PtrInicio,Dato);
	ImprimirLista(PtrInicio);
	Eliminar(&PtrInicio);
	ImprimirLista(PtrInicio);
	Eliminar(&PtrInicio);
	ImprimirLista(PtrInicio);
	Contador(PtrInicio);
	isEmpty(PtrInicio);
	getche();
}

void insertarInicio(PtrLista *PIni,char Valor)
{
	PtrLista PtrNuevo,PtrActual;
	
	PtrNuevo =(Lista *) malloc(sizeof(Lista));

	if(PtrNuevo!=NULL){
		PtrNuevo->Dato='1';
		PtrNuevo->sgte=*PIni;
		*PIni=PtrNuevo;
	}
	/*
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
	}*/
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
	printf("\n\nLa cantidad de nodos es: %d",contador1);
	return 0;
}

void isEmpty(PtrLista PtrActual)
{
	if (PtrActual==NULL)
		printf("\n\n1");
	else
	{
		printf("\n\n0");
	}
}
	
void ImprimirLista(PtrLista PtrActual)
{
	if (PtrActual==NULL)
		printf("La lista esta vacia");
	else
	{
		printf ("\n\nLa lista es la siguiente: ");

		while (PtrActual!=NULL)
		{
			printf("[%c]-->",PtrActual->Dato );
			PtrActual=PtrActual->sgte;
		}
	}
}
