#ifndef VIEWCLIENTE_C
#define VIEWCLIENTE_C
#include "opaqueTypeClienteIntern.h"

int viewCliente(){
    int temp;

    printf("(0) Inserir ID manualmente: \n(1) Inserir ID aleatoriamente: \n");
    scanf("%d", &temp);

    return temp;
}

int viewClienteManual(){
    int tempID;

    printf("Escreva um ID para o cliente: \n");
    scanf("%d", &tempID);

    return tempID;
}

void viewClienteAuto(int tempID){
    printf("O ID gerado para o cliente foi: %d\n", tempID);
}

void viewPreencherNome(char str[]){
    printf("Escreva o nome do cliente: \n");
    scanf("%*c");
    scanf("%[^\n]%*c", str);
}

void viewPreencherData(int *dia, int *mes, int *ano){
    printf("Escreva a data de nascimento do cliente(dia mes ano): \n");
    scanf("%d %d %d", dia, mes, ano);
}

int viewRemoverCliente(){
    int temp;

    printf("Qual ID do cliente deseja remover?\n");
    scanf("%d", &temp);

    return temp;
}

void viewIDNotFound(){
    printf("ID nao encontrado!\n");
}

#endif // VIEWCLIENTE_C
