//Cesar Alejandro Velazquez Mercado
//372329
//Me dice si aprovo o reprovo un alumno
//22/08/2023
#include <stdio.h>

int main()
{
    int cali_1,cali_2,cali_3,cali_4;
    float promedio;
    printf("Dame 4 calificaciones: ");
    scanf("%d",&cali_1);
    printf("\n\ndame 2 calificación: ");
    scanf("%d",&cali_2);
    printf("\n\ndame 3 calificación: ");
    scanf("%d",&cali_3);
    printf("\n\ndame 4 calificación: ");
    scanf("%d",&cali_4);
    promedio=(cali_1+cali_2+cali_3+cali_4)/4;
    printf("El promedio es: %f",promedio);
    if (promedio>= 70)
    {
        printf("\n\nAprovado");
    }
    if(promedio<70)
    {
        printf("\n\nReprovado");
    }
}