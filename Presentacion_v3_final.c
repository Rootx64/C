#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct caja{
	int codigo;
	char rut[11];
	char contenido[20];
	struct caja *sig;
}slotCaja;

typedef slotCaja *pos;

void menu();
void ingresarCaja(pos*, char[], char[], int);
void imprimir(pos);
void buscarCaja(pos);
void eliminarCaja(pos *);
void menuError1();
void menuError2();
void menuError3();
void exitoRetiro();

int main()
{
	menu();
	return 0;
}

void menu()
{
	pos inicio = NULL;
	int opcion = 0, codigo = 0, rutError = 0, rutError2 = 0, contenidoError = 0;
	char rut[11], contenido[20];
	do
	{
		system("cls");
		printf("\n            City MailBox v1.0        \n\n");
		printf("*****************************************\n");
		printf("--------           Men\243          --------\n");
		printf("*****************************************\n\n\n");
		printf("[1] Ingresar caja al sistema\n");
		printf("[2] Mostrar cajas en el sistema\n");
		printf("[3] Buscar caja\n");
		printf("[4] Retiro caja\n");
		printf("[5] Salir\n\n");
		printf("\t\tIngrese su opcion: [ ]\b\b");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1:
				rutError = 0;
				rutError2 = 0;
				contenidoError = 0;
				system("cls");
				printf("\n            City MailBox v1.0        \n\n");
				printf("*****************************************\n");
				printf("--------    Datos de la caja    --------\n");
				printf("*****************************************\n\n");
				printf ("\n*");	
				printf("\n- Rut       : ");
				scanf("%s", &rut);
				while(rut[rutError] != '\0'){
					rutError++;
				}
				if (rutError >= 11)
					{
						menuError2();
					}
					else{
						while(rut[rutError2] != '-' && rutError2 <= 7){
							rutError2++;
						}
						rutError2+=1;
						if (rut[rutError2] != '-' && rutError2 <= 7)
						{
							menuError2();
						}else
						{
							rutError-=2;
							if (rut[rutError] == '-')
							{
								fflush(stdin);
								printf("- Contenido : ");
								scanf("%s", &contenido);
								fflush(stdin);
								while(contenido[contenidoError] != '\0')
								{
									contenidoError++;
								}
								if (contenidoError >= 21)
								{
									menuError2();
								}else
								{
									codigo+=1;
									printf("- Codigo    : %d\n",codigo);
									printf ("_________________________________\n\n");	
									ingresarCaja(&inicio, rut, contenido, codigo);
									system("pause");
								}
							}else{
								menuError2();
							}
						}
					}
				break;
			case 2:
				system("cls");
				imprimir(inicio);
				system("pause");
				break;
			case 3:
				system("cls");
				buscarCaja(inicio);
				system("pause");
				break;
			case 4:
				system("cls");
				eliminarCaja(&inicio);
				system("pause");
				break;
			case 5:
				system("cls");
				printf("\n            City MailBox v1.0        \n\n");
				printf("*****************************************\n");
				printf("-----            Gracias!           -----\n");
				printf("-----------------------------------------\n");
				printf("---   Te esperamos pronto de vuelta!  ---\n");
				printf("*****************************************\n\n\n");
				break;
			default:
				system("cls");
				printf("\n            City MailBox v1.0        \n\n");
				printf("*****************************************\n");
				printf("-----              Error!           -----\n");
				printf("-----------------------------------------\n");
				printf("---           Opcion invalida!        ---\n");
				printf("*****************************************\n\n\n");
				system("pause");
				break;
		}
	}while(opcion != 5);
}
void ingresarCaja(pos *ini, char rut[], char contenido[], int codigo)
{
	pos nueva, actual;
	nueva = (slotCaja *)malloc(sizeof(slotCaja));
	if (nueva != NULL)
	{
		nueva -> codigo = codigo;
		strcpy(nueva -> rut, rut);
		strcpy(nueva -> contenido, contenido);
		nueva -> sig = NULL;
		actual = *ini;
		if (actual == NULL)
		{
			*ini = nueva;
		}else
		{
			while(actual -> sig != NULL)
			{
				actual = actual -> sig;
			}
			actual -> sig = nueva;
		}
	}else
	{
		menuError1();
	}
}

void imprimir(pos actual)
{
	if (actual == NULL)
	{
		menuError1();
	}else
	{
		printf("\n            City MailBox v1.0        \n\n");
		printf("*****************************************\n");
		printf("--------    Cajas registradas    --------\n");
		printf("*****************************************\n");
		while (actual != NULL)
		{
			printf ("\n*");	
			printf("\n- Codigo    : [%d]\n",actual -> codigo);
			printf("- Rut       : [%s]\n",actual -> rut);
			printf("- Contenido : [%s]\n",actual -> contenido);
			printf ("_________________________________");	
			actual = actual -> sig;
		}
	}
	printf("\n");
}

void buscarCaja(pos actual)
{
	int consulta = 0;
	if (actual == NULL)
	{
		menuError1();
	}else
	{
		system("cls");
		printf("\n            City MailBox v1.0        \n\n");
		printf("*****************************************\n");
		printf("--------    Datos de la caja    ---------\n");
		printf("*****************************************\n\n");
		printf ("\n*");	
		printf("\n- Codigo    : ");
		scanf("%d", &consulta);
		fflush(stdin);
		while(actual != NULL)
		{
			if (actual -> codigo == consulta)
			{
				system("cls");
				printf("\n            City MailBox v1.0        \n\n");
				printf("*****************************************\n");
				printf("-------  Tu caja ya esta disponible -----\n");
				printf("-----     Retirala ahora mismo!      ----\n");
				printf("*****************************************\n\n\n");
				break;
			}else{
				system("cls");
				printf("\n            City MailBox v1.0        \n\n");
				printf("*****************************************\n");
				printf("------         Lo sentimos          -----\n");
				printf("---   esta caja no esta disponible!   ---\n");
				printf("*****************************************\n\n\n");
			}
		actual = actual -> sig;	
		}
	}
}

void eliminarCaja(pos *ini){
	pos actual, aux, aux_ant;
	actual = *ini;
	if (actual == NULL)
	{
		menuError1();
	}else
	{
		aux = actual;
		aux_ant = NULL;
		int elimina = 0;
		char rutElimina[10];

		system("cls");
		printf("\n            City MailBox v1.0        \n\n");
		printf("*****************************************\n");
		printf("--------    Datos de la caja    ---------\n");
		printf("*****************************************\n\n");
		printf ("\n*");	
		printf("\n- Codigo    : ");
		scanf("%d", &elimina);
		fflush(stdin);
		printf("- Rut       : ");
		scanf("%s", &rutElimina);
		fflush(stdin);
		if (strcmp(aux -> rut, rutElimina) == 0 && aux -> codigo == elimina)
		{
			while(aux != NULL && aux -> codigo != elimina && aux -> rut != rutElimina)
			{
				aux_ant = aux;
				aux = aux -> sig;
			}
			if (aux_ant == NULL)
			{
				actual = actual -> sig;
				*ini = actual;
				free(aux);
				exitoRetiro();
			}
			else
			{
				aux_ant -> sig = aux -> sig;
				free(aux);
				exitoRetiro();
			}
		}
		else{
			menuError3();
		}
	}
}

void menuError1()
{
	system("cls");
	printf("\n            City MailBox v1.0        \n\n");
	printf("*****************************************\n");
	printf("-------- No hay cajas registradas -------\n");
	printf("*****************************************\n\n\n");
}

void menuError2()
{
	system("cls");
	printf("\n            City MailBox v1.0        \n\n");
	printf("*****************************************\n");
	printf("----- Rut o Contenido mal ingresado -----\n");
	printf("-----------------------------------------\n");
	printf("----- Compruebe su Rut               ----\n");
	printf("----- Contenido maximo 20 caracteres ----\n");
	printf("*****************************************\n\n\n");
	system("pause");
}

void menuError3()
{
	system("cls");
	printf("\n            City MailBox v1.0        \n\n");
	printf("*****************************************\n");
	printf("-----  Rut o codigo mal ingresado   -----\n");
	printf("-----------------------------------------\n");
	printf("----- Compruebe su Rut               ----\n");
	printf("----- Compruebe su codigo            ----\n");
	printf("*****************************************\n\n\n");
}

void exitoRetiro()
{
	system("cls");
	printf("\n            City MailBox v1.0        \n\n");
	printf("*****************************************\n");
	printf("-----              EXITO            -----\n");
	printf("-----------------------------------------\n");
	printf("--- Muchas gracias por su preferencia ---\n");
	printf("*****************************************\n\n\n");
}
