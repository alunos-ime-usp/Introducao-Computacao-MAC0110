/*-------------------------------------------------CABECALHO------------------------------------------------------------
 *  Enunciado do problema:Dizemos que um inteiro positivo n eh perfeito se for igual a soma de seus divisores positibos diferentes de n. Verificar se um dado numero inteiro eh positivo. 
 *  Materia: Introducao a Computacao I MAC0110
 *  Código do problema: 1.13
 *  Referência: livro de exercicios
 *  TAGS:loop inteiros basico
 * ----------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
  int num,
      sum,
      count = 1;

  printf("Mr. Stark, which number should be tested if perfect or not? ");
  scanf("%d", &num);

  while( count < num )
  {
    if(num%count == 0)
      sum = sum + count;
    count++;
  }

  if( num==sum )
  {
    printf("%d is indeed perfect, sir.\n", num);
  } else
  {
    printf("I'm sorry sir, but %d is not perfect.\n", num);
  }

  return 0;
}
