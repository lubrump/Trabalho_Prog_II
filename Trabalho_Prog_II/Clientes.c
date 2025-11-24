#include "clientes.h"

void cadastrarCliente() {
    FILE *arquivo;
    Cliente cliente;
    int qtd;
    printf("-----------------------------------------------------------\n");
    printf("Quantos clientes deseja cadastrar?\n");
    printf("-----------------------------------------------------------\n");
    scanf("%d", &qtd);
    getchar(); // limpa o buffer

    arquivo = fopen("clientes.txt", "ab"); 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
    printf("----------------- Cadastro de Cliente %d ------------------\n", i + 1);
        printf("ID: ");
        scanf("%d", &cliente.id);
        getchar();

        printf("Nome: ");
        fgets(cliente.nome, 50, stdin);
        cliente.nome[strcspn(cliente.nome, "\n")] = '\0';

        printf("CNH: ");
        fgets(cliente.cnh, 20, stdin);
        cliente.cnh[strcspn(cliente.cnh, "\n")] = '\0';

        printf("Telefone: ");
        fgets(cliente.telefone, 20, stdin);
        cliente.telefone[strcspn(cliente.telefone, "\n")] = '\0';

        printf("Email: ");
        fgets(cliente.email, 50, stdin);
        cliente.email[strcspn(cliente.email, "\n")] = '\0';

        cliente.ativo = 1;

        fwrite(&cliente, sizeof(Cliente), 1, arquivo);
    }

    fclose(arquivo);
    printf("-----------------------------------------------------------\n");
    printf("Clientes cadastrados!\n");
}
void lerCliente() {
    FILE *arquivo;
    Cliente cliente;

    arquivo = fopen("clientes.txt", "rb");
    if (arquivo == NULL) {
        printf("Nenhum arquivo encontrado.\n");
        return;
    }

    printf("-------------- Lista de Clientes Cadastrados --------------\n\n");
    while ((fread(&cliente, sizeof(Cliente), 1, arquivo) == 1)) {
        if(cliente.ativo == 1){
            printf("ID: %d\n", cliente.id);
            printf("Nome: %s\n", cliente.nome);
            printf("CNH: %s\n", cliente.cnh);
            printf("Telefone: %s\n", cliente.telefone);
            printf("Email: %s\n\n", cliente.email);
        }
    }
    fclose(arquivo);
}
void editarCliente() {
    FILE *arquivo;
    Cliente cliente, editaCliente;
    int id, encontrado = 0;

    printf("--------------- Qual cliente deseja editar? ---------------\n\n");
    scanf("%d", &id);
    getchar(); // limpa o buffer

    arquivo = fopen("clientes.txt", "rb+"); 
    if (arquivo == NULL) {
        printf("-----------------------------------------------------------\n");
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    while((fread(&cliente, sizeof(Cliente), 1, arquivo)) > 0){
        if((id == cliente.id) && (cliente.ativo == 1)){
            encontrado = 1;
            printf("ID: %d\n", cliente.id);
            printf("Nome: %s\n", cliente.nome);
            printf("CNH: %s\n", cliente.cnh);
            printf("Telefone: %s\n", cliente.telefone);
            printf("Email: %s\n\n", cliente.email);
            printf("-------------------  Digite sua edicao: -------------------\n\n");
            printf("ID: ");
            scanf("%d", &editaCliente.id);
            getchar();

            printf("Nome: ");
            fgets(editaCliente.nome, 50, stdin);
            editaCliente.nome[strcspn(editaCliente.nome, "\n")] = '\0';

            printf("CNH: ");
            fgets(editaCliente.cnh, 20, stdin);
            editaCliente.cnh[strcspn(editaCliente.cnh, "\n")] = '\0';

            printf("Telefone: ");
            fgets(editaCliente.telefone, 20, stdin);
            editaCliente.telefone[strcspn(editaCliente.telefone, "\n")] = '\0';

            printf("Email: ");
            fgets(editaCliente.email, 50, stdin);
            editaCliente.email[strcspn(editaCliente.email, "\n")] = '\0';

            editaCliente.ativo = 1;

            fseek(arquivo, -sizeof(Cliente), SEEK_CUR);
            fwrite(&editaCliente, sizeof(Cliente), 1, arquivo);
            printf("\n-----------------------------------------------------------\n");
            printf("Registro %d editado com sucesso!\n", id);
            break;
        }
    }
    if(encontrado != 1){
        printf("\n-----------------------------------------------------------\n");
        printf("Registo com ID: %d nao encontrado\n", id);
    }
    fclose(arquivo);
}
   void deletarCliente(){
    FILE *arquivo;
    Cliente cliente, deletaCliente;
    int id, encontrado;

    printf("--------------- Qual cliente deseja deletar? ---------------\n\n");
    scanf("%d", &id);
    getchar(); // limpa o buffer

    arquivo = fopen("clientes.txt", "rb+"); 
    if (arquivo == NULL) {
        printf("-----------------------------------------------------------\n");
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    while((fread(&cliente, sizeof(Cliente), 1, arquivo)) > 0){
        if(id == cliente.id){
            encontrado = 1;
            printf("ID: %d\n", cliente.id);
            printf("Nome: %s\n", cliente.nome);
            printf("CNH: %s\n", cliente.cnh);
            printf("Telefone: %s\n", cliente.telefone);
            printf("Email: %s\n\n", cliente.email);

            deletaCliente.id = cliente.id;
            strcpy(deletaCliente.nome, cliente.nome);
            strcpy(deletaCliente.cnh, cliente.cnh);
            strcpy(deletaCliente.telefone, cliente.telefone);
            strcpy(deletaCliente.email, cliente.email);
            deletaCliente.ativo = 0;

            fseek(arquivo, -sizeof(Cliente), SEEK_CUR);
            fwrite(&deletaCliente, sizeof(Cliente), 1, arquivo);
            printf("\n-----------------------------------------------------------\n");
            printf("Registro %d deletado com sucesso!\n", id);
            break;
        }
    }
    if(encontrado != 1){
        printf("\n-----------------------------------------------------------\n");
        printf("Registo com ID: %d nao encontrado\n", id);
    }
    fclose(arquivo);
}