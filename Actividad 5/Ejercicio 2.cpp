//Cesar Alejandro Velazquez Mercado
//372329
//Me da 200 numeros aleatorios y me dice cuantos par e impar hay
//10/09/2023
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int msges();
void menu();
int main()
{
   menu();

	return 0;
}
int msges()
{ 
    int op;
    op=rand()%200;
    return op;
}

void menu()
{
  int op, test, par=0, impar=0;
  srand(time(NULL));
  for(int i=0; i<=200; i++)
  {
    op=msges();
    test=op%2;
    if(test==0)
    {
        printf("%d Es par \n", op);
        par=par+1;
    }
    else
    {
        printf("%d Es impar \n", op);
        impar=impar+1;
    }
  }
    printf("Los cantidad de numeros pares es: %d \n", par);
    printf("Los cantidad de numeros impares es: %d \n", impar);
}
