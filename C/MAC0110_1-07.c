/*-------------------------------------------------CABECALHO------------------------------------------------------------
 *  Enunciado do problema: Dados n e uma sequencia de n numeros inteiros, determinar a soma dos numeros pares
 *  Materia: Introducao a Computacao I MAC0110
 *  Código do problema: 1.7
 *  Referência: livro de exercicios
 *  TAGS:loop inteiros basico
 * ----------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
  int sum = 0,
      n,
      count = 1,
      current;

  printf("Mr. Stark, please input the size of the sequence: ");
  scanf("%d", &n);


  while ( count <= n)
  {
    printf("Please input the number #%d of the sequence: ", count);
    scanf("%d", &current);

    /* only add even numbers */
    if( current%2 == 0 )
      sum = sum + current;

    count++;
  }

  printf("The sum of the even numbers in the sequence is %d.\n", sum);

  return 0;
}
