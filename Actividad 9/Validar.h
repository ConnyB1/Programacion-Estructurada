#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int llenar_V1(int Vector1[15]);
int llenar_matriz(int matriz[4][4]); 
void imprimirV(int vector1[15]);
int validacionNumero(int fi, int fu)  
{
    int numero, valido;  
    char cadena[100]; 
    do{
        valido=0;  
        fflush(stdin);  
        gets(cadena);   
        numero= atoi(cadena);  //lo convierte
        if(numero < fi || numero > fu)  
        {
            printf("el numero debe estar dentro de este rango (%d-%d)\n", fi, fu);  
            printf("por favor, introduce otro numero\n");
            valido=1;
        }

    }while(valido==1);  
    return numero; 
}

int llenar_V1(int vector1[15])
{
    int num, tab;
    for (int j = 0; j < 15; j++)
    {
        do
        {
            num=rand()%101 +100;
            for (int i = 0; i < 15; i++)
            {
                if (num != vector1[i])
                {
                    tab=1;
                }
                else
                {
                    tab=0;
                }
            }
        } while (tab!=1);
        vector1[j]=num;
    }
    return vector1[15];
} 

int llenar_matriz(int matriz[4][4])
{
    int n = 0, p = 0;
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            do
            {
                p=rand()%16 + 1;
                for (int j = 0; j < 4; j++)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if (p == matriz[j][i])
                        {
                            n=1;
                        }
                        else
                        {
                            n=0;
                        }
                        
                    }
                }
            } while (n != 0);
            matriz[j][i] = p;
        }
    }
    return matriz[4][4];
}

void imprimirV(int vector1[15]) 
{
    printf("Imprimiendo vector 1...\n\n");
    for (int i = 0; i < 15; i++) 
    {
        printf("%d, ", vector1[i]);
    }
    printf("\n");
}