/*-------------------------------------------------CABECALHO------------------------------------------------------------
 *  Enunciado do problema: Dado n, imprimir os n primeiro inteiros positivos impares 
 *  Materia: Introducao a Computacao I MAC0110
 *  Código do problema: 1.3
 *  Referência: livro de exercicios
 *  TAGS:loop inteiros basico
 * ----------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
  int input, counter = 0, output = 1;
  printf("Mr. Stark, please input an integer: ");
  scanf("%d", &input);
  while ( counter < input )
  {
    if ( (counter + 1) != input )
    {
      printf("%d, ", output);
    } else 
    {
      printf("%d.\n", output);
    }
    output = output + 2;
    counter = counter + 1;
  }
  return 0;
}
