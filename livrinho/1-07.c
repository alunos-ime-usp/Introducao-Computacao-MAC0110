/* 
 * Coded by Nathan Benedetto Proenca
 * 09/03/2014
 */

#include <stdio.h>

int main()
{
  int sum = 0,
      n,
      count = 1,
      current;

  printf("Mr. Stark, please input the size of the sequence: ");
  scanf("%d", &n);


  while ( count <= n)
  {
    printf("Please input the number #%d of the sequence: ", count);
    scanf("%d", &current);

    /* only add even numbers */
    if( current%2 == 0 )
      sum = sum + current;

    count++;
  }

  printf("The sum of the even numbers in the sequence is %d.\n", sum);

  return 0;
}
