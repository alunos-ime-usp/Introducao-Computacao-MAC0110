/*-------------------------------------------------CABECALHO------------------------------------------------------------
 *  Enunciado do problema: O n-esimo numero da sequencia de fibonacci Fn eh dado pela seguinte formula:
    Fn = 1 se n = 1
    Fn = 2 se n = 2
    Fn = F(n-1) + F(n-2)
    Faca um programa que dado n calcula o Fn .
 *  Materia: Introducao a Computacao I MAC0110
 *  Código do problema: 1.14
 *  Referência: livro de exercicios
 *  TAGS:loop inteiros basico
 * ----------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
  int input,
      count = 2,
      f1 = 1,
      f2 = 1,
      sum;

  printf("Mr. Stark, please input an integer: ");
  scanf("%d", &input);

  if( input <= count )
    printf("The F%d fibonacci number is 1.\n", input);
  else
  {
    while( input > count )
    {
      sum = f1 + f2;
      f1 = f2;
      f2 = sum;
      count ++;
    }

    printf("The F%d fibonacci number is %d.\n", input, f2);
  }

  return 0;
}
