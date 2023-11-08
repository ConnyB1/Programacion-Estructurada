//Cesar Alejandro Velazquez Mercado
//372329
//Me dice el genero del que contesta
//22/08/2023
#include <stdio.h>

int main()
{
    int genero;
    printf("Eres hombre o mujer? escribe \n\n");
    printf("1.- HOMBRE \n");
    printf("2.- MUJER \n");
    scanf("%d",&genero);
    if(genero==1)
    {
        printf("HOLA, ERES HOMBRE");
    }
    else
    {
        printf("HOLA, ERES MUJER");
    }
}