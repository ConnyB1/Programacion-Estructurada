//Cesar Alejandro Velazquez Mercado
//372329
//Es el juego de CHINCHAMPU
//29/08/2023
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int op, comp;
    srand(time(NULL));
    printf("Selecciona una opcion: ");
    printf("\n1)piedra");
    printf("\n2)papel");
    printf("\n3)tijera\n");
    scanf("%d",&op);
    comp=rand()%3 + 1;
    printf("comp dice: %d\n",comp);
    switch (op)
    {
    case 1:
        if (comp== 1)
        {
            printf("Empate");
        }
        else
        {
            if (comp == 2)
            {
                printf("Perdiste");
            }
            else
            {
                printf("Ganaste");
            }       
        }    
        break;
        case 2:
        {
           if (comp== 1)
            {
            printf("Ganaste");
            }
            else
            {
                if (comp == 2)
                {
                printf("Empate");
                }
                else
                {
                printf("Perdiste");
                }       
            }   
        }
        break;
        case 3:
        {
            if (comp== 1)
            {
            printf("Perdiste");
            }
            else
            {
                if (comp == 2)
                {
                printf("Ganaste");
                }
                else
                {
                printf("Empate");
                }       
            } 
        }
    }
    return 0;
}