#include <stdio.h>

int main()
{
  int number;
  printf("Mr. Stark, please input a sequence of number: ");
  scanf("%d", &number);
  while(number!=0)
  {
    printf("The square of the number is: %d\n", (number*number) );
    number = 0;
    printf("Please insert another number: ");
    scanf("%d", &number);
  }
  return 0;
}
