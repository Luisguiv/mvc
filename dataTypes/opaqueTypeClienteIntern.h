#ifndef OPAQUETYPECLIENTEINTERN_H
#define OPAQUETYPECLIENTEINTERN_H
#include "opaqueTypeCliente.h"

struct Cliente{
    int clienteID;
    char clienteNome[MAX];
    int ano, mes, dia; // deve ser concatenado posteriormente;
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

#endif // OPAQUETYPECLIENTEINTERN_H
