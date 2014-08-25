/* Diseñe un algoritmo que reciba tres longitudes y determine si forman o no un 
triángulo. Para ello defina una estructura que contenga los valores recibidos. Luego cree 
una función que determine de qué tipo de triángulo se trata y devuelva un valor, este 
valor servirá para decidir entre: equilátero (si tiene tres lados iguales), isósceles (si tiene 
dos lados iguales) o escaleno (si tiene tres lados desiguales). Considere que para formar 
un triángulo se requiere que: "el lado mayor sea menor que la suma de los otros dos 
lados". Tenga en cuenta la posibilidad de que no se pueda formar un triángulo */
#include <stdio.h>
#include <stdlib.h>  // libreria para trabajar con punteros 

//declaracion de la estructura
typedef struct valoresTriangulo{
	int lado1,lado2,base;
}triangulo;

typedef triangulo *puntero;
// fin declaracion estructura

//pre declaracion de las funciones
void crearTriangulo(puntero*, int, int, int);
void tipoTriangulo(puntero);


int main(){
	puntero inicio = NULL;
	int lado1 = 0,lado2 = 0,base = 0;
	printf("Ingrese lado 1: ");
	scanf("%d",&lado1);
	printf("\nIngrese lado 2: ");
	scanf("%d",&lado2);
	printf("\nIngrese la base: ");
	scanf("%d",&base);
	if (lado1+lado2 > base)
	{

		crearTriangulo(&inicio,lado1,lado2,base);
		tipoTriangulo(inicio);
	}else
	{
		printf("los valores no cumplen las condiciones\n");
	}
	

	return 0;
}

void crearTriangulo(puntero *ini, int lado1, int lado2, int base)
{
	puntero nueva;
	nueva = (triangulo *)malloc(sizeof(triangulo)); // asignamos espacio de memoria al nuevo nodo;
	if (nueva != NULL)
	{
		nueva -> lado1 = lado1; // asignamos el lado1 ingresado al lado 1 que esta en la estructura 
		nueva -> lado2 = lado2; // asignamos el lado2 ingresado al lado 2 que esta en la estructura
		nueva -> base = base; // asignamos la base ingresada a la base que esta en la estructura
		*ini = nueva;       // le asignamos el nodo a la direccion de inicio 
	}else
	{
		printf("No hay espacio en memoria");
	}
}
void tipoTriangulo(puntero actual)
{
	if (actual == NULL)
	{
		printf("no hay triangulo\n");
	}else
	{
		if (actual->lado1 == actual->lado2 && actual->lado2 == actual->base)
		{
			printf("equilatero\n");
		}else if(actual->lado1 != actual->lado2 && actual->lado2 != actual->base && actual->lado1 != actual->base)
		{
			printf("escaleno\n");	
		}else
		{
			printf("isoscele\n");
		}
	}
}
