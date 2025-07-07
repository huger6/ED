#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fila.h"

int menu()
{
    int opcao;
    //system("cls");
    printf("\n #----------------------------------------------------------------#");
    printf("\n | (1) Adicionar viatura na fila de espera                        |");
    printf("\n | (2) Terminar lavagem de viatura (remover)                      |");
    printf("\n | (3) Mostrar todas as viaturas à espera de lavagem              |");
    printf("\n | (5) Gravar ficheiro                                            |");
    printf("\n | (6) Ler ficheiro                                               |");
    printf("\n | (7) Limpar/esvaziar fila de viaturas                           |");
    printf("\n |                                                                |");
    printf("\n | (8) Inserir viatura PREENCHIDA na fila de espera               |");
    //printf("\n | (9) Pesquisar viaturas na fila (pesquisa por marca)            |");
    //outras funcionalidades???

    printf("\n |                                                                |");
    printf("\n |----------------------------------------------------------------|");
    printf("\n | (0) SAIR                                                       |");
    printf("\n #----------------------------------------------------------------#");
    do {
        printf("\nQual a sua opção: ");
        fflush(stdin);
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 8); // alterar de modo a permitir que seja inserido caracter e não terminar a execucao!!
    return opcao;
}

int main()
{
    setlocale(LC_ALL,"");//para usar acentos!
    printf("Ficha n 4: Estruturas dinâmicas: FILAS DE ESPERA\n");

    int opcao, ind = 0;
    ptFILA fila = CriarFila();
    ptVIATURA v;

    do{
        opcao = menu();
        switch(opcao){
            case 1: //fazer XPTO
                break;
            case 2: // fazer xpto
                break;
            case 3: // mostrar a fila
                MostrarFila(fila);
                break;
            case 4: // fazer xpto
                break;
            case 5: // fazer xpto
                break;
            case 6: // fazer xpto
                break;
            case 7: // fazer xpto
                break;
            case 8: //criar viatura preenchida e inserir na fila
                v = CriarViaturaPreenchida(++ind);
                InserirFila(fila, v);
                break;
        }
    } while(opcao !=0);

    // qd opçao==0: o que fazer antes do return ?? antes de sair do programa??
    DestruirFila(fila);
    return 0;
}



