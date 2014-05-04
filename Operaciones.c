#include<stdio.h>

int main(){
	int var1,var2,resultado;
	var1 = 11;
	var2 = 2;
	
	//Suma
	resultado = var1+var2;
	printf("%d + %d = %d\n", var1,var2,resultado);
	
	//Resta
	resultado = var1-var2;
	printf("%d - %d = %d\n", var1,var2,resultado);
	
	//Multiplicacion
	resultado = var1*var2;
	printf("%d * %d = %d\n", var1,var2,resultado);
	
	//Division
	resultado = var1/var2;
	printf("%d / %d = %d\n", var1,var2,resultado);
	
	//Resto division
	resultado = var1%var2;
	printf("Resto de %d / %d = %d\n", var1,var2,resultado);
		
	return 0;
}
