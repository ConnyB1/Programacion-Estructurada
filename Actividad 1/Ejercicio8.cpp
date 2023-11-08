//Cesar Alejandro Velazquez Mercado
//372329
//me dice el número que es de en medio
//22/08/2023
#include <stdio.h>

int main()
{
    int num1,num2,num3;
    printf("Dame un numero entero: ");
    scanf("%d",&num1);
    printf("Dame otro numero: ");
    scanf("%d",&num2);
    printf("Dame otro numero: ");
    scanf("%d",&num3);
    if(num1>num2)
    {
        if(num1>num3)
        {
            if(num2>num3)
            {
                printf("El numero en la posicion 2 es %d y es el de en medio", num2);
            }
            else
            {
                printf("El numero en la posicion 3 es %d y es el de en medio", num3);
            }
        }
        else
        {
            if(num2>num1)
            {
                printf("El numero en la posicion 2 es %d y es el de en medio", num2);
            }
            else
            {
                printf("El numero en la posicion 1 es %d y es el de en medio", num1);
            }
        }
    }
    else
    {
        if(num3>num2)
        {
            if(num1>num2)
            {
                printf("El numero en la posicion 1 es %d y es el de en medio", num1);
            }
            else
            {
                printf("El numero en la posicion 2 es %d y es el de en medio", num2);
            }
        }
        else
        {
            if(num3>num1)
            {
                printf("El numero en la posicion 3 es %d y es el de en medio", num3);
            }
            else
            {
                printf("El numero en la posicion 1 es %d y es el de en medio", num1);
            }
        }
    }
}