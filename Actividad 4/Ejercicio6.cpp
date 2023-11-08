//Cesar Alejandro Velazquez Mercado
//372329
//Me da el total a pagar de  agua
//29/08/2023
#include <stdio.h>

int main()
{
    int m3, tpago, iva, total;
    printf("Cuantos m3 de agua se consumieron: ");
    scanf("%d",&m3);
    if(m3<=4)
    {
        tpago=m3*50;
        iva=(tpago*.16);
        total=tpago+iva;
        printf("SubTotal: %d, Iva(16%): %d, Total: %d", tpago,iva,total);
    }
    else
    {
        if(m3<=15)
        {
            tpago=(4*50)+((m3-4)*8);
            iva=(tpago*.16);
            total=tpago+iva;
            printf("SubTotal: %d, Iva(16%): %d, Total: %d", tpago,iva,total);
        }
        else
        {
            if(m3<=50)
            {
                tpago=(4*50)+((m3-4)*8)+((m3-15)*10);
                iva=(tpago*.16);
                total=tpago+iva;
                printf("SubTotal: %d, Iva(16%): %d, Total: %d", tpago,iva,total);
            }
            else
            {
                tpago=(4*50)+((m3-4)*8)+((m3-15)*10)+((m3-50)*11);
                iva=(tpago*.16);
                total=tpago+iva;
                printf("SubTotal: %d, Iva(16%): %d, Total: %d", tpago,iva,total);
            }
        }
    }
}