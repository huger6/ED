// ---------------------------------------------------------------------
// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

// ---------------------------------------------------------------------
// MACROS
#define MAXMAT 8
#define MAXPROP 30
#define MARCA_COR 15

// ---------------------------------------------------------------------
// estruturas de dados

//1.1
typedef struct {
    char matricula[MAXMAT+1]; //a
    char proprietario[MAXPROP+1]; //b
    char marca[MARCA_COR+1]; //c
    char cor[MARCA_COR+1];
    time_t tempo_entrada;
    time_t tempo_saida;
    int tempo_lavagem;
} VIATURA, *ptVIATURA;

// ---------------------------------------------------------------------
// prototipos funcoes

ptVIATURA LerViatura();
ptVIATURA CriarViaturaPreenchida(int int);
void MostrarViatura(ptVIATURA vt);
void DestruirViatura(ptVIATURA v);
int TempoLavagem(time_t tempoInicio, time_t tempoFim);
void GravarViaturaFicheiro(ptVIATURA v, FILE *fich);
int LerViaturaFicheiro(ptVIATURA v, FILE *fich);

