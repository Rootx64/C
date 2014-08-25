/*
OPERADORES
a < b : a menor que b
a > b : a mayor que b
a <= b : a menor o igual que b
a >= b : a mayor o igual que b
a == b : a igual que b
a != b : a distinto que b
1 : Verdadero
0 : Falso
&& : and = y
|| : or = o
a++ : a=a+1
a+=b : a=a+b
a-- : a=a-1
a-=b : a=a-b
a/=b : a= a/b;

*/
#include<stdio.h>
int main(){
	int a=3,b=5,c=3,resultado;
	resultado = (a>b);
	printf("a > b resultado: %d\n",resultado);
	
	resultado = (a<b);
	printf("a < b resultado: %d\n",resultado);
	
	resultado = (a==b);
	printf("a == b resultado: %d\n",resultado);
	
	resultado = (a==c);
	printf("a == c resultado: %d\n",resultado);
	
	return 0;
}
