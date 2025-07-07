//
//  Pessoa.h
//  Ficha5_Hashing_Base
//
//  Created by Jorge Loureiro on 31/03/2025.
//

#ifndef Pessoa_h
#define Pessoa_h

// ---------------------------------------------------------------------
// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ---------------------------------------------------------------------
// estruturas de dados
#define MAX_NOME 20

typedef struct Pessoa {
  char nome[MAX_NOME+1];
  int idade;
  float peso;
  float altura;
} *ptPESSOA, PESSOA;

ptPESSOA CriarPessoa(void);
ptPESSOA LerPessoa(void);
ptPESSOA GerarPessoaPreenchida(void);
void MostrarPessoa(ptPESSOA X);
void DestruirPessoa(ptPESSOA X);
int CompararPessoas(ptPESSOA X, ptPESSOA Y);
int PessoasIguais(ptPESSOA X, ptPESSOA Y);

// ---------------------------------------------------------------------
// prototipos funcoes




#endif /* Pessoa_h */
