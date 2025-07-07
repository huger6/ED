#include "viatura.h"

ptVIATURA LerViatura()
{
    printf("Fazer funcao |%s| aqui\n", __FUNCTION__);
    return NULL;
}

ptVIATURA CriarViaturaPreenchida(int ind)
{
    ptVIATURA vt = (ptVIATURA)malloc(sizeof(VIATURA));

    sprintf(vt->matricula, "AA-%02d-ZZ", ind);
    sprintf(vt->proprietario, "Proprietario_%d", ind);
    sprintf(vt->marca, "marca_%d", ind);
    sprintf(vt->cor, "cor_%d", ind);
    vt->tempo_entrada = time(NULL);
    vt->tempo_saida = vt->tempo_entrada;
    vt->tempo_lavagem = 0;

    ind++;
    return vt;
}

void MostrarViatura(ptVIATURA vt)
{
    printf("Matricula : %s\n", vt->matricula);
    printf("Proprietario: %s\n", vt->proprietario);
    printf("Marca: %s\n", vt->marca);
    printf("COR: %s\n", vt->cor);
    printf("Tempo de entrada: %s", ctime(&vt->tempo_entrada)); //ctime() tem parametro entrada um ponteiro (time_t *)
    printf("Tempo de saida: %s", ctime(&vt->tempo_saida));
    printf("Tempo de lavagem: %d (sec.) ",vt->tempo_lavagem);
}

void DestruirViatura(ptVIATURA v)
{
    free(v);
}

int TempoLavagem(time_t tempoInicio, time_t tempoFim)
{
    return ((int) difftime(tempoFim, tempoInicio));
}

void GravarViaturaFicheiro(ptVIATURA v, FILE *fich)
{
    if (!v || !fich) return;

    fwrite(v, sizeof(ptVIATURA), 1, fich);
}

int LerViaturaFicheiro(ptVIATURA v, FILE *fich)
{
    if (!v || !fich) return 0;

    fread(v, sizeof(ptVIATURA), 1, fich);
    return 1;
}
