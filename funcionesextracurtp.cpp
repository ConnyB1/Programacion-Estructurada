#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h> 
#include <string.h>

/*
    getch ← lee caracter por caracter y lo transforma a codigo ascii
    isalpha ← revisa si la letra es minuscula o mayuscula
    isalnum ← revisa letras y numeros
    idigit ← revisa numeros
    https://www.programiz.com/c-programming/library-function/ctype.h/iscntrl
*/

void leercadena(char str [], char msge[])
{
    int tecla, i, esp = 1;
    i = 0;
    do
    {
	    tecla = getch();
        tecla = toupper(tecla);
        if (isalpha(tecla))
        {
		    printf("%c", tecla);
		    str[i++] = tecla;
            esp = 0;
        }
        else
        {
            if(tecla == 32 && esp == 0)
            {
                printf("%c", tecla);
                str[i++] = tecla;
                esp = 0;
            }
            else
            {
                if(tecla == 164)
                {
                    tecla = 165;
                }
                if(tecla == 165)
                {
                    printf("%c",tecla);
                    str[i++] = 165;
                } 
                //validar que no termine en espacio
            }
        }
    }while(tecla != 13);
    str[i]='\0';
}

void leenum(char str[], char msge[], int ri, int rf, int dig)
{
    int tecla, i;
    printf("%s", msge);
    do
    {
        tecla = getch();
        if (isdigit(tecla))
        {
            str[i++] = tecla;
            printf("%c", tecla);
        }
    }while(dig != i);
}

void leemes(char mes[])
{
    int dia[13] = {0, 31, 28, 31, 30, 31, 30, 31,31,30,31,30,31};
    valinum(1, dia,[atoi(mes)]);
    //validar años biciestos
}

void leeedo(char str[])
{
    char edos[34][3] = {"NULL","AG", "BC","...","NF"};
    char op[3];
    atoi(leenum(op,"edo? ",1, 32));
    strcpy(str, edos[atoi(op)]);

    
}

tdato gencurp (tdato r)
{
    tdato reg;
    reg = r;
    reg.curp[1] = reg.app[0];
    reg.curp[2] = segundo_char(r.app);
    reg.curp[3] = reg.appmat[0];
    reg.curp[4] = '\0';
    reg.curp[4] = palinc(re.curp);
}

char segundo_char(char str[])
{
    int t;
    t = strlen(str);
    i = 1;
    while(i < t)
    {
        if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') //para la consonante solo es cambiar el "or" por "and"
        {
            return str[i];
        }
    }
    return 'X';
}
/*
EJEMPLO 

struct 
{
    char appat[10];
    char appmat[10];
    char nom[10];

    char anio[5];
    char mes[3];
    char dia[3];

    char curp[19];
}tdato

tdato reg;

leercadena(reg.appat, "Apellido paterno: ");
leercadena(reg.appmaat, "Apellido materno: ");
leercadena(reg.nom, "Nombre: ");
leernum(reg.anio,"anio[AAAA]",1900, 2023, 4);


EXTRA -> usar localtime() 
*/

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
void leercadena(char str [])
{
    int tecla, i, esp = 1;
    i = 0;
    do
    {
	    tecla = getch();
        tecla = toupper(tecla);
        if (isalpha(tecla))
        {
		    printf("%c", tecla);
		    str[i++] = tecla;
            esp = 0;
        }
        else
        {
            if(tecla == 32 && esp == 0)
            {
                printf("%c", tecla);
                str[i++] = tecla;
                esp = 0;
            }
            else
            {
                if(tecla == 164)
                {
                    tecla = 165;
                }
                if(tecla == 165)
                {
                    printf("%c",tecla);
                    str[i++] = 165;
                } 
                //validar que no termine en espacio
            }
        }
    }while(tecla != 13);
    str[i]='\0';
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