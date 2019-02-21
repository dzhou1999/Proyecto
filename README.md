# Proyecto
hola
adios
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main (void)
{
	int n,suma=0;
	
	printf ("introducir un numero (-1=FIN): ");
	scanf ("%d",&n);
	while (n != -1)
	{
		suma=suma + n;
		printf("Introducir un numero (-1=FIN): ");
		scanf("%d",&n);
	}
    printf("La suma vale %d \n",suma);	
	system("PAUSE");
	return 0;
}
