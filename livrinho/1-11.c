/*
 * Coded by Nathan Benedetto Proenca
 * 09/03/2014
 */

#include <stdio.h>

int main()
{
  int p,
      n = 2,
      prime = 1;

  printf("Mr. Stark, which number should I verify if it's prime? ");
  scanf("%d", &p);

  /* JARVIS will go through the numbers below p and see if there
   * is any that divides p.
   * If any divide, it will break out of it.
   */

  while( ( n<p )&&( prime==1 ) )
  {
    if(p%n == 0)
      prime = 0;
    n++;
  }

  if(prime == 1)
    printf("Mr. Stark, %d is indeed prime.\n", p);
  else
    printf("Mr. Stark, %d is not prime.\n", p);



  return 0;
}
