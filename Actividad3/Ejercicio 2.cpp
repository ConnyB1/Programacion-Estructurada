//Cesar Alejandro Velazquez Mercado
//372329
//Es Chimchampu pero contra la maquina
//10/09/2023
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void perdiste (void);
void ganaste (void);
void empate (void);
//****  main principal  *********
int main()
{
   menu();

	return 0;
}
//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************
int msges()
{ int op;
  system ("CLS");
  printf ("   M  E   N   U \n");
  printf("1.- piedra \n");
  printf("2.- papel \n");
  printf("3.- tijera \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf ("%d",&op);
  return op;
}
//****************
void menu()
{
  int op, comp;
  do{
    comp=rand()%3 +1;
      op=msges();
      if (op == 1)
      {
        if (comp == 1)
        {
            empate();
        }
        else
        {
            if(comp == 2)
            {
                perdiste();
            }
            else
            {
                ganaste();
            }
        }
      }
      else
      {
        if (op == 2)
        {
            if (comp == 1)
            {
                ganaste();
            }
            else
            {
                if (comp == 2)
                {
                    empate();
                }
                else
                {
                    perdiste();
                }
            }
        }
        else
        {
            if (op == 3)
            {
                if (comp == 1)
                {
                    perdiste();
                }
                else
                {
                    if (comp == 2)
                    {
                        ganaste();
                    }
                    else
                    {
                        empate();
                    }
                }
            }
        }
      }
    }while (op != 0);
}

//*********************
void ganaste (void)
{
    //  VARIALES LOCALES 
    system ("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   ganaste\n"); 
    system ("PAUSE");
}

//*************************
void perdiste (void)
{

    //  VARIALES LOCALES 
    system ("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   perdiste\n"); 
    system ("PAUSE");
}
//****************************
void empate (void)
{
    //  VARIALES LOCALES 
    system ("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   empate\n"); 
    system ("PAUSE");

}