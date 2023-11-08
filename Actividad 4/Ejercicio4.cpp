//Cesar Alejandro Velazquez Mercado
//372329
//Me da el salario de un trabajador
//29/08/2023
#include <stdio.h>

int main()
{
    int horas, salario, pago, salextra, saltotal;
    printf("Dime cuantas horas trabajaste esta semana: ");
    scanf("%d",&horas);
    printf("\nAhora dime tu salario por hora: ");
    scanf("%d",&salario);
    salextra=0;
    if(horas<=40)
    {
        pago=horas*salario;
        saltotal=pago+salextra;
        printf("Tu salario por hora es: %d, Horas trabajadas: %d, Salario normal: %d, Salario extra: %d y el salario total es: %d", horas,salario, pago, salextra, saltotal);
    }    
    else
    {
        if (horas>40 && horas<=49)
        {
            pago=40*salario;
            salextra=(horas-40)*(salario*2);
            saltotal=pago+salextra;
            printf("Tu salario por hora es: %d, Horas trabajadas: %d, Salario normal: %d, Salario extra: %d y el salario total es: %d", horas,salario, pago, salextra, saltotal);
        }
        else
        {
            pago=40*salario;
            salextra=(9*(salario*2))+((horas-49)*(salario*3));
            saltotal=pago+salextra;
            printf("Tu salario por hora es: %d, Horas trabajadas: %d, Salario normal: %d, Salario extra: %d y el salario total es: %d", horas,salario, pago, salextra, saltotal);
        }
        
    }
}
