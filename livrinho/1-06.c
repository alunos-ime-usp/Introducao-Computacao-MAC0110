/*
** Coded by Nathan Benedetto Proenca
** 09/03/2014
*/

#include <stdio.h>

int main()
{
  int n, 
      currentGrade, 
      maxGrade = 0, 
      minGrade = 100,
      count = 1;

  /* Get the number of students */
  printf("Mr. Stark, please input the number of students in MAC 414: ");
  scanf("%d", &n);

  /* Go through grades */
  while( count <= n)
  {
    printf("Please input the grade of the student number #%d: ", count);
    scanf("%d", &currentGrade);

    /* Only save the relevant grades */
    if(currentGrade >= maxGrade)
      maxGrade = currentGrade;
    if(currentGrade <= minGrade)
      minGrade = currentGrade;

    count ++;
  }

  printf("The grades ranged from %d to %d, Mr. Stark.\n", maxGrade, minGrade);
  return 0;

}
