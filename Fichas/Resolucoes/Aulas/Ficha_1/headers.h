#ifndef HEADERS
#define HEADERS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char nome[50];
    char utilizador[20];
    char password[20];
    float joia;
    Data data_registo;
    char email[30];
    char pagina_web_pessoal[50];
    int telemovel;
    int numero_acessos;
    Data data_ultimo_acesso;
} Users;

int randomInt(int min, int max);
int GerarFicheiroParaTestes();
void MostrarUser(Users * user);
Users * LerFicheiro(char * nome_ficheiro, int * nUsers);
Users * DuplicarDados(Users * original, int n);
void OrdernarDados(Users * original, int n);
void OrdernarDados(Users * original, int n);
void LibertarMemoria(Users * vetor);
void ListarUtilizadores(Users * vetor, int nUsers);
void ContarPessoasAcessosAno(Users * vetor, int n, int ano);
Users * PesquisaCod(Users * vetor, int n, int codigo);
Users * PesquisaNome(Users * vetor, int n, char * nome);
Users * PessoaMaisAcessos(Users * vetor, int n);
int TotalJoias(Users * vetor, int n);
int MesMaisRegistos(Users * vetor, int n);
int GravarXML(Users * v, int n, char * ficheiro);
char * NomeMaisComum(Users *V, int N);

#endif