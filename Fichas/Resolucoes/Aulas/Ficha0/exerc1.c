#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 2
#define COLUNAS 3

int Esparsa(int * Matriz, int M, int n, float percentagem);
int * CriarPreencherMatriz(int M, int N);
void DestruirMatriz(int * Matriz);
int Aleatorio(int min, int max);
void MostrarMatriz(int * matriz, int m, int n);

int main() {
    srand(time(NULL));
    int MAT = NULL;
    MAT = CriarPreencherMatriz(LINHAS, COLUNAS);


    return 0;
}

int Esparsa(int * Matriz, int m, int n, float percentagem) {
    int cont_zeros = 0;
    int n_elementos = m * n;
    for (int i = 0; i < n_elementos; i++) {
        if (Matriz[i] == 0) cont_zeros++;
    }

    float p_zeros = cont_zeros / n_elementos;
    if (p_zeros > percentagem) return 1;

    return 0;
}


int * CriarPreencherMatriz(int m, int n) {
    if (m == 0|| n == 0) {
        return NULL;
    }

    int * matriz = (int *) malloc(m * n * sizeof(int));
    if (!matriz) {
        return NULL;
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

        }
    }
    return NULL;
}

void DestruirMatriz(int * matriz) {
    if (!matriz) free(matriz);
}

void MostrarMatriz(int * matriz, int m, int n) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            print("%d\t", count++);
        }
        print("\n");
    }
}

int Aleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}