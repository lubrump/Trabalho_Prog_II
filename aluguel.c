#include <stdio.h>
#include "carros.h"
#include "clientes.h"

int main(){

    int menu;

    printf("-----------------------------------------------------------\n");
    printf("Seja muito bem vindo ao sistema de gerenciamento de carros!\n");
    do{
    printf("-----------------------------------------------------------\n");
    printf("Escolha uma opcao:\n");
    printf("1- Cadastrar\n");
    printf("2- Consultar\n");
    printf("3- Editar\n");
    printf("4- Alugar\n");
    printf("5- Deletar\n");
    printf("0- Sair\n");
    printf("-----------------------------------------------------------\n");
    scanf("%d", &menu);
    switch (menu)
    {
   case 1:
        printf("-----------------------------------------------------------\n");
        printf("Selecione o que deseja cadastrar:\n");
        printf("1- Cliente\n");
        printf("2- Carro\n");
        printf("-----------------------------------------------------------\n");
        int cadastro;
        scanf("%d", &cadastro);
        switch (cadastro)
        {
        case 1:
            cadastrarCliente();
            break;
        
        case 2:
            cadastrarCarro();
            break;
        
        default:
            break;
        }
        break;
   case 2:
        printf("-----------------------------------------------------------\n");
        printf("Selecione o que deseja consultar:\n");
        printf("1- Todos os Clientes\n");
        printf("2- Todos os Carros\n");
        printf("3- Carros Disponiveis\n");
        printf("4- Carros Alugados\n");
        printf("-----------------------------------------------------------\n");
        int consulta;
        scanf("%d", &consulta);
        switch (consulta)
        {
        case 1:
            lerCliente();
            break;
        
        case 2:
            lerCarro();
            break;

        case 3:
            lerDisponiveis();
            break;
        
        case 4:
            lerAlugados();
            break;
        
        default:
            break;
        }
        break;
     case 3:
        printf("-----------------------------------------------------------\n");
        printf("Selecione o que deseja editar:\n");
        printf("1- Cliente\n");
        printf("2- Carro\n");
        printf("-----------------------------------------------------------\n");
        int edicao;
        scanf("%d", &edicao);
        switch (edicao)
        {
        case 1:
            editarCliente();
            break;
        
        case 2:
            editarCarro();
            break;
        
        default:
            break;
        }
        break;
   case 4:
        printf("-----------------------------------------------------------\n");
        printf("Selecione o que deseja fazer:\n");
        printf("1- Alugar um carro\n");
        printf("2- Devolver um carro\n");
        printf("-----------------------------------------------------------\n");
        int aluguel;
        scanf("%d", &aluguel);
        switch (aluguel)
        {
        case 1:
            alugarCarro();
            break;
        
        case 2:
            devolverCarro();
            break;
        
        default:
            break;
        }
        break;
    case 5:
        printf("-----------------------------------------------------------\n");
        printf("Selecione o que deseja deletar:\n");
        printf("1- Cliente\n");
        printf("2- Carro\n");
        printf("-----------------------------------------------------------\n");
        int deleta;
        scanf("%d", &deleta);
        switch (deleta)
        {
        case 1:
            deletarCliente();
            break;

        case 2:
            deletarCarro();
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }
    }
    while(menu != 0);

    return 0;
}
