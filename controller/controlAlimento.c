// controlador façade para Alimento;
#ifndef CONTROLALIMENTO_C
#define CONTROLALIMENTO_C
#include "opaqueTypeClienteIntern.h"

Alimento *criarAlimento(){
    Alimento *newAlimento = malloc(sizeof(Alimento));

    inicializarAlimento(newAlimento, INIT, "'\0'", INIT, INIT, "'\0'");

    return newAlimento;
} // construtor;

void freeAlimento(Alimento *this){
    free(this);
} // destrutor;

void inicializarAlimento(Alimento *this, int alimentoID, char alimentoNome[], float valorCalorico, float preco, char marca[]){
    this->alimentoID = alimentoID;
    this->valorCalorico = valorCalorico;
    this->preco = preco;;
    strcpy(this->alimentoNome, alimentoNome);
    strcpy(this->marca, marca);
} // inicializador;

int showAlimentoID(Alimento *this){
    return this->alimentoID;
}

float showCaloria(Alimento *this){
    return this->valorCalorico;
}

float showPreco(Alimento *this){
    return this->preco;
}

void setAlimentoNome(Alimento *this, char nome[]){
    strcpy(this->alimentoNome, nome);
} // control;

void setCalorico(Alimento *this, float calorico){
    this->valorCalorico = calorico;
} // control;

void setPreco(Alimento *this, float preco){
    this->preco = preco;
} // control;

void setAlimentoID(Alimento *this, int ID){
    this->alimentoID = ID;
} // control;

void setMarca(Alimento *this, char marca[]){
    strcpy(this->marca, marca);
} // control;

void inserirAlimento(Alimento *alimento){
    int temp;

    temp = viewAlimento();

    if(temp==0) inserirAlimentoManual(alimento);
    if(temp==1) inserirAlimentoAuto(alimento);
} // control;

void inserirAlimentoManual(Alimento *alimento){
    int tempID;

    tempID = viewAlimentoManual();

    if(validarID(tempID)){
        if(livreAlimentoID(tempID)){
            setAlimentoID(alimento, tempID);
            preencherCadastrosAlimento(tempID);
            preencherAlimento(alimento);
            preencherAlimentoTxt(alimento);
        }
        else imprimirLog();
    }
    else imprimirLog();
} // control;

void inserirAlimentoAuto(Alimento *alimento){
    int tempID;

    tempID = gerarID();
    viewAlimentoAuto(tempID);
    setAlimentoID(alimento, tempID);
    preencherCadastrosAlimento(tempID);
    preencherAlimento(alimento);
    preencherAlimentoTxt(alimento);
} // control;

void removerAlimento(Alimento *alimento){
    int temp;

    if(alimento != NULL){ // remover da memoria;
        freeAlimento(alimento);
    }

    temp = viewRemoverAlimento();

    // remover do arquivo;
    if(livreID(temp)) viewIDNotFound();
    else{
        removerCadastrosAlimento(temp);
        removerInfoAlimento(temp);
    }
    writeOverCadastrosAlimento();
    writeOverInfoAlimento();
} // control;

void alterarAlimento(Alimento *alimento){
    int id;

    id = viewAlterarAlimento();

    if(livreID(id)) viewIDNotFound();
    else{
        alterarCadastrosAlimento(id, alimento);
    }
} // control;

void consultarAlimento(){
    system("notepad %USERPROFILE%\\Desktop\\build-mvc-Desktop_Qt_6_2_4_MinGW_64_bit-Debug\\infoAlimento.txt");
    system("pause");
} // control;

#endif // CONTROLALIMENTO_C
