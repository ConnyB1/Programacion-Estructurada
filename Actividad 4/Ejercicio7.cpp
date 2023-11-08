//Cesar Alejandro Velazquez Mercado
//372329
//Me el promedio de un alumno sin considerar su calificacion mas baja
//29/08/2023
#include <stdio.h>

int main()
{
    int cal1, cal2, cal3, cal4, cal5, pivote, promedio;
    printf("Dame la calificacion de tus examenes: ");
    scanf("%d",&cal1);
    printf("\nDame otra calificacion: ");
    scanf("%d",&cal2);
    printf("\nDame otra calificacion: ");
    scanf("%d",&cal3);
    printf("\nDame otra calificacion: ");
    scanf("%d",&cal4);
    printf("\nDame otra calificacion: ");
    scanf("%d",&cal5);
    pivote=cal1;
    if(pivote>=cal2)
    {
        pivote=cal2;
    }
    if(pivote>=cal3)
    {
        pivote=cal3;
    }
    if(pivote>=cal4)
    {
        pivote=cal4;
    }
    if(pivote>=cal5)
    {
        pivote=cal5;
    }
    promedio=((cal1+cal2+cal3+cal4+cal5)-pivote)/4;
    printf("El promedio del examen es: %d", promedio);
}