#include <stdio.h>

int main()
{
  int input, n = 1, output = 0;
  printf("Mr. Stark, please input an integer: ");
  scanf("%d", &input);
  while( n <= input )
  {
    output = output + n;
    n = n + 1;
  }
  printf("The sum of all the integers up to %d is %d \n", input, output);
  return 0;
}
