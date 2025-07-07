#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_CC 20

typedef struct{
    int dia, mes, ano;
}DATA;

typedef struct{
    char CC[MAX_CC];
    float ALTURA;
    float MASSA;
    char GENERO;
    DATA D_Nascimento;
}Individuo;

int Aleatorio(int min, int max) {
    // ain da nao feita
    int valor = min + rand() % (max - min + 1);
    return valor;
}

Individuo *GerarIndividuos(int m) {
    Individuo *v = (Individuo *)malloc(m * sizeof(Individuo));
    for (int i = 0; i < m; i++)
    {
        sprintf(v[i].CC, "ZT-%d-VIS", Aleatorio(1000, 10000));
        v[i].ALTURA = Aleatorio(100, 200) / 100.0f;
        v[i].MASSA = Aleatorio(40, 110) * 1.0f;
        v[i].D_Nascimento.ano = Aleatorio(2000, 2025);
        v[i].D_Nascimento.dia = Aleatorio(1, 31);
        v[i].D_Nascimento.mes = Aleatorio(1, 12);
    }
    return v;
}

void MostrarIndividuos(Individuo *v, int tam) {
    for (int i = 0; i < tam; i++)
    {
        printf("Individuo:\n");
        printf("\t CC: [%s]\n", v[i].CC);
        printf("\t ALTURA: %f\n", v[i].ALTURA);
    }
}

void DestruirIndividuos(Individuo *v) {
    if (v) free(v);
}

void indSaudaveis(Individuo *v, int tam) {
   // printf("Tenho de fazer indSaudaveis\n");
    int cont = 0;
    for (int i = 0; i < tam; i++)
    {
        float IMC = v[i].MASSA / (v[i].ALTURA * v[i].ALTURA) ;
        printf("IMC = %f\n", IMC);
        if ((IMC > 18.5) && (IMC < 24.9))
            cont++;
    }
    printf("Ind. Saudaveis = %d\n", cont);
}

int Media(Individuo *v, int tam, int ano_i, int ano_f) {
    float media_IMC = 0.0f;
    int cont = 0;

    for (int i = 0; i < tam; i++) {
        if (v[i].D_Nascimento.ano > ano_i && v[i].D_Nascimento.ano < ano_f) {
            media_IMC += (v[i].MASSA / (v[i].ALTURA * v[i].ALTURA));
            cont++;
        }
    }  

    if (cont == 0) return 0;

    return (media_IMC / cont);
}

int removeIndiv(Individuo * vet_ind, int * tam, int nCC) {
    for (int i = 0; i < *tam; i++) {
        if (vet_ind[i].CC == nCC) {
            int tam_restante = *tam - i - 1;
            //Copiar para a posição anterior  
            for (int j = i; j < tam_restante; j++) {
                vet_ind[j] = vet_ind[j+1];
            }
            (*tam)--;
            break;
        }
    }
}

char * gerar_cc() {
    char cc[13];
}

int main() {
    srand(time(NULL));
    /*
    int MAX_IND = Aleatorio(1, 10);
    Individuo *v_ind = GerarIndividuos(MAX_IND);
    MostrarIndividuos(v_ind, MAX_IND);

    indSaudaveis(v_ind, MAX_IND);
    Media(v_ind, MAX_IND, 2010, 2015);

    DestruirIndividuos(NULL);
    return 0;
    */

    char * cc = gerar_cc();
    printf("%s\n", cc);
    free(cc);
}
