# 🚗 Sistema de Gerenciamento de Aluguel de Veículos

> **Projeto desenvolvido como exigência parcial da disciplina SI203/SI200 (Algoritmos e Programação de Computadores II) da Faculdade de Tecnologia - UNICAMP.**

![Language](https://img.shields.io/badge/language-C-blue)
![Status](https://img.shields.io/badge/status-Concluído-success)
![University](https://img.shields.io/badge/unicamp-FT-orange)

## 📖 Sobre o Projeto

Este projeto consiste em um sistema completo para automação e gerenciamento de uma locadora de veículos. O objetivo principal foi desenvolver uma solução que otimize o fluxo de trabalho de uma frota, substituindo processos manuais propensos a erros por um sistema confiável e ágil.

O software foi desenvolvido inteiramente em **Linguagem C**, utilizando conceitos avançados de manipulação de arquivos binários para garantir a persistência dos dados de clientes, veículos e contratos de aluguel, mesmo após o fechamento do programa.

## ⚙️ Funcionalidades

O sistema conta com um menu interativo via console que permite realizar todas as operações essenciais (CRUD) e processos de negócio da locadora:

### 🚘 Gestão de Frota (Carros)
- **Cadastrar:** Adição de novos veículos com ID, modelo, placa, ano e preço da diária.
- **Consultar:** Listagem geral, apenas de carros disponíveis ou apenas de carros alugados.
- **Editar:** Atualização de dados de veículos já cadastrados.
- **Excluir:** Remoção de veículos do sistema.

### 👥 Gestão de Clientes
- **Cadastrar:** Registro de clientes com ID, nome, CNH, telefone e e-mail.
- **Consultar:** Visualização da base completa de clientes.
- **Editar:** Alteração de informações de contato ou documentos.
- **Excluir:** Remoção de clientes da base de dados.

### 🔑 Operações de Aluguel
- **Realizar Aluguel:** Vincula um carro disponível a um cliente cadastrado, gerando um contrato ativo.
- **Realizar Devolução:** Finaliza o contrato, liberando o carro novamente para a frota de disponíveis.

## 🛠️ Tecnologias e Conceitos Utilizados

- **Linguagem C:** Lógica principal e estruturação do código.
- **Structs:** Organização dos dados complexos (Carro, Cliente, Aluguel).
- **Manipulação de Arquivos (`FILE *`):**
  - Uso de `fopen`, `fread`, `fwrite`, `fseek` para leitura e escrita.
  - Armazenamento em arquivos `.txt` (modo binário/texto) para persistência de dados (`carros.txt`, `clientes.txt`, `carrosalugados.txt`).
- **Modularização:** Código dividido em arquivos `.c` e `.h` (`Aluguel.c`, `Carros.c`, `Clientes.c`) para melhor organização e manutenção.

## 🚀 Como Executar

Para rodar o projeto em sua máquina, você precisará de um compilador C (como o GCC).

1. **Clone o repositório:**
   ```bash
   git clone [https://github.com/lubrump/Trabalho_Prog_II.git](https://github.com/lubrump/Trabalho_Prog_II.git)
   
2. **Compile o código: Navegue até a pasta do projeto e execute o comando de compilação:**
   ```bash
   gcc Aluguel.c Carros.c Clientes.c -o locadora

4. **Execute o programa.**

   **OBS(Caso seja Windows):**
   ```bash
   locadora.exe
   ```

## **Projeto desenvolvido pelas alunas do curso de Tecnologia em Análise e Desenvolvimento de Sistemas:**

Barbára Helóra Nigra Táparo

Bianka Barboza Baptista de Oliveira

Gabriela Nogueira

Luiza Brum Pires de Brito

Yasmin Caetano Betioli
