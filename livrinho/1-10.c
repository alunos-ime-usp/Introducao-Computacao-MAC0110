/*
 * Coded by Nathan Benedetto Proenca
 * 09/03/2014
 */

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
