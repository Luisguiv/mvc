#ifndef OPAQUETYPECLIENTEINTERN_H
#define OPAQUETYPECLIENTEINTERN_H
#include "opaqueTypeCliente.h"

struct Cliente{
    int clienteID;
    char clienteNome[MAX];
    int ano, mes, dia; // deve ser concatenado posteriormente;
};

void inicializarCliente(Cliente *this, int clienteID, char clienteNome[], int ano, int mes, int dia); // inicializador;

#endif // OPAQUETYPECLIENTEINTERN_H
