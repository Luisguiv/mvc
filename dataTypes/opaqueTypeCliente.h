#ifndef OPAQUETYPECLIENTE_H
#define OPAQUETYPECLIENTE_H
#include "libraries.h"

typedef struct Cliente Cliente;
Cliente *criarCliente(); // construtor;
void freeCliente(Cliente *this); // destrutor;

void setAno(Cliente *this, int ano); // control;
void setMes(Cliente *this, int mes); // control;
void setDia(Cliente *this, int dia); // control;
void setID(Cliente *this, int ID); // control;
void setNome(Cliente *this, char str[]); // control;
int showAno(Cliente *this); // control;
int showMes(Cliente *this); // control;
int showDia(Cliente *this); // control;
int showID(Cliente *this); // control;
char *showNome(Cliente *this); // control;
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
char *viewPreencherNome(); // view
void viewPreencherData(int *dia, int *mes, int *ano); // view;
int viewRemoverCliente(); // view;
void viewIDNotFound(); // view;


#endif // OPAQUETYPECLIENTE_H
