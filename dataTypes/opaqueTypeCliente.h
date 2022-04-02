#ifndef OPAQUETYPECLIENTE_H
#define OPAQUETYPECLIENTE_H
#include "libraries.h"

typedef struct Cliente Cliente;
Cliente *criarCliente(); // construtor;
void freeCliente(Cliente *this); // destrutor;
void writeOverCadastros(); // model;
void writeOverInfo(); // model;
int validarID(int ID); // control;
int gerarID(); // control;
void inserirCliente(Cliente *clienteAtual); // control;
void inserirClienteManual(Cliente *clienteAtual); // control;
void inserirClienteAuto(Cliente *clienteAtual); // control;
void removerCliente(Cliente *clienteAtual); // control;
int livreID(int ID); // model;
void imprimirLog(); // model;
void preencherCadastros(int ID); // model;
void preencherClienteTxt(Cliente *clienteAtual); // model;
void preencherCliente(Cliente *clienteAtual); // model;
int linhaRemover(int ID, char str[]); // model;
void removerInfo(int ID); // model;
void removerCadastros(int ID); // model;
void removerClienteMemoria(Cliente *clienteAtual); // model;
int viewCliente(); // view;
int viewClienteManual(); // view;
void viewClienteAuto(int tempID); // view;
void viewPreencherNome(char str[]); // view
void viewPreencherData(int *dia, int *mes, int *ano); // view;
int viewRemoverCliente(); // view;
void viewIDNotFound(); // view;
void alterarCliente(Cliente *clienteAtual); // control;
void alterarCadastrosCliente(int id, Cliente *clienteAtual); // model;
void alterarInfoDesejada(Cliente *cliente); // model;
void getNome(char buffer[], Cliente *cliente); // model;
void getDate(char buffer[], Cliente *cliente); // model;
int viewAlterarCliente(); // view;
int viewAlterarClienteInfo(); // view;
int viewTemp(); // view;
void consultar(); // control;

typedef struct Alimento Alimento;
Alimento *criarAlimento(); // construtor;
void freeAlimento(Alimento *this); // destrutor;
void inserirAlimento(Alimento *alimento); // control;
void inserirAlimentoManual(Alimento *alimento); // control;
void inserirAlimentoAuto(Alimento *alimento); // control;
void removerAlimento(Alimento *alimento); // control;
void preencherCadastrosAlimento(int ID); // model;
void preencherAlimentoTxt(Alimento *alimento); // model;
void preencherAlimento(Alimento *alimento); // model;
void removerInfoAlimento(int ID); // model;
void removerCadastrosAlimento(int ID); // model;
void removerAlimentoMemoria(Alimento *alimento); // model;
void alterarAlimento(Alimento *alimento); // control;
void alterarCadastrosAlimento(int id, Alimento *alimento); // model;
void alterarInfoDesejadaAlimento(Alimento *alimento); // model;
void getNomeAlimento(char buffer[], Alimento *alimento); // model;
void getCaloria(char buffer[], Alimento *alimento); // model;
void getPreco(char buffer[], Alimento *alimento); // model;
void getMarca(char buffer[], Alimento *alimento); // model;
int viewAlimento(); // view;
int viewAlimentoManual(); // view;
void viewAlimentoAuto(int tempID); // view;
void viewPreencherNomeAlimento(char str[]); // view
int viewRemoverAlimento(); // view;
int livreAlimentoID(int ID); // model;
void writeOverCadastrosAlimento(); // model;
void writeOverInfoAlimento(); // model;
int viewAlterarAlimento(); // view;
int viewAlterarAlimentoInfo(); // view;
float viewTempAlimento(); // view;
void consultarAlimento(); // control;
void viewPreencherAlimentoNome(char tempNome[]); // view;
void viewPreencherCalPr(float *tempCal, float *tempPr); // view;
int viewPreencherMarca(char tempMar[]); // view;

#endif // OPAQUETYPECLIENTE_H
