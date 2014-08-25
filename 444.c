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
	Eliminar(&PtrInicio);
	ImprimirLista(PtrInicio);
	Eliminar(&PtrInicio);
	ImprimirLista(PtrInicio);
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
