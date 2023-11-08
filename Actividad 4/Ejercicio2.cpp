//Cesar Alejandro Velazquez Mercado
//372329
//Convierte unidades a otro formato diferencte
//29/08/2023
#include <stdio.h>

int main()
{
    float num1, res, op;
    printf("Dime que conversion quieres hacer: \n");
    printf("1) Cm a Pulgadas \n");
    printf("2) Cm a Pies \n");
    printf("3) Km a millas \n");
    printf("4) Pulgadas a Cm \n");
    printf("5) Pies a Cm \n");
    printf("6) Millas a Km \n");
    scanf("%f",&op);
    if(op==1)
    {
        printf("\nIntroduce el numero: ");
        scanf("%f",&num1);
        res=num1*0.393701;
        printf("El resultado es: %f",res);
    }
    else
    {
        if(op==2)
        {
            printf("\nIntroduce el numero: ");
            scanf("%f",&num1);
            res=num1*0.0328084;
            printf("El resultado es: %f",res);
        }
        else
        {
            if(op==3)
            {
                printf("\nIntroduce el numero: ");
                scanf("%f",&num1);
                res=num1*1.60934;
                printf("El resultado es: %f",res);
            }
            else
            {
                if (op==4)
                {
                    printf("\nIntroduce el numero: ");
                    scanf("%f",&num1);
                    res=num1*2.54;
                    printf("El resultado es: %f",res);
                }
                else
                {
                    if(op==5)
                    {
                        printf("\nIntroduce el numero: ");
                        scanf("%f",&num1);
                        res=num1*0.0328084;
                        printf("El resultado es: %f",res);
                    }
                    else
                    {
                        printf("\nIntroduce el numero: ");
                        scanf("%f",&num1);
                        res=num1*0.621371;
                        printf("El resultado es: %f",res);
                    }
                }
                
            }
        }
        
    }
}