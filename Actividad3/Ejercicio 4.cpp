//Cesar Alejandro Velazquez Mercado
//372329
//Me dice el numero mayor
//10/09/2023
#include <stdio.h>
#include <stdlib.h>

int menu1();
int menu2();
int menu3();
int operacion(int num1, int num2, int num3);

int main() 
{
    int num1, num2, num3;
    
    num1 = menu1();
    num2 = menu2();
    num3 = menu3();
    
    operacion(num1, num2, num3);
    
    return 0;
}

int menu1()
{
    int num1;
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    return num1;
}

int menu2()
{
    int num2;
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    return num2;
}

int menu3()
{
    int num3;
    printf("Ingrese el tercer numero: ");
    scanf("%d", &num3);
    return num3;
}

int operacion(int num1, int num2, int num3)
{
    if ((num1 > num2) && (num1 > num3))
    {
        printf("El primer numero (%d) es el mayor.\n", num1);
    }
    if ((num2 > num1) && (num2 > num3))
    {
        printf("El segundo numero (%d) es el mayor.\n", num2);
    }
    if ((num3 > num1) && (num3 > num2))
    {
        printf("El tercer numero (%d) es el mayor.\n", num3);
    }
    if((num1 == num2)|| (num2 == num3) || (num1 == num3))
    {
        printf("Los numeros son iguales.\n");
    }
    return 0;
}
