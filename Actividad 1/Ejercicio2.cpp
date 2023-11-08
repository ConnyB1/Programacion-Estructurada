//Cesar Alejandro Velazquez Mercado
//372329
//Me dice si un número es par o impar 
//22/08/2023
#include <stdio.h>

int main()
{
    int num;
    float resi;
    printf("\n\nDame un número y te dire si es par o impar: ");
    scanf("%d",&num);
    resi=num%2;
    if(resi==0)
    {
        printf("Es par");
    }
    if(resi!=0)
    {
        printf("Es impar");
    }
}