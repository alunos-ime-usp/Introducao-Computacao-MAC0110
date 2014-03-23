/*-------------------------------------------------CABECALHO------------------------------------------------------------
 *  Enunciado do problema: Uma loja de discos anota diariamente durante o mes de marco a quantidade de discos vendidos. Determinar em que dia desse mes ocorreu a maior venda e qual foi a quantidade de discos vendidos
 *  Materia: Introducao a Computacao I MAC0110
 *  Código do problema: 1.5
 *  Referência: livro de exercicios 
 *  TAGS:loop inteiros basico
 * ----------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
  int date = 1, 
      currentSold,
      maxSold = 0,
      maxDate = 0;

  while( date <= 31 )
  {
    printf("Mr. Stark, please input the disks solds in %d/03/2014 :", date );
    scanf("%d", &currentSold);
    if(currentSold >= maxSold)
    {
      maxSold = currentSold;
      maxDate = date;
    }
    date ++;
  }

  printf("The day with biggest sells were: %d/03/2014, when you sold %d disks\n", maxDate, maxSold );

  return 0;
}
