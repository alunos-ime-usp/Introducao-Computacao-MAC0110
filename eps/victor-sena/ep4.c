/*  **************************************************************************  */
/*  Nome:  Victor Sena Molero                                                   */ 
/*  Numero  USP:   8941317                                                      */  
/*  Exercício-programa  4                                                       */  
/*  **************************************************************************  */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMS 10000 /* Quantidade de Números na Tabela Normal */
#define SQRT2PI 2.506628274631000502

/* Funções Auxiliares */
/* -- Busca Binária -- */
int busca_binaria(float * vetor, float valor, int com, int fim) {
    int     i = (fim+com)/2;

    if (fim - com < 2) return i;
    if (vetor[i] == valor) return i;
    if (vetor[i] > valor) return busca_binaria(vetor, valor, com, i);
    return busca_binaria(vetor, valor, i, fim);
}

/* -- Gerador de Tabela da Normal Padrão -- */
void gerar_tabela(float * tabela) {
    float   delta = (float) 10/NUMS, x = -5.0;
    int     i;
    tabela[0] = 0;
    for (i = 1; i < NUMS-1; i++) {
        x += delta;
        tabela[i] = tabela[i-1] + delta/(SQRT2PI*exp((x*x)/(2)));
    }
    tabela[NUMS-1] = 1;
}

/* -- Calculando Valor de N(0,1) à partir de U(0,1) -- */
float aleatorio_normal(float * tabela, float val) {
    int i;
    float r;

    i = busca_binaria(tabela, val, 0, NUMS-1);
    r = (float)i*(10.0/NUMS) - 5.0;

    return r;
}

/* -- Gerando U(0,1) -- */
unsigned int aleatorio_uniforme(unsigned int seed) {
    unsigned int m = 0u-1, a = 22695477u, b = 1u;

    return (a*seed+b)%m;
}

/* Funções de Matriz */
/* Imprimir Matriz */
void matriz_print(float ** mat, int n, int m) {
    int i, j;

    printf("--- ---\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }
    printf("--- ---\n");
}

/* Preenchendo a Matriz */
void matriz_fill (float ** mat, int n, int m, int seed) {
    int i, j;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
             seed = 3*(seed+4029)%203040;
             mat[i][j] = seed;
        }
    }
}

/* Produto de Matrizes: Recebe a[n][p] e b[p][m] e retorna out[n][m] */
void matriz_prod (float ** a, float ** b, float ** out, int n, int p, int m, int trans) {
    int i, j, k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            out[i][j] = 0;
            for (k = 0; k < p; k++) {
                /* Sem Transpostas */
                if (trans == 0) out[i][j] += a[i][k]*b[k][j];
                /* Transposta de a */
                else if (trans == 1) out[i][j] += a[n-i-1][n-k-1]*b[k][j];
                /* Transposta de b */
                else if (trans == 2) out[i][j] += a[i][k]*b[n-k-1][n-j-1];
                /* Duas Transpostas */
                else out[i][j] += a[n-i-1][n-k-1]*b[n-k-1][n-j-1];
            }
        }
    }
}

/* Determinante por Triangulação */
float matriz_triang (float ** mat, int n, int lin, int col) {
    int     i,          /* Iterador de Linha Principal */
            j,          /* Iterador de Coluna Principal */
            k,          /* Iterador de Linha Acumulada */
            r,          /* Iterador de Linha Auxiliar */
            c;          /* Iterador de Coluna Auxiliar */
    float   ** trig,    /* Matriz Nova */
            mult,       /* Multiplicador */
            det = 1,
            aux;

    /* Calculando o Tamanho da Matriz Nova */
    if ( lin >= 0 ) n--;

    /* Alocando e Preenchendo a Matriz Nova */
    trig = (float **) malloc( n*sizeof(float *) );
    /* -- Definindo Primeira Linha de mat -- */
    r = 0;
    for (i = 0; i < n; i++) {
    /* -- Primeira Coluna de mat -- */
        c = 0;
        trig[i] = (float *) malloc ( n*sizeof(float) );
        for (j = 0; j < n; j++) {
    /* -- Linhas e Colunas ignoradas são eliminadas aqui -- */
            if (lin == r) r++;
            if (col == c) c++;
    /* -- Guarda o Valor -- */
            trig[i][j] = mat[r][c];
            c++;
        }
        r++;
    }
    
    /* Fazendo Algebrolismos (triangulando a matriz) */
    for (i = 0; i < n - 1; i++) {
    /* -- Troca 1: Permuta de Linhas -- */        
    /* -- Isso Vai buscar a linha sem 0 no indice k,i mais proxima, mesmo que seja a i,i ou nenhuma -- */
        for (k = i; k < n && trig[k][i] == 0; k++);
        if (k != i && k < n) {
            det *= -1;
            for (j = 0; j < n; j++) {
               aux = trig[i][i];
               trig[i][i] = trig[k][i];
               trig[k][i] = aux;
            }
        }

    /* -- Troca 2: Soma -- */
        for (k = i + 1; k < n; k++) { 
    /* -- Se, depois da Permuta o Role Ainda é 0 significa que todos abaixo também são 0 -- */
            if (trig[i][i] == 0) mult = 0;
    /* -- Descobrindo o Multiplicador da Linha Anterior -- */
            else mult = trig[k][i]/trig[i][i];

    /* -- Somando as Linhas -- */
            for (j = 0; j < n; j++) {
                trig[k][j] -= mult*trig[i][j];
            }
        }
    /* -- Calculando o Valor da Determinante -- */
        det *= trig[i][i];
    }

    /* -- Ultimo Valor =) -- */
    det *= trig[n-1][n-1];
    free(trig[n-1]);

    /* Limpando e Retornando */
    for (i = 0; i < n; i++) {
        free(trig[i]);
    }
    free(trig);
    return det;
}

/* Determinante de Matriz: Recebe mat[n][m] e uma lin e col para serem ignorados. */
float matriz_det (float ** mat, int n, int lin, int col) {
    /* Matriz nxn : Resolvendo Por Triangulação */
    return matriz_triang (mat, n, lin, col);
}

void matriz_inversa (float ** in, float ** out, int n) {
    float   det,      /* Determinante de in */
            temp;
    int     i,
            j;

    /* Calculando a Determinante */
    det = matriz_det (in, n, -1, -1);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            /* Calculando a Matriz dos Cofatores */
            temp = matriz_det (in, n, i, j);
            if ((i+j)%2) temp = -temp; 

            /* Calculando a Matriz Inversa */
            out[n-i-1][n-j-1] = temp/det;
        }
    }

}

/* Principal */
int main () {
/* ### ----- Parte 0 || Inicialização ----- ### */
    unsigned int    seed = 482384,  /* Seed da Congruência Linear */
                    lin;            /* ~U(0,1) */
    int     p,          /* Quantidade de Betas */
            n,          /* Quantidade de Observações */
            N,          /* Quantidade de Iterações */
            v,          /* Iterador Mestre */
            i,          /* Iterador 1 */
            j,          /* Iterador 2 */
            k;          /* Iterador 3 */
    float   * betas,    /* Vetor de Betas [p] */
            * vet_y,    /* Vetor de Ys (somatórias de xB com erro) [n] */
            * vet_u,    /* Vetor Temporário [p] */
            ** mat_s,   /* Matriz Temporária [n][n] */
            ** mat_t,   /* Matriz Temporária [n][n] */
            ** mat_x,   /* Matriz de Xs (xB) [n][p] */
            ** estim,   /* Matriz de  Betas Estimados [N][p] */
            tab[NUMS],  /* Tabela da Normal */
            aux;        /* Variável Auxiliar */

    /* Inserção de Valores */
    printf("Entre com os valores de p, n e N.\n");
    scanf("%d %d %d", &p, &n, &N);
    printf("Entre com %d valores de beta.\n", p);

    /* Alocação Dinâmica */
    betas = (float *) malloc( p*sizeof(float) );
    vet_u = (float *) malloc( p*sizeof(float) );
    vet_y = (float *) malloc( n*sizeof(float) );
    mat_x = (float **) malloc( n*sizeof(float *) );
    mat_s = (float **) malloc( p*sizeof(float *) );
    mat_t = (float **) malloc( p*sizeof(float *) );
    estim = (float **) malloc( N*sizeof(float *) );
    for (i = 0; i < N || i < n || i < p; i++) {
        if ( i < n ) {
            mat_x[i] = (float *) malloc ( p*sizeof(float) );
        }
        if ( i < p ) { 
            mat_s[i] = (float *) malloc ( p*sizeof(float) );
            mat_t[i] = (float *) malloc ( p*sizeof(float) );
        }
        if ( i < N ){
            estim[i] = (float *) malloc ( p*sizeof(float) );
        }
    }

    /* Inserção de Betas */
    for (i = 0; i < p; i++) {
        scanf("%f", &betas[i]);
    }

    /* Geração da Tabela de Normal */
    gerar_tabela(tab); 

    /* ### ----- Parte 1 || Gerando Vetores de Betas ----- ### */
    for (v = 0; v < N; v++) {
    /* ## --- Parte 1.1 || Gerando Matrizes --- ## */
        for (i = 0; i < n; i++) {
            /* Gerando Erro de y */
            seed = aleatorio_uniforme(seed);
            lin = seed%100000;
            vet_y[i] = aleatorio_normal(tab, (float)lin/100000);

            for (j = 0; j < p; j++) {
                /* Gerando o Aleatório */
                seed = aleatorio_uniforme(seed);
                lin = seed%100000;
                /* Colocando em X e Y */
                mat_x[i][j] = aleatorio_normal(tab, (float)lin/100000);
                vet_y[i] += mat_x[i][j];
            }
        }
        
    /* ## --- Parte 1.2 || Fazendo Cálculos --- ## */
        /* Equação: (mat_x^(T)*mat_x)^(-1)*mat_x^(T)*vet_y = estim[v] *\
        ** vet_y[n]
        ** vet_u[p]
        ** mat_x[n][p]
        ** mat_s[p][p]
        ** mat_t[p][p]
        ** estim[N][p]
        \* ---------------------------------------------------------- */
        /* Parte 1: mat_x^(T) * mat_x = mat_s */
        for (i = 0; i < p; i++) {
            for (j = 0; j < p; j++) {
                mat_s[i][j] = 0;
                for (k = 0; k < n; k++) {
                    mat_s[i][j] += mat_x[n-k-1][p-i-1]*mat_x[k][j];
                }
            }
        }
        
        /* Parte 2: mat_t = mat_s^(-1) */
        matriz_inversa(mat_s, mat_t, p);

        /* Parte 3: vet_u = mat_x^(T)*vet_y */
        for (i = 0; i < p; i++) {
            vet_u[i] = 0;
            for (k = 0; k < n; k++) {
                vet_u[i] += mat_x[n-k-1][p-i-1]*vet_y[k];
            }
        }

        /* Parte 4: estim[v] = mat_t*vet_u */
        for (i = 0; i < p; i++) {
            estim[v][i] = 0;
            for (j = 0; j < p; j++) {
                estim[v][i] += mat_t[i][j]*vet_u[j];
                /* Ordenando no Vetor */
                for (k = v; k > 0 && estim[k][i] < estim[k-1][i]; k--) {
                    aux = estim[k-1][i];
                    estim[k-1][i] = estim[k][i];
                    estim[k][i] = aux;
                }
            }
        }
    }

/* ### ----- Parte 2 || Imprimindo ----- ### */
    printf("Beta #   valor      ||  q(0.25)    ||  q(0.5)     ||  q(0.75)       ||\n");
    for (v = 0; v < p; v++) {
        printf("%3d      ", v);

        printf("%+2.6f  ", betas[v]);
        printf("||  %+2.6f  ", estim[N/4][v]);
        printf("||  %+2.6f  ", estim[N/2][v]);
        printf("||  %+2.6f     ||\n", estim[3*N/4][v]);
    }

/* ### ----- Parte 3 || Finalizando ----- ### */
    /* Soltando os malucos */
    for (i = 0; i < n || i < N || i < p; i++) {
        if(i < n) {
            free(mat_x[i]);
        }
        if(i < p) {
            free(mat_s[i]);
            free(mat_t[i]);
        }
        if(i < N) {
            free(estim[i]);
        }
    }
    free(betas);
    free(vet_y);
    free(vet_u);
    free(mat_x);
    free(mat_s);
    free(mat_t);
    free(estim);

    return 0;
}
