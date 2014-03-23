/*-------------------------------------------------CABECALHO------------------------------------------------------------
 *  Enunciado do problema: Dizemos que um numero natural eh triangular se ele eh produto de tres numeros naturais consecutivos. Dado um inteiro nao-negativo n, verificar se n eh triangular
 *  Materia: Introducao a Computacao I MAC0110
 *  Código do problema: 1.10
 *  Referência: livro de exercicios
 *  TAGS:loop inteiros basico
 * ----------------------------------------------------------------------------------------------------------------------*/


#include <stdio.h>

int main()
{
  int n,
      c = 1;
  printf("Mr. Stark, which number should I verify its triangularity? ");
  scanf("%d", &n);

  while( c*(c+1)*(c+2) < n )
    c++;

  if( c*(c+1)*(c+2) == n)
  {
    printf("Seems like %d indeed is a triangular number.\n", n );
  } else
  {
    printf("Well, %d is not triangular at all!\n", n);
  }
  
  

  return 0;
}
