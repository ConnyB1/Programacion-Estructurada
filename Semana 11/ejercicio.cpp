#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

void readtxtfile();
void createtxtfile();
void preguntatxtfile(void);

int main()
{
    int op;
    do
    {

        printf("que quieres hacer: 1)imprimir bonito 2)crear archivo con nombre 3) preguntas 0)salir");
        op=valinum(0, 3); 
        if (op==1)
        {
            readtxtfile();
        }
        else
        {
            if (op==2)
            {
                createtxtfile();
            }
            else
            {
                if (op==3)
                {
                    preguntatxtfile();
                }
                
            }
            
        }
        
    } while (op!=0);
    
    printf("Adios \n");
    return 0;
}

void readtxtfile(void)
{
    FILE    *archivo;
    char caracter;
    archivo = fopen ("C:\\Users\\costco\\Documents\\Programacion estructurada\\Semana 11\\cancion.txt","r"); //r de lectura
    if (archivo)
    {
        do
        {
            caracter = fgetc(archivo);
            printf("%c", caracter);
        } while (!feof(archivo)); //feof busca el final del archivo
        fclose(archivo);
    }
    
}

void createtxtfile(void)
{
    FILE    *archivo;
    archivo = fopen ("C:\\Users\\costco\\Documents\\Programacion estructurada\\Semana 11\\crear.txt","a"); //la "a" va a crear
    fprintf(archivo,"Alejandro Vela  300   \n\n");

    fclose(archivo);
    
}
void preguntatxtfile(void)
{
    FILE    *archivo;
    char nom[30], appe[30], edad[30], ciudad[30];

    archivo = fopen ("C:\\Users\\costco\\Documents\\Programacion estructurada\\Semana 11\\crearcadena.txt","a"); //la "a" va a crear
    printf("dame tu nombre: ");
    gets(nom);
    printf("dame tu apellido: ");
    gets(appe);
    printf("dame tu edad: ");
    gets(edad);
    printf("dame tu ciudad: ");
    gets(ciudad);
    fprintf(archivo,"%s %s %s %s  \n\n", nom, appe, edad, ciudad);

    fclose(archivo);
    
}