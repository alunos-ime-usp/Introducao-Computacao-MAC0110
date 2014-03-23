/*-------------------------------------------------CABECALHO------------------------------------------------------------
 *  Enunciado do problema:Dado um numero natural na base binaria, transforma-lo para a base decimal. 
 *  Materia: Introducao a Computacao I MAC0110
 *  Código do problema: 1.16
 *  Referência: livro de exercicios
 *  TAGS:loop inteiros basico
 * ----------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int power(int x, int y)
{
  int c = 0,
      out = 1;

  while( c < y )
  {
    out *= x;
    c++;
  }

  return out;
}

int main()
{
  int input,
      result = 0,
      exp = 0;

  printf("Mr. Stark, please input a binary digit: ");
  scanf("%d", &input);

  while(input > 0)
  {
    result = result + (input%10)*(power(2,exp)) ;
    input /= 10;
    exp++;
  }
  printf("The number is the same as %d\n", result);

  return 0;
}
