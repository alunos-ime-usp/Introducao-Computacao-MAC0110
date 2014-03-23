/*-------------------------------------------------CABECALHO------------------------------------------------------------
 *  Enunciado do problema: Dados dois numeros inteiros positivos, determinar o maximo divisor comum entre eles usando o algoritmo de Euclides
 *  Materia: Introducao a Computacao I MAC0110
 *  Código do problema: 1.12
 *  Referência: livro de exercicios
 *  TAGS:loop inteiros basico
 * ----------------------------------------------------------------------------------------------------------------------*/


#include <stdio.h>

int main()
{
  int a,
      b,
      c;

  printf("Mr. Stark, please input a pair of integers: ");
  scanf("%d %d", &a, &b);
  c = a%b;

  while( c!= 0 )
  {
    a = b;
    b = c;
    c = a%b;
  }

  printf("The GCD of the numbers inputed is %d.\n",b);

  return 0;  
}
