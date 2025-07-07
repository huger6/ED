#include "headers.h"

int main(void)
{
    Lista * li = criar_lista_aleatoria();
    mostrar_lista(li);
    printf("Lista antes:\n");
    ordenarLista(li);
    printf("\n\nLista depois:\n");
    mostrar_lista(li);
    printf("\n");
    system("pause");
    return 0;
}
