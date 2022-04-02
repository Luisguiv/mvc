#ifndef MODELALIMENTO_C
#define MODELALIMENTO_C
#include "opaqueTypeClienteIntern.h"

int livreAlimentoID(int ID){
    int tempID;
    char buffer[20];
    char *line;
    FILE *f;

    f = fopen("cadastrosAlimento.txt", "r");

    do{ // ignora a primeira linha que contem \n;
        fgets(buffer, 20, f);
    }   while(0);

    while((line = fgets(buffer, 20, f))!=NULL){
        sscanf(line, "%d", &tempID);
        if(ID==tempID) return 0;
    }
    fclose(f);

    return 1;
} // model;

void writeOverCadastrosAlimento(){
    FILE *f1, *f2;
    char buffer[MAX];

    f1 = fopen("cadastrosAlimento.txt", "w");
    f2 = fopen("replicaAlimento.txt", "r");

    while(fgets(buffer, MAX, f2)!=NULL){
        fprintf(f1, "%s", buffer);
    }

    fclose(f1);
    fclose(f2);
} // model;

void writeOverInfoAlimento(){
    FILE *f1, *f2;
    char buffer[MAX];

    f1 = fopen("infoAlimento.txt", "w");
    f2 = fopen("replicaInfoAlimento.txt", "r");

    while(fgets(buffer, MAX, f2)!=NULL){
        fprintf(f1, "%s", buffer);
    }

    fclose(f1);
    fclose(f2);
} // model;

void alterarCadastrosAlimento(int id, Alimento *alimento){
    char *line;
    char buffer[MAX];
    FILE *f;
    char temp[MAX];

    sprintf(temp, "%d", id);

    f = fopen("infoAlimento.txt", "r");

    while(fgets(buffer, MAX, f)!=NULL){
        if(strstr(buffer, temp)){ // achou a linha que contem o ID;
            setAlimentoID(alimento, id); // prencheu ID em memoria;
            getNomeAlimento(buffer, alimento); // preencheu Nome em memoria;
            // preencheu Info restantes em memoria;
            getCaloria(buffer, alimento);
            getPreco(buffer, alimento);
            getMarca(buffer, alimento);

            removerInfoAlimento(id); // removeu info antiga;
            writeOverInfoAlimento(); // escrever em cima;

            alterarInfoDesejadaAlimento(alimento); // alterar o que deseja;
            preencherAlimentoTxt(alimento); // preencheu info nova;
            break; // sai da analise;
        }
    }
    fclose(f);
} // model;

void alterarInfoDesejadaAlimento(Alimento *alimento){
    int escolha;
    float temp;
    char tempNome[MAX];
    char tempMar[MAX];

    escolha = viewAlterarAlimentoInfo();

    switch(escolha){
        case 1:
            scanf("%*c");
            scanf("%[^\n]%*c", tempNome);
            setAlimentoNome(alimento, tempNome);
            break;
        case 2:
            temp = viewTempAlimento();
            setCalorico(alimento, temp);
            break;
        case 3:
            temp = viewTempAlimento();
            setPreco(alimento, temp);
            break;
        case 4:
            scanf("%*c");
            scanf("%[^\n]%*c", tempMar);
            setMarca(alimento, tempMar);
            break;
    }
} // model;

void getNomeAlimento(char buffer[], Alimento *alimento){
    char temp[MAX];

    sscanf(buffer, "%*d %*c%*c%*c%*c%*c%*c %[^;]%*c", temp);
    setAlimentoNome(alimento, temp);
} // model;

void getCaloria(char buffer[], Alimento *alimento){
    float tempCal;
    char *temp;

    temp = strstr(buffer, "Calorias: ");
    sscanf(temp, "%*c%*c%*c%*c%*c%*c%*c%*c%*c %f", &tempCal);
    setCalorico(alimento, tempCal);
} // model;

void getPreco(char buffer[], Alimento *alimento){
    float tempPr;
    char *temp;

    temp = strstr(buffer, "Preco: ");
    sscanf(temp, "%*c%*c%*c%*c%*c%*c %f", &tempPr);
    setPreco(alimento, tempPr);
} // model;

void getMarca(char buffer[], Alimento *alimento){
    char tempMar[MAX];
    char *temp;

    if(alimento->temMar){
        temp = strstr(buffer, "Marca: ");
        sscanf(buffer, "%*c%*c%*c%*c%*c%*c %[^}]%*c", tempMar);
        setMarca(alimento, tempMar);
    }

} // model;

void preencherCadastrosAlimento(int ID){
    FILE *f;

    f = fopen("cadastrosAlimento.txt", "a");
    fprintf(f, "\n");
    fprintf(f, "%d", ID);

    fclose(f);
} // model;

void preencherAlimentoTxt(Alimento *alimento){
    FILE *f;
    int count;

    f = fopen("infoAlimento.txt", "a");
    fprintf(f, "\n");
    fprintf(f, "%d {Nome: ",  showAlimentoID(alimento));
    for(count=0; alimento->alimentoNome[count]!=0; count++) fprintf(f, "%c", alimento->alimentoNome[count]);
    fprintf(f, "; Calorias: %.2f kcal; Preco: R$%.2f", showCaloria(alimento), showPreco(alimento));
    if(alimento->temMar){
        fprintf(f, "; Marca: ");
        for(count=0; alimento->marca[count]!=0; count++) fprintf(f, "%c", alimento->marca[count]);
    }
    else fprintf(f, "; Marca: SEM_MARCA");
    fprintf(f, "}\n");
    fclose(f);
} // model;

void preencherAlimento(Alimento *alimento){
    char tempNome[MAX];
    float tempCal, tempPr;
    char tempMar[MAX];

    viewPreencherAlimentoNome(tempNome);
    setAlimentoNome(alimento, tempNome);
    viewPreencherCalPr(&tempCal, &tempPr);
    setCalorico(alimento, tempCal);
    setPreco(alimento, tempPr);
    if(viewPreencherMarca(tempMar)) {
        setMarca(alimento, tempMar);
        alimento->temMar = 1;
    }
    else {
        setMarca(alimento, "SEM_MARCA");
        alimento->temMar = 0;
    }
} // model;

void removerInfoAlimento(int ID){
    FILE *f1, *f2;
    int del;
    int line_number=1;
    char buffer[MAX];

    del = linhaRemover(ID, "infoAlimento.txt");

    f1 = fopen("infoAlimento.txt", "r");
    f2 = fopen("replicaInfoAlimento.txt", "w");

    while(fgets(buffer, MAX, f1)!=NULL){
        if(del != line_number){
          fprintf(f2, "%s", buffer);
        }
        line_number++;
    }

    fclose(f1);
    fclose(f2);
} // model;

void removerCadastrosAlimento(int ID){
    FILE *f1, *f2;
    int del;
    int line_number=1;
    char buffer[MAX];

    del = linhaRemover(ID, "cadastrosAlimento.txt");

    f1 = fopen("cadastrosAlimento.txt", "r");
    f2 = fopen("replicaAlimento.txt", "w");

    while(fgets(buffer, MAX, f1)!=NULL){
        if(del != line_number){
          fprintf(f2, "%s", buffer);
        }
        line_number++;
    }

    fclose(f1);
    fclose(f2);
} // model;

#endif // MODELALIMENTO_C
