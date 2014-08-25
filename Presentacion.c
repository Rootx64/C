#include <stdio.h> // biblioteca standar para trabajar con entrada y salida
#include <stdlib.h>  // Biblioteca para trabajar con punteros
#include <string.h>  // Biblioteca para trabajar con cadenas de caracteres  

//declaramos la estructura y sus miembros 
typedef struct caja{
	int codigo;
	char rut[11];
	char contenido[20];
	struct caja *sig,*ant;
}slotCaja; // definimos una estructura del tipo de la estructura anterior

typedef slotCaja *pos;

// Prototipo de funciones, declaramos los parametros que ocupan y el tipo de resultado que devuelve
void menu();
void ingresarCaja(pos*, char[], char[], int);
void imprimir(pos);
void buscarCaja(pos);
void eliminarCaja(pos *);
void menuError1();
void menuError2();
void menuError3();
void exitoRetiro();

//funcion principal main
int main()
{
	menu();
	return 0;
}

void menu()
{
	pos inicio = NULL; 
	int opcion = 0, codigo = 0, rutError = 0, rutError2 = 0, contenidoError = 0;
	char rut[11],contenido[20];
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
				rutError= 0;
				rutError2=0;
				contenidoError = 0;
				system("cls");
				printf("\n            City MailBox v1.0        \n\n");
				printf("*****************************************\n");
				printf("--------    Datos de la caja    --------\n");
				printf("*****************************************\n\n");
				printf ("\n*");	
				printf("\n- Rut       : ");
				scanf("%s",&rut);
				while(rut[rutError] != '\0'){ //inicio comprobacion de rut no tenga mas de 10 caracteres
					rutError++;
				}
				if (rutError >= 11)     // si el rut tiene mas o igual a 11 caracteres nos envia a la funcion menuError2 que esta imprime el error
					{
						menuError2();
					}
					else{
						while(rut[rutError2] != '-' && rutError2<=7){ // si todo va bien, aqui comprobamos que el rut no tenga el guion antes
							rutError2++;							// del caracter numero 7 para no aceptar numeros como este 123-123
						}
						rutError2+=1;
						if (rut[rutError2] != '-' && rutError2<=7) // si hay guion imprimimos la funcion menuError2 de nuevo 
						{
							menuError2();
						}else
						{
							rutError-=2;
							if (rut[rutError] == '-')  // si hay un guion en la posicion 8 o 9 la cual seria la correcta 1234567-1 entramos al if que este continuara con la entrada de datos
							{
								fflush(stdin);
								printf("- Contenido : ");
								scanf("%s",&contenido);
								fflush(stdin);
								while(contenido[contenidoError] != '\0') // comprobamos que al ingresar el contenido este no tenga mas de 20
								{											// caracteres que es el maximo permitido
									contenidoError++;
								}
								if (contenidoError >=21)
								{
									menuError2();  // si tiene mas imprimimos el error
								}else
								{
									codigo+=1;   // contador del codigo si hay error en rut o contenido no sumara por que no llegaria hasta aqui
									printf("- Codigo    : %d\n",codigo);
									printf ("_________________________________\n\n");	
									ingresarCaja(&inicio,rut,contenido,codigo); //le pasamos la direccion y los 3 que necesita la funcion ingresar
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
void ingresarCaja(pos *ini, char rut[], char contenido[], int codigo) // Esta funcion es la que crea un nuevo nodo e ingresa sus datos
{
	pos nueva, actual;
	nueva = (slotCaja *)malloc(sizeof(slotCaja)); // reservamos la memoria a utilizar
	if (nueva != NULL)			// si hay memoria procedemos a insertar los datos
	{
		nueva -> codigo = codigo;  // ingresamos el codigo
		strcpy(nueva -> rut,rut);  // ingresamos el rut -> ocupamos strcpy para ingresar la cadena entera
		strcpy(nueva -> contenido,contenido);  // ingresamos el contenido -> ocupamos strcpy para ingresar la cadena entera
		nueva -> sig = NULL;		 // si es el primer nodo ->sig y ->ant apuntaran a NULL
		nueva -> ant = NULL;
		actual = *ini;      // actual ahora tiene el valor de donde apunta *ini 
		if (actual == NULL)  // en el primer caso actual sera NULL, el segundo en adelante no
		{
			*ini = nueva;  // la estructura nueva la asignamos a *ini que seria el inicio que es NULL
		}else // si ya hay un nodo pasara a esta parte 
		{
			while(actual -> sig != NULL) // mientras actual -> sig sea distinto de null la seguira recorriendo, esto para llegar a la ultima
			{								// posicion de la lista
				actual = actual -> sig; // avanza y asigna
			}
			actual -> sig = nueva; // asignamos el nuevo nodo a actual->sig que seria NULL
			nueva -> ant = actual; //asigamos actual a nueva->ant 
		}
	}else
	{
		menuError1();  // imprimimos el error que no hay memoria
	}
}

void imprimir(pos actual) // funcion para imprimir la lista de cajas
{
	if (actual == NULL)  // si actual es NULL significa que la lista esta vacia 
	{
		menuError1();	// por lo tanto imprimimos error
	}else
	{
		printf("\n            City MailBox v1.0        \n\n");
		printf("*****************************************\n");
		printf("--------    Cajas registradas    --------\n");
		printf("*****************************************\n");
		while (actual != NULL) // mientras actual sea distinto de NULL avanzara e imprimira
		{
			printf ("\n*");	 // decidi no imprimir el rut por seguridad, ya que si aparece cualquier persona puede retirar cualquier caja
			printf("\n- Codigo    : [%d]\n",actual->codigo);
			printf("- Contenido : [%s]\n",actual->contenido);
			printf ("_________________________________");	
			actual=actual->sig; // avanza y asigna 
		}
	}
	printf("\n");
}

void buscarCaja(pos actual)  // funcion para buscar caja una caja especifica
{
	int consulta = 0;
	if (actual == NULL) // si actual es NULL es `por que la lista esta vacia
	{
		menuError1(); // error lista vacia
	}else
	{
		system("cls");
		printf("\n            City MailBox v1.0        \n\n");
		printf("*****************************************\n");
		printf("--------    Datos de la caja    ---------\n");
		printf("*****************************************\n\n");
		printf ("\n*");	
		printf("\n- Codigo    : ");
		scanf("%d",&consulta);  // ingresamos el codigo de la caja que queremos buscar
		fflush(stdin);
		while(actual != NULL)  // mientras actual sea distinto de NULL avanzamos
		{
			if (actual -> codigo == consulta) // si actual->codigo es igual al codigo, imprimimos que la caja ya esta
			{
				system("cls");
				printf("\n            City MailBox v1.0        \n\n");
				printf("*****************************************\n");
				printf("-------  Tu caja ya esta disponible -----\n");
				printf("-----     Retirala ahora mismo!      ----\n");
				printf("*****************************************\n\n\n");
			}else{ // si no imprimimos que la caja aun no esta en el sistema
				system("cls");
				printf("\n            City MailBox v1.0        \n\n");
				printf("*****************************************\n");
				printf("------         Lo sentimos          -----\n");
				printf("---   esta caja no esta disponible!   ---\n");
				printf("*****************************************\n\n\n");
			}
		actual=actual->sig;	// avanza y asigna
		}
	}
}

void eliminarCaja(pos *ini){  // esta seria la funcion mas compleja porque busca y ademas elimina una caja
	pos actual,aux,aux_ant; // varibale de tipo puntero
	actual = *ini; // asignamos el inicio de la lista a actual 
	if (actual == NULL) // si es NULL imprimimos error que esta vacia
	{
		menuError1();
	}else
	{
		aux = actual;  // aux tiene el valor de actual
		aux_ant = NULL; // aux_ant tiene el valor de null
		int elimina = 0;
		char rutElimina[10];

		system("cls");
		printf("\n            City MailBox v1.0        \n\n");
		printf("*****************************************\n");
		printf("--------    Datos de la caja    ---------\n");
		printf("*****************************************\n\n");
		printf ("\n*");	
		printf("\n- Codigo    : ");
		scanf("%d",&elimina);				// ingresamos el codigo y el rut para validar y eliminar la caja
		fflush(stdin);
		printf("- Rut       : ");
		scanf("%s",&rutElimina);
		fflush(stdin);
		if (strcmp(aux->rut,rutElimina) == 0 && aux->codigo == elimina) // validamos que ambos valores ingresados sean igual al que buscamos
		{
			while(aux != NULL && aux->codigo != elimina && aux->rut != rutElimina) // mientras aux sea distinto de NULL y aux->codigo sea distinto al codigo que ingresamos Y aux-> rut sea distinto de rutElimina que es el rut que ingresamos 
			{// vamos avanzar
				aux_ant = aux; //aux_ant tendra el valor de aux
				aux = aux -> sig; // y aux tendra el valor de aux->sig 
			} //cuando encuentre el valor saldra del ciclo while
			if (aux_ant == NULL)  // si aux_ant es NULL significa que no encontre el valor en el while, esto quiere decir que seria el primer nodo de la lista el que tiene el valor que buscamos
			{
				actual = actual -> sig; // actual le asignamos el siguiente valor
				*ini = actual; // y asignamos actual al inicio de la lista
				free(aux); // liberamos aux que contiene el valor que buscabamos
				exitoRetiro(); // imprimimos la funcion exito que es la que tiene el mensaje de que todo salio ok
			}
			else
			{ 
				aux_ant->sig = aux->sig; // asignamos aux->sig a aux_ant 
				free(aux); // liberamos aux que tiene el valor que encontramos
				exitoRetiro(); // mensaje de todo ok
			}
		}
		else{
			menuError3();  // error de que el rut y el codigo no coinciden con ninguna caja
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
	printf("-----        Retire su caja!         ----\n\n");
	printf("--- Muchas gracias por su preferencia ---\n");
	printf("*****************************************\n\n\n");
}
