/*
Listas y pilas prox clase
Hacer un programa utilizando pilas que permita ingresar  un nombre, caracter por caracter y lo muestre al revez
*/

#include<stdio.h>
#include<stdlib.h>

struct nodo{
	char valor;
	struct nodo *siguiente;
};

typedef struct nodo pila;
typedef pila *ptrPila;

void insertar(ptrPila *,char);
void imprimir(ptrPila*);
void imprimir2(ptrPila);

int main (){
	char letra;
	ptrPila ptrInicio=NULL;
	
	printf("Ingresar un nombre de 4 letras caracter por caracter.");
	printf("\n\nPrimera letra: ");
	scanf("%s",&letra);
	insertar(&ptrInicio,letra);
	printf("\n\nSegunda letra: ");
	scanf("%s",&letra);
	insertar(&ptrInicio,letra);
	printf("\n\nTercera letra: ");
	scanf("%s",&letra);
	insertar(&ptrInicio,letra);
	printf("\n\nCuarta letra: ");
	scanf("%s",&letra);
	insertar(&ptrInicio,letra);
	imprimir(&ptrInicio);
	system("pause");
	imprimir2(ptrInicio);
	return 0;
}

void insertar(ptrPila *pCima, char letra){
		ptrPila ptrNuevo;
		ptrNuevo =(pila*)malloc(sizeof(pila));
		if(ptrNuevo!=NULL){
			ptrNuevo->valor=letra;
			ptrNuevo->siguiente=*pCima;
			*pCima=ptrNuevo;
		}else{
			printf("No hay memoria");
		}
}

void imprimir(ptrPila *ptrActual){
	ptrPila aux;
	
	while (*ptrActual!=NULL){
		aux=*ptrActual;
		*ptrActual=aux->siguiente;
		printf("[%c]-->",aux->valor);	
		free(aux);		
	}
}
void imprimir2(ptrPila ptrActual){
	if (ptrActual!=NULL)
		printf("no es null");

}

