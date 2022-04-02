#ifndef OPAQUETYPECLIENTEINTERN_H
#define OPAQUETYPECLIENTEINTERN_H
#include "opaqueTypeCliente.h"

struct Cliente{
    int clienteID;
    char clienteNome[MAX];
    int ano, mes, dia; // deve ser concatenado posteriormente;
    int viagensQtd;
    int historicoPerma; // refere-se ao id do alimento + quando foi pedido;
    int historicoMutavel; // historicoPerma com somente os alimento nao removidos;
};

void inicializarCliente(Cliente *this, int clienteID, char clienteNome[], int ano, int mes, int dia); // inicializador;
void setAno(Cliente *this, int ano); // control;
void setMes(Cliente *this, int mes); // control;
void setDia(Cliente *this, int dia); // control;
void setID(Cliente *this, int ID); // control;
void setNome(Cliente *this, char str[]); // control;
int showAno(Cliente *this); // control;
int showMes(Cliente *this); // control;
int showDia(Cliente *this); // control;
int showID(Cliente *this); // control;

struct Alimento{
    int alimentoID;
    char alimentoNome[MAX];
    float valorCalorico;
    float preco;
    char marca[MAX];
};

void inicializarAlimento(Alimento *this, int alimentoID, char alimentoNome[], float valorCalorico, float preco, char marca[]); // inicializador;
void setAlimentoNome(Alimento *this, char nome[]); // control;
void setCalorico(Alimento *this, float calorico); // control;
void setPreco(Alimento *this, float preco); // control;
void setAlimentoID(Alimento *this, int ID); // control;
void setMarca(Alimento *this, char marca[]); // control;
int showAlimentoID(Alimento *this); // control;
float showCaloria(Alimento *this); // control;
float showPreco(Alimento *this); // control;

#endif // OPAQUETYPECLIENTEINTERN_H
