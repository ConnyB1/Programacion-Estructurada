//Cesar Alejandro Velazquez Mercado
//372329
//me da el salario de un trabajador
//22/08/2023
#include <stdio.h>

int main()
{
    int horasT, dinero, pago;
    printf("Dame las horas trabajadas: ");
    scanf("%d",&horasT);
    printf("Dame el salario por hora: ");
    scanf("%d",&dinero);
    if(horasT<=40)
    {
         pago=horasT*dinero;
         printf("Su Salario por hora es: %d, las horas trabajadas fueron: %d y su salario total es: %d ", dinero, horasT, pago);
    }
    else
    {
        if(horasT>40 && horasT<=49)
        {
            int salextra, saltotal;
            pago=40*dinero;
            salextra=((dinero*2)*(horasT-40));
            saltotal=salextra+pago;
            printf("Su Salario por hora es: %d, las horas trabajadas fueron: %d, su salario normal es: %d, su salario extra es: %d y su salario total es: %d ", dinero, horasT, pago, salextra, saltotal);
        }
        else
        {
            int salextra, saltotal;
            pago=40*dinero;
            salextra=((9*dinero)*2+(((horasT-49)*dinero)*3));
            saltotal=salextra+pago;
            printf("Su Salario por hora es: %d, las horas trabajadas fueron: %d, su salario normal es: %d, su salario extra es: %d y su salario total es: %d ", dinero, horasT, pago, salextra, saltotal);
        }
    }
}