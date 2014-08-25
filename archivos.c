/*
xiste un archivo (Registros.txt) que contiene 2 números con
decimales por cada línea representando las temperaturas mínima y máxima para
cada día según un sensor. Escriba un programa en C para leer dicho archivo
(cantidad de líneas desconocidas) utilizando la estructura más ideal teniendo en
cuenta que se necesita poner las temperaturas mínimas y máximas en dos
archivos separados (Minimas.txt y Maximas.txt) pero en orden inverso de como
están en el archivo original.
*/
// #include <stdio.h>
// int main(int argc, char *argv[])
// {
//      FILE *archivo;/*El manejador de archivo*/
//      archivo=fopen("1.txt", "w");
//      if(archivo==NULL)
//      {
//      	printf("error\n");
//         return 1;
//      }else
//      {
//      	fprintf(archivo, "Hola, mundo\n");/*Escribimos en el archivo*/
//   		fclose(archivo);/*Cerramos el archivo*/
//   		printf("ok\n");
//      }
//      return 0;
// }
/******   Inicio programa ******/


// #include <stdio.h>


// main()

// {

//       FILE *Fd;

//       char texto[30], fitxizen[30];

//       float zenb,zbkiak[100],tmp;

//       int i=0,j,k;


//       printf("Mete el nombre del fichero del que cogeremos los numeros reales: ");

//       gets(fitxizen);

//       Fd=fopen(fitxizen,"rb");

//       if (Fd==NULL)

//          printf("Error abriendo el fichero");


//       while (feof(Fd)==0)

//       {
//             fgets(texto,30,Fd);

//             sscanf(texto,"%f",&zenb);

//             zbkiak[i]=zenb;

//             i++;
//       }


//       i=i-1; //hacemos i-1 ya que fgets pilla tambien la ultima linea y esa no nos interesa

//       for (j=0;j<i;j++)

//       {
//           for (k=j+1;k<i;k++)

//           {
//               if(zbkiak[j]>zbkiak[k])

//               {
//                  tmp=zbkiak[k];

//                  zbkiak[k]=zbkiak[j];

//                  zbkiak[j]=tmp;

//               }
//           }
//       }

//       printf("Los numeros ordenados: \n");

//       for (j=0;j<i;j++)

//       {
//           printf("%.2f \n",zbkiak[j]);
//       }

//       getchar();
// }



// /******   Fin programa******/
#include <stdio.h>
int main()
{
	float hola = 1.1;
	printf("%2f \n",hola );
	/* code */
	return 0;
}
