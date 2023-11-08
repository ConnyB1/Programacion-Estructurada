#include <stdio.h>

int fibonacci(int n);
int factorial(int n);
int contarDigitos(int n);

int main()
{
    int opcion;
    do 
    {
        printf("Menu\n");
        printf("1. Fibonacci\n");
        printf("2. Factorial\n");
        printf("3. Cantidad de digitos\n");
        printf("0. Para salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion) 
        {
            case 1:
            {
                int n;
                printf("Cuantas veces deseas realizar Fibonacci: ");
                scanf("%d", &n);
                printf("Fibonacci:\n");
                for (int i = 0; i < n; i++) 
                {
                    printf("%d ", fibonacci(i));
                }
                printf("\n\n\n");
            }
            break;

            case 2:
            {
                int num;
                printf("Ingrese un numero para calcular su factorial: ");
                scanf("%d", &num);
                int resultado = factorial(num);
                printf("%d\n",resultado);
                printf("\n\n\n");
            }
            break;

            case 3:
            {
                int numero;
                printf("Dame un numero y te dire los digitos: ");
                scanf("%d", &numero);
                int digitos = contarDigitos(numero);
                printf("Tiene %d digito(s) \n",digitos);
                printf("\n\n\n");
            }
            break;
            
            default:
            {

            }
        }
    }while(opcion != 0);
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int contarDigitos(int n) {
    int count = 0;
    while (n != 0) {
        n = n / 10;
        count++;
    }
    return count;
}