/*-------------------------------------------------CABECALHO------------------------------------------------------------
 *  Enunciado do problema: Dado n, calcula a soma dos n primeiros numeros inteiros positivos 
 *  Materia: Introducao a Computacao I MAC0110
 *  Código do problema: 1.2
 *  Referência: livro de exercicios
 *  TAGS: loop inteiros basico
 * ----------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
  int input, n = 1, output = 0;
  printf("Mr. Stark, please input an integer: ");
  scanf("%d", &input);
  while( n <= input )
  {
    output = output + n;
    n = n + 1;
  }
  printf("The sum of all the integers up to %d is %d \n", input, output);
  return 0;
}
