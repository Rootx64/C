int main(){
 nodo *minimas = NULL;
 nodo *maximas = NULL;
 FILE *archivoEntrada, *archivoMin, *archivoMax;
 int contador=0, i;
 double min, max;
 
 archivoEntrada = fopen("Registros.txt", "r"); // arhivo solo para leer /r
 archivoMin = fopen("Minimas.txt", "w"); // archivo para escribir temp minimas /w
 archivoMax = fopen("Maximas.txt", "w");  // archivo para escribir temp maximas /w
 
 if(archivoEntrada == NULL || archivoMin == NULL || archivoMax == NULL){
 // si archivoEntrada == NULL o archivoMin == NULL o archivoMax == NULL 
 // el programa imprime que no se pueden abrir los archivos y se sale
 // = NULL significa que el archivo no existe 
 	printf("No es posible abrir uno de los archivos.\n");
 	exit(1);
 }

 fscanf(archivoEntrada, "%lf %lf", &min, &max); // obtiene los primeros valores del archivo entrada
 while(!feof(archivoEntrada)){  // mientras no llegue al final del archivo hara el ciclo
 	contador++;  // suma +1 cada vez que entra al ciclo
 	push(min, &minimas); // ingresa el valor a la pila 
 	push(max, &maximas); // ingresa el valor a la pila
 	fscanf(archivoEntrada, "%lf %lf", &min, &max); // toma los valores del archivo de entrada
 }
 
 for(i=1; i<=contador; i++){ // hace el ciclo la misma cantidad de veces que hizo arriba
 	fprintf(archivoMin, "%lf\n", pop(&minimas)); // va escribiendo  los datos de la pila en el archivo
 	fprintf(archivoMax, "%lf\n", pop(&maximas));  // va escribiendo  los datos de la pila en el archivo
 }
 
 return 0;
}
