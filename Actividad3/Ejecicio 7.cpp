//Cesar Alejandro Velazquez Mercado
//372329
//Me dice el Horoscopo
//10/09/2023
#include <stdio.h>

void obtenerSignoHoroscopo(int mes, int dia);

int main() {
    int mes, dia;

    printf("Ingrese el mes de nacimiento (1-12): ");
    scanf("%d", &mes);

    printf("Ingrese el día de nacimiento (1-31): ");
    scanf("%d", &dia);

    obtenerSignoHoroscopo(mes, dia);

    return 0;
}

void obtenerSignoHoroscopo(int mes, int dia) 
{
    if(mes<=6)
    {
        if(mes<=3)
        {
            if(mes<=2)
            {
                if((mes==1 && dia>=20)||(mes==2 && dia<=18))
                {
                    printf("Tu horoscopo es: Acuario ");
                }
                else
                {
                    if(mes==1 && dia<=19)
                    {
                        printf("Tu horoscopo es: Capricornio ");
                    }
                    else
                    {
                        printf("Tu horoscopo es: Piscis ");
                    }
                }
            }
            else
            {
                if(mes==3 && dia>=20)
                {
                    printf("Tu horoscopo es: Piscis ");
                }
                else
                {
                    printf("Tu horoscopo es: Aries ");
                }
            }
        }
        else
        {
            if(mes<=5)
            {
                if(mes=4 && dia<=19)
                {
                    printf("Tu horoscopo es: Aries ");
                }
                else
                {
                    if((mes==4 && dia>=20)||(mes==5 && dia<=20))
                    {
                        printf("Tu horoscopo es: Tauro ");
                    }
                    else
                    {
                        printf("Tu horoscopo es: Géminis ");
                    }
                }
            }
            else
            {
                if(dia<=20)
                {
                    printf("Tu horoscopo es: Géminis ");
                }
                else
                {
                    printf("Tu horoscopo es: Cáncer ");
                }
            }
        }
    }
    else
    {
        if(mes<=9)
        {//<>
            if(mes<=8)
            {
                if((mes==7 && dia<=22))
                {
                    printf("Tu horoscopo es: Cáncer ");
                }
                else
                {
                    if((mes==7 && dia>22) || (mes==8 && dia<=22))
                    {
                        printf("Tu horoscopo es: Leo ");
                    }
                    else
                    {
                        printf("Tu horoscopo es: Virgo ");
                    }
                    
                }
            }
            else
            {
                if(mes==9 && dia<=22)
                {
                    printf("Tu horoscopo es: Virgo ");
                }
                else
                {
                    printf("Tu horoscopo es: Libra ");
                }
            }
        }
        else
        {
            if(mes<=11)
            {
                if(mes=10 && dia<=22)
                {
                    printf("Tu horoscopo es: Libra ");
                }
                else
                {
                    if((mes==10 && dia>22)||(mes==11 && dia<=21))
                    {
                        printf("Tu horoscopo es: Escorpio ");
                    }
                    else
                    {
                        printf("Tu horoscopo es: Sagitario ");
                    }
                }
            }
            else
            {
                if(mes==12 && dia<=21)
                {
                    printf("Tu horoscopo es: Sagitario ");
                }
                else
                {
                    printf("Tu horoscopo es: Capricornio ");
                }
            }
        }
    }
}
