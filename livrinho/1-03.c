#include <stdio.h>

int main()
{
  int input, counter = 0, output = 1;
  printf("Mr. Stark, plesae input an integer: ");
  scanf("%d", &input);
  while ( counter < input )
  {
    if ( (counter + 1) != input )
    {
      printf("%d, ", output);
    } else 
    {
      printf("%d.\n", output);
    }
    output = output + 2;
    counter = counter + 1;
  }
  return 0;
}
