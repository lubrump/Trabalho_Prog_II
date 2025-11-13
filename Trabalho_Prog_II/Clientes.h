#ifndef CLIENTES_H
#define CLIENTES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//estrutura para cliente
typedef struct {
    int id;
    char cnh[20];
    char telefone[20];
    char nome[50];
    char email[50];
    int ativo;

} Cliente;

// Funções
void cadastrarCliente();
void lerCliente();
void editarCliente();
void deletarCliente();

#endif