//
//  Lista.c
//  Ficha5_Hashing_Base
//
//  Created by Jorge Loureiro on 31/03/2025.
//

#include "Lista.h"
// Função para criar a lista
ptLISTA CriarLista(void){
	ptLISTA L = (ptLISTA)malloc(sizeof(LISTA));
	if(!L) return NULL;

	L->numel = 0;
	L->inicio = NULL;
	return L;
}

// Função para criar o elemento ou nó
ptELEM CriarElemento(void){
	ptELEM E = (ptELEM) malloc(sizeof(ELEM));
	if(!E) return NULL;

	E->info = NULL;
	E->seg = NULL;
	return E;
}

// Fução que elimina todos os elementos da lista e, no final, elimina a própria lista
void DestruirLista(ptLISTA lista){
	if (!lista || !lista->inicio) return;

	ptELEM atual = lista->inicio;
	while (atual) {
		ptELEM frente = atual->seg;
		DestruirElemento(atual);
		atual = frente;
  }
  free(lista);
}

// Função que elimina um elemento (nó) da lista
void DestruirElemento(ptELEM eleA){
	if (eleA) {
		DestruirPessoa(eleA->info);
		free(eleA);
	}
}

// Função que aceita os dados de cada elemento. Caso tenha havido erro ao ler os dados do elemento, vai destruir o elemento
void LerElemento(ptELEM eleNovo){
	if(eleNovo)
		eleNovo->info = LerPessoa();
	if(!eleNovo->info) DestruirElemento(eleNovo);
}

// Função que gera um elemento preenchido com valores gerados aleatoriamente
void GerarElementoPreenchido(ptELEM eleNovo) {
	if(!eleNovo) return;

	eleNovo->info = GerarPessoaPreenchida();
	if(!eleNovo->info) DestruirElemento(eleNovo);
}

// Função que mostra os dados de um qq. elemento
void MostrarElemento(ptELEM eleA){
	if(eleA)
		MostrarPessoa(eleA->info);
}

// Função que vai mostrar todos os elementos da lista, invocando a função MostrarElemento para apresentar cada um deles
void MostrarLista(ptLISTA lista){
	if(!lista || !lista->inicio) return;
	printf("numel = %d\n", lista->numel);
	ptELEM p = lista->inicio;
	while(p){
		MostrarElemento(p);
		p = p->seg;
	}
}

// Função que vai inserir um elemento novo na lista, inserirndo-o de modo a que a lista esteja asempre ordenada de forma crescente
// atendendo ao membro que é usado na função CompararElemento
void InserirElementoListaOrdenado(ptLISTA L, ptELEM eleNovo) {
	if (!L || !eleNovo)
		return;

	int av=1;
	ptELEM ant,act;

	if (L->inicio==NULL) {//lista vazia
		eleNovo->seg=NULL;
		L->inicio=eleNovo;
	}else {
		ant = act = L->inicio;
		while(av)
			if(act == NULL)//atingido o fim da lista
				av = 0;
			else if(CompararElementos(act, eleNovo)>0)
				av = 0;// inserir antes de act
			else {//avanÁa para o elemento seguinte
				ant = act;
				act = act->seg;
			}
		if(act == L->inicio) {//inserir no inÌcio
				eleNovo->seg = L->inicio;
				L->inicio = eleNovo;
		}else {//inserir entre ant e act
				ant->seg = eleNovo;
				eleNovo->seg = act;
		}
	}
	L->numel++;
}

// Função que compara elmentos para verificar da sua ordem
// Obviamente deve ser usado código para comparar o membro de cada elemento da lista e do elemento a comparar co o anterior
int CompararElementos(ptELEM A, ptELEM B) {
	if(!A && !B)
		return 0;
	if(!A)
		return -1;
	if(!B)
		return 1;
	return CompararPessoas(A->info, B->info);
}

// Função que vai retornar o valor lógico atendendo à comparação feita com a função CompararElementos
int ElementosIguais(ptELEM A, ptELEM B) {
	return PessoasIguais(A->info,B->info);
}

// Função que vai pesquisar um elemento na lista, atendendo a um membro da pessoa, devendo a função ElementosIguais e as
// que são invocadas por esta, ser adequadas a comparar o membro correspondente
ptELEM PesquisarElementoLista(ptLISTA L, ptELEM elePesquisa) {
  if (!elePesquisa || !L || !elePesquisa)
	return NULL;

  ptELEM aux = L->inicio;
  while (aux) {
	if (ElementosIguais(aux, elePesquisa))
		return aux;
	else
		aux = aux->seg;
  }
  return NULL;
}

// Função que vai eliminar um elemento da lista, atendendo a um membro da pessoa, devendo a função ElementosIguais e as
// que são invocadas por esta, ser adequadas a comparar o membro correspondente
ptELEM RemoverElementoLista(ptLISTA L, ptELEM eleRemover)
{
	if (!L || L->inicio == NULL || !eleRemover)
		return NULL;

	int av = 1;
	ptELEM ant,act;

	ant = act = L->inicio;
	while(av)
		if(act == NULL)  //chegou ao fim, sem encontrar
			av = 0;
		else if(ElementosIguais(act, eleRemover))
			av = 0; //encontrado elemento a remover: act
		else { // avança nos elementos
			ant = act;
			act = act->seg;
		}

	if(act == NULL) // nao encontrou o elemento a remover
		return NULL;

	// act: elemento a remover da lista
	if(L->inicio == act) // elem a remover é o primeiro
		L->inicio = act->seg;
	else
		ant->seg = act->seg; // fazer ligação entre elementos saltando o elemento a remover (act)

	L->numel--;
	return act;
}

// Função que retorna o número de elementos da lista
int SizeLista(ptLISTA L)
{
	if (!L) return -1;
	return L->numel;
}
