//Cesar Alejandro Velazquez Mercado
//372329
//me dice si su calificacición es suficiente 
//22/08/2023
#include <stdio.h>

int main()
{
    float promedio;
    int cali_1,cali_2,cali_3;
    printf("Dame 3 calificaciones\n\n");
    printf("Dame la primera calificación: ");
    scanf("%d",&cali_1);
    printf("Dame la Segunda calificación: ");
    scanf("%d",&cali_2);
    printf("Dame la tercera calificación: ");
    scanf("%d",&cali_3);
    promedio=(cali_1+cali_2+cali_3)/3;
    if(promedio>=70)
    {
        if(promedio>=90)
        {
            if(promedio>=90 && promedio<98)
            {
                printf("Muy bien");
            }
            else
            {
                if(promedio>=98 && promedio<=100)
                {
                    printf("Excelente");
                }
                if(promedio>100)
                {
                    printf("Error en promedio");
                }
            }
        }
        else
        {
            if(promedio>=70 && promedio<80)
            {
                printf("Regular");
            }
            if(promedio>=80 && promedio<90)
            {
                printf("Bien");
            }
        }
    }
    else
    {
        if(promedio<70 && promedio>=30)
        {
            if(promedio>=60 && promedio<70)
            {
            printf("Suficiente");
            }
            if(promedio>=30 && promedio<60)
            {
            printf("Extraordinario");
            }
        }
        if(promedio<30)
        {
            printf("Repetir");
        }
    }
}