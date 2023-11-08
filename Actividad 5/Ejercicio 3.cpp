//Cesar Alejandro Velazquez Mercado
//372329
//Me pide numeros aleatorios y me dice cual es menor y cual mayor
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
    op=rand()% (200-100+1) + 100;
    return op;
}

void menu()
{
  int op, mayor=0, menor=200;
  srand(time(NULL));
  for(int i=0; i<=35; i++)
  {
    op=msges();
    if(mayor<op)
    {
        mayor=op;
    }
    else
    {
        if(op<menor)
        {
            menor=op;
        }
    }
  }
    printf("El numero mayor es: %d \n", mayor);
    printf("El numero menor es: %d \n", menor);
}
