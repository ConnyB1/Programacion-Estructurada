//Cesar Alejandro Velazquez Mercado
//372329
//Me dice monto a pagar de una llamada telefonica
//29/08/2023
#include <stdio.h>

int main()
{
    int llamada, tiempo, subtotal, iva, total;
    printf("Que tipo de llamada haras? ");
    printf("\n1) Llamada local $3.00 sin límite de tiempo");
    printf("\n2) Llamada nacional $7.00 por los 3 primeros minutos y $2.00 minuto adicional");
    printf("\n3) Llamada internacional $9.00 por los 2 primeros minutos y $4.00 minuto adicional\n\n");
    scanf("%d",&llamada);
    printf("\n\ncuanto tiempo duro la llamada? ");
    scanf("%d",&tiempo);
    if(llamada==1)
    {
        subtotal=(tiempo*3);
        iva=(subtotal*.16);
        total=(subtotal+iva);
        printf("El subtotal a pagar es: %d, iva: %d, total: %d",subtotal, iva, total);
    }
    if(llamada==2)
    {
        if(tiempo<=3)
        {
            subtotal=(tiempo*7);
            iva=(subtotal*.16);
            total=(subtotal+iva);
            printf("El subtotal a pagar es: %d, iva: %d, total: %d",subtotal, iva, total);
        }
        else
        {
            subtotal=(3*7)+((tiempo-3)*2);
            iva=(subtotal*.16);
            total=(subtotal+iva);
            printf("El subtotal a pagar es: %d, iva: %d, total: %d",subtotal, iva, total);
        }
    }
    if(llamada==3)
    {
        if(tiempo<=2)
        {
            subtotal=(tiempo*9);
            iva=(subtotal*.16);
            total=(subtotal+iva);
            printf("El subtotal a pagar es: %d, iva: %d, total: %d",subtotal, iva, total);
        }
        else
        {
            subtotal=(2*9)+((tiempo-3)*4);
            iva=(subtotal*.16);
            total=(subtotal+iva);
            printf("El subtotal a pagar es: %d, iva: %d, total: %d",subtotal, iva, total);
        }
    }
}
    