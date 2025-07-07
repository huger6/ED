#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include "viatura.h"

// ---------------------------------------------------------------------
// bibliotecas


// ---------------------------------------------------------------------
// estruturas de dados

// 2.2
typedef struct Elemento{
    ptVIATURA dados;
    struct Elemento *seg;
}NO, *ptNO;

typedef struct {
    ptNO Inicio;
    ptNO Fim;
    int numel;
}FILA, *ptFILA;


// ---------------------------------------------------------------------
// prototipos funcoes
ptFILA CriarFila();
void DestruirFila(ptFILA f);
void MostrarFila(ptFILA f);
void InserirFila(ptFILA f, ptVIATURA vt);
ptVIATURA RemoverFila(ptFILA f);
int TotalFila(ptFILA f);
void GravarFilaFich(ptFILA f, char *nomeFich);
void LerFilaFich(ptFILA f, char *nomeFich);
void LimparFila(ptFILA f); // remover todos os ve�culos sem destruir a fila


#endif // FILA_H_INCLUDED
