#include <stdio.h>
#include <ctype.h>
#include <conio.h>
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
        num = atoi(cadena);  

        if (num < fi || num > fu)  
        {
            printf("Asegúrate de que esté en este rango (%d-%d)\n", fi, fu);  
            vali = 1;
        }
    } while (vali == 1);  

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

void leercadena(char str[], int fi) 
{
    int tecla, i = 0;
    int esp = 1;
    
    do
    {
        tecla = getch();
        tecla = toupper(tecla);

        if (i <fi - 1) 
        { 
            if (isalpha(tecla) || (tecla == 32 && esp == 0))
            {
                printf("%c", tecla);
                str[i++] = tecla;
                esp = (tecla == 32) ? 1 : 0;
            }
            if (tecla == 164) 
            {
                tecla = 165;
            }
            else 
            {
                if (tecla == 165) 
                {
                    printf("%c", tecla);
                    str[i++] = 165;
                    esp = 0;
                }
            }
        }
    }while(tecla != 13);
    str[i] = '\0';
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
