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

int viewAlterarCliente(){
    int id;

    printf("Qual o ID do cliente que deseja alterar: \n");
    scanf("%d", &id);

    return id;
}

int viewAlterarClienteInfo(){
    int escolha;

    printf("\t\t\t\tQual info deseja alterar?\n");
    printf("\t\t\t\t(1) Nome: \n");
    printf("\t\t\t\t(2) Dia: \n");
    printf("\t\t\t\t(3) Mes: \n");
    printf("\t\t\t\t(4) Ano: \n");
    scanf("%d", &escolha);

    return escolha;
}

int viewTemp(){
    int temp;

    printf("Digite a nova info: \n");
    scanf("%d", &temp);

    return temp;
}

#endif // VIEWCLIENTE_C
