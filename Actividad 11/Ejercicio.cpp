//Cesar Alejandro Velazquez Mercado
//372329
//Me registros de personas y muestra el curp
//01/11/2023
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include "Funciones.h"

typedef struct _curp
{
    int status;
    int matricula;
    char ApPat[30];
    char ApMat[30];
    char Nombre1[30];  
    char Nombre2[30];
    int anio[5];
    int mes[3];
    int dia[3];
    char sexo[7];
    char estado[30];
    char currp[19];
} reg;

void guardarEnArchivo(reg curp[], int n);
char calcularDiferenciadorSiglo(int anioNacimiento);
char calcularDigitoVerificador(char curp[]);
void eliminarRegistro(reg curp[], int *n, int matricula);
void buscarPorMatricula(reg curp[], int n, int matricula);
void ordenarPorMatricula(reg curp[], int n);
char *nombres(char genero);
void agregarAutomatico(reg curp[], int *n);
int esBisiesto(int anio);
void leemes(char mes[]);
void impr_reg(reg alum[], int n);
void agregarManual(reg curp[], int *n);
char segundo_char(char str[]);
void agregarAutomatico(reg curp[], int *n);
char *apellidos();
char *generarCURP(reg persona, int estadoSeleccionado, int anio, int mes, int dia);
int estaOrdenadoPorMatricula(reg curp[], int n);
void ordenarPorMatriculaSeleccion(reg curp[], int n);
void ordenarPorMatriculaBurbuja(reg curp[], int n);

int main()
{
    reg curp[2000];
    int op, n = 0, matricula;
    char op2;
                
    do
    {
        system("cls");
        printf("\n\tMenu\n");
        printf("1.- Agregar \n");
        printf("2.- Eliminar Registro\n");
        printf("3.- Buscar\n");
        printf("4.- Ordenar\n");
        printf("5.- Imprimir\n");
        printf("6.- Archivo Texto\n");
        printf("0.- Salir\n");
        op = valinum(0, 6);
        if (op == 1)
        {
            do
            {
                system("cls");
                printf("a) Manual (1)\n");
                printf("b) Automatico (100)\n");
                printf("c) Regresar ");
                op2 = getch();
                op2 = tolower(op2);
                if (isalpha(op2))
                {
                    printf("%c", op2);
                }
                printf("\n\n");
                if (op2 == 'a')
                {
                                
                    agregarManual(curp, &n);
                    printf("\n\n");
                    system("pause");
                }
                else
                {
                    if (op2 == 'b')
                    {
                        agregarAutomatico(curp, &n);
                        printf("\n\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        if (op2 == 'c')
                        {
                            printf("\n\n");
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            printf("introduce un valor valido\n\n");
                        }
                                    
                    }
                                
                }
                            

            } while (op2 != 'c');
                        
        }
        else
        {
            if (op == 2)
            {
                printf("\ningresa la matricula que deseas borrar: ");
                matricula = valinum(300000, 399999);
                eliminarRegistro(curp, &n, matricula);
                printf("\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                if (op == 3)
                {
                    printf("Ingrese la matricula que desea buscar: ");
                    matricula = valinum(300000, 399999);
                    buscarPorMatricula(curp, n, matricula);
                    printf("\n\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    if (op == 4)
                    {
                        ordenarPorMatricula(curp, n);
                        printf("\n\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        if (op == 5)
                        {
                            impr_reg(curp, n);
                            printf("\n\n");
                            system("pause");
                            system("cls");
                            
                        }
                        else
                        {
                            if (op == 6)
                            {
                                guardarEnArchivo(curp, n);
                                printf("\n\n");
                                system("pause");
                                system("cls");
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
            
        }
                    
    } while (op != 0);
}

void agregarManual(reg curp[], int *n)
{
    
    if (*n < 2000)
    {
        curp[*n].status = 1;
        printf("\n\nIngrese la matricula: ");
        curp[*n].matricula = valinum(300000, 399999);

        printf("\n\nIngrese el apellido paterno: ");
        leercadena(curp[*n].ApPat, sizeof(curp[*n].ApPat));

        printf("\n\nIngrese el apellido materno: ");
        leercadena(curp[*n].ApMat, sizeof(curp[*n].ApMat));

        printf("\n\nIngrese el primer nombre: ");
        leercadena(curp[*n].Nombre1, sizeof(curp[*n].Nombre1));

        printf("\n\ntiene otro nombre? 1)si 2)no \n");
        int num = valinum(1,2);
        if (num == 1)
        {
            printf("\n\nIngrese el segundo nombre: ");
            leercadena(curp[*n].Nombre2, sizeof(curp[*n].Nombre2));
        }
        
        printf("\n\nDame tu año de nacimiento: ");
        time_t seconds=time(NULL);
        struct tm* current_time=localtime(&seconds); 
        int check = current_time->tm_year; 
        curp[*n].anio[0] = valinum(1900, check + 1900);

        printf("Cual es tu mes de nacimiento: ");
        curp[*n].mes[0] = valinum(1, 12);

        int maxDay = (curp[*n].mes[0] == 2 && esBisiesto(curp[*n].anio[0])) ? 29 : 28;
        maxDay = (curp[*n].mes[0] == 4 || curp[*n].mes[0] == 6 || curp[*n].mes[0] == 9 || curp[*n].mes[0] == 11) ? 30 : maxDay;

        printf("Dame tu dia de nacimiento (1-%d): ", maxDay);
        curp[*n].dia[0] = valinum(1, maxDay);

        
        const char estados[32][30] = {
        "AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR", "CAMPECHE", "COAHUILA",
        "COLIMA", "CHIAPAS", "CHIHUAHUA", "CIUDAD DE MEXICO", "DURANGO",
        "GUANAJUATO", "GUERRERO", "HIDALGO", "JALISCO", "MEXICO",
        "MICHOACAN", "MORELOS", "NAYARIT", "NUEVO LEON", "OAXACA",
        "PUEBLA", "QUERETARO", "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA",
        "SONORA", "TABASCO", "TAMAULIPAS", "TLAXCALA", "VERACRUZ", "YUCATAN", "ZACATECAS"
        };

        printf("Selecciona tu estado de la lista:\n");
        for (int i = 0; i < 32; i++)
        {
                        
            printf("%d) %s\n", i + 1, estados[i]);
        }
        int estadoSeleccionado;
        printf("Ingresa el número correspondiente al estado: ");
        estadoSeleccionado = valinum(1, 32);
        strcpy(curp[*n].estado, estados[estadoSeleccionado - 1]);
        


        printf("Ingrese el sexo (M/F): ");
        char gen = tolower(getch()); 
        if (gen == 'f')
        {
            strcpy(curp[*n].sexo, "MUJER");
            printf("%s", curp[*n].sexo);
        }
        if (gen == 'm')
        {
            strcpy(curp[*n].sexo, "HOMBRE");
            printf("%s", curp[*n].sexo);
        }

        char *curpGenerado = generarCURP(curp[*n], estadoSeleccionado, curp[*n].anio[0],  curp[*n].mes[0],  curp[*n].dia[0]);
        strcpy(curp[*n].currp, curpGenerado);
        (*n)++;
    }
    else
    {
        printf("El registro de alumnos esta lleno. No se pueden agregar mas.\n");
    }
}

int esBisiesto(int anio)
{
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
    {
        return 1;
    }
    return 0;
}

char segundo_char(char str[])
{
    int t, i;
    t = strlen(str);
    i = 1;
    while(i < t)
    {
        if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') //para la consonante solo es cambiar el "or" por "and"
        {
            return str[i];
        }
        i++;
    }
    return 'X';
}


void impr_reg(reg curp[], int n) 
{
    printf("Listado de registros:\n");

    int registrosPorPagina = 40;
    int paginas = (n + registrosPorPagina - 1) / registrosPorPagina; 

    for (int pagina = 0; pagina < paginas; pagina++) 
    {
        int inicio = pagina * registrosPorPagina;
        int fin = (pagina + 1) * registrosPorPagina;
        if (fin > n) {
            fin = n;
        }

        for (int i = inicio; i < fin; i++) 
        {
            if (curp[i].status == 1) {
                printf("Matrícula: \t%d\n", curp[i].matricula);
                printf("Nombre 1: \t%s\n", curp[i].Nombre1);
                if (strlen(curp[i].Nombre2) > 0) {
                    printf("Nombre 2: \t%s\n", curp[i].Nombre2);
                }
                printf("Apellido Paterno: \t%s\n", curp[i].ApPat);
                printf("Apellido Materno: \t%s\n", curp[i].ApMat);
                printf("Fecha de nacimiento: \t%.2d-%.2d-%.4d\n", curp[i].dia[0], curp[i].mes[0], curp[i].anio[0]);
                printf("Sexo: \t%s\n", curp[i].sexo);
                printf("Estado: \t%s\n", curp[i].estado);
                printf("CURP: \t%s\n", curp[i].currp);
                printf("\n");
            }
        }

        if (pagina < paginas - 1) 
        {
            printf("Presiona Enter para continuar...");
            while (getch() != 13) {} 
        }
    }
}



void ordenarPorMatricula(reg curp[], int n)
{
    if (estaOrdenadoPorMatricula(curp, n))
    {
        printf("El arreglo ya está ordenado por matrícula. No es necesario ordenarlo de nuevo.\n");
    }
    else
    {
        int tamanio = n;

        if (tamanio <= 100)
        {
            ordenarPorMatriculaSeleccion(curp, tamanio);
            printf("El arreglo ha sido ordenado por matrícula utilizando el algoritmo de selección.\n");
        }
        else
        {
            ordenarPorMatriculaBurbuja(curp, tamanio);
            printf("El arreglo ha sido ordenado por matrícula utilizando el algoritmo de burbuja.\n");
        }
    }
}
int estaOrdenadoPorMatricula(reg curp[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (curp[i].matricula < curp[i - 1].matricula)
        {
            return 0; 
        }
    }
    return 1;
}

void ordenarPorMatriculaSeleccion(reg curp[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (curp[j].status == 1 && (curp[j].matricula < curp[minIndex].matricula))
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            reg temp = curp[i];
            curp[i] = curp[minIndex];
            curp[minIndex] = temp;
        }
    }
}

void ordenarPorMatriculaBurbuja(reg curp[], int n)
{
    int intercambio;
    for (int i = 0; i < n - 1; i++)
    {
        intercambio = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (curp[j].status == 1 && (curp[j].matricula > curp[j + 1].matricula))
            {
                reg temp = curp[j];
                curp[j] = curp[j + 1];
                curp[j + 1] = temp;
                intercambio = 1;
            }
        }
        if (intercambio == 0)
        {
            break; 
        }
    }
}

void agregarAutomatico(reg curp[], int *n)
{
    if (*n + 100 > 2000) {
        printf("No se pueden agregar 100 registros automáticamente, ya que superaría el límite de 2000 registros.\n");
        return;
    }

    for (int i = 0; i < 100; i++)
    {
        curp[i].status = 1;
        curp[i].matricula = valinumran(300000, 399999);
        char gen = (rand() % 2 == 0) ? 'M' : 'F'; 
        if (gen == 'F')
        {
            strcpy(curp[i].sexo, "MUJER");
        }
        if (gen == 'M')
        {
            strcpy(curp[i].sexo, "HOMBRE");
        }
        char *nombreGenerado = nombres(gen);
        strcpy(curp[i].Nombre1, nombreGenerado);

        int segundoNombre = rand() % 2 == 0;
        if (segundoNombre == 0)
        {
            char *nombreGenerado2 = nombres(gen);
            strcpy(curp[i].Nombre2, nombreGenerado2);
        }

        strcpy(curp[i].ApPat, apellidos());
        strcpy(curp[i].ApMat, apellidos());
        
        curp[i].anio[0] = valinumran(1900, 2023);
        curp[i].mes[0] = valinumran(1, 12);

        int maxDay = (curp[i].mes[0] == 2 && esBisiesto(curp[i].anio[0])) ? 29 : 28;
        maxDay = (curp[i].mes[0] == 4 || curp[i].mes[0] == 6 || curp[i].mes[0] == 9 || curp[i].mes[0] == 11) ? 30 : maxDay;

        curp[i].dia[0] = valinumran(1, maxDay);

        const char estados[32][30] = {
            "AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR", "CAMPECHE", "COAHUILA",
            "COLIMA", "CHIAPAS", "CHIHUAHUA", "CIUDAD DE MEXICO", "DURANGO",
            "GUANAJUATO", "GUERRERO", "HIDALGO", "JALISCO", "MEXICO",
            "MICHOACAN", "MORELOS", "NAYARIT", "NUEVO LEON", "OAXACA",
            "PUEBLA", "QUERETARO", "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA",
            "SONORA", "TABASCO", "TAMAULIPAS", "TLAXCALA", "VERACRUZ", "YUCATAN", "ZACATECAS"
        };

        int estadoSeleccionado = rand() % 32;

        strcpy(curp[i].estado, estados[estadoSeleccionado]);
        char *curpGenerado = generarCURP(curp[*n], estadoSeleccionado, curp[i].dia[0], curp[i].mes[0], curp[i].anio[0]);
        strcpy(curp[*n].currp, curpGenerado);

        (*n)++;
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

void buscarPorMatricula(reg curp[], int n, int matricula)
{
    int encontrado = 0;  
    int izquierda = 0;
    int derecha = n - 1;

    while (izquierda <= derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (curp[medio].matricula == matricula && curp[medio].status == 1)
        {
            printf("Registro encontrado:\n");
            printf("Matrícula: \t%d\n", curp[medio].matricula);
            printf("Nombre 1: \t%s\n", curp[medio].Nombre1);
            if (strlen(curp[medio].Nombre2) > 0)
            {
                printf("Nombre 2: \t%s\n", curp[medio].Nombre2);
            }
            printf("Apellido Paterno: \t%s\n", curp[medio].ApPat);
            printf("Apellido Materno: \t%s\n", curp[medio].ApMat);
            printf("Fecha de nacimiento: \t%.2d-%.2d-%.4d\n", curp[medio].dia[0], curp[medio].mes[0], curp[medio].anio[0]);
            printf("Sexo: \t%s\n", curp[medio].sexo);
            printf("Estado: \t%s\n", curp[medio].estado);
            printf("CURP: \t%s\n", curp[medio].currp);
            encontrado = 1;  
            break;
        }
        else if (curp[medio].matricula < matricula)
        {
            izquierda = medio + 1;
        }
        else
        {
            derecha = medio - 1;
        }
    }

    if (!encontrado)
    {
        printf("No se encontro un registro con la matricula %d.\n", matricula);
    }
}

void eliminarRegistro(reg curp[], int *n, int matricula)
{
    int encontrado = 0;

    for (int i = 0; i < *n; i++)
    {
        if (curp[i].matricula == matricula && curp[i].status == 1)
        {
            printf("Registro encontrado:\n");
            printf("Matrícula: \t%d\n", curp[i].matricula);
            printf("Nombre 1: \t%s\n", curp[i].Nombre1);
            if (strlen(curp[i].Nombre2) > 0)
            {
                printf("Nombre 2: \t%s\n", curp[i].Nombre2);
            }
            printf("Apellido Paterno: \t%s\n", curp[i].ApPat);
            printf("Apellido Materno: \t%s\n", curp[i].ApMat);
            printf("Fecha de nacimiento: \t%.2d-%.2d-%.4d\n", curp[i].dia[0], curp[i].mes[0], curp[i].anio[0]);
            printf("Sexo: \t%s\n", curp[i].sexo);
            printf("Estado: \t%s\n", curp[i].estado);
            printf("CURP: \t%s\n", curp[i].currp);
            printf("¿Desea eliminar este registro (s/n)? ");
            char respuesta = tolower(getch()); 
            if (respuesta == 's')
            {
                curp[i].status = 0; 
                printf("Registro con matrícula %d eliminado de forma lógica.\n", matricula);;
            }
            encontrado = 1;
            break;
        }
    }
    if (!encontrado)
    {
        printf("No se encontró un registro activo con la matrícula %d.\n", matricula);
    }
}

char *generarCURP(reg persona, int estadoSeleccionado, int anio, int mes, int dia)
{
    char curp[19];
    curp[0] = toupper(persona.ApPat[0]);
    curp[1] = segundo_char(persona.ApPat);
    curp[2] = toupper(persona.ApMat[0]);
    curp[3] = toupper(persona.Nombre1[0]);
    sprintf(&curp[4], "%02d%02d%02d", anio % 100, mes, dia);
    curp[10] = toupper(persona.sexo[0]);

    const char estadoAbreviacion[][3] = {
        "AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DF", "DG", "GT", "GR", "HG",
        "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR",
        "TC", "TS", "TL", "VZ", "YN", "ZS"
    };
    
    strcpy(&curp[11], estadoAbreviacion[estadoSeleccionado - 1]);
    char consonantes[3] = {0};
    int ci = 0;
    for (size_t i = 1; i < strlen(persona.ApPat) && ci < 2; i++)

    {
        if (!strchr("AEIOUaeiouáéíóúÁÉÍÓÚ", persona.ApPat[i])) 
        {
            consonantes[ci] = toupper(persona.ApPat[i]);
            ci++;
        }
    }
    for (size_t i = 1; i < strlen(persona.ApMat) && ci < 2; i++) 
    {
        if (!strchr("AEIOUaeiouáéíóúÁÉÍÓÚ", persona.ApMat[i])) 
        {
            consonantes[ci] = toupper(persona.ApMat[i]);
            ci++;
        }
    }
    for (size_t i = 1; i < strlen(persona.Nombre1) && ci < 3; i++) 
    {
        if (!strchr("AEIOUaeiouáéíóúÁÉÍÓÚ", persona.Nombre1[i])) 
        {
            consonantes[ci] = toupper(persona.Nombre1[i]);
            break;
        }
    }
    curp[13] = consonantes[0];
    curp[14] = consonantes[1];
    curp[15] = consonantes[2];
    
    curp[16] = calcularDiferenciadorSiglo(anio);  
    curp[17] = calcularDigitoVerificador(curp);
    curp[18] = '\0';

    char *curpGenerado = (char *)malloc(19 * sizeof(char));
    strcpy(curpGenerado, curp);

    return curpGenerado;
}





char calcularDigitoVerificador(char curp[])
{
    const char tabla[] = "0123456789ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    const int pesos[] = { 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2 };

    int suma = 0;
    for (int i = 0; i < 17; i++)
    {
        char c = curp[i];
        int indice = 0;
        while (tabla[indice] != c)
        {
            indice++;
        }
        suma += (indice % 10) * pesos[i];
    }

    int residuo = suma % 10;
    char digitoVerificador;

    if (residuo == 0)
    {
        digitoVerificador = '0';
    }
    else
    {
        digitoVerificador = tabla[10 - residuo];
    }

    return digitoVerificador;
}

char calcularDiferenciadorSiglo(int anioNacimiento)
{
    char diferenciador;

    if (anioNacimiento >= 1900 && anioNacimiento <= 1999)
    {
        diferenciador = '0';
    }
    else if (anioNacimiento >= 2000 && anioNacimiento <= 2099)
    {
        diferenciador = 'A';
    }
    else
    {
        diferenciador = '0'; 
    }
    return diferenciador;
}

void guardarEnArchivo(reg curp[], int n) 
{
    FILE *archivo;
    archivo = fopen("C:\\Users\\costco\\Documents\\Programacion estructurada\\Actividad 11\\registros.txt", "a"); 

    if (archivo == NULL) 
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    for (int i = 0; i < n; i++) 
    {
        if (curp[i].status == 1) 
        {
            fprintf(archivo, "Matrícula: %d\n", curp[i].matricula);
            fprintf(archivo, "Nombre 1: %s\n", curp[i].Nombre1);
            if (strlen(curp[i].Nombre2) > 0) {
                fprintf(archivo, "Nombre 2: %s\n", curp[i].Nombre2);
            }
            fprintf(archivo, "Apellido Paterno: %s\n", curp[i].ApPat);
            fprintf(archivo, "Apellido Materno: %s\n", curp[i].ApMat);
            fprintf(archivo, "Fecha de nacimiento: %.2d-%.2d-%.4d\n", curp[i].dia[0], curp[i].mes[0], curp[i].anio[0]);
            fprintf(archivo, "Sexo: %s\n", curp[i].sexo);
            fprintf(archivo, "Estado: %s\n", curp[i].estado);
            fprintf(archivo, "CURP: %s\n", curp[i].currp);  // Agregado el CURP
            fprintf(archivo, "\n");
        }
    }

    fclose(archivo); 
    printf("Datos guardados en el archivo 'registros.txt'.\n");
}
