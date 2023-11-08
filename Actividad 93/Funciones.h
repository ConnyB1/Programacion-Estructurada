#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int valinum(int fi, int fu)  
{
    int num, vali;  
    char cadena[100]; 
    do {
        vali = 0;  
        fgets(cadena, sizeof(cadena), stdin);
        num = atoi(cadena);  

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

int esCadenaValida(const char *cadena) {
    int i = 0;

    while (cadena[i] != '\0') 
    {
        char caracter = cadena[i];

        if (caracter >= 'A' && caracter <= 'Z' ) 
        {
            if (caracter >= '0' && caracter <= '9')
            {
                return 0; 
            }
        }
        i++;
    }

    return 1; 
}
void convertirAMayusculas(char *cadena) {
    int i = 0;
    while (cadena[i] != '\0') {
        if (islower(cadena[i])) {
            cadena[i] = toupper(cadena[i]);
        }
        i++;
    }
}

bool esConsonante(char c) 
{
    char consonantes[] = "BCDFGHJKLMNPQRSTVWXYZ";
    c = toupper(c);
    return strchr(consonantes, c) != NULL;
}