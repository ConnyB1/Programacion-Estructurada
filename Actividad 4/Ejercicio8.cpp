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
    if((op == 1 && comp == 3))
    {
        printf("Ganaste");
    }
    else
    {
        if((op == 2 && comp == 1))
        {
            printf("Ganaste");
        }
        else
        {
            if((op == 3 && comp == 2))
            {
                printf("Ganaste");      
            }
        }
    }
    if(op == 1 && comp == 2)
    {
        if(op == 2 && comp == 3)
        {
            printf("Perdiste");
        }
        else
        {
            if((op == 3 && comp == 1))
            {
                printf("Perdiste");
            }
        }
    }
    if(op == comp)
    {
        printf("Empate");
    }
    return 0;

}