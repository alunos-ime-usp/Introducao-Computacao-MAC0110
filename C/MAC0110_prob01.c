/*
 * Problema 1
 * Dado uma sequencia n em Z, n != 0,
 * terminada em 0, calcular a soma da sequencia
 */

#include <stdio.h>

int main()
{
    int num, soma = 0;
    printf("Entre com a sequencia de numeros");
    scanf("%d", &num);
    while(num!=0)
    {
        soma = soma + num;
        scanf("%d", &num);
    }
    printf("Soma = %d\n");
    return 0;
}
