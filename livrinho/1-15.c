/*
 * Coded by Nathan Benedetto Proenca
 * 09/03/2014
 */

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
