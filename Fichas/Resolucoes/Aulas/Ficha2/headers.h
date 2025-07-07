#ifndef FICHA2_HEADERS
#define FICHA2_HEADERS

#define MAX_PALAVRA 50
#define MAX_LINGUA 3

#define LINGUA_DEFAULT "PT"
#define FILENAME "PT.txt"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

typedef struct {
    char texto[MAX_PALAVRA];
} Palavra, *ptPALAVRA;

typedef struct elemento {
    Palavra * info;
    struct elemento * prox;
} Elemento, *ptELEMENTO;

typedef struct {
    char lingua[MAX_LINGUA];
    int n_elementos;
    Elemento * inicio;
} Lista, *ptLISTA;

int randomInt(int min, int max);

Lista * criar_lista();
Elemento * criar_elemento();
int validar_elemento(Elemento e);
void ler_elemento(Elemento e);
void inserir_elemento_inicio(Lista * lista, Elemento * e);
void inserir_elemento_fim(Lista * lista, Elemento * e);
int comparar_elementos(Elemento * a, Elemento * b);
int elementos_iguais(Elemento * a, Elemento * b);
void inserir_elemento_ordenado(Lista * li, Elemento * novo);
Elemento * pesquisar_iterativo(Lista * li, Elemento * chave);
Elemento * pesquisar_recursivo(Lista * li, Elemento * chave);
void libertar_elemento(Elemento * e);
int remover_elemento(Lista * li, Elemento * remover);
void remover_primeiro(Lista * li);
void remover_ultimo(Lista * li);
void mostrar_elemento(Elemento * e);

void ordenarLista(Lista * li);
Lista * criar_lista_aleatoria();
void mostrar_lista(Lista * li);



#endif
