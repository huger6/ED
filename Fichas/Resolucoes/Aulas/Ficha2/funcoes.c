#include "headers.h"

Lista * criar_lista() {
    Lista * lista = (Lista *) malloc(sizeof(Lista));
    if (!lista) return NULL;

    lista->inicio = NULL;
    lista->n_elementos = 0;
    strcpy(lista->lingua, LINGUA_DEFAULT);

    return lista;
}

Elemento * criar_elemento() {
    Elemento * p = (Elemento *) malloc(sizeof(Elemento));
    if (!p) return NULL;

    p->info = (Palavra *) malloc(sizeof(Palavra));
    p->prox = NULL;

    return p;
}

/*
int validar_elemento(Elemento e) {
    if (!e) return 0;

    int tamanho_str = strlen(e.info->texto);

    for (int i = 0; i < tamanho_str; i++) {
        if (!isalpha(e->info->texto[i])) return 1;
    }
    return 1;
}

void ler_elemento(Elemento e) {
    if (!e || !e.info) return;

    do {
        printf("Palavra: ");
        scanf(" %s", e->info->texto);
    } while (!validar_elemento(e));
}

*/

void inserir_elemento_inicio(Lista * lista, Elemento * e) {
    if (!lista || !e) return;

    e->prox = lista->inicio;
    lista->inicio = e;
    lista->n_elementos++;
}

/*
void inserir_elemento_fim(Lista * lista, Elemento * e) {
    if (!lista || !e) return;

    Elemento * X = lista->inicio;

    if (lista->n_elementos == 0) {
        X->prox = e;
    }
    else {
        while( X->prox != NULL) {
            X = X->prox;
        }
        //Cheg�mos ao �ltimo elemento da lista
        X->prox = e;
    }

    e->prox = NULL;
    lista->n_elementos++;
}

*/

int comparar_elementos(Elemento * a, Elemento * b) {
    return (strcmp(a->info->texto, b->info->texto));
}

int elementos_iguais(Elemento * a, Elemento * b) {
    if (strcmp(a->info->texto, b->info->texto) == 0) {
        return 1;
    }

    return 0;
}

/*
void inserir_elemento_ordenado(Lista * li, Elemento * novo) {
    if (!li || !novo) return;

    Elemento * anterior = NULL;
    Elemento * proximo = li->inicio;
    while(proximo) {
        if (comparar_elementos(novo->info->texto, proximo->info->texto) > 0) {
            anterior = proximo;
            proximo = proximo->prox
        }
        else break;
    }
    //Inserir entre o anterior e o proximo
    if (anterior) anterior->prox = novo;
    //Inserir no inicio
    else li->inicio = novo;

    novo->prox = proximo;
    li->n_elementos++;
}

Elemento * pesquisar_iterativo(Lista * li, Elemento * chave) {
    Elemento * X = li->inicio;

    while(X->prox != NULL) {
        if (comparar_elementos(X->prox->info->texto, chave->info->texto) == 0) {
            return X->prox->info;
        }
        X = X->prox;
    }
    //Cheg�mos ao �ltimo elemento da lista
    if (comparar_elementos(X->info->texto, chave->info->texto) == 0) {
        return X->prox->info;
    }
    //N�o foi encontrado
    return NULL;
}

Elemento * pesquisar_recursivo(Lista * li, Elemento * chave) {
    if (!li || !li->inicio) return NULL; //N�o existe

    Elemento * atual = li->inicio;
    if (elementos_iguais(atual, chave)) {
        return atual;
    }

    Lista novaLista;
    novaLista.inicio = atual->prox;
    novaLista.n_elementos = li->n_elementos - 1;
    strcpy(novaLista.lingua, li->lingua);

    return pesquisar_recursivo(&novaLista, chave);
}

int elemento_repetidos(Lista * li) {
    Elemento * x = li->inicio;

    while(x) {
        while(x->prox) {
            if (comparar_elementos(x->info->texto, x->prox->info->texto) == 0) {
                return 1;
            }
            x = x->prox;
        }
        x = x->prox;
    }

    return 0;
}

void libertar_elemento(Elemento * e) {
    free(e->info);
    free(e);
}

int remover_elemento(Lista * li, Elemento * remover) {
    Elemento * anterior = NULL;
    Elemento * prox = li->inicio;

    int flag = 0;
    while (!flag && prox) {
        if (strcmp(prox->info->texto, remover->info->texto) == 0) {
            flag = 1;
        }
        else {
            anterior = prox;
            prox = prox->prox;
        }
    }
    if (flag) {
        if (anterior) {
            anterior->prox = prox->prox;
        }
        else {
            li->inicio = prox->prox;
        }

        libertar_elemento(remover);
        li->n_elementos--;
    }
    return flag;
}

void remover_primeiro(Lista * li) {
    Elemento * remover = li->inicio;
    if (!remover) return;

    li->inicio = li->inicio->prox;
    libertar_elemento(remover);
    li->n_elementos--;
}

void remover_ultimo(Lista * li) {
    Elemento * x = li->inicio;
    Elemento * anterior = NULL;
    //Ir para o �ltimo
    while(x->prox) {
        anterior = x;
        x = x->prox;
    }

    //Remover o x(ultimo)
    libertar_elemento(x);
    anterior->prox = NULL;
    li->n_elementos--;
}

void mostrar_elemento(Elemento * e) {
    printf("Texto: %s\n", e->info->texto);
}

//Exerc extra

int removerPorPosicao(Lista * li, int k) {
    if (k > li->n_elementos || k < 0) return 0;

    Elemento * ant = NULL;
    Elemento * p = li->inicio;

    for (int i = 0; i < k; i++) {
        ant = p;
        p = p->prox;
    }

    ant->prox = p->prox;
    free(p->info);
    free(p);

    return 1;
}

int contarComuns(Lista * li, Lista * li2) {
    Elemento * p = li->inicio;
    int comuns = 0;
    while(p) {
        Elemento * q = li2->inicio;
        while(q) {
            if (comparar_elementos(p->info->texto, q->info->texto) == 0) {
                comuns++;
            }
            q = q->prox;
        }
        p = p->prox;
    }

    return comuns;
}

int inverterLista(Lista * li) {
    Elemento * p = li->inicio;
    Elemento * ant = NULL;
    Elemento * seg = NULL;

    while(p) {
        seg = p->prox;
        p->prox = ant;
        ant = p;
        p = seg;
    }
    li->inicio = ant;
}

*/

void ordenarLista(Lista * li) {
    if (!li || li->n_elementos < 2) return;

    int trocou;
    do {
        Elemento * ant = NULL;
        Elemento * a = li->inicio; //atual
        Elemento * p = a->prox; //proximo
        trocou = 0;

        while (p) {
            if (comparar_elementos(a, p) > 0) {
                trocou = 1; //trocar p para a posicao de atual
                a->prox = p->prox;
                p->prox = a;

                if (ant) ant->prox = p;
                else li->inicio = p; //atual � o inicio

                ant = p;
                p = a->prox;
            } else {
                ant = a;
                a = p;
                p = p->prox;
            }
        }
    } while (trocou);
}

//Testar ordenarLista

int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

Lista * criar_lista_aleatoria() {
    Lista * li = criar_lista();
    if (!li) return NULL;

    int tamanho = randomInt(5, 20);

    for (int i = 0; i < tamanho; i++) {
        Elemento * novo = criar_elemento();
        if (!novo) continue;

        int len = randomInt(3, 9);
        for (int j = 0; j < len; j++) {
            novo->info->texto[j] = 'a' + rand() % 26; // Letras de a a z
        }
        novo->info->texto[len] = '\0';

        inserir_elemento_inicio(li, novo);
    }

    return li;
}

void mostrar_lista(Lista * li) {
    Elemento * atual = li->inicio;
    while (atual) {
        printf("%s -> ", atual->info->texto);
        atual = atual->prox;
    }
    printf("NULL\n");
}

