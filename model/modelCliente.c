#ifndef MODELCLIENTE_C
#define MODELCLIENTE_C
#include "opaqueTypeClienteIntern.h"

void addTrip(){
    FILE *f;
    int ID;
    char str[MAX];

    printf("Qual o ID do usuario?\n");
    scanf("%d", &ID);
    printf("Para onde o usuario vai/foi?\n");
    scanf("%*c");
    scanf("%[^\n]%*c", str);

    f = fopen("trip.txt", "a");
    fprintf(f, "\n");
    fprintf(f, "%d: {%s}\n", ID, str);

    fclose(f);
}

void addHist(){
    time_t rawtime;
    struct tm *timeinfo;
    FILE *f;
    int IDc, IDa;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    printf("Qual o ID do usuario?\n");
    scanf("%d", &IDc);
    printf("Qual o ID do alimento pedido?\n");
    scanf("%d", &IDa);

    f = fopen("hist.txt", "a");
    fprintf(f, "\n");
    fprintf(f, "%d: %d: %s", IDc, IDa, asctime(timeinfo));

    fclose(f);
}

int livreID(int ID){ // arquivo;
    int tempID;
    char buffer[20];
    char *line;
    FILE *f;

    f = fopen("cadastros.txt", "r");

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

    f = fopen("info.txt", "a");
    fprintf(f, "\n");
    fprintf(f, "%d {Nome: ",  showID(clienteAtual));
    for(count=0; clienteAtual->clienteNome[count]!=0; count++) fprintf(f, "%c", clienteAtual->clienteNome[count]);
    fprintf(f, "; Data: %02d/%02d/%04d}\n", showDia(clienteAtual), showMes(clienteAtual), showAno(clienteAtual));
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

    fprintf(f, "ERRO: ID nao se enquadra nas regras de validacao; (ID DEVE SER UNICO E SER UM NUMERO POSITIVO MAIOR OU IGUAL A ZERO): %s", asctime(timeinfo));

    fclose(f);

    printf("ERRO: ID nao se enquadra nas regras de validacao; (ID DEVE SER UNICO E SER UM NUMERO POSITIVO MAIOR OU IGUAL A ZERO).\n");
}

int linhaRemover(int ID, char str[]){ // arquivo;
    int i=1;
    int tempID;
    char *line;
    char buffer[MAX];
    FILE *f;

    f = fopen(str, "r");

    do{ // ignora a primeira linha que contem \n;
        line = fgets(buffer, MAX, f);
        line = fgets(buffer, MAX, f);
    }   while(0);

    while(line!=NULL){
        sscanf(buffer, "%d", &tempID);
        if(ID==tempID) return i+1;
        i++;
        line = fgets(buffer, MAX, f);
    }
    fclose(f);

    return -1;
}

void removerInfo(int ID){ // arquivo;
    FILE *f1, *f2;
    int del;
    int line_number=1;
    char buffer[MAX];

    del = linhaRemover(ID, "info.txt");

    f1 = fopen("info.txt", "r");
    f2 = fopen("replicaInfo.txt", "w");

    while(fgets(buffer, MAX, f1)!=NULL){
        if(del != line_number){
          fprintf(f2, "%s", buffer);
        }
        line_number++;
    }

    fclose(f1);
    fclose(f2);
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
}

void writeOverCadastros(){
    FILE *f1, *f2;
    char buffer[MAX];

    f1 = fopen("cadastros.txt", "w");
    f2 = fopen("replica.txt", "r");

    while(fgets(buffer, MAX, f2)!=NULL){
        fprintf(f1, "%s", buffer);
    }

    fclose(f1);
    fclose(f2);
}

void writeOverInfo(){
    FILE *f1, *f2;
    char buffer[MAX];

    f1 = fopen("info.txt", "w");
    f2 = fopen("replicaInfo.txt", "r");

    while(fgets(buffer, MAX, f2)!=NULL){
        fprintf(f1, "%s", buffer);
    }

    fclose(f1);
    fclose(f2);
}

void getName(char buffer[], Cliente *cliente){
    char temp[MAX];

    sscanf(buffer, "%*d %*c%*c%*c%*c%*c%*c %[^;]%*c", temp);
    setNome(cliente, temp);
}

void getDate(char buffer[], Cliente *cliente){
    int tempD, tempM, tempA;
    char *temp;

    temp = strstr(buffer, "Data: ");
    sscanf(temp, "%*c%*c%*c%*c%*c %d%*c%d%*c%d", &tempD, &tempM, &tempA);
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
            scanf("%*c");
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

    sprintf(temp, "%d", id);

    f = fopen("info.txt", "r");

    while(fgets(buffer, MAX, f)!=NULL){
        if(strstr(buffer, temp)){ // achou a linha que contem o ID;
            setID(cliente, id); // prencheu ID em memoria;
            getName(buffer, cliente); // preencheu Nome em memoria;
            getDate(buffer, cliente); // preencheu Data em memoria;

            removerInfo(id); // removeu info antiga;
            writeOverInfo(); // escrever em cima;

            alterarInfoDesejada(cliente); // alterar o que deseja;
            preencherClienteTxt(cliente); // preencheu info nova;
            break; // sai da analise;
        }
    }
    fclose(f);
}

#endif // MODELCLIENTE_C
