//Cesar Alejandro Velazquez Mercado
//372329
//Me genera matrices y vectores
//03/10/2023
#include "Validar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int checar();
void menu();

int main()
{
    int veri;
    srand(time(NULL));
    do
    {
    menu();  
    veri = checar(); 
    }while(veri!=0);
    
    printf("ADIOS!!!");
    return 0;
}

int checar()
{
    int op;  
    int vector1[15]; 
    int matriz[4][4]; 
    int fi, fu;  
    op = validacionNumero(0,6);
    if(op == 1)
    {
        fi=100;
        fu=200;
        llenar_V1(vector1);
    }
    if(op == 2)
    {
        llenar_matriz(matriz);
    }
    if(op == 3)
    {
        imprimirV(vector1);
    }
    if(op == 4)
    {
        
    }
    if (op == 5)
    {
       
    }
    if (op == 6)
    {
        
    }

return op;
}





void menu()
{
    printf("\n\n\tMENU \n");
    printf("1.- LLENAR VECTOR \n");
    printf("2.- LLENAR MATRIZ \n");
    printf("3.- IMPRIMIR VECTOR\n");       
    printf("4.- IMPRIMIR MATRIZ\n");
    printf("5.- ORDENAR VECTOR\n");
    printf("6.- BUSCAR VALOR EN VECTOR\n");
    printf("0.- SALIR\n\n");
    printf("\n"); 
}