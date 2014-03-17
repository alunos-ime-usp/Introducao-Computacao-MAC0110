/*
 * Coded by Nathan Benedetto Proenca
 * 09/03/2014
 */

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
