/*  **************************************************************************  */
/*  Nome: Victor Sena Molero                                                    */
/*  Numero  USP: 8941317                                                        */
/*  Exercício-programa  1                                                       */
/*  Qual versão foi implementada: espartana (http://tinyurl.com/obdtvrp)        */
/*  **************************************************************************  */

#include <stdio.h>
int main() {
    int n, /* Número Fornecido */
        aux, /* Variável Auxiliar */
        m = 1000; /* Variável que define a casa a ser calculada */

    printf("Entre com um número de 1 até 3999.\n");
    scanf("%d", &n);
    printf("O número %d descrito em numerais romanos é: ", n);

    while(n > 0) {
        /* Deixando só a casa que importa */
        /* É repetido no final de cada if: evita o uso de else e diminui a quantidade de loops */
        aux = (n/m);
        
        if (aux == 9) {
            if (m == 100) printf("CM");
            if (m == 10) printf("XC");
            if (m == 1) printf("IX");
            n = n - 9*m;
            aux = (n/m)*10; 
        }   
        if (aux >= 5) {
            if (m == 100) printf("D");
            if (m == 10) printf("L");
            if (m == 1) printf("V");
            n = n - 5*m;
            aux = (n/m)*10; 
        }
        if (aux == 4) {
            if (m == 100) printf("CD");
            if (m == 10) printf("XL");
            if (m == 1) printf("IV");
            n = n - 4*m;
            aux = (n/m)*10; 
        }
        if (aux > 0) {
            if (m == 1000) printf("M");
            if (m == 100) printf("C");
            if (m == 10) printf("X");
            if (m == 1) printf("I");
            n = n - 1*m;
            aux = (n/m)*10; 
        }

        /* Quer dizer que a casa já foi impressa por inteiro */
        if (aux == 0) {
            m = m/10;
        }
    }

    printf("\n");
    return 0;
}

/*
gcc -Wall -ansi -pedantic -O2 -o ep1 ep1.c

*/
