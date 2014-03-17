/*
 * Coded by Nathan Benedetto Proenca
 * 09/03/2014
 */

#include <stdio.h>

int main()
{
  int n, c = 0, out = 1;

  printf("Mr. Stark, please input an integer n: ");
  scanf("%d", &n);

  while( c < n )
  {
    out = out*(n-c);
    c++;
  }

  printf("The value of %d! is %d.\n", n, out);

  return 0;
}
