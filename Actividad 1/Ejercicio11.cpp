//Cesar Alejandro Velazquez Mercado
//372329
//me da el orden ascendente de los numeros
//22/08/2023
#include <stdio.h>

int main()
{
    int minutos, Tllamada, coste; 
    float iva, total;
    printf("Cuanto duro la llamada: ");
    scanf("%d",&minutos);
    printf("Que tipo de llamada fue 1)Local, 2)Nacional, 3)Internacional: ");
    scanf("%d",&Tllamada);
    switch (Tllamada)
    {
        case 1:
        {
        coste=minutos*3;
        iva=(coste*.16);
        total=coste+iva;
        printf("El subtotal es: %d, el iva fue de: %f y el total es: %f ", coste, iva, total);
        }
        break;
        case 2:
        {
            if (minutos<=3)
            {
                coste=minutos*7;
            }
            else
            {
                coste=(3*7)+((minutos-3)*2);
                iva=(coste*.16);
                total=coste+iva;
                printf("El subtotal es: %d, el iva fue de: %f y el total es: %f ", coste, iva, total);
            }
        }
        break;
        case 3:
        {
            coste=(2*9)+((minutos-2)*4);
            iva=(coste*.16);
            total=coste+iva;
            printf("El subtotal es: %d, el iva fue de: %f y el total es: %f ", coste, iva, total);
        }
    }

    
}