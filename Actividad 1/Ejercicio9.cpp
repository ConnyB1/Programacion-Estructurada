//Cesar Alejandro Velazquez Mercado
//372329
//me da el orden ascendente de los numeros
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
                printf("El orden es el siguiente: -> %d, %d, %d", num3, num2,num1);
            }
            else
            {
                printf("El orden es el siguiente: %d, %d, %d", num2, num3,num1);
            }
        }
        else
        {
            if(num2>num1)
            {
                printf("El orden es el siguiente: %d, %d, %d", num1, num2, num3);
            }
            else
            {
                printf("El orden es el siguiente: %d, %d, %d", num2, num1, num3);
            }
        }
    }
    else
    {
        if(num3>num2)
        {
            if(num1>num2)
            {
                printf("El orden es el siguiente: %d, %d, %d", num2, num1, num3);
            }
            else
            {
                printf("El orden es el siguiente: %d, %d, %d", num1, num2, num3);
            }
        }
        else
        {
            if(num3>num1)
            {
                printf("El orden es el siguiente: %d, %d, %d", num1, num3, num2);
            }
            else
            {
                printf("El orden es el siguiente: %d, %d, %d", num3, num1, num2);
            }
        }
    }
}