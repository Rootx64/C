#include <stdio.h> 
#include <stdlib.h>

typedef struct caja{
	int codigo;
	struct caja *sig;
}slotCaja;

typedef slotCaja *pos;

void menu();
void ingresarCaja(pos*, int);
void imprimir(pos);

int main()
{
	menu();
	return 0;
}

void menu()
{
	pos inicio = NULL;
	int opcion = 0, codigo = 0;
	do
	{
		system("cls");
		printf("[1] Ingresar numero\n");
		printf("[2] Imprimir\n");
		printf("[3] Salir\n\n");
		printf("\t\tIngrese su opcion: [ ]\b\b");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1:
				system("cls");
				printf("insertar: ");
				scanf("%d",&codigo);
				ingresarCaja(&inicio, codigo);
				system("pause");
				break;
			case 2:
				system("cls");
				imprimir(inicio);
				system("pause");
				break;
			default:
				system("cls");
				printf("error\n");
				system("pause");
				break;
		}
	}while(opcion != 3);
}

void ingresarCaja(pos *ini, int codigo)
{
	pos nueva, actual;
	nueva = (slotCaja *)malloc(sizeof(slotCaja));
	if (nueva != NULL)
	{
		nueva -> codigo = codigo;
		actual = *ini;
		if (actual == NULL)
		{
			nueva -> sig = nueva;
			*ini = nueva;
		}else
		{
			while(actual -> sig != (*ini))
			{
				actual = actual -> sig;
			}
			actual -> sig = nueva;
			nueva -> sig = (*ini);
		}
	}else
	{
		printf("no memoria\n");
	}
}

void imprimir(pos actual)
{
	pos aux;
	aux = actual;
	if (actual == NULL)
	{
		printf("null\n");
	}else
	{
		while (actual != aux)
		{
			printf("\n- Codigo    : [%d]\n",actual -> codigo);
			actual = actual -> sig;
		}
	}
	printf("\n");
}
