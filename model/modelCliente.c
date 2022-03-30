#ifndef MODELCLIENTE_C
#define MODELCLIENTE_C
#include "opaqueTypeClienteIntern.h"

int livreID(int ID){ // arquivo;
    int tempID;
    char buffer[20];
    char *line;
    FILE *f;

    f = fopen("cadastros.txt", "rt");

    do{ // ignora a primeira linha que contem \n;
        fgets(buffer, 20, f);
    }   while(0);

    while(!feof(f)){
        line = fgets(buffer, 20, f);
        if(line==NULL) break;
        sscanf(line, "%d", &tempID);
        if(ID==tempID) return 0;
    }
    fclose(f);

    return 1;
}

void preencherCadastros(int ID){ // arquivo;
    FILE *f;

    f = fopen("cadastros.txt", "a");
    fprintf(f, "\n");
    fprintf(f, "%d", ID);

    fclose(f);
}

void preencherClienteTxt(Cliente *clienteAtual){ // arquivo;
    FILE *f;
    int count;

    printf("%s / %d / %d %d %d", clienteAtual->clienteNome, showID(clienteAtual), showDia(clienteAtual), showMes(clienteAtual), showAno(clienteAtual));
    f = fopen("info.txt", "a");
    fprintf(f, "\n");
    fprintf(f, "ID: %d{\t\tNome: ",  showID(clienteAtual));
    for(count=0; clienteAtual->clienteNome[count]!=0; count++) fprintf(f, "%c", clienteAtual->clienteNome[count]);
    fprintf(f, "\n\t\tData: %02d/%02d/%04d\n\t}", showDia(clienteAtual), showMes(clienteAtual), showAno(clienteAtual));
    fclose(f);
}

void preencherCliente(Cliente *clienteAtual){ // memoria;
    char tempNome[MAX];
    int tempD, tempM, tempA;

    // clienteNome;
    viewPreencherNome(tempNome);
    setNome(clienteAtual, tempNome);
    //cliente dia/mes/ano;
    viewPreencherData(&tempD, &tempM, &tempA);
    setDia(clienteAtual, tempD);
    setMes(clienteAtual, tempM);
    setAno(clienteAtual, tempA);
}

void imprimirLog(){ // arquivo;
    FILE *f;
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    f = fopen("erro.txt", "a");
    fprintf(f, "\n");
    fprintf(f, "%s%*c: ERRO: ID nao se enquadra nas regras de validacao; (ID DEVE SER UNICO E SER UM NUMERO POSITIVO MAIOR OU IGUAL A ZERO).", asctime(timeinfo));

    fclose(f);
}

int linhaRemover(int ID, char str[]){ // arquivo;
    int i=1;
    int tempID;
    char *line;
    char buffer[MAX];
    FILE *f;

    fopen(str, "rf");

    while(!feof(f)){
        line = fgets(buffer, MAX, f);
        sscanf(line, "%d", &tempID);
        if(ID==tempID) return i;
        i++;
    }
    fclose(f);

    return -1;
}

void removerInfo(int ID){ // arquivo;
    FILE *f1, *f2;
    char file1[] ="info.txt";
    char file2[] ="info.txt";
    char curr;
    int del, line_number = 0;
    int i=2; // duas linhas pra remover;

    del = linhaRemover(ID, "info.txt");

    f1 = fopen(file1,"r");
    f2 = fopen(file2, "w");

    curr = getc(f1);
    if(curr!=EOF) {line_number =1;}
    while(i){
      if(del != line_number)
        putc(curr, f2);
        curr = getc(f1);
        if(curr =='\n') line_number++;
        if(curr == EOF) break;
      else i--;
    }
    fclose(f1);
    fclose(f2);
}

void removerCadastros(int ID){ // arquivo;
    FILE *f1, *f2;
    char file1[] ="cadastros.txt";
    char file2[] ="cadastros.txt";
    char curr;
    int del, line_number = 0;

    del = linhaRemover(ID, "cadastros.txt");

    f1 = fopen(file1,"r");
    f2 = fopen(file2, "w");

    curr = getc(f1);
    if(curr!=EOF) {line_number =1;}
    while(1){
      if(del != line_number)
        putc(curr, f2);
        curr = getc(f1);
        if(curr =='\n') line_number++;
        if(curr == EOF) break;
    }
    fclose(f1);
    fclose(f2);
}

void alterarCadastrosCliente(int id){
    char *line;
    char buffer[MAX];
    FILE *f;
    char temp[MAX];
    int escolha;
    char newName[MAX];
    int tempD, tempM, tempA;

    sprintf(temp, "ID: %d", id);

    f = fopen("info.txt", "rf");

    while(fgets(buffer, MAX, f)!=NULL){
        if(strstr(buffer, temp)){ // achou a linha que contem o ID;
            // 2 linhas a computar;
            scanf("%d", &escolha); // 1 nome, 2 data;
            for(int i=1; i<=2; i++){
                if(i==1 && i==escolha){
                    scanf("%[^\n]%*c", newName);
                    sprintf(buffer, "ID: %d{\t\tNome: %s\n", id, newName);
                }
                if(i==2 && i==escolha){
                    fgets(buffer, MAX, f);
                    scanf("%d %d %d", tempD, tempM, tempA);
                    sprintf(buffer, "\t\t\tData: %02d/%02d/%04d\n\t}", tempD, tempM, tempA);
                }
            }
        }
    }
    fclose(f);
}

#endif // MODELCLIENTE_C
