//
//  Lista.h
//  Ficha5_Hashing_Base
//
//  Created by Jorge Loureiro on 31/03/2025.
//

#ifndef Lista_h
#define Lista_h

#include "Pessoa.h"
// ---------------------------------------------------------------------
// estruturas de dados

typedef struct Elemento {
  ptPESSOA info;
  struct Elemento *seg;
} ELEM, *ptELEM;

typedef struct Lista {
  int numel;
  ptELEM inicio;
} *ptLISTA, LISTA;


// ---------------------------------------------------------------------
// prototipos funcoes
ptLISTA CriarLista(void);
ptELEM CriarElemento(void);
void DestruirLista(ptLISTA lista);void DestruirElemento(ptELEM eleA);
void LerElemento(ptELEM eleNovo);
void GerarElementoPreenchido(ptELEM eleNovo);
void MostrarElemento(ptELEM eleA);
void MostrarLista(ptLISTA lista);
void InserirElementoListaOrdenado(ptLISTA L, ptELEM eleNovo);
int CompararElementos(ptELEM A, ptELEM B);
int ElementosIguais(ptELEM A, ptELEM B);
ptELEM PesquisarElementoLista(ptLISTA L, ptELEM elePesquisa);
ptELEM RemoverElementoLista(ptLISTA L, ptELEM eleRemover);
int SizeLista(ptLISTA L);

#endif /* Lista_h */
