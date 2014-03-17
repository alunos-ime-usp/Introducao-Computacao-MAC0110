/*
 * Coded by Nathan Benedetto Proenca
 * 09/03/2014
 */

#include <stdio.h>

int main()
{
  int input,
      count = 2,
      f1 = 1,
      f2 = 1,
      sum;

  printf("Mr. Stark, please input an integer: ");
  scanf("%d", &input);

  if( input <= count )
    printf("The F%d fibonacci number is 1.\n", input);
  else
  {
    while( input > count )
    {
      sum = f1 + f2;
      f1 = f2;
      f2 = sum;
      count ++;
    }

    printf("The F%d fibonacci number is %d.\n", input, f2);
  }

  return 0;
}
