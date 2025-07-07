#include "headers.h"

int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

int GerarFicheiroParaTestes() {
    int nUsers = randomInt(3, 10);
    printf("nUsers: %d", nUsers);
    Users * db = (Users *) malloc(nUsers * sizeof(Users));

    for (int i = 0; i < nUsers; i++) {
        db[i].data_registo.ano = randomInt(2020, 2025);
        db[i].data_registo.mes = randomInt(1,12);
        db[i].data_registo.dia = randomInt(1,31);

        db[i].numero_acessos = randomInt(1,200);
        db[i].data_ultimo_acesso.ano = randomInt(2020, 2025);
        db[i].data_ultimo_acesso.mes = randomInt(1,12);
        db[i].data_ultimo_acesso.dia = randomInt(1,31);

        int nome_num = randomInt(0, 500);

        sprintf(db[i].pagina_web_pessoal, "luis.%d", nome_num);
        sprintf(db[i].email, "luis.%d@gmail.com", nome_num);
        sprintf(db[i].nome, "Luis-%d", nome_num);
        sprintf(db[i].utilizador, "luis%d", nome_num);
        sprintf(db[i].password, "LuIs%d", nome_num);

        db[i].telemovel = randomInt(10000, 99999);

        db[i].joia = randomInt(100, 1000) / 100.0f;

        MostrarUser(&(db[i]));
    }

    FILE * ficheiro = fopen("Utilizadores.dat", "wb");

    fwrite(db, sizeof(db), nUsers, ficheiro);

    return nUsers;
}

void MostrarUser(Users * user) {
    printf("Nome: [%s]\n", user->nome);
    printf("Utilizador: [%s]\n", user->utilizador);
    printf("Data Ultimo Acesso: [%2d-%2d-%4d]\n", user->data_ultimo_acesso.dia, user->data_ultimo_acesso.mes, user->data_ultimo_acesso.ano);
}

Users * LerFicheiro(char * nome_ficheiro, int * nUsers) {
    FILE * ficheiro = fopen(nome_ficheiro, "rb");

    if (!ficheiro) return NULL;

    long posicao = ftell(ficheiro);
    *nUsers = posicao / sizeof(Users);
    rewind(ficheiro);

    Users * vetor = (Users *) malloc(*nUsers * sizeof(Users));
    fread(vetor, sizeof(Users), *nUsers, ficheiro);

    return vetor;
}

Users * DuplicarDados(Users * original, int n) {
    Users * v2 = (Users *) malloc(n * sizeof(Users));
    for (int i = 0; i < n; i++) {
        v2[i] = original[i]; 
    }

    return v2;
}

void OrdernarDados(Users * original, int n) {
    printf("!");
}

void LibertarMemoria(Users * vetor) {
    if (vetor) free(vetor);
}

void ListarUtilizadores(Users * vetor, int nUsers) {
    for (int i = 0; i < nUsers; i++)
    {
        MostrarUser(&(vetor[i]));
    }
}

void ContarPessoasAcessosAno(Users * vetor, int n, int ano) {
    printf("!");
}

Users * PesquisaCod(Users * vetor, int n, int codigo) {
    printf("!");

    return NULL;
}

Users * PesquisaNome(Users * vetor, int n, char * nome) {
if (!nome) return NULL;

    for (int i = 0; i < n; i++) {
        if (stricmp(vetor[i].nome, nome) == 0) {
            return (&(vetor[i]));
        }
    }

    return NULL;
}

Users * PessoaMaisAcessos(Users * vetor, int n) {
    if (!vetor) return NULL;

    int maior = 0;

    for (int i = 1; i < n; i++) {
        if (vetor[i].numero_acessos > vetor[maior].numero_acessos)
            maior = i;
    }

    return &(vetor[maior]);
}

int TotalJoias(Users * vetor, int n) {
    if (!vetor) return 0;

    float soma = 0.0f;
    for (int i = 0; i < n; i++) {
        soma += vetor[i].joia;
    }

    return soma;
}

int MesMaisRegistos(Users * vetor, int n) {
    int meses[12];

    for (int i = 0; i < 12; i++) {
        meses[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        meses[vetor[i].data_registo.mes - 1]++;
    }

    int pos_maior = 0;
    for (int i = 1; i < 12; i++) {
        if (meses[i] > meses[pos_maior]) pos_maior = i;
    }

    return (pos_maior + 1);
}

int GravarXML(Users * v, int n, char * ficheiro) {
    FILE * f = fopen(ficheiro, "w");

    fprintf(f, "<DADOS>\n");

    for (int i = 0; i < n; i++) {
        fprintf(f, "\t<USER>\n");

        fprintf(f, "\t\t<NOME>%s</NOME>\n", v[i].nome);
        fprintf(f, "\t\t<UTILIZADOR>%s</UTILIZADOR>\n", v[i].utilizador);
        fprintf(f, "\t\t<JOIA>%.2f</JOIA>\n", v[i].joia);

        fprintf(f, "\t</USER>\n");
    }
    
    fprintf(f, "</DADOS\n");

    fclose(f);
}

char * NomeMaisComum(Users * v, int n) {
    char * nome = NULL;
    char ** unicos = (char **) malloc(n * sizeof(char *));
    int * count = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        nome = strtok(v[i].nome, " ");


    }
}