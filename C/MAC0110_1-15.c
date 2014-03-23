/*-------------------------------------------------CABECALHO------------------------------------------------------------
 *  Enunciado do problema: Dizemos que um numero i eh congruente modulo m a j se i%m = j%m. Dados inteiros positivos n, j e m, imprimir os n primeiros naturais congruentes a j%m
 *  Materia: Introducao a Computacao I MAC0110
 *  Código do problema: 1.15
 *  Referência: livro de exercicios
 *  TAGS:loop inteiros basico
 * ----------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
  int n,
      j,
      m,
      counter = 0;
  printf("Mr. Stark, please input the number of values you desire: ");
  scanf("%d", &n);
  printf("Now input the number and the mod <num>%%<mod>: ");
  scanf("%d%%%d", &j, &m);

  printf("The numbers are ");
  while( counter < n )
  {
    printf("%d ", ((j%m)+counter*m));
    counter++;
  }printf("\n");


  return 0;
}
