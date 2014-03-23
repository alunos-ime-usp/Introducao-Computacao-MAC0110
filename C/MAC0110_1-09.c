/*-------------------------------------------------CABECALHO------------------------------------------------------------
 *  Enunciado do problema: Dado n e dois numeros inteiros positivos i e j, imprimir em ordem crescente os n primeiros naturais que sao multiplos de i ou de j ou de ambos 
 *  Materia: Introducao a Computacao I MAC0110
 *  Código do problema: 1.9
 *  Referência: livro de exercicios
 *  TAGS:loop inteiros basico
 * ----------------------------------------------------------------------------------------------------------------------*/


#include <stdio.h>

int main()
{
  int n,
      i,
      j,
      printed = 0,
      counter = 0;

  printf("Mr. Stark, please input the size of the sequeced desired: ");
  scanf("%d", &n);
  printf("Now, please the values of i and j: ");
  scanf("%d %d", &i, &j);

  printf("The %d numbers multiples of %d or %d are ", n, i, j);
  while( printed < n )
  {
    if( (counter%i == 0)||(counter%j==0) )
    {
      printed++;
      printf("%d ", counter);
    }
    counter ++;
  }printf("\n");


  return 0;
}
