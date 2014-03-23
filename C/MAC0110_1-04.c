/*-------------------------------------------------CABECALHO------------------------------------------------------------
 *  Enunciado do problema: Ddos um inteiro x e um inteiro nao negativo n, calcular x^n
 *  Materia: Introducao a Computacao I MAC0110
 *  Código do problema: 1.4
 *  Referência: livro de exercicios
 *  TAGS:loop inteiros basico
 * ----------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
  int x, n, c = 0, out = 1;
  printf("Mr. Stark, please input an x and a n: ");
  scanf("%d %d", &x, &n);

  while ( c < n )
  {
    out = x*out;
    c++;
  }

  printf("The number %d elevated to the %dnth potency is %d\n", x, n, out);

  return 0;
}
