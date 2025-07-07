#ifndef ARVORES_HEADERS
#define ARVORES_HEADERS

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no *left;
    struct no *right;
    int *num;
} NoArvore;

typedef struct {
    NoArvore *root;
    int nel;
} ArvBinaria;

ArvBinaria *criarArvBinaria();
void printArvBinaria(ArvBinaria *ab);
void freeArvBinaria(ArvBinaria *ab);
int *pesquisarArvBinaria(ArvBinaria *ab, int cod);
void addToArvBinaria(ArvBinaria *ab, int *num);
void deleteFromArvBinaria(ArvBinaria *ab, int *num);
int contarNosArvBinaria(ArvBinaria *ab);
int contarFolhas(ArvBinaria *ab);
int contarFolhasNivelPar(ArvBinaria *ab);
int alturaArvBinaria(ArvBinaria *ab);
int arvBinariaEquilibrada(ArvBinaria *ab);
void inverterOrdem(ArvBinaria *ab);



#endif