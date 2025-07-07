#include "fila.h"
#include "viatura.h"


ptFILA CriarFila()
{
    ptFILA f = (ptFILA)malloc(sizeof(FILA));
    f->Fim = f->Inicio = NULL;
    f->numel = 0;
    return f;
}
void DestruirFila(ptFILA f)
{
    NO * p = f->Inicio;
    while(p) {
        DestruirViatura(p->dados);
        p = p->seg;
    }
    free(f);
}

void MostrarFila(ptFILA f)
{
    if (!f || !f->Inicio) return;

    ptNO aux = f->Inicio;
    int i=0;
    while(aux){
        printf("\n*** VIATURA %d ****\n", i++);
        printf("====================================\n");
        MostrarViatura(aux->dados);
        aux = aux->seg;
    }
}

void InserirFila(ptFILA f, ptVIATURA vt)
{
    f->Fim->seg = vt;
    f->Fim = f->Fim->seg;
    f->numel++; 
}

ptVIATURA RemoverFila(ptFILA f)
{
    if (!f || f->Inicio) {
        return NULL;
    }
    ptVIATURA out = f->Inicio->dados;
    free(f->Inicio);
    f->Inicio = f->Inicio->seg;
    return out;
}

int TotalFila(ptFILA f)
{
    if (!f) return -1;
    return f->numel;
}

void GravarFilaFich(ptFILA f, char *nomeFich)
{
    if (!f || !nomeFich) return;

    FILE * file = fopen(nomeFich, "wb");
    if (!file) return;

    ptNO p = f->Inicio;
    while(p) {
        fwrite(p->dados, sizeof(ptVIATURA), 1, file);
        p = p->seg;
    }
    fclose(file);
}

void LerFilaFich(ptFILA f, char *nomeFich)
{
    if (!f || !nomeFich) return;

    FILE * file = fopen(nomeFich, "rb");
    if (!file) return;

    ptNO p = f->Inicio;
    while(p) {
        fread(p->dados, sizeof(ptVIATURA), 1, file);
        p = p->seg;
    }
    fclose(file);
}

void LimparFila(ptFILA f)
{
    if (!f) return;

    while(f->Inicio) {
        DestruirViatura(RemoverFila(f));
    }
}
