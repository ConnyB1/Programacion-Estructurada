#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int valinum(int fi, int fu)  
{
    int num, vali;  
    char cadena[100]; 
    do {
        vali = 0;  
        fgets(cadena, sizeof(cadena), stdin);
        num = atoi(cadena);  // Lo convierte

        if (num < fi || num > fu)  
        {
            printf("Asegúrate de que esté en este rango (%d-%d)\n", fi, fu);  
            vali = 1;
        }
    } while (vali == 1);  

    return num; 
}

int valinumran(int fi, int fu)  
{
    int num;  
    int valido = 0;
    do 
    {
        num = rand() % (fu - fi + 1) + fi;
        if (num >= fi && num <= fu) 
        {
            valido = 1;
        }
    } while (!valido);

    return num; 
}

