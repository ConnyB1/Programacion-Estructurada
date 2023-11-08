//Cesar Alejandro Velazquez Mercado
//372329
//Me dice cual es el mayor
//29/08/2023
#include <stdio.h>

int main()
{
    int num1, num2, num3, num4, num5, num6, mayor;
    printf("Dame un numero: ");
    scanf("%d",&num1);
    printf("\nDame otro numero: ");
    scanf("%d",&num2);
    printf("\nDame otro numero: ");
    scanf("%d",&num3);
    printf("\nDame otro numero: ");
    scanf("%d",&num4);
    printf("\nDame otro numero: ");
    scanf("%d",&num5);
    printf("\nDame otro numero: ");
    scanf("%d",&num6);
    mayor=num1;
    if(num2>mayor)
    {
        mayor=num2;
    }
    if(num3>mayor)
    {
        mayor=num3;
    }
    if(num4>mayor)
    {
        mayor=num4;
    }
    if(num5>mayor)
    {
        mayor=num5;
    }
    if(num6>mayor)
    {
        mayor=num6;
    }
    printf("El mayor es: %d",mayor);
}