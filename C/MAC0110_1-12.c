/*
 * Coded by Nathan Benedetto Proenca
 * 09/03/2014
 */

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
