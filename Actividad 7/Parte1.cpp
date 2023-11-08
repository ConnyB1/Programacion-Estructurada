//Cesar Alejandro Velazquez Mercado
//372329
//Me despliega la cadena de diferentes formas
//25/09/2023
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void salida3(char cadena[30]);
void voltearcadena(char cadena[30]);
int contarcadena(char cadena[30]);
void inciofin(char cadena[30]);
void fininicio(char cadena[30]);
void spar(char cadena[30]);

int main() 
{
    char cadena[30];
    //strcpy(cadena,"ENSENADA");
    printf("Escribe algo: ");
    gets(cadena);
    printf("Salida 1: %s \n\n",cadena);
    system("Pause");
    printf("\n\nPresione una tecla para continuar...");
    system("CLS");

    voltearcadena(cadena);
    printf("Salida 2: %s \n\n",cadena);
    voltearcadena(cadena);

    system("Pause");
    printf("\n\nPresione una tecla para continuar...");
    system("CLS");


    //strrev(cadena); //hacer esto manual
    //strrev(cadena);
    
    fflush(stdin);
    printf("\nSalida 3: \n");
    salida3(cadena);
    
    
    voltearcadena(cadena);
    printf("\nSalida 4: \n");
    salida3(cadena);

    printf("\nSalida 5: \n");
    inciofin(cadena);

    printf("\nSalida 6: \n");
    voltearcadena(cadena);
    inciofin(cadena);

    printf("\nSalida 7: \n");
    fininicio(cadena);

    printf("\nSalida 8: \n");
    voltearcadena(cadena);
    fininicio(cadena);

    

    spar(cadena);
}
void salida3(char cadena[30])
{
    int i=0;
    char letra[3];
    while(cadena[i]!='\0')
    {
        letra[0]=cadena[i];
        printf("\n%s ",letra);
        i++;
    }
    printf("\n\n");
    system("Pause");
    printf("\n\n\n\nPresione una tecla para continuar...");
    system("CLS");
}

void voltearcadena(char cadena[30])
{
    int n,j;
    
    n=contarcadena(cadena);
    char tabulador[n+1];
    j=n-1;
    for (int z = 0; z <= n; z++)
    {
            tabulador[z]=cadena[z];
    }
    for (int i = 0; i < n; i++)
    {
        cadena[i]=tabulador[j];
        j--;
    }
}

int contarcadena(char cadena[30])
{
    int n=0;
    while(cadena[n]!='\0')
    {
        n++;
    }
    return n;
}   

void inciofin(char cadena[30])
{
    int n;
    n=contarcadena(cadena);
    
    for (int i = n; i >= 0; i--)
    {
        for (int z = 0; z< i; z++)
        {
            printf("%c", cadena[z]);
        }
        printf("\n");
    }
    printf("\n\n");
    system("Pause");
    printf("\n\n\n\nPresione una tecla para continuar...");
    system("CLS");
}

void fininicio(char cadena[30])
{
    int n;
    n=contarcadena(cadena);
    for (int i = 0; i < n; i++)
    {
        for (int z = i; z< n; z++)
        {
            printf("%c", cadena[z]);
        }
        printf("\n");
    }
    printf("\n\n");
    system("Pause");
    printf("\n\n\n\nPresione una tecla para continuar...");
    system("CLS");
}

void spar(char cadena[30])
{
    int n, j=0, k=0;
    n=contarcadena(cadena);
    char vocales[n], no_vocales[n];;
    printf("Salida 9: \n");
    for (int i = 0; i < n; i++) 
    {
        char caracter = cadena[i];
        if (caracter >= 'a') 
        {
            if (caracter <= 'z')
            {
                caracter = caracter - 32;
            }
        }

        if (caracter == 'A')
        {
            vocales[j++] = caracter;
        } 
        else
        {
            if (caracter == 'E')
            {
                vocales[j++] = caracter;
            }
            else
            {
                if (caracter == 'I')
                {
                    vocales[j++] = caracter;
                }
                else
                {
                    if (caracter == 'O')
                    {
                        vocales[j++] = caracter;
                    }
                    else
                    {
                        if (caracter == 'U')
                        {
                            vocales[j++] = caracter;
                        }
                    }
                }
            }
        }
        if (caracter>= 'A')
        {
            if (caracter <= 'Z')
            {
                if (caracter != 'A')
                {
                    if (caracter != 'E')
                    {
                        if (caracter != 'I')
                        {
                            if (caracter != 'O')
                            {
                                if (caracter != 'U')
                                {
                                    no_vocales[k++] = caracter;
                                }
                            }
                        }
                    }
                }
                
                
            }
        }
        
    }
    vocales[j] = '\0';
    no_vocales[k] = '\0';
    printf("Vocales: %s\n", vocales);
    printf("Consonantes: %s\n", no_vocales);
}