//Cesar Alejandro Velazquez Mercado
//372329
//Me despliega la cadena de diferentes formas
//25/09/2023
#include <stdio.h>
#include <string.h>
#include <ctype.h>



void convertirMayusculas(char cadena[]);
void convertirMinusculas(char cadena[]);
void convertirCapital(char cadena[]);
int contarCaracteres(char cadena[]);
void invertirCadena(char cadena[]);
void eliminarEspacios(char cadena[]);
void validarYLimpiarCadena(char cadena[]);
int esPalindromo(char cadena[]);

int main() {
    char cadena[100];

    printf("Ingrese una cadena: ");
    gets(cadena);

    convertirMayusculas(cadena);
    printf("Mayúsculas: %s\n", cadena);

    convertirMinusculas(cadena);
    printf("Minúsculas: %s\n", cadena);

    convertirCapital(cadena);
    printf("Capital: %s\n", cadena);


    int caracteres = contarCaracteres(cadena);
    printf("Cantidad de caracteres: %d\n", caracteres);

    invertirCadena(cadena);
    printf("Invertida: %s\n", cadena);

    eliminarEspacios(cadena);
    printf("Sin espacios: %s\n", cadena);

    validarYLimpiarCadena(cadena);
    printf("Validada y sin espacios consecutivos: %s\n", cadena);

    printf("Mayúsculas: ");
    convertirMayusculas(cadena);
    printf("%s\n", cadena);

    printf("Minúsculas: ");
    convertirMinusculas(cadena);
    printf("%s\n", cadena);

    printf("Capital: ");
    convertirCapital(cadena);
    printf("%s\n", cadena);

    printf("Sin espacios: ");
    eliminarEspacios(cadena);
    printf("%s\n", cadena);

    printf("Invertida: ");
    invertirCadena(cadena);
    printf("%s\n", cadena);

    if (esPalindromo(cadena)) {
        printf("Es un palíndromo.\n");
    } else {
        printf("No es un palíndromo.\n");
    }

    return 0;
}


void convertirMayusculas(char cadena[]) {
    for (int i = 0; cadena[i]; i++) {
        cadena[i] = toupper(cadena[i]);
    }
}

void convertirMinusculas(char cadena[]) {
    for (int i = 0; cadena[i]; i++) {
        cadena[i] = tolower(cadena[i]);
    }
}

void convertirCapital(char cadena[]) {
    if (cadena[0]) {
        cadena[0] = toupper(cadena[0]);
    }
    for (int i = 1; cadena[i]; i++) {
        cadena[i] = tolower(cadena[i]);
    }
}

int contarCaracteres(char cadena[]) {
    return strlen(cadena);
}

void invertirCadena(char cadena[]) {
    int longitud = strlen(cadena);
    for (int i = 0, j = longitud - 1; i < j; i++, j--) {
        char temp = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = temp;
    }
}

void eliminarEspacios(char cadena[]) {
    int i, j;
    for (i = 0, j = 0; cadena[i]; i++) {
        if (!isspace(cadena[i])) {
            cadena[j] = cadena[i];
            j++;
        }
    }
    cadena[j] = '\0';
}

void validarYLimpiarCadena(char cadena[]) 
{
    int i, j;
    int prevCharIsSpace = 1;
    for (i = 0, j = 0; cadena[i]; i++) {
        if (isalpha(cadena[i])) {
            cadena[j] = cadena[i];
            j++;
            prevCharIsSpace = 0;
        } else if (!prevCharIsSpace && isspace(cadena[i])) {
            cadena[j] = ' ';
            j++;
            prevCharIsSpace = 1;
        }
    }
    while (j > 0 && isspace(cadena[j - 1])) {
        j--;
    }

    cadena[j] = '\0';
}

int esPalindromo(char cadena[]) {
    int longitud = strlen(cadena);
    for (int i = 0, j = longitud - 1; i < j; i++, j--) {
        if (cadena[i] != cadena[j]) {
            return 0;
        }
    }
    return 1; 
}
