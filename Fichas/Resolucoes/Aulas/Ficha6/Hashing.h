//
//  Hashing.h
//  Ficha5_Hashing_Base
//
//  Created by Jorge Loureiro on 31/03/2025.
//

#ifndef Hashing_h
#define Hashing_h

#include "Lista.h"

// ---------------------------------------------------------------------
// estruturas de dados
#define MAX_FAIXAS_ETARIAS 10

typedef struct Grupo {
  int faixaEtaria;
  ptLISTA lista;
} GRUPO;

// 10 faixas etárias possíveis
typedef struct Hashing {
	GRUPO vetor[MAX_FAIXAS_ETARIAS]; //se não soubessemos o num de faixas etárias??
} *ptHASHING, HASHING;


// ---------------------------------------------------------------------
// prototipos funcoes
ptHASHING CriarVectorHashing(void);
void DestruirHashing(ptHASHING H);
void InicializarVectorHashing(ptHASHING HashPessoas);
int PosicaoHashingElemento(ptELEM eleA);
int ValidarPosicaoHashing(int pos);
void InserirElementoHashing(ptHASHING H, ptELEM Y);
void MostrarElementosHashing(ptHASHING EstHashing);
ptELEM RemoverElementoHashing(ptHASHING H, ptELEM Y);
ptELEM PesquisarElementoHashing(ptHASHING H, ptELEM Y);

#endif /* Hashing_h */
