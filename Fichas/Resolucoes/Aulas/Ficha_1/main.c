#include "headers.h"

int main(void) {
    srand(time(NULL));

    int nUsers = GerarFicheiroParaTestes();
    Users * db = LerFicheiro("Utilizadores.dat", nUsers);
    GravarXML(db, nUsers, "utilizadores.xml")
    system("pause");


}