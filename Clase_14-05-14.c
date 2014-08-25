/* 15->Proximo Nº17 ->Nº18

Como se crea una lista lineal?
	- a) creando cada nodo nuevo de la lista a continuacion del ultimo creado
 	- b) creando cada nodo nuevo de la lista delante del ultimo creado
 	
 	Creando cada nodo nuevo de la lista a continuacion o delante del ultimo creado.
 
 * Como se referencia al ultimo elemento de la lista?
 
 	- Manteniendo un puntero al ultimo elemento para poder enlazarlo con el nodo que se va añadir.

Hacer un programa utilizando listas y pilas:
	1-. Se debe ingresar datos numericos en una lista simple( el ingreso es por el final ).
	2-. Eliminar los datos de la lista uno a uno por el inicio y obtener el valor eliminado para ingresarlo en una pila.
	3-. Eliminar los daatos de la pila y obtener la suma de ellos
*/
#include<stdio.h>
#include<stdlib.h> 

struct datosNum{
	int numeroLista;
	struct datosNum *sgte;
};

struct sumaNum{
	int numeroPila;
	struct sumaNum *sgte;
};

typedef struct datosNum listaNum;
typedef listaNum *ptrListaNum;

typedef struct sumaNum pilaNum;
typedef pilaNum *ptrPilaNum;

void insertarLista(ptrListaNum *, int);
void ImprimirLista(ptrListaNum);
void eliminarInicio(ptrListaNum*);

int main(){
	ptrListaNum iniLista=NULL; 
	ptrPilaNum  iniPila= NULL;
	int valor=0;
	printf("\nIngrese un numero: ");
	scanf("%d",&valor);
	insertarLista(&iniLista,valor);
	printf("\nIngrese un numero: ");
	scanf("%d",&valor);
	insertarLista(&iniLista,valor);
	printf("\nIngrese un numero: ");
	scanf("%d",&valor);
	insertarLista(&iniLista,valor);
	ImprimirLista(iniLista);
	eliminarInicio(&iniLista);
	ImprimirLista(iniLista);
	ImprimirLista(iniLista);
	return 0;
}

void insertarLista(ptrListaNum *pIni, int valor){
	ptrListaNum ptrNuevo,ptrActual;
	ptrNuevo=(listaNum *)malloc(sizeof(listaNum));
	if(ptrNuevo != NULL){
		ptrNuevo->numeroLista=valor;
		ptrNuevo->sgte=NULL;
		ptrActual=*pIni;
		if(ptrActual==NULL){
			ptrNuevo->sgte=NULL;
			*pIni=ptrNuevo;
		}else{
			while(ptrActual->sgte!=NULL){
				ptrActual=ptrActual->sgte;
			}
			ptrActual->sgte=ptrNuevo;		
		}
	}
}

void ImprimirLista(ptrListaNum ptrActual)
{
	printf ("\n\nLa lista es la siguiente: ");
	while (ptrActual!=NULL)
	{
		printf("[%d]-->",ptrActual->numeroLista );
		ptrActual=ptrActual->sgte;
	}
}

void eliminarInicio(ptrListaNum *pIni){
	ptrListaNum ptrActual,ptrAux;
	ptrActual=*pIni;
	if(ptrActual==NULL){
		printf("Lista Vacia");
	}else{
		printf("No vacia");
		ptrAux=*pIni;
		*pIni=ptrAux->sgte;
		free(ptrAux);
		
	/*	while(ptrActual!=NULL ){
			ptrActual=ptrActual->sgte;
			//printf("%d",ptrActual->numeroLista);
		}
		ptrAux=ptrActual->sgte;
		ptrActual->sgte=NULL;
		free(ptrAux);
	
	*/}
}
