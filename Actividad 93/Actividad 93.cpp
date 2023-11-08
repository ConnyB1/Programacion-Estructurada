//Cesar Alejandro Velazquez Mercado
//372329
//Me genera un curp
//15/10/2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include "Funciones.h"


int limpiarBuffer();
char calcularPrimeraLetra(const char ApPat[]);
bool esPalabraMalsonante(const char curp[]);
char calcularDiferenciadorSiglo(int anioNacimiento);
bool esConsonante(char c);
void obtenerConsonantes(const char cadena[], char consonantesEncontradas[], int longitud);
char calcularDigitoVerificador(const char curp[]);
void generarCURP(char curp[]);
char obtenerPrimerCaracterDespuesDelEspacio(const char cadena[]);

int main()
{
    srand(time(NULL));
    int op;
    char curp[19] = "";

    do
    {
        printf("Proporciona los siguientes datos para obtener el CURP: \n");
        generarCURP(curp);
        printf("¿Deseas calcular otro CURP? 1) Sí, 2) No\n");
        op = valinum(1, 2);
    } while (op != 2);
    return 0;
}
void generarCURP(char curp[])
{
    char ApPat[30] = "", ApMat[30] = "", Nombre[30] = "";
    int año, mes, dia;
    char meses[3], dias[3], sexo;
    
    printf("Ingrese el apellido paterno: ");
    fgets(ApPat, sizeof(ApPat), stdin);
    ApPat[strcspn(ApPat, "\n")] = '\0'; 
    strupr(ApPat);  

    printf("Ingrese el apellido materno: ");
    fgets(ApMat, sizeof(ApMat), stdin);
    ApMat[strcspn(ApMat, "\n")] = '\0';  
    strupr(ApMat);  

    printf("Ingrese el nombre: ");
    fgets(Nombre, sizeof(Nombre), stdin);
    Nombre[strcspn(Nombre, "\n")] = '\0';  
    strupr(Nombre);  

    char ApPatCopia[30];
    char ApMatCopia[30];
    char NombreCopia[30];
    
    strcpy(ApPatCopia, ApPat);
    strcpy(ApMatCopia, ApMat);
    strcpy(NombreCopia, Nombre);

    for (int i = 0; ApPat[i] != '\0'; i++)
    {
        if (strchr(".-/'", ApPat[i]) != NULL)
        {
            ApPat[i] = ' ';
        }
    }
    for (int i = 0; ApMat[i] != '\0'; i++)
    {
        if (strchr(".-/'", ApMat[i]) != NULL)
        {
            ApMat[i] = ' ';
        }
    }
    for (int i = 0; Nombre[i] != '\0'; i++)
    {
        if (strchr(".-/'", Nombre[i]) != NULL)
        {
            Nombre[i] = ' ';
        }
    }

    int length = strlen(ApPat);
    for (int i = 0; i < length; i++)
    {
        if (ApPat[i] == ' ' && ApPat[i + 1] == ' ')
        {
            for (int j = i; j < length; j++)
            {
                ApPat[j] = ApPat[j + 1];
            }
            length--;
            i--;
        }
    }

    length = strlen(ApMat);
    for (int i = 0; i < length; i++)
    {
        if (ApMat[i] == ' ' && ApMat[i + 1] == ' ')
        {
            for (int j = i; j < length; j++)
            {
                ApMat[j] = ApMat[j + 1];
            }
            length--;
            i--;
        }
    }

    length = strlen(Nombre);
    for (int i = 0; i < length; i++)
    {
        if (Nombre[i] == ' ' && Nombre[i + 1] == ' ')
        {
            for (int j = i; j < length; j++)
            {
                Nombre[j] = Nombre[j + 1];
            }
            length--;
            i--;
        }
    }

    char estados[32][30] = {
        "AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR", "CAMPECHE", "COAHUILA",
        "COLIMA", "CHIAPAS", "CHIHUAHUA", "CIUDAD DE MEXICO", "DURANGO",
        "GUANAJUATO", "GUERRERO", "HIDALGO", "JALISCO", "MEXICO",
        "MICHOACAN", "MORELOS", "NAYARIT", "NUEVO LEON", "OAXACA",
        "PUEBLA", "QUERETARO", "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA",
        "SONORA", "TABASCO", "TAMAULIPAS", "TLAXCALA", "VERACRUZ", "YUCATAN", "ZACATECAS"
    };
    int op;
    char estado[30];
    const char estadoss[32][3] = { "AS", "BC", "BS", "CC", "CS", "CH", 
	"CL", "CM", "DF", "DG", "GT", "GR", "HG",
	"JC", "MC", "MN", "MS", "NT", "NL", "OC",
	"PL", "QT", "QR", "SP", "SL", "SR", "TC",
	"TS", "TL", "VZ", "YN", "ZS" };

    printf("Selecciona tu estado de la lista:\n");
    for (int i = 0; i < 32; i++)
    {
        printf("%d) %s\n", i + 1, estados[i]);
    }
    printf("Opción: ");
    op = -1;
    while (op < 1 || op > 32)
    {
        scanf("%d", &op);
        if (op < 1 || op > 32)
        {
            printf("Opción no válida. Introduce un número entre 1 y 32.\n");
        }
    }
    while (getchar() != '\n');

 
    char inicialesEstado[3];
    strncpy(inicialesEstado, estadoss[op - 1], 3);

    printf("Ingrese el año de nacimiento: ");
    año = valinum(1821, 2023);

    printf("Ingrese el mes de nacimiento: ");
    mes = valinum(1, 12);
    sprintf(meses, "%02d", mes);

    printf("Ingrese el día de nacimiento: ");
    if (mes == 2)
    {
        if ((año % 4 == 0 && año % 100 != 0) || (año % 400 == 0))
        {
            dia = valinum(1, 29);
        }
        else
        {
            dia = valinum(1, 28);
        }
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        dia = valinum(1, 30);
    }
    else
    {
        dia = valinum(1, 31);
    }

    sprintf(dias, "%02d", dia);

     do
    {
        printf("Ingrese el sexo (Hombre/H o Mujer/F): ");
        char input[10];
        fgets(input, sizeof(input), stdin);
        sexo = toupper(input[0]);

        if (sexo != 'H' && sexo != 'F')
        {
            printf("Ingrese un género válido (H o F).\n");
        }
    } while (sexo != 'H' && sexo != 'F');

    char fechaNacimiento[9];
    sprintf(fechaNacimiento, "%02d%02d%02d", (año % 100), mes, dia);

    char consonantesEstado[10];
    obtenerConsonantes(estado, consonantesEstado, sizeof(consonantesEstado));

    ApPat[strcspn(ApPat, "\n")] = '\0';
    ApMat[strcspn(ApMat, "\n")] = '\0';
    Nombre[strcspn(Nombre, "\n")] = '\0';

    const char primeraLetra = calcularPrimeraLetra(ApPat);
    char letraDespuesDelEspacio = obtenerPrimerCaracterDespuesDelEspacio(estado);

    char imprAp[5];
    obtenerConsonantes(ApPat, imprAp, sizeof(imprAp));

    char imprApMat[5];
    obtenerConsonantes(ApMat, imprApMat, sizeof(imprApMat));

    char imprN[5];
    obtenerConsonantes(Nombre, imprN, sizeof(imprN));

    char diferenciador = calcularDiferenciadorSiglo(año);


    sprintf(curp, "%c%c%c%c%c%c%c%c%c%c%c%c", imprAp[0], imprApMat[0], imprN[0], fechaNacimiento, sexo, inicialesEstado[0], inicialesEstado[1], inicialesEstado[2], letraDespuesDelEspacio, imprApMat[1], imprN[1], diferenciador);    if (strchr(curp, 'Ñ') || strchr(curp, 'ñ'))
    {
        curp[1] = 'X'; 
    }
    if (esPalabraMalsonante(curp)) {
        curp[1] = 'X';
    }
    char digitoVerificador = calcularDigitoVerificador(curp);

    printf("CURP generado: %s%c\n", curp, digitoVerificador);
}

bool esPalabraMalsonante(const char curp[]) {
    const char *palabrasMalsonantes[] = {
        "BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO",
        "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE", "COJI", "COJO",
        "COLA", "CULO", "FETO", "FALO", "GETA", "GUEI", "GUEY", "JETA",
        "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE",
        "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO",
        "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS",
        "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA",
        "NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", "PUTA",
        "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO", "RUIN", "SENO",
        "TETA", "VACA", "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI",
        "WUEY"
    };

    char curp_lower[19];
    for (int i = 0; i < 19; i++) {
        curp_lower[i] = tolower(curp[i]);
    }

    char posiblePalabra[5] = {curp_lower[0], curp_lower[1], curp_lower[2], curp_lower[3], '\0'};

    for (int i = 0; i < sizeof(palabrasMalsonantes) / sizeof(palabrasMalsonantes[0]); i++) {
        if (strcmp(posiblePalabra, palabrasMalsonantes[i]) == 0) {
            return true;
        }
    }

    return false;
}


char calcularDigitoVerificador(const char curp[]) 
{
    if (strlen(curp) != 17) {
        return 'X'; 
    }
    int suma1 = 0;
    int suma2 = 0;

    const int pesos[] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2};

    for (int i = 0; i < 12; i++) 
    {
        int valor = curp[i] - '0'; 
        if (valor < 0 || valor > 9) 
        {
            return 'X'; 
        }
        suma1 += valor * pesos[i];
    }
    const char letras[] = "0123456789ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    int posLetra = 0;
    for (int i = 0; i < 36; i++) {
        if (curp[12] == letras[i]) {
            posLetra = i;
            break;
        }
    }
    suma1 += (posLetra % 10) * pesos[10];

    int digitoVerificador = (10 - (suma1 % 10)) % 10;
    return static_cast<char>(digitoVerificador + '0');
}



void obtenerConsonantes(const char cadena[], char consonantesEncontradas[], int longitud) 
{
    int contador = 0;
    for (int i = 0; cadena[i] != '\0'; i++) 
    {
        if (esConsonante(cadena[i]) && contador < longitud - 1) 
        {
            consonantesEncontradas[contador] = cadena[i];
            contador++;
        }
    }
    consonantesEncontradas[contador] = '\0';
}

char obtenerPrimeraConsonante(char cadena[])
{
    int i;
    for (i = 0; cadena[i] != '\0'; i++)
    {
        if (esConsonante(cadena[i]))
        {
            return cadena[i];
        }
    }
    return '\0';
}

char obtenerPrimerCaracterDespuesDelEspacio(char cadena[])
{
    char *espacio = strchr(cadena, ' ');
    if (espacio != NULL && *(espacio + 1) != '\0')
    {
        return *(espacio + 1);
    }
    return '\0';
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

char calcularPrimeraLetra(const char ApPat[])
{
    char *token;
    char apellido[30];  // Usaremos una copia del apellido paterno para evitar modificar el original

    strcpy(apellido, ApPat);
    token = strtok(apellido, " ");

    while (token != NULL)
    {
        if (strcmp(token, "MARIA") != 0 && strcmp(token, "JOSE") != 0)
        {
            return toupper(token[0]);
        }
        token = strtok(NULL, " ");
    }

    return toupper(ApPat[0]);
}

int limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return c;
}
char obtenerPrimerCaracterDespuesDelEspacio(const char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] == ' ' && cadena[i + 1] != '\0')
        {
            return cadena[i + 1];
        }
    }
    return '\0';  
}
