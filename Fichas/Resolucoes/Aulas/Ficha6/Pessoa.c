//
//  Pessoa.c
//  Ficha5_Hashing_Base
//
//  Created by Jorge Loureiro on 31/03/2025.
//

#include "Pessoa.h"

// Função que gera um número aleatório entre mim e max
int Aleatorio(int min, int max)
{
	return min + rand() % (max - min + 1);
}

// Função que aloca memória para uam pessoa
ptPESSOA CriarPessoa(void){
	ptPESSOA pessoazinha = (ptPESSOA) malloc(sizeof(PESSOA));
	return pessoazinha;
}

// Função que aceita os dados relativos à pessoa e retorna o respectivo ponteiro
ptPESSOA LerPessoa(void){
	ptPESSOA pessoazinha = CriarPessoa();
	if(!pessoazinha) return NULL;

	printf("Nome: ");
	char PessoaNome[MAX_NOME+1];

	sprintf(pessoazinha->nome, "%s", PessoaNome);
	printf("Idade: ");
	scanf("%d", &pessoazinha->idade);
	printf("Peso: ");
	scanf("%f", &pessoazinha->peso);
	printf("Altura: ");
	scanf("%f", &pessoazinha->altura);

	return pessoazinha;
}

// Função que gera uma pessoa usando algumas "Sementes" acrescentando depois números aleatórios gerados
// Substitui a função LerPessoa, evitando, assim, estar a aceitar os vários membros (campos da pessoa)
ptPESSOA GerarPessoaPreenchida(void){
	ptPESSOA pessoazinha = CriarPessoa();
	if(!pessoazinha) return NULL;

	char *ListaNomesProprios[ ] = {"Francisco", "Jorge", "Carlos", "Raquel", "Miguel"};
	sprintf(pessoazinha->nome, "%s", ListaNomesProprios[Aleatorio(0,4)]);
	pessoazinha->idade = Aleatorio(1,100);
	pessoazinha->peso = (1.0*Aleatorio(80,1200))/10;
	pessoazinha->altura = (1.0*Aleatorio(70,199))/100;
	return pessoazinha;
}

// Função que mostar os dados de uma pessoa
void MostrarPessoa(ptPESSOA X){
	if (X){
		printf("Nome: |%-25s| \t Idade: %d anos \t Peso: %.2f (kg) \t Altura: %.2f (m)\n",
		X->nome, X->idade, X->peso, X->altura);
	}
}

// Função que limpa os dados alocado a uma pessoa, passando a ficar disponíveis
void DestruirPessoa(ptPESSOA X){
	if(X)
		free(X);
}

// Função que compra pessoas
int CompararPessoas(ptPESSOA X, ptPESSOA Y){
	if(!X && !Y)
		return 0;
	if(!X)
		return -1;
	if(!Y)
		return 1;

	if (X->idade < Y->idade)
		return -1;
	else if (X->idade == Y->idade)
		return 0;
	else
		return 1;
}

// Função que retrorna o valor lógico da comparação entre 2 pessoas
int PessoasIguais(ptPESSOA X, ptPESSOA Y){
	return CompararPessoas(X, Y) == 0;
}
