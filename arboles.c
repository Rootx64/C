/* Hacer un programa utilizando arboles binarios de busqueda que permita insertar elementos en el arbol y hacer un recorrido in-orden
	pre-orden y post orden segun un menu de opcion, los numeros son ingresados por teclado.
*/ 
#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int clave;
	struct nodo *izq;
	struct nodo *der;
};

typedef struct nodo Nodo;
typedef Nodo *ptrNodo;
 
void Insertar(ptrNodo *,int);
void inorden(ptrNodo);
void postorden(ptrNodo);
void preorden(ptrNodo);

void menu();

int main()
{
	menu();
	// 
	// Insertar(&raiz,1);
	// Insertar(&raiz,6);
	// Insertar(&raiz,5);
	// inorden(raiz);
	system("pause");
	return 0;
}

void menu()
{
	ptrNodo raiz=NULL;
	int opcion = 0, valor = 0;
	do
	{
		system("cls");
		printf("[1] Ingresar numero\n");
		printf("[2] Recorrido pre-orden\n");
		printf("[3] Recorrido in-orden\n");
		printf("[4] Recorrido post-orden\n");
		printf("[5] Salir\n\n");
		printf("\t\tIngrese su opcion: [ ]\b\b");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1:
				system("cls");
				printf("Ingresa el valor: ");
				scanf("%d",&valor);
				Insertar(&raiz,valor);
				system("pause");
				break;
			case 2:
				system("cls");
				preorden(raiz);
				system("pause");
				break;
			case 3:
				system("cls");
				inorden(raiz);
				system("pause");
				break;
			case 4:
				system("cls");
				postorden(raiz);
				system("pause");
				break;
			case 5:
				system("cls");
				printf("Salida\n");
				break;
			default:
				system("cls");
				printf("error\n");
				system("pause");
				break;
		}
	}while(opcion != 5);
}

void inorden(ptrNodo a)
{
  if (a != NULL) {
    inorden(a->izq);
    printf("%d\n",a->clave);
    inorden(a->der);
  }
}

void preorden(ptrNodo a)
{
  if (a != NULL) {
  	printf("%d\n",a->clave);
    preorden(a->izq);
    preorden(a->der);
  }
}

void postorden(ptrNodo a)
{
  if (a != NULL) {
    postorden(a->izq);
    postorden(a->der);
    printf("%d\n",a->clave);
  }
}

void Insertar(ptrNodo *a,int dato)
{

if(*a==NULL)
{

	*a=(Nodo *)malloc(sizeof(Nodo));
	(*a)->clave=dato;
	(*a)->der =NULL;
	(*a)->izq =NULL;
}
else 
	if((*a)->clave<dato)
		Insertar(&(*a)->der,dato);

else 
	if((*a)->clave>dato)
		Insertar(&(*a)->izq,dato); 
}
