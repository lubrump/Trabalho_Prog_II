#ifndef CARROS_H
#define CARROS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para carro
typedef struct {
    int id;
    char modelo[50];
    char placa[10];
    int ano;
    float preco;
    int ativo;
    int alugado;
} Carro;

typedef struct 
{
    char placa[10];
    char nome[50];
    char cnh[20];
    char dataaluguel[15];
    char datadevolucao[15];
    int ativo;

} Aluguel;


// Funções
void cadastrarCarro();
void lerCarro();
void editarCarro();
void deletarCarro();
void lerDisponiveis();
void lerAlugados();
void alugarCarro();
void devolverCarro();

#endif