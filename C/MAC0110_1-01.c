/*-------------------------------------------------CABECALHO------------------------------------------------------------
 *  Enunciado do problema: Dada uma colecao de numeros inteiros positivos terminada por 0, imprimir seus quadrados. 
 *  Materia: Introducao a Computacao I MAC0110
 *  Código do problema: 1.1
 *  Referência: livro de exercicios
 *  TAGS: loop inteiros basico
 * ----------------------------------------------------------------------------------------------------------------------*/

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
        scanf("%d", &number);
    }
    return 0;
}
