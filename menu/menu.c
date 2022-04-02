#ifndef MENU_C
#define MENU_C
#include "menu.h"
#include "conio.h"

int menu(Cliente *cliente, Alimento *alimento){
    textbackground(12);
    textcolor(7);
    system("cls");
    int *escolha = malloc(sizeof(int));
    int escolhaHist;

    printf("\n\n\n");
    printf("\t\t\t\t(1) Inserir um Cliente: \n");
    printf("\t\t\t\t(2) Remover um Cliente: \n");
    printf("\t\t\t\t(3) Alterar um Cliente: \n");
    printf("\t\t\t\t(4) Consultar Relatorio de clientes: \n");
    printf("\t\t\t\t(5) Inserir um Alimento: \n");
    printf("\t\t\t\t(6) Remover um Alimento: \n");
    printf("\t\t\t\t(7) Alterar um Alimento: \n");
    printf("\t\t\t\t(8) Consultar Relatorio de alimentos: \n");
    printf("\t\t\t\t(9) Adicionar ao historico: \n");
    printf("\t\t\t\t(10) Gerar historico: \n");
    printf("\t\t\t\t(11) Fechar programa: \n");

    scanf("%d", escolha);
    scanf("%*c");

    switch(*escolha){
        case 1:
            inserirCliente(cliente);
            break;

        case 2:
            removerCliente(cliente);
            break;

        case 3:
            alterarCliente(cliente);
            break;

        case 4:
            loadingScr();
            consultar();
            break;

        case 5:
            inserirAlimento(alimento);
            break;

         case 6:
            removerAlimento(alimento);
            break;

         case 7:
            alterarAlimento(alimento);
            break;

         case 8:
            loadingScr();
            consultarAlimento();
            break;

         case 9:
            callHist();
            break;

         case 10:
            printf("(0) para consultar historico: \n");
            printf("(1) para consultar viagens: \n");
            scanf("%d", &escolhaHist);
            if(!escolhaHist){
                loadingScr();
                consultarHist();
            }
            else{
                loadingScr();
                consultarTrip();
            }
            break;

         default:
            free(escolha);
            return 1;
    }

    return 0;
}

void loadingScr(){
    int i;
    char limpa[120]=""; //limpa o espaco reservado na memoria
    for(i=0; i<=100; i++)//laco de repeticao de zero a 100.
    {
    if(i%2){textcolor(7); strcat(limpa,"|"); }//variavel limpa recebe caractere Û.
    system("cls");//limpa a tela

    printf("\t\t\t\t --------------------------------------------------");
    textcolor(7); printf("\n\tLoading Relatorio: ");

    textcolor(7);
    printf("%s",limpa);//exibe na tela a contagem de "i" e acumula os caracteres "Û" na tela

    textcolor(7);
    printf("\n\t\t\t\t --------------------------------------------------");
    gotoxy(64,1);
    printf("\t%d%% ",i);
    Sleep(25); //tempo de 25 milisegundo
    textcolor(7);
    }
    system("cls");	//limpa a tela
    printf("\n\tCarregado %d%%\n\t",i-1);//exibe na tela a ultima conatagem de "ï"na tela tipo: 100%
    Sleep(1000);//espera de um segundo
}

#endif // MENU_C
