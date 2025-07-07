//
//  Hashing.c
//  Ficha5_Hashing_Base
//
//  Created by Jorge Loureiro on 31/03/2025.
//

#include "Hashing.h"

ptHASHING CriarVectorHashing(void){
	HASHING * has = (HASHING *)malloc(sizeof(HASHING));
	if (!has) return NULL;
	for (int i = 0; i < MAX_FAIXAS_ETARIAS; i++) {
		has->vetor[i].faixaEtaria = i;
		has->vetor[i].lista = NULL;
	}
	InicializarVectorHashing(has);
	return has;
}

void DestruirHashing(ptHASHING H){
	for (int i = 0; i < MAX_FAIXAS_ETARIAS; i++) {
		DestruirLista(H->vetor[i].lista);
	}
	free(H);
}

void InicializarVectorHashing(ptHASHING HashPessoas){
	for (int i = 0; i < MAX_FAIXAS_ETARIAS; i++) {
		if (HashPessoas->vetor[i].lista == NULL) {
			HashPessoas->vetor[i].lista = CriarLista();
			HashPessoas->vetor[i].lista->inicio = NULL;
			HashPessoas->vetor[i].lista->numel = 0;
		}
	}
}

int PosicaoHashingElemento(ptELEM eleA){
	printf("vou fazer a ff |%s| aqui...\n", __FUNCTION__);
	/*
	 Dicas:
		1. Há que validar se existe o hashing;
		2. Determinar em que sublista o elemento E deverá ser inserido;
		3. Importam determinar se a sublista calculada é válida;
		4. Se for válida, então, sim, inserir o elemento na sublista apropriada, de forma ordenada;
		5. Mostar erro, de contrário.
	 */
	if (!eleA || !eleA->info) return -1;
	
	int pos = eleA->info->idade % MAX_FAIXAS_ETARIAS;
	if (pos < 0 || pos >= MAX_FAIXAS_ETARIAS) return -1;
	
	return pos;
}

int ValidarPosicaoHashing(int pos){
	printf("vou fazer a ff |%s| aqui...\n", __FUNCTION__);
	/*
	 Dicas:
		1. 	Simplesmente verificar se a posição calculada no vector
			(qual a sublista onde o elemento será inserido é válida);
		2.	Mostrar mensagem, de contrário.
	 
	 */
	return -1;
}

void InserirElementoHashing(ptHASHING H, ptELEM Y){
	printf("vou fazer a ff |%s| aqui...\n", __FUNCTION__);
	/*
	 Dicas:
		1. 	Há que determinar a posição do vector (qual a sublista) onde se irá inserir
			o novo elemento
		2.	Depois, valídar a posição (usar a função respectiva);
		3.  Se a posição for válida, inserir o novo elemento na sublista apropriada;
		4.  Mostrar mensagem de erro, de contrário.
	 */
	if (!H || !Y) {
		printf("Erro!\n");
		return;
	}
	//Determinar posicao
	int pos = PosicaoHashingElemento(Y);

	//Inicializar listas se necessário
	if (!H->vetor[pos].lista) {
		H->vetor[pos].lista = CriarLista();
		if (!H->vetor[pos].lista) {
			printf("Erro a criar lista\n");
			return;
		}
	}

	//Inserir na lista
	InserirElementoListaOrdenado(H->vetor[pos].lista, Y);
}

void MostrarElementosHashing(ptHASHING EstHashing){
	printf("vou fazer a ff |%s| aqui...\n", __FUNCTION__);
	/*
	 Dicas:
		No hashing, não vai haver uma lista, mas várias sublistas.
		Assim ter-se-ão de mostar os elementos de todas as sublistas. Assim:
		1.	Há que percorrer o vector para saber qual a "sublista" associada a cada elemento do hashing;
		2. 	Para cada sublista:
		2.1.	Calcular o limite inferior e superior de cada faixa etária;
		2.2.	Se houver elementos a mostar:
		2.2.1. 		Mostar uma mensagem a informar qual a faixa etária das pessoas que se irão listar;
		2.2.2. 			Usar a função das listas para mostar os elementos da subista;
		2.3. Se não houver elementos, mostar a mensagem a informar qual a faixa etária e indicar que não há pessoas nela
	 */
	if (!EstHashing || !EstHashing->vetor) return;

	for (int i = 0; i < MAX_FAIXAS_ETARIAS; i++) {
		ptELEM x = EstHashing->vetor[i].lista->inicio;
		if (!x->info) continue;
		printf("Chave: %d\n", EstHashing->vetor[i].faixaEtaria);
		printf("Altura: %.2fm\n", x->info->altura);
		printf("Idade: %d anos\n", x->info->idade);
		printf("Nome: [%s]\n", x->info->nome);
		printf("Peso: %.2fkg\n\n", x->info->peso);
		x = x->seg;
	}
}

ptELEM RemoverElementoHashing(ptHASHING H, ptELEM Y){
	printf("vou fazer a ff |%s| aqui...\n", __FUNCTION__);
	/*
	 Dicas:
		No hashing, não vai haver uma lista, mas várias sublistas.
		Assim, ter-se-á de saber primeiro, usando a função de hashing,
		onde pode estar o elemento a pesquisar, para depois o remover. Assim:
		1.  Como se pretende retornar o elemento que foi eliminado, declarar um ponteiro para o poder fazer;
		2.	Determinar a posição do vector (qual a sublista) a pesquisar;
		3.  Validar a posição encontrada, pois o elemento especificado pode estar incorrecto;
		3.1. 	Se a posição (sublista) for válida, invocar a função apropriada da lista para remover o elemento da sublista,
				aproveitando o ponteiro para elemento retornado para o retornar nesta função;
		3.2. 	De contrário, mostrar mensagem sugestiva e retornar o valor adequado.
	 */
	if (!H || !H->vetor || !Y) return NULL;

	int pos = PosicaoHashingElemento(Y);

	if (!H->vetor[pos].lista) {
		printf("Lista inválida!\n");
		return NULL;
	}

	// Remove element from the sublist at position pos
    ptELEM elementoRemovido = RemoverElementoLista(H->vetor[pos].lista, Y);
    
    if (!elementoRemovido) {
        printf("Elemento não encontrado na posição %d!\n", pos);
    }

    return elementoRemovido;
}

ptELEM PesquisarElementoHashing(ptHASHING H, ptELEM Y){
	printf("vou fazer a ff |%s| aqui...\n", __FUNCTION__);

	/*
	Dicas:
	 No hashing, não vai haver uma lista, mas várias sublistas.
	 Assim, ter-se-á de saber primeiro, usando a função de hashing,
	 onde pode estar o elemento a pesquisar. Assim:
	 1.	Como se pretende retornar o elemento que foi encontrado, declarar um ponteiro para o poder fazer;
	 2.	Determinar a posição do vector (qual a sublista) a pesquisar;
	 3. Validar a posição encontrada, pois o elemento especificado pode estar incorrecto;
	 3.1. 	Se a posição (sublista) for válida, invocar a função apropriada da lista para pesquisar o elemento da sublista,
			 aproveitando o ponteiro para elemento retornado para o retornar nesta função;
	 3.2. 	De contrário, mostrar mensagem sugestiva e retornar o valor adequado.
	*/
	
	if (!H || !H->vetor || !Y) return NULL;

	int pos = PosicaoHashingElemento(Y);

	if (!H->vetor[pos].lista) {
		printf("Lista inválida!\n");
		return NULL;
	}

	ptELEM p = H->vetor[pos].lista->inicio;
	while (p) {
		if (ElementosIguais(p, Y))
			return p;
		p = p->seg;
	}

	return NULL;
}
