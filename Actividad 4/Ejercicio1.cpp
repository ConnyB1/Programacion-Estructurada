//Cesar Alejandro Velazquez Mercado
//372329
//Me da un menú para sumar,restar,multiplicar y dividir
//29/08/2023
#include <stdio.h>

int main()
{
    int num1, num2, op, res;
    printf("Dime que operación quieres hacer: \n");
    printf("1) Suma \n");
    printf("2) Resta \n");
    printf("3) Multiplicación \n");
    printf("4) División \n");
    scanf("%d",&op);
    if(op==1)
    {
        printf("\nIntroduce el primer numero: ");
        scanf("%d",&num1);
        printf("\nIntroduce el segundo numero: ");
        scanf("%d",&num2);
        res=num1+num2;
        printf("El resultado es: %d",res);
    }
    else
    {
        if(op==2)
        {
            printf("\nIntroduce el primer numero: ");
            scanf("%d",&num1);
            printf("\nIntroduce el segundo numero: ");
            scanf("%d",&num2);
            res=num1-num2;
            printf("El resultado es: %d",res);
        }
        else
        {
            if(op==3)
            {
                printf("\nIntroduce el primer numero: ");
                scanf("%d",&num1);
                printf("\nIntroduce el segundo numero: ");
                scanf("%d",&num2);
                res=num1*num2;
                printf("El resultado es: %d",res);
            }
            else
            {
                printf("\nIntroduce el primer numero: ");
                scanf("%d",&num1);
                printf("\nIntroduce el segundo numero: ");
                scanf("%d",&num2);
                res=num1/num2;
                printf("El resultado es: %d",res);
            }
        }
        
    }
}