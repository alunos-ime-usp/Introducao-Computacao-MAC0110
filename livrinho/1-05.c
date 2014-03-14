#include <stdio.h>

int main()
{
  int date = 1, 
      currentSold,
      maxSold = 0,
      maxDate = 0;

  while( date <= 31 )
  {
    printf("Mr. Stark, please input the disks solds in %d/03/2014 :", date );
    scanf("%d", &currentSold);
    if(currentSold >= maxSold)
    {
      maxSold = currentSold;
      maxDate = date;
    }
    date ++;
  }

  printf("The day with biggest sells were: %d/03/2014, when you sold %d disks\n", maxDate, maxSold );

  return 0;
}
