//Cesar Alejandro Velazquez Mercado
//372329
//me dice el número que es menor
//22/08/2023
#include <stdio.h>

int main()
{
    int num1,num2,num3;
    printf("Dame un número entero: ");
    scanf("%d",&num1);
    printf("Dame otro número: ");
    scanf("%d",&num2);
    printf("Dame otro número: ");
    scanf("%d",&num3);
    if(num1>num2)
    {
        if(num1>num3)
        {
            if(num2>num3)
            {
                printf("El numero en la posición 3 es %d y es el menor", num3);
            }
            else
            {
                printf("El numero en la posición 2 es %d y es el menor", num2);
            }
        }
        else
        {
            if(num2>num1)
            {
                printf("El numero en la posición 1 es %d y es el menor", num1);
            }
            else
            {
                printf("El numero en la posición 2 es %d y es el menor", num2);
            }
        }
    }
    else
    {
        if(num3>num2)
        {
            if(num1>num2)
            {
                printf("El numero en la posición 2 es %d y es el menor", num2);
            }
            else
            {
                printf("El numero en la posición 1 es %d y es el menor", num1);
            }
        }
        else
        {
            if(num3>num1)
            {
                printf("El numero en la posición 1 es %d y es el menor", num1);
            }
            else
            {
                printf("El numero en la posición 3 es %d y es el menor", num3);
            }
        }
    }
}