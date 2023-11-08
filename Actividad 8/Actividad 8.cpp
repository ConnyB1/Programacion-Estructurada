//Cesar Alejandro Velazquez Mercado
//372329
//Me despliega arreglos y matrices
//02/10/2023
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int llenar_v1(int vector1[10]);
int llenar_V2(int vector2[10]);
int llenar_V3(int vector1[10], int vector2[10], int vector3[20]);
void imprimirV(int vector1[10], int vector2[10], int vector3[20]);
int llenar_matriz(int vector1[10], int vector2[10], int matriz[4][4]);
void imprimir_matriz(int matriz[4][4]);

int main()
{
    int vector1[10], vector2[10], vector3[20], matriz[4][4], op;

    do
    {
        printf("\tMENU \n");
        printf("1.- LLENAR VECTOR 1 (MANUALMENTE) \n");
        printf("2.- LLENAR VECTOR 2 ALEATORIAMENTE\n");
        printf("3.- LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2)\n");
        printf("4.- IMPRIMIR VECTORES\n");
        printf("5.- LLENA MATRIZ 4 X 4\n");
        printf("6.- IMPRIMIR MATRIZ\n");
        printf("0.- SALIR\n\n");
        scanf("%d",&op);
        printf("\n");

        if(op == 1)
        {
            llenar_v1(vector1);
        }
        if(op == 2)
        {
            llenar_V2(vector2);
        }
        if(op == 3)
        {
            llenar_V3(vector1,vector2,vector3);
        }
        if(op == 4)
        {
            imprimirV(vector1,vector2,vector3);
        }
        if (op == 5)
        {
            llenar_matriz(vector1, vector2, matriz);
        }
        if (op == 6)
        {
            imprimir_matriz(matriz);
        }
        
        
    }while(op!=0);
    
    printf("ADIOS!!!");
    return 0;
}

int llenar_v1(int vector1[10])
{
    int llenar, comp;
    printf("llena el vector con 10 espacios : ");
    printf("NOTA: deben de ser numeros del 30 al 70\n\n");
    for(int i=0; i<10;i++)
    {   
        printf("dame tu numero %d: ", i+1);
        
        do
        {
            scanf("%d",&llenar);
            if (llenar>=30)
            {
                if (llenar<=70)
                {   
                    comp=1;
                }
                else
                {
                    comp=0;
                    printf("por favor elige un numero valido: ");
                } 
            }
            else
            {
                comp=0;
                printf("por favor elige un numero valido: ");
            }

        } while (comp!=1);
        vector1[i]=llenar;
    }
    printf("\n\n");
    system("Pause");
    printf("\n\n\n\nPresione una tecla para continuar...");
    system("CLS");
    return vector1[10];
}

int llenar_V2(int vector2[10])
{
    srand(time(NULL));
    int num, tab;
    printf("llenando...");
    system("Pause");
    printf("\n\n\n\nPresione una tecla para continuar...");
    system("CLS");
    for (int j = 0; j < 10; j++)
    {
        do
        {
            num=rand()%20 +1;
            for (int i = 0; i < 10; i++)
            {
                if (num != vector2[i])
                {
                    tab=1;
                }
                else
                {
                    tab=0;
                }
            }
        } while (tab!=1);
        vector2[j]=num;
    }
    printf("Se lleno exitosamente!!! \n\n");
    system("Pause");
    printf("\n\n\n\nPresione una tecla para continuar...");
    system("CLS");
    return vector2[10];
} 

int llenar_V3(int vector1[10], int vector2[10], int vector3[20])
{
    for (int i = 0; i < 10; i++)
    {
        vector3[i]=vector1[i];
        vector3[i+10]=vector2[i];
    }
    printf("listo!!! \n\n\n");
    system("Pause");
    printf("\n\n\n\nPresione una tecla para continuar...");
    system("CLS");
    return vector3[20];
}


void imprimirV(int vector1[10], int vector2[10], int vector3[20])
{
    printf("Imprimiendo vector 1... \n\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d, ",vector1[i]);
    }

    system("Pause");
    printf("\n\n\n\nPresione una tecla para continuar...");
    system("CLS");

    printf("Imprimiendo vector 2... \n\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d, ",vector2[i]);
    }

    system("Pause");
    printf("\n\n\n\nPresione una tecla para continuar...");
    system("CLS");
    
    printf("Imprimiendo vector 3... \n\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%d, ",vector3[i]);
    }
    printf("\n\n");
    system("Pause");
    printf("\n\n\n\nPresione una tecla para continuar...");
    system("CLS");
}

int llenar_matriz(int vector1[10], int vector2[10], int matriz[4][4])
{
    system("CLS");
    int n = 0, p = 0;
    printf("llenando...\n\n");
    system("Pause");
    printf("\n\n\n\nPresione una tecla para continuar...");
    system("CLS");
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (n < 9)
            {
                matriz[j][i] = vector1[n];
                n++;
            }
            else
            {
                matriz[j][i] = vector2[p];
                p++;
            }
        }
    }
    printf("Se lleno exitosamente!!! \n\n");
    system("Pause");
    printf("\n\n\n\nPresione una tecla para continuar...");
    system("CLS");
    return matriz[4][4];
}

void imprimir_matriz(int matriz[4][4])
{
    system("CLS");
    printf("MATRIZ: \n\n");
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            printf("%d\t",matriz[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    system("Pause");
    printf("\n\n\n\nPresione una tecla para continuar...");
    system("CLS");
}