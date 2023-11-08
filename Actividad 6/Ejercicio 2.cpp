#include <stdio.h>
#include <stdlib.h>

void calcularSumaYMedia(int n);
void promedio(float promedioFinal);

int main() 
{

    int opcion;

    printf("Menu\n");   
    printf("1. Calificaciones de alumnos\n");
    printf("2. Imprimir tablas de multiplicar\n");
    printf("3. Leer una cantidad de numeros\n");
    printf("4. Saber el peso maximo de una embarcacion\n");
    printf("5. Situacion academica de un alumno\n");
    printf("Elija una opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
        case 1:
        {
            int calificaciones[40][5];
            int reprob = 0;

            for (int i = 0; i < 40; i++) 
            {
                for (int j = 0; j < 5; j++) 
                {
                    printf("Ingresa 5 calificaciones del alumno %d", i+1);
                    scanf("%d", &calificaciones[i][j]);
                }
            }

            for (int i = 0; i < 40; i++) 
            {
                int suma = 0;
                for (int j = 0; j < 5; j++) 
                {
                    suma += calificaciones[i][j];
                }
                float promedio = suma / 5.0;
                if (promedio < 50) 
                {
                    reprob++;
                }
            }

            printf("Cantidad de alumnos sin derecho al examen de nivelación: %d\n", reprob);
        }
        break;
        case 2:
        {
            int res;
            for (int i = 1; i <= 10; i++)
            {
                for (int j = 1; j <= 10; j++)
                {
                    res=j*i;
                    printf("%d * %d = %d\n",i,j,res);
                }
                system("Pause");
                printf("\n\nPresione una tecla para continuar...");
                system("CLS");
                
            }
            
        }
        break;
        case 3:
        {
            int n;
            printf("Ingrese la cantidad de numeros a procesar: ");
            scanf("%d", &n);
            calcularSumaYMedia(n);
        }
        break;
        case 4:
        {
            int numTuristas = 0;
            int pesoTotal = 0;
            int sobrepeso = 0;
            int op=1;

            while (op==1) 
            {
                int pesoTurista;
                printf("Ingrese el peso del turista #%d (kg): ", numTuristas + 1);
                scanf("%d", &pesoTurista);

                pesoTotal += pesoTurista;
                numTuristas++;
                if (pesoTurista > 70) 
                {
                    sobrepeso++;
                }

                if (numTuristas >= 10 || pesoTotal >= 700 || sobrepeso >= numTuristas * 0.15) 
                {
                    op=0;
                }
            }
            if (numTuristas > 0) 
            {
                float promedioPeso = pesoTotal / numTuristas;
                printf("Promedio de peso de los turistas: %f kg\n", promedioPeso);
            }
            if (numTuristas >= 10) 
            {
                printf("Se alcanzó el máximo de 10 turistas.\n");
            }
            if (pesoTotal >= 700) 
            {
                printf("Se alcanzó el máximo de 700 kg de pasajeros.\n");
            }
            if (sobrepeso >= numTuristas * 0.15) 
            {
                printf("Se superó el porcentaje de sobrepeso permitido.\n");
            }
            else 
            {
                printf("No se ingresaron datos de turistas.\n");
            }
        }
        break;
        case 5:
        {
            int examen1, examen2, examen3;
            printf("Ingrese la primera calificacion: ");
            scanf("%d", &examen1);
            printf("Ingrese la segunda calificacion: ");
            scanf("%d", &examen2);
            printf("Ingrese la tercera calificacion: ");
            scanf("%d", &examen3);

            float promedioFinal = (examen1 + examen2 + examen3) / 3.0;
            printf("Promedio final: %f\n", promedioFinal);


            printf("SituaciOn acadEmica: ");
            promedio(promedioFinal);
       
        }
    }
    return 0;
}

void calcularSumaYMedia(int n) 
{
    int suma = 0;
    int contador = 0;
    
    for (int i = 0; i < n; i++) 
    {
        int numero;
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
        
        if (numero >= 1 && numero <= 100) 
        {
            suma += numero;
            contador++;
        }
    }
    
    if (contador > 0) {
        double media = (double)suma / contador;
        printf("Suma de los numeros validos: %d\n", suma);
        printf("Media de los numeros validos: %.2lf\n", media);
    } 
    else 
    {
        printf("No se ingresaron numeros validos\n");
    }
}

void promedio(float promedioFinal) 
{
    if (promedioFinal >= 60.0) 
    {
        printf("Aprobado\n");
    } 
    else
    {
        if (promedioFinal >= 50.0) 
        {
            printf("Repetir materia\n");
        } 
        else 
        {
            printf("Baja academica\n");
        }
    }
    
}