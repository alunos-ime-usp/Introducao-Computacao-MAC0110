/*-------------------------------------------------CABECALHO------------------------------------------------------------
 *  Enunciado do problema: Dados o numero n de alunos de uma turma de MAC414 e suas notas da primeira prova, determinar a maior e a menor nota obtidas por essa turma ( nota maxima = 100 e nota minima = 0)
 *  Materia: Introducao a Computacao I MAC0110
 *  Código do problema: 1.6
 *  Referência: livro de exercicios
 *  TAGS:loop inteiros basico
 * ----------------------------------------------------------------------------------------------------------------------*/

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

  printf("The grades ranged from %d to %d, Mr. Stark.\n", minGrade, maxGrade);
  return 0;

}
