#ifndef OPAQUETYPECLIENTE_H
#define OPAQUETYPECLIENTE_H
#include "libraries.h"

typedef struct Cliente Cliente;
Cliente *criarCliente(); // construtor;
void freeCliente(Cliente *this); // destrutor;
void writeOverCadastros();
void writeOverInfo();
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
void consultar();

#endif // OPAQUETYPECLIENTE_H
