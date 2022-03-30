// controlador façade para Cliente;
#ifndef CONTROLCLIENTE_C
#define CONTROLCLIENTE_C
#include "opaqueTypeClienteIntern.h"

// construtor:
Cliente *criarCliente(){
    Cliente *newCliente = malloc(sizeof(Cliente));

    inicializarCliente(newCliente, INIT, "'\0'", INIT, INIT, INIT);

    return newCliente;
}

// inicializador;
void inicializarCliente(Cliente *this, int clienteID, char clienteNome[], int ano, int mes, int dia){
    this->clienteID = clienteID;
    this->ano = ano;
    this->mes = mes;
    this->dia = dia;
    strcpy(this->clienteNome, clienteNome);
}

// destrutor;
void freeCliente(Cliente *this){
    free(this);
}

// setters;
void setAno(Cliente *this, int ano){
    this->ano = ano;
}

void setMes(Cliente *this, int mes){
    this->mes = mes;
}

void setDia(Cliente *this, int dia){
    this->dia = dia;
}

void setID(Cliente *this, int ID){
    this->clienteID = ID;
}

void setNome(Cliente *this, char str[]){
    strcpy(this->clienteNome, str);
}

// shows;
int showAno(Cliente *this){
    return this->ano;
}

int showMes(Cliente *this){
    return this->mes;
}

int showDia(Cliente *this){
    return this->dia;
}

int showID(Cliente *this){
    return this->clienteID;
}

///////////////////////////////////////////////////////////////
/////////////////// funcoes e procedimentos ///////////////////
///////////////////////////////////////////////////////////////

int validarID(int ID){
    // REGRA DE VALIDAÇÃO: ID deve ser maior ou igual a 0;
    if(ID >= 0) return 1;
    else return 0;
}

int gerarID(){
    int tempID;
    time_t t;

    srand((unsigned) time(&t));

    tempID = rand() % 50;

    while(!livreID(tempID)){
        tempID = rand() % 50;
    }

    return tempID;
}

void inserirCliente(Cliente *clienteAtual){
    int temp;

    temp = viewCliente();

    if(temp==0) inserirClienteManual(clienteAtual);
    if(temp==1) inserirClienteAuto(clienteAtual);
}

void inserirClienteManual(Cliente *clienteAtual){
    int tempID;

    tempID = viewClienteManual();

    if(validarID(tempID)){
        if(livreID(tempID)){
            setID(clienteAtual, tempID);
            preencherCadastros(tempID);
            preencherCliente(clienteAtual);
            preencherClienteTxt(clienteAtual);
        }
        else imprimirLog();
    }
    else imprimirLog();
}

void inserirClienteAuto(Cliente *clienteAtual){
    int tempID;

    tempID = gerarID();
    viewClienteAuto(tempID);
    setID(clienteAtual, tempID);
    preencherCadastros(tempID);
    preencherCliente(clienteAtual);
    preencherClienteTxt(clienteAtual);
}

void removerCliente(Cliente *clienteAtual){
    int temp;

    if(clienteAtual != NULL){ // remover da memoria;
        freeCliente(clienteAtual);
    }

    temp = viewRemoverCliente();

    // remover do arquivo;
    if(livreID(temp)) viewIDNotFound();
    else{
        removerCadastros(temp);
        removerInfo(temp);
    }
}

void alterarCliente(Cliente *clienteAtual){
    int id;

    id = viewAlterarCliente();

    if(livreID(id)) viewIDNotFound();
    else{
        alterarCadastrosCliente(id);
    }
}

#endif // CONTROLCLIENTE_C
