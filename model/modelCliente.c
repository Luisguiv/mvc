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

    f = fopen("cadastros.txt", "r");

    do{ // ignora a primeira linha que contem \n;
        line = fgets(buffer, MAX, f);
        line = fgets(buffer, MAX, f);
    }   while(0);

    while(line!=NULL){
        printf("[%s]\n", buffer);
        sscanf(buffer, "%d", &tempID);
        printf("{%d / %d}\n", ID, tempID);
        if(ID==tempID) return i;
        i++;
        line = fgets(buffer, MAX, f);
    }
    fclose(f);

    return -1;
}

void removerInfo(int ID){ // arquivo;
    // to be done;
}

void removerCadastros(int ID){ // arquivo;
    FILE *f1, *f2;
    int del;
    int line_number=1;
    char buffer[MAX];

    del = linhaRemover(ID, "cadastros.txt");

    f1 = fopen("cadastros.txt", "r");
    f2 = fopen("replica.txt", "w");

    while(fgets(buffer, MAX, f1)!=NULL){
        if(del != line_number){
          fprintf(f2, "%s", buffer);
        }
        line_number++;
    }

    fclose(f1);
    fclose(f2);

    remove("cadastros.txt");
    rename("replica.txt", "cadastros.txt");
}

void getName(char buffer[], Cliente *cliente){
    char temp[MAX];

    sscanf(buffer, "%*c%*c%*c %*d%*c%*[\t]%*[\t]%*s %s", temp);
    setNome(cliente, temp);
}

void getDate(char buffer[], Cliente *cliente){
    int tempD, tempM, tempA;

    sscanf(buffer, "%*s %d%*c%d%*c%d", tempD, tempM, tempA);
    setDia(cliente, tempD);
    setMes(cliente, tempM);
    setAno(cliente, tempA);
}

void alterarInfoDesejada(Cliente *cliente){
    int escolha, temp;
    char tempNome[MAX];

    escolha = viewAlterarClienteInfo();

    switch(escolha){
        case 1:
            scanf("%[^\n]%*c", tempNome);
            setNome(cliente, tempNome);
            break;
        case 2:
            temp = viewTemp();
            setDia(cliente, temp);
            break;
        case 3:
            temp = viewTemp();
            setMes(cliente, temp);
            break;
        case 4:
            temp = viewTemp();
            setAno(cliente, temp);
            break;
    }
}

void alterarCadastrosCliente(int id, Cliente *cliente){
    char *line;
    char buffer[MAX];
    FILE *f;
    char temp[MAX];

    sprintf(temp, "ID: %d", id);

    f = fopen("info.txt", "w+");

    while(fgets(buffer, MAX, f)!=NULL){
        if(strstr(buffer, temp)){ // achou a linha que contem o ID;
            setID(cliente, id); // prencheu ID em memoria;
            getName(buffer, cliente); // preencheu Nome em memoria;
            fgets(buffer, MAX, f);
            getDate(buffer, cliente); // preencheu Data em memoria;
            removerInfo(id); // removeu info antiga;
            alterarInfoDesejada(cliente);
            preencherClienteTxt(cliente); // preencheu info nova;
            break; // sai da analise;
        }
    }
    fclose(f);
}

#endif // MODELCLIENTE_C
