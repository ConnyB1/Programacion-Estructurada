//Cesar Alejandro Velazquez Mercado
//372329
//Me guarda loso datos de un alumno
//15/10/2023
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Funciones.h"

typedef struct _registro
{
    int status;
    int matricula;
    char ApPat[30];
    char ApMat[30];
    char Nombre[30];
    int edad;
    char sexo;
} res;


int menu();
void agregarAutomatico(res alum[], int *n);
void agregarManual(res alum[], int *n);
void eliminarRegistro(res alum[], int *n, int matricula);
char *nombres(char genero);
void buscarPorMatricula(res alum[], int n, int matricula);
void ordenarPorMatricula(res alum[], int n);
void impr_reg(res alum[], int n);
char *apellidos();

int main()
{
    res alum[500];
    srand(time(NULL));
    int op, n = 0, matricula;

    do
    {
        op = menu();
        if (op == 1)
        {
            agregarAutomatico(alum, &n);
        }
        else 
        {
            if (op == 2)
            {
                agregarManual(alum, &n);
            }
            else
            {
                if (op == 3)
                {
                    eliminarRegistro(alum, &n, matricula);
                }
                else
                {
                    if (op == 4)
                    {
                        printf("Ingrese la matricula que desea buscar: ");
                        matricula = valinum(300000, 399999);
                        buscarPorMatricula(alum, n, matricula);
                    }
                    else
                    {
                        if (op == 5)
                        {
                            ordenarPorMatricula(alum, n);
                        }
                        else
                        {
                            if (op == 6)
                            {
                                impr_reg(alum, n);
                            }
                        }
                    }
                }
            }
        }
    } while (op != 0);

    return 0;
}

int menu()
{
    int op;
    printf("\n\tMenu\n");
    printf("1.- AGREGAR (AUTOM 10 REGISTROS)\n");
    printf("2.- AGREGAR MANUAL\n");
    printf("3- ELIMINAR REGISTRO (lógico)\n");
    printf("4.- BUSCAR\n");
    printf("5- ORDENAR\n");
    printf("6.- IMPRIMIR\n");
    printf("0.- SALIR\n");
    op = valinum(0, 6);
    return op;
}
       
void agregarAutomatico(res alum[], int *n)
{
    int inicio = *n;
    for (int i = inicio; i < inicio + 10; i++)
    {
        alum[i].status = valinumran(1, 2);
        alum[i].matricula = valinumran(300000, 399999);
        alum[i].edad = valinumran(0, 120);     
        alum[i].sexo = (rand() % 2 == 0) ? 'M' : 'F';
        strcpy(alum[i].ApPat, apellidos());
        strcpy(alum[i].ApMat, apellidos());
        strcpy(alum[i].Nombre, nombres(alum[i].sexo));
    }
    *n += 10;
    int registrosAgregados = *n - inicio;
    printf("Se han agregado %d registros.\n", registrosAgregados);
}



void agregarManual(res alum[], int *n)
{
    if (*n < 500)
    {
        printf("ingrese su status 1)vivo 2)fallecido");
        alum[*n].status = valinum(1, 2);
        printf("Ingrese la matricula: ");
        alum[*n].matricula = valinum(300000, 399999);

        printf("Ingrese el apellido paterno: ");
        fgets(alum[*n].ApPat, sizeof(alum[*n].ApPat), stdin);
        alum[*n].ApPat[strcspn(alum[*n].ApPat, "\n")] = '\0'; 

        printf("Ingrese el apellido materno: ");
        fgets(alum[*n].ApMat, sizeof(alum[*n].ApMat), stdin);
        alum[*n].ApMat[strcspn(alum[*n].ApMat, "\n")] = '\0'; 

        printf("Ingrese el nombre: ");
        fgets(alum[*n].Nombre, sizeof(alum[*n].Nombre), stdin);
        alum[*n].Nombre[strcspn(alum[*n].Nombre, "\n")] = '\0'; 

        printf("Ingrese la edad: ");
        alum[*n].edad = valinum(0, 120);

        printf("Ingrese el sexo (M/F): ");
        alum[*n].sexo = getchar();
        getchar();

        (*n)++;
    }
    else
    {
        printf("El registro de alumnos esta lleno. No se pueden agregar mas.\n");
    }
}

char *nombres(char genero)
{
    char nombresMas[][30] = {
        "Juan", "Carlos", "Luis", "Segismundo", "Diego",
        "Andres", "Soponcio", "Jose", "Felipe", "Rafael",
        "Obama", "Adolfo", "Fernando", "Cipriano", "Francisco",
        "David", "Emilio", "Miguel", "Alberto", "Roberto"
    };

    char nombresFem[][30] = {
        "Maria", "Ana", "Sofia", "Laura", "Isabel",
        "Digna", "Clara", "Adriana", "Valeria", "Daniela",
        "Carolina", "Paola", "Camila", "Natalia", "Andrea",
        "Lucia", "Verónica", "Ana", "Beatriz", "Marciana"
    };

    char *nombreElegido = (char *)malloc(31);

    if (genero == 'M')
    {
        int nom = rand() % 20;
        strcpy(nombreElegido, nombresMas[nom]);
    }
    else
    {
        int nom = rand() % 20;
        strcpy(nombreElegido, nombresFem[nom]);
    }

    return nombreElegido;

}

char *apellidos()
{
    char listaApellidos[][30] = {
        "Garcia", "Martinez", "Lopez", "Rodriguez", "Perez",
        "Fernandez", "Gonzalez", "Sánchez", "Ramirez", "Torres",
        "Jimenez", "Díaz", "Vargas", "Romero", "Suarez",
        "Mendoza", "Ortega", "Hernández", "Silva", "Rojas",
        "Cruz", "Morales", "Núñez", "Guerrero", "Paredes",
        "Salazar", "Estrvez", "Figueroa", "Valencia", "Molina"
    };

    char *apellidoElegido = (char *)malloc(31); 
    int indice = rand() % 30;
    strcpy(apellidoElegido, listaApellidos[indice]);

    return apellidoElegido;
}


void eliminarRegistro(res alum[], int *n, int matricula)
{
    matricula = valinum(300000, 399999);
    int encontrado = 0; 
    printf("\ningresa la matricula que deseas borrar: ");
    
    for (int i = 0; i < *n; i++)
    {
        if (alum[i].matricula == matricula)
        {
            alum[i].status = 0; 
            printf("Registro con matricula %d eliminado de forma logica.\n", matricula);
            encontrado = 1; 
        }
    }

    if (!encontrado)
    {
        printf("No se encontro un registro con la matricula %d.\n", matricula);
    }
}


void buscarPorMatricula(res alum[], int n, int matricula)
{
    printf("\ningresa la matricula que deseas buscar: ");
    for (int i = 0; i < n; i++)
    {
        if (alum[i].matricula == matricula && alum[i].status == 1)
        {
            printf("Registro encontrado:\n");
            impr_reg(alum, n);
            return; 
        }
    }
    printf("No se encontro un registro con la matricula %d.\n", matricula);
}

void ordenarPorMatricula(res alum[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (alum[j].status == 1 && (alum[j].matricula < alum[minIndex].matricula))
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            res temp = alum[i];
            alum[i] = alum[minIndex];
            alum[minIndex] = temp;
        }
    }

    printf("Registros ordenados por matricula:\n");
    impr_reg(alum, n);
}

void impr_reg(res alum[], int n)
{
    printf("Listado de registros:\n");
    for (int i = 0; i < n; i++)
    {
        if (alum[i].status == 1)
        {
            printf("estatus: vivo");
            printf("Matricula: %d\n", alum[i].matricula);
            printf("Apellido Paterno: %s\n", alum[i].ApPat);
            printf("Apellido Materno: %s\n", alum[i].ApMat);
            printf("Nombre: %s\n", alum[i].Nombre);
            printf("Edad: %d\n", alum[i].edad);
            printf("Sexo: %c\n", alum[i].sexo);
            printf("\n");
        }
        else
        {
            printf("estatus: fallecido");
            printf("Matricula: %d\n", alum[i].matricula);
            printf("Apellido Paterno: %s\n", alum[i].ApPat);
            printf("Apellido Materno: %s\n", alum[i].ApMat);
            printf("Nombre: %s\n", alum[i].Nombre);
            printf("Edad: %d\n", alum[i].edad);
            printf("Sexo: %c\n", alum[i].sexo);
            printf("\n");
        }
    }
}