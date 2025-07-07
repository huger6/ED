#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float nota;
    char * nome;
} UC;

typedef struct {
    int n_mecanografico;
    char * nome;
    UC cadeiras[5];
} Aluno;

int Aleatorio(int min, int max) {
    int valor = min + rand() % (max - min + 1);
    return valor;
}

char * NomeAleatorio(int n) {
    char * nome = (char *)  malloc(n * sizeof(char));

    for (int i = 0; i < n; i++) {
        nome[i] = (char) Aleatorio(65, 90);
    }
    nome[n-1] = '\0';

    return nome;
}

Aluno GerarDadosAleatorios(int n) {
    Aluno * vetor = (Aluno *) malloc(n * sizeof(Aluno *));
    
    for (int i = 0; i < n; i++) {
        vetor[i].nome = NomeAleatorio(20);
        vetor[i].n_mecanografico = Aleatorio(0, 30000);
        
        for (int j = 0; j < 5; j++) {
            vetor[i].cadeiras[j].nome = NomeAleatorio(1);
            vetor[i].cadeiras[j].nota = Aleatorio(0,200) / 10.0f; 
        }
    }
    
    return vetor;
}

void DestruirVetor(Aluno * vetor, int n) {
    if (!vetor) return;
    
    for (int i = 0; i < n; i++) {
        if (vetor[i].nome) free(vetor[i].nome);
        
        for (int j = 0; j < 5; j++) {
            if (vetor[i].cadeiras[j].nome) free(vetor[i].cadeiras[j].nome);
        }
    }

    free(vetor);
}

int qtosPassam(Aluno * vetor, int n) {
    int passam = 0;

    for (int i = 0; i < n; i++) {
        float media = 0.0f;
        for (int j = 0; j < 5; j++) {
            media += vetor[i].cadeiras[j].nota;
        }
        if (media == 0) continue;
        media /= 5;
        if (media >= 9.5) passam++;
    }

    return passam;
}



int main() {
    srand(time(NULL));

    char * nome = NomeAleatorio(10);
    printf("%s1", nome);
}
