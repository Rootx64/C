#include<stdio.h>

int global = 1;

int main(){
	int local = 0;
	
	printf("Local = %d, global = %d", local,global);
	
	return 0;
}
