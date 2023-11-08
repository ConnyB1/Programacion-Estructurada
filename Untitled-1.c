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
char calcularPrimeraLetra(char ApPat[], char ApMat[], char Nombre[]);
bool esPalabraMalsonante(const char curp[]);
char calcularDiferenciadorSiglo(int anioNacimiento);
bool esConsonante(char c);
void obtenerConsonantes(char cadena[], char consonantesEncontradas[], int longitud);
char calcularDigitoVerificador(char curp[]);
char calcularHomoclave(char ApPat[], char ApMat[], char Nombre[], int año, int mes, char sexo);
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
        op = valinum(1,2);
    } while (op != 2);
    return 0;
}

void generarCURP(char curp[])
{
    

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

    // Almacena las iniciales del estado
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

    do {
        printf("Ingrese el sexo (H/F): ");
        sexo = toupper(getchar());
        while (getchar() != '\n');

        if (sexo != 'H' && sexo != 'F') {
            printf("Ingrese un género válido (H o F).\n");
        }
    } while (sexo != 'H' && sexo != 'F');

    char homoclave = calcularHomoclave(ApPat, ApMat, Nombre, año, mes, sexo);

    char fechaNacimiento[9];
    sprintf(fechaNacimiento, "%02d%02d%02d", (año % 100), mes, dia);

    char consonantesEstado[10];
    obtenerConsonantes(estado, consonantesEstado, sizeof(consonantesEstado));

    char letraDespuesDelEspacio = obtenerPrimerCaracterDespuesDelEspacio(estado);

    char imprAp[5];
    obtenerConsonantes(ApPat, imprAp, sizeof(imprAp));

    char imprApMat[5];
    obtenerConsonantes(ApMat, imprApMat, sizeof(imprApMat));

    char imprN[5];
    obtenerConsonantes(Nombre, imprN, sizeof(imprN));

    char diferenciador = calcularDiferenciadorSiglo(año);

    char primeraLetra = calcularPrimeraLetra(ApPat, ApMat, Nombre);

    sprintf(curp, "%c%c%c%c%s%c%c%c%c%c%c%c", ApPat[0], ApPat[1], ApMat[0], Nombre[0], fechaNacimiento, sexo, inicialesEstado[0], inicialesEstado[1], inicialesEstado[2], letraDespuesDelEspacio, imprAp[1], imprApMat[1], imprN[1], diferenciador);
    if (strchr(curp, 'Ñ') || strchr(curp, 'ñ'))
    {
        curp[1] = 'X'; 
    }
    if (esPalabraMalsonante(curp)) {
        curp[1] = 'X'; // Cambia la segunda letra a X
    }
    char digitoVerificador = calcularDigitoVerificador(curp);

    printf("CURP generado: %s%c\n", curp, digitoVerificador);
}

bool esPalabraMalsonante(const char curp[])
{
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

    char primeraLetra = tolower(curp[0]);
    char segundaLetra = tolower(curp[1]);
    char terceraLetra = tolower(curp[2]);
    char cuartaLetra = tolower(curp[3]);

    char posiblePalabra[5] = {primeraLetra, segundaLetra, terceraLetra, cuartaLetra, '\0'};

    for (int i = 0; i < sizeof(palabrasMalsonantes) / sizeof(palabrasMalsonantes[0]); i++)
    {
        if (strcmp(posiblePalabra, palabrasMalsonantes[i]) == 0)
        {
            return true;
        }
    }

    return false;
}

char calcularHomoclave(char ApPat[], char ApMat[], char Nombre[], int año, int mes, char sexo)
{
    char homoclave;
    homoclave = toupper(ApPat[0]);
    homoclave = (homoclave << 5) | (toupper(ApMat[0]) - 'A');
    homoclave = (homoclave << 5) | (toupper(Nombre[0]) - 'A');
    homoclave = (homoclave << 5) | ((año % 100) % 10);
    homoclave = (homoclave << 4) | mes;
    homoclave = (homoclave << 1) | (sexo == 'H' ? 0 : 1);
    return homoclave;
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


void obtenerConsonantes(char cadena[], char consonantesEncontradas[], int longitud)
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

    for (int i = 0; consonantesEncontradas[i] != '\0'; i++)
    {
        switch (consonantesEncontradas[i])
        {
            case 'Á': consonantesEncontradas[i] = 'A'; break;
            case 'É': consonantesEncontradas[i] = 'E'; break;
            case 'Í': consonantesEncontradas[i] = 'I'; break;
            case 'Ó': consonantesEncontradas[i] = 'O'; break;
            case 'Ú': consonantesEncontradas[i] = 'U'; break;
            case 'Ü': consonantesEncontradas[i] = 'U'; break;
            case 'Ñ': consonantesEncontradas[i] = 'N'; break;
        }
    }
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

char calcularPrimeraLetra(char ApPat[], char ApMat[], char Nombre[])
{
    char primeraLetra = '\0';

    char *token = strtok(ApPat, " ");

    while (token != NULL)
    {
        if (strcmp(token, "MARIA") != 0 && strcmp(token, "JOSE") != 0)
        {
            primeraLetra = toupper(token[0]);
            break;
        }

        token = strtok(NULL, " ");
    }

    if (primeraLetra == '\0')
    {
        primeraLetra = toupper(ApPat[0]);
    }

    return primeraLetra;
}
int limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return 0;
}
char obtenerPrimerCaracterDespuesDelEspacio(const char cadena[]) 
{
    int i = 0;
    while (cadena[i] != '\0') 
    {
        if (cadena[i] == ' ' && cadena[i + 1] != '\0') 
        {
            return cadena[i + 1];
        }
        i++;
    }
    return '\0';
}