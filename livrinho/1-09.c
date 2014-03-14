/*
 * Coded by Nathan Benedetto Proenca
 * 09/03/2014
 */

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
