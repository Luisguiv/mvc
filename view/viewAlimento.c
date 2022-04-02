#ifndef VIEWALIMENTO_C
#define VIEWALIMENTO_C
#include "opaqueTypeClienteIntern.h"

int viewAlimento(){
    int temp;

    printf("(0) Inserir ID do alimento manualmente: \n(1) Inserir ID do alimento aleatoriamente: \n");
    scanf("%d", &temp);

    return temp;
} // view;

int viewAlimentoManual(){
    int tempID;

    printf("Escreva um ID para o alimento: \n");
    scanf("%d", &tempID);

    return tempID;
} // view;

void viewAlimentoAuto(int tempID){
    printf("O ID gerado para o alimento foi: %d\n", tempID);
} // view;

void viewPreencherNomeAlimento(char str[]){
    printf("Escreva o nome do alimento: \n");
    scanf("%*c");
    scanf("%[^\n]%*c", str);
} // view

int viewRemoverAlimento(){
    int temp;

    printf("Qual ID do alimento que deseja remover?\n");
    scanf("%d", &temp);

    return temp;
} // view;

int viewAlterarAlimento(){
    int id;

    printf("Qual é o ID do alimento que deseja alterar: \n");
    scanf("%d", &id);

    return id;
} // view;

int viewAlterarAlimentoInfo(){
    int escolha;

    printf("\t\t\t\tQual info deseja alterar?\n");
    printf("\t\t\t\t(1) Nome: \n");
    printf("\t\t\t\t(2) Caloria: \n");
    printf("\t\t\t\t(3) Preco: \n");
    printf("\t\t\t\t(4) Marca: \n");
    scanf("%d", &escolha);

    return escolha;
} // view;

float viewTempAlimento(){
    float temp;

    printf("Digite a nova info: \n");
    scanf("%f", &temp);

    return temp;
} // view;

void viewPreencherAlimentoNome(char tempNome[]){
    printf("Escreva o nome do alimento: \n");
    scanf("%*c");
    scanf("%[^\n]%*c", tempNome);
}
// view;

void viewPreencherCalPr(float *tempCal, float *tempPr){
    printf("Escreva o valor calorico e a preco do alimento: \n");
    scanf("%f %f", tempCal, tempPr);
} // view;

int viewPreencherMarca(char tempMar[]){
    int escolha;

    printf("O alimento é industrializado?\n(1) Sim\t(2)Nao\n");
    scanf("%d", &escolha);

    if(escolha==1){
        printf("Escreva a marca do alimento: \n");
        scanf("%*c");
        scanf("%[^\n]%*c", tempMar);
        return 1;
    }
    else return 0;
} // view;

#endif // VIEWALIMENTO_C
