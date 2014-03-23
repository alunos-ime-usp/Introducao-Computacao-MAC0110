/*-------------------------------------------------CABECALHO------------------------------------------------------------
 *  Enunciado do problema: Dado um inteiro nao negativo, determinar n! 
 *  Materia: Introducao a Computacao I MAC0110
 *  Código do problema: 1.8
 *  Referência: livro de exercicios
 *  TAGS:loop inteiros basico
 * ----------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
  int n, c = 0, out = 1;

  printf("Mr. Stark, please input an integer n: ");
  scanf("%d", &n);

  while( c < n )
  {
    out = out*(n-c);
    c++;
  }

  printf("The value of %d! is %d.\n", n, out);

  return 0;
}
