#include "arvore.h"

ArvBinaria *criarArvBinaria() {
    ArvBinaria *ab = (ArvBinaria *)malloc(sizeof(ArvBinaria));
    ab->root = NULL;
    ab->nel = 0;
    return ab;
}

static void printNoArvBinaria(NoArvore *no) {
    if (!no || !no->num) return NULL;
    printNoArvBinaria(no->left);
    printf("%d\n", *(no->num));
    printNoArvBinaria(no->right);
}

void printArvBinaria(ArvBinaria *ab) {
    if (!ab) return;

    printNoArvBinaria(ab->root);
}

static void freeNo(NoArvore *no) {
    if (!no) return;
    
    freeNo(no->left);
    freeNo(no->right);
    free(no->num);
    free(no);
}

void freeArvBinaria(ArvBinaria *ab) {
    if (!ab) return;
    
    freeNo(ab->root);
    free(ab);
}

static int *pesquisarNos(NoArvore *no, int cod) {
    if (!no) return NULL;
    if (*(no->num) == cod) return no->num;
    if (cod < no->num) return pesquisarNos(no->left, cod);
    return pesquisarNos(no->right, cod);
}

int *pesquisarArvBinaria(ArvBinaria *ab, int cod) {
    if (!ab) return;
    
    return pesquisarNos(ab->root, cod);
}

static NoArvore *addNoArvBinaria(NoArvore *no, int *num, int *inserted) {
    if (!no) {
        no = (NoArvore *)malloc(sizeof(NoArvore));
        if (!no) return;
        no->left = NULL;
        no->right = NULL;
        no->num = num;
        *inserted = 1;
    }
    if (*num < *(no->num)) no->left = addNoArvBinaria(no->left, num, inserted);
    else if (*num > *(no->num)) {
        no->right = addNoArvBinaria(no->right, num, inserted);
    }
    return no;
}

void addToArvBinaria(ArvBinaria *ab, int *num) {
    if (!ab || !num) return;

    int inserted = 0;
    ab->root = addNoArvBinaria(ab->root, num, &inserted);
    if (inserted) ab->nel++;
}

static NoArvore *deleteNoArvBinaria(NoArvore *no, int *num, int *removed) {
    if (!no || !num) return NULL;
    
    if (*num == *(no->num)) {
        if (!no->left || !no->right) {
            free(no->num);
            free(no);
            *removed = 1;
            return NULL;
        }
        else {
            if (no->left) {
                NoArvore *sub = maiorNo(no->left);
                int *aux = no->num;
                no->num = sub->num;
                no->left = deleteNoArvBinaria(no->left, num, removed);
            }
            else {
                NoArvore *sub = menorNo(no->right);
                int *aux = no->num;
                no->num = sub->num;
                no->right = deleteNoArvBinaria(no->right, num, removed);
            }
        }
    }
    else {
        if (*num < *(no->num)) {
            no->left = deleteNoArvBinaria(no->left, num, removed);
        }
        else {
            no->right = deleteNoArvBinaria(no->right, num, removed);
        }
    }
    return no;
}

void deleteFromArvBinaria(ArvBinaria *ab, int *num) {
    if (!ab || !num) return;

    int removed = 0;
    ab->root = deleteNoArvBinaria(ab->root, num, &removed);
    if (removed) ab->nel--;
}

static int contarNos(NoArvore *no) {
    if (!no) return 0;

    int nos = 1;
    nos += contarNos(no->left);
    nos += contarNos(no->right);
    return nos;
}

int contarNosArvBinaria(ArvBinaria *ab) {
    if (!ab) return 0;

    return contarNos(ab->root);
    // Ou então faz-se:
    // return ab->nel;
}

static int contarFolhasNo(NoArvore *no) {
    if (!no) return 0;
    if (!no->left && !no->right) {
        return 1;
    }
    return contarFolhasNo(no->left) + contarFolhasNo(no->right);
}

int contarFolhas(ArvBinaria *ab) {
    if (!ab) return 0;

    return contarFolhasNo(ab->root);
}

static int contarFolhasNoPar(NoArvore *no, int nivel) {
    if (!no) return 0;

    if (nivel % 2 == 0 && !no->left && !no->right) {
        return 1;
    }
    else if (nivel % 2 != 0 && !no->left && !no->right) {
        return 0;
    }
    return contarFolhasNoPar(no->left, ++nivel) + contarFolhasNoPar(no->right, ++nivel);
}

int contarFolhasNivelPar(ArvBinaria *ab) {
    if (!ab) return 0;

    return contarFolhasNoPar(ab->root, 1);
}

static int alturaNosArvBinaria(NoArvore *no) {
    if (!no) return 0;
    
    if (!no->left && !no->right) return 1;

    return 1 + max(alturaNosArvBinaria(no->left), alturaNosArvBinaria(no->right));
}

int alturaArvBinaria(ArvBinaria *ab) {
    if (!ab) return 0;

    return alturaNosArvBinaria(ab->root);
}

static int nosEquilibrados(NoArvore *no) {
    if (!no) return 1;

    if (modulo(alturaNosArvBinaria(no->left) - alturaNosArvBinaria(no->right)) > 1) return 0;

    return nosEquilibrados(no->left) && nosEquilibrados(no->right);
}

int arvBinariaEquilibrada(ArvBinaria *ab) {
    if (!ab) return 1;

    return nosEquilibrados(ab->root);
}

static NoArvore *inverterOrdemNo(NoArvore *no) {
    if (!no) return NULL;

    NoArvore *temp = no->left;
    no->left = inverterOrdemNo(no->right);
    no->right = inverterOrdemNo(temp);

    return no;
}

void inverterOrdem(ArvBinaria *ab) {
    if (!ab) return;

    ab->root = inverterOrdemNo(ab->root);
}


// Auxiliares

NoArvore *maiorNo(NoArvore *no) {
    if (!no) return NULL;
    if (!no->right) return no;
    return maiorNo(no->right);
}

NoArvore *menorNo(NoArvore *no) {
    if (!no) return NULL;
    if (!no->left) return no;
    return menorNo(no->left);
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int modulo(int a) {
    if (a < 0) return -a;
    return a;
}