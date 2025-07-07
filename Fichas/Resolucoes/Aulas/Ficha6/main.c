//
//  main.c
//  Ficha5_Hashing_Base
//
//  Created by Jorge Loureiro on 31/03/2025.
//

#include <locale.h>
#include <time.h>
#include "Pessoa.h"
#include "Lista.h"
#include "Hashing.h"

//ex 25
int MenuPrincipal(void) {
	int opcao;

	printf("\n# MENU PRINCIPAL --------------------------------------------#");
	printf("\n|  (1) Inserir novos elementos no vector de hashing          |");
	printf("\n|  (2) Retirar um elemento do vector de hashing              |");
	printf("\n|  (3) Mostrar os elementos do vector de hashing             |");
	printf("\n|  (4) Pesquisar um elemento no vector de hashing            |");
	//printf("\n|  (5) Mostrar total de pessoas no vector de hashing         |");
	printf("\n|  ----------------------------------------------------------|");
	printf("\n|  (0) SAIR                                                  |");
	printf("\n#------------------------------------------------------------#\n");
	//outras funcionalidades???

	// ATENÇÃO: alterar para evitar interrupções na execução:
	do {
		printf("\nQual a sua opção: ");
		scanf("%d", &opcao); // ATENÇÃO: '\n' fica no buffer
	} while (opcao < 0 || opcao > 4);
	return opcao;
}
int main(int argc, const char * argv[]) {
	srand((unsigned) time(NULL));
	setlocale(LC_ALL,"");//para usar acentos!
	printf("Ficha de Trabalho n.º 6: HASHING!\n");

	ptELEM eleNovo, eleRemover, elePesquisar;

	ptHASHING hashPes = CriarVectorHashing();
	InicializarVectorHashing(hashPes);

	for ( ; ; ){
		switch(MenuPrincipal()){
			case 1:
				//eleNovo = CriarElemento();
				//LerElemento(eleNovo);
				//InserirElementoHashing(hashPes, eleNovo);
				for(int i=0;i<50;i++){
					eleNovo = CriarElemento();
					GerarElementoPreenchido(eleNovo);
					InserirElementoHashing(hashPes, eleNovo);
				}
				break;
			case 2: // retirar elemento do vector hashing
				break;
			case 3: // mostrar os elementos do vector hashing
				MostrarElementosHashing(hashPes);
				break;
			case 4: // pesquisar elemento no vector hashing
				break;
			//case 5: // mostrar total de elementos no vector hashing
			//    break;
			case 0:{// sair...
				//o que fazer????
				return 0;
			}
		}
	}
}
