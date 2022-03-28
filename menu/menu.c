#ifndef MENU_C
#define MENU_C
#include "menu.h"

int menu(Cliente *cliente){
    int *escolha = malloc(sizeof(int));

    printf("\n\n\n");
    printf("\t\t\t\t(1) Inserir um Cliente: \n");
    printf("\t\t\t\t(2) Remover um Cliente: \n");
    printf("\t\t\t\t(3) Fechar programa: \n");

    scanf("%d", escolha);
    scanf("%*c");

    switch(*escolha){
        case 1:
            inserirCliente(cliente);
            break;

        case 2:
            removerCliente(cliente);
            break;

        default:
            return 1;
    }
    return 0;
}

#endif // MENU_C
