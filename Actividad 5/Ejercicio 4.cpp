//Cesar Alejandro Velazquez Mercado
//372329
//Me dice la tabla de multiplicar de un numero del 1 al 20
//10/09/2023
#include <stdio.h>
#include <stdlib.h>
#define N 10
int msges();
void menu();
int main()
{
   menu();

	return 0;
}
int msges()
{ int op;
    regreso:
    printf (" DAME UN NUMERO DEL 1 AL 20: ");
    scanf ("%d",&op);
    if(op<=1 || op>=20)
    {
        printf("Numero incorrecto \n");
        goto regreso; //Sirve para regresarnos al punto previamente marcado
    }

  return op;
}

void menu()
{
    int op, res;
    op=msges();
    for(int i=1; i<=10; i++)
    {
        res=op*i;
        printf("%d\t*\t%d\t=\t%d\n", op, i, res);
    }

}