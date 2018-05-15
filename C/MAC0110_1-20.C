/*-------------------------------------------------CABECALHO------------------------------------------------------------
* Enunciado do problema:Escreva um programa que imprima tds os milhares AABB 
              cuja raíz quadrada seja a soma das dezenas formadas pela divisão abaixo.
              dez_1 = AA  // --> AABB / 100
              dez_2 = BB  \\ --> AABB % 100;
* Materia: Introducao a Computacao I MAC0110
* Código do problema: 1.20
* Referência: livro de exercicios
* TAGS: funções, inteiros basico
* ----------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
int soma (int n)
{
    int part1, part2, resp;
    part2=n%100;
    part1=n/100;
    resp=part1+part2;
    return resp;
}

float sq (float a)
{
    float x0, xn, eps=0.0001;
    x0=a;
    xn=0.5*(x0+(a/x0));
    while (x0-xn>eps){
        x0=xn;
        xn=0.5*(x0+(a/x0));
    }
    return xn;
}

int main()
{
    int soman, ii;
    float sqrn, ifl;
    printf ("Esses números obedecem às propriedades\n");
    for (ii=1000;ii<=9999;ii++)
    {
        ifl=(float)ii;
        soman=soma(ii);
        sqrn=sq(ifl);
        if (soman == sqrn)
        {
            printf ("%d  \n", ii);
        }
    }
    return 0;
}
