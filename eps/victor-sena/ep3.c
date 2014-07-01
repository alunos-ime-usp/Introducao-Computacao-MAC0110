/*	**************************************************************************	*/	
/*	Nome: Victor Sena Molero                                                    */
/*	Numero	USP: 8941317                                                        */
/*	Exercício-programa 3                                                        */
/*	**************************************************************************	*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Constantes */
#define QTD 5000		/* Quantidade de Pontos na tabela da Distribuição Normal Padrão */
#define SQRT2PI 2.5066	/* Raiz de Pi*2 */
#define PREC 1000000    /* Para criar um float com precisao PREC^-1 */

/* ### ---- Funcoes Inline e Auxiliares ---- ### */
/* Geracao de Aleatorios */
unsigned int aleatorio(unsigned int seed) {
	/* com 0u-1 consegue-se o maior numero suportavel */
	unsigned int m = 0u-1, a = 22695477u, b = 1u;

	return (a*seed+b)%m;
}

/* Encontra o Valor de X t.q. F(X) = Y sendo F a Distribuicao Normal Acumulada com media e dp dados */
int busca_binaria(float valores[], float Y) {
	int i = QTD/2, init = 0, fim = QTD-1;

	/* Busca Binaria Pelo Valor Y no Array */
	while (fim - init > 0) {
		if (valores[i] > Y) fim = i - 1;
		else if (valores[i] < Y) init = i + 1;
	    else return i;
        
        i = (fim+init)/2;
    }

	return i;
}

/* Tendo F(X):=N(media, dp) e a localizacao de Y num vetor Im(F) retorna-se X : Y=F(X) */
float inversa(float normal[], float Y, float media, float dp) {
    float   delta = dp*7/QTD;
    int     indice;

    indice = busca_binaria(normal, Y);
    
    return media + (float)indice*delta - 3.5*dp;
}

/* Função que calcula o Quantil */
float quantil(float lista[], int tamanho, float quartil) {
    int      base = (int) tamanho*quartil;

    if (base == (float)tamanho*quartil) {
        return lista[base-1];
    } else {
        return (lista[base]+lista[base-1])/2;
    }
}

int main() {
	float   x,              /* 0 - Variavel Generica */
            aux,            /* 0 - Variavel Generica */
            media,          /* 1 - Média Escolhida */
            dp,             /* 1 - Dp Escolhida */
            k,              /* 1 - Constante Escolhida */
            delta,          /* 1 - Precisao do Calculo da Tabela */
            tabela[QTD+4],  /* 1 - Tabela da Distribuição Normal Padrão */
            *pearsons,      /* 1 - N Coeficientes de Pearson */
            *normal,        /* 2 - n Números Aleatórios Gerados à Partir de N(media, dp) */
            *ajustada,      /* 2 - n Números Gerados à Partir de *normal e E~(0,1) */
            norm,           /* 2 - Valor Aleatório Normal */
            var_n,          /* 2 - Variança de N */
            var_a,          /* 2 - Variança de A */
            covar,          /* 2 - Covariança de A e N */
            media_n,        /* 2 - Media das Aleatórias Normais */
            media_a;        /* 2 - Media das Aleatórias Ajustadas */
    int     n,              /* 1 - Quantidade de Aleatorios Gerados */
            N,              /* 1 - Quantidade de Coeficientes de Pearson Gerados */
            i,              /* 0 - Iterador */
            j;              /* 0 - Iterador */
    unsigned int    uni1 = 2942044, /* 2 - Valor Aleatório Uniforme 1 */
                    uni2 = 7394023; /* 2 - Valor Aleatório Uniforme 2 */

/* ### --- 1. Inicialização --- ### */
/* ----- Definindo Constantes Importantes ----- */
    printf("Entre com media, dp, n, k e N.");
    scanf("%f %f %d %f %d", &media, &dp, &n, &k, &N);
    delta = (float) 7/QTD;

/* ----- Gerando Tabela de N(0,1) ----- */
    /* Buscando o x Inicial */
    x = -3.5;

    /* Determinando o Inicio do Acumulo em 0 */
    tabela[0] = 0;

    /* Calcula o Acumulo dos Valores da Curva Normal (de 0 a 1) */
    for(i = 1; i < QTD-1; ++i) {
        x += delta;
        tabela[i] = tabela[i-1] + delta/(SQRT2PI*exp((x*x)/(2)));
    }

    /* Determinando o Final do Acumulo em 1 */
    tabela[QTD-1] = 1;

/* ----- Alocando Memória Para os Vetores Dinâmicos ----- */
    /* Mallocs */
    normal = (float *) malloc(n*sizeof(float));
    ajustada = (float *) malloc(n*sizeof(float));
    pearsons = (float *) malloc(N*sizeof(float));

    /* Checando Falhas */
    if (normal == NULL || ajustada == NULL || pearsons == NULL) {
        printf("Erro Fatal. Não há memória suficiente.");
        exit( EXIT_FAILURE );
        return 1;
    }

/* ### --- 2. Geração do Vetor de Pearson --- ### */
    for (i = 0; i < N; ++i) {
        media_n = media_a = 0;

        /* Gerando os Vetores normal e ajustada */
        for (j = 0; j < n; ++j) {
            /* Gera uni1~U(0,1) */
            uni1 = aleatorio(uni1);

            /* Gera normal~N(media,dp) */
            norm = (float) (uni1%PREC)/PREC;
            norm = inversa(tabela, norm, media, dp);
            normal[j] = norm;
            media_n += norm;

            /* Gera uni2~U(0,1) */
            uni2 = aleatorio(uni2);

            /* Gera ajustada~k*norm+N(0,1) */
            norm = (float) (uni2%PREC)/PREC;
            norm = k*normal[j] + inversa(tabela, norm, 0, 1);
            ajustada[j] = norm;
            media_a += norm;
        }

        /* Definindo o Valor da Média */
        media_n /= n;
        media_a /= n;

        var_n = var_a = covar = 0;
        /* Calculando Pearson */
        for (j = 0; j < n; ++j) {
            var_a += (ajustada[j]-media_a)*(ajustada[j]-media_a);
            var_n += (normal[j]-media_n)*(normal[j]-media_n);
            covar += (normal[j]-media_n)*(ajustada[j]-media_a);
        }

        aux = sqrt(var_n*var_a);

        /* Colocando no Vetor de Forma Ordenada (algoritmo de insertion) */
        pearsons[i] = covar/aux;
        for (j = i; j > 0 && pearsons[j] < pearsons[j-1]; --j) {
            aux = pearsons[j-1];
            pearsons[j-1] = pearsons[j];
            pearsons[j] = aux;
        }
    }

/* ### --- 3. Calculo dos Quartis de Pearson --- ### */
    printf("Primeiro Quantil: %f\n", quantil(pearsons, N, 0.25));
    printf("Segundo Quantil: %f\n", quantil(pearsons, N, 0.5));
    printf("Terceiro Quantil: %f\n", quantil(pearsons, N, 0.75));

/* ### --- 4. Final --- ### */
    /* Liberando Memória */
    free(normal);
    free(ajustada);
    free(pearsons);

	return 0;
}













