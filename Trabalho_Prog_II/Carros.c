#include "carros.h"
#include "clientes.h"

void cadastrarCarro() {
    FILE *arquivo;
    Carro carro;
    int qtd;
    printf("-----------------------------------------------------------\n");   
    printf("Quantos carros deseja cadastrar?\n");
    printf("-----------------------------------------------------------\n");
    scanf("%d", &qtd);
    getchar(); // limpa o buffer

    arquivo = fopen("carros.txt", "ab"); 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("------------------ Cadastro do carro %d -------------------\n", i + 1);
        printf("ID: ");
        scanf("%d", &carro.id);
        getchar();

        printf("Modelo: ");
        fgets(carro.modelo, 50, stdin);
        carro.modelo[strcspn(carro.modelo, "\n")] = '\0';

        printf("Placa: ");
        fgets(carro.placa, 10, stdin);
        carro.placa[strcspn(carro.placa, "\n")] = '\0';

        printf("Ano: ");
        scanf("%d", &carro.ano);
        getchar();

        printf("Preco: ");
        scanf("%f", &carro.preco);
        getchar();
        carro.ativo = 1;
        carro.alugado = 0;

        fwrite(&carro, sizeof(Carro), 1, arquivo);
    }

    fclose(arquivo);
    printf("-----------------------------------------------------------\n");
    printf("Carros cadastrados!\n");
}
void lerCarro() {
    FILE *arquivo;
    Carro carro;

    arquivo = fopen("carros.txt", "rb");
    if (arquivo == NULL) {
        printf("-----------------------------------------------------------\n");
        printf("Nenhum arquivo encontrado.\n");
        return;
    }

    printf("--------------- Lista de Carros Cadastrados ---------------\n\n");
    while ((fread(&carro, sizeof(Carro), 1, arquivo) == 1)) {
        if(carro.ativo == 1){
            printf("ID: %d\n", carro.id);
            printf("Modelo: %s\n", carro.modelo);
            printf("Placa: %s\n", carro.placa);
            printf("Ano: %d\n", carro.ano);
            printf("Preco: R$%.2f\n\n", carro.preco);
        }
    }
    fclose(arquivo);
}
void lerDisponiveis() {
    FILE *arquivo;
    Carro carro;

    arquivo = fopen("carros.txt", "rb");
    if (arquivo == NULL) {
        printf("-----------------------------------------------------------\n");
        printf("Nenhum arquivo encontrado.\n");
        return;
    }

    printf("--------------- Lista de Carros Disponiveis ---------------\n\n");
    while ((fread(&carro, sizeof(Carro), 1, arquivo) == 1)) {
        if((carro.ativo == 1) && (carro.alugado == 0)){
            printf("ID: %d\n", carro.id);
            printf("Modelo: %s\n", carro.modelo);
            printf("Placa: %s\n", carro.placa);
            printf("Ano: %d\n", carro.ano);
            printf("Preco: R$%.2f\n", carro.preco);
            printf("Disponivel!\n\n");
        }
    }
    fclose(arquivo);
}
void lerAlugados() {
    FILE *alugados = fopen("carrosalugados.txt", "rb");
    FILE *arquivo = fopen("carros.txt", "rb");
    Aluguel aluguel;
    Carro carro;
 
    if (alugados == NULL) {
        printf("-----------------------------------------------------------\n");   
        printf("Nenhum arquivo encontrado.\n");
        return;
    }
    if (arquivo == NULL) {
        printf("-----------------------------------------------------------\n");   
        printf("Nenhum arquivo encontrado.\n"); 
        return;
    }

    printf("----------------- Lista de Carros Alugados ----------------\n\n");

    while ((fread(&aluguel, sizeof(Aluguel), 1, alugados) == 1)) {

        if(aluguel.ativo == 1){
            printf("Placa: %s\n", aluguel.placa);
            printf("Nome do Locatario: %s\n", aluguel.nome);
            printf("CNH: %s\n", aluguel.cnh);
            printf("Data de Aluguel: %s\n", aluguel.dataaluguel);
            printf("Data de Devolucao: %s\n", aluguel.datadevolucao);

            rewind(arquivo);

            while ((fread(&carro, sizeof(Carro), 1, arquivo) == 1)) {
                if((aluguel.ativo == 1) && (strcmp(aluguel.placa, carro.placa) == 0)){
                    printf("Modelo: %s\n", carro.modelo);
                    printf("Ano: %d\n", carro.ano);
                    printf("Preco: R$%.2f\n\n", carro.preco);
                }      
            }      
    }
    
    }
    fclose(alugados);
}
void editarCarro() {
    FILE *arquivo;
    Carro carro, editaCarro;
    int id, encontrado = 0;

    printf("---------------- Qual carro deseja editar? ----------------\n\n");
    scanf("%d", &id);
    getchar(); // limpa o buffer

    arquivo = fopen("carros.txt", "rb+"); 
    if (arquivo == NULL) {
        printf("-----------------------------------------------------------\n");   
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    while((fread(&carro, sizeof(Carro), 1, arquivo)) > 0){
        if((id == carro.id) && (carro.ativo == 1)){
            encontrado = 1;
            printf("ID: %d\n", carro.id);
            printf("Modelo: %s\n", carro.modelo);
            printf("Placa: %s\n", carro.placa);
            printf("Ano: %d\n", carro.ano);
            printf("Preco: R$%.2f\n\n", carro.preco);

            printf  ("-------------------- Digite sua edicao: -------------------\n\n");
            printf("ID: ");
            scanf("%d", &editaCarro.id);
            getchar();

            printf("Modelo: ");
            fgets(editaCarro.modelo, 50, stdin);
            editaCarro.modelo[strcspn(editaCarro.modelo, "\n")] = '\0';

            printf("Placa: ");
            fgets(editaCarro.placa, 10, stdin);
            editaCarro.placa[strcspn(editaCarro.placa, "\n")] = '\0';

            printf("Ano: ");
            scanf("%d", &editaCarro.ano);
            getchar();

            printf("Preco: ");
            scanf("%f", &editaCarro.preco);
            getchar();

            editaCarro.ativo = 1;
            editaCarro.alugado = 0;

            fseek(arquivo, -sizeof(Carro), SEEK_CUR);
            fwrite(&editaCarro, sizeof(Carro), 1, arquivo);
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
void deletarCarro(){
    FILE *arquivo;
    Carro carro, deletaCarro;
    int id, encontrado;

    printf("--------------- Qual carro deseja deletar? ----------------\n");
    scanf("%d", &id);
    getchar(); // limpa o buffer

    arquivo = fopen("carros.txt", "rb+"); 
    if (arquivo == NULL) {
        printf("-----------------------------------------------------------\n");   
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    while((fread(&carro, sizeof(Carro), 1, arquivo)) > 0){
        if((id == carro.id) && (carro.ativo == 1)){
            encontrado = 1;
            printf("ID: %d\n", carro.id);
            printf("Modelo: %s\n", carro.modelo);
            printf("Placa: %s\n", carro.placa);
            printf("Ano: %d\n", carro.ano);
            printf("Preco: R$%.2f\n\n", carro.preco);

            deletaCarro.id = carro.id;
            strcpy(deletaCarro.modelo, carro.modelo);
            strcpy(deletaCarro.placa, carro.placa);
            deletaCarro.ano = carro.ano;
            deletaCarro.preco = carro.preco;
            deletaCarro.alugado = 0;
            deletaCarro.ativo = 0;

            fseek(arquivo, -sizeof(Carro), SEEK_CUR);
            fwrite(&deletaCarro, sizeof(Carro), 1, arquivo);
            printf("-----------------------------------------------------------\n");   
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
void alugarCarro() {

    Aluguel aluguel;
    Carro carro, carroAlugado;
    int encontrado = 0;

    FILE * arquivo = fopen("carros.txt", "rb+");
    FILE * alugados = fopen("carrosalugados.txt", "ab");
    if (arquivo == NULL) {
        printf("-----------------------------------------------------------\n");   
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    getchar();
    printf("-----------------------------------------------------------\n");
    printf("Alugar Carro\n"); 
    printf("-----------------------------------------------------------\n");
    printf("Digite a placa do carro que deseja alugar: \n");  
    fgets(aluguel.placa, 10, stdin);
    aluguel.placa[strcspn(aluguel.placa, "\n")] = '\0';
    printf("-----------------------------------------------------------\n");
    while (fread(&carro, sizeof(Carro), 1, arquivo) > 0)
    {
        if((strcmp(aluguel.placa, carro.placa) == 0) && (carro.alugado == 0)){
            encontrado = 1;
            printf("Nome do Locatario: ");
            fgets(aluguel.nome, 50, stdin);
            aluguel.nome[strcspn(aluguel.nome, "\n")] = '\0';

            printf("CNH do Locatario: ");
            fgets(aluguel.cnh, 20, stdin);
            aluguel.cnh[strcspn(aluguel.cnh, "\n")] = '\0';

            printf("Data de Aluguel (DD/MM/AAAA): ");
            fgets(aluguel.dataaluguel, 15, stdin);
            aluguel.dataaluguel[strcspn(aluguel.dataaluguel, "\n")] = '\0';

            printf("Data de Devolucao (DD/MM/AAAA): ");
            fgets(aluguel.datadevolucao, 15, stdin);
            aluguel.datadevolucao[strcspn(aluguel.datadevolucao, "\n")] = '\0';

            aluguel.ativo = 1;

            carroAlugado.id = carro.id;
            strcpy(carroAlugado.modelo, carro.modelo);
            strcpy(carroAlugado.placa, carro.placa);
            carroAlugado.ano = carro.ano;
            carroAlugado.preco = carro.preco;
            carroAlugado.alugado = 1;
            carroAlugado.ativo = 1;

            fseek(arquivo, -sizeof(Carro), SEEK_CUR);
            fwrite(&carroAlugado, sizeof(Carro), 1, arquivo);
            fwrite(&aluguel, sizeof(Aluguel), 1, alugados);
            fclose(arquivo);
            fclose(alugados);
            printf("-----------------------------------------------------------\n");   
            printf("Carro alugado com sucesso!\n");
            break;
        }
    }
    if(encontrado!= 1){
        fclose(arquivo);
        fclose(alugados);
        printf("\n-----------------------------------------------------------\n");   
        printf("Carro indisponivel ou inexistente.\n");
    }
}
void devolverCarro(){

    Aluguel aluguel, aluguelDevolve;
    Carro carro, carroDevolve;
    int encontrado1 = 0, encontrado2 = 0;

    FILE * arquivo = fopen("carros.txt", "rb+");
    FILE * alugados = fopen("carrosalugados.txt", "rb+");
    if (arquivo == NULL) {
        printf("-----------------------------------------------------------\n");   
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    if (alugados == NULL) {
        printf("-----------------------------------------------------------\n");   
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    getchar();
    printf("-----------------------------------------------------------\n");
    printf("Devolver Carro\n");
    printf("-----------------------------------------------------------\n");   
    printf("Digite a placa do carro que deseja devolver: \n");
    printf("-----------------------------------------------------------\n");   
    fgets(aluguel.placa, 10, stdin);
    aluguel.placa[strcspn(aluguel.placa, "\n")] = '\0';

    while (fread(&carro, sizeof(Carro), 1, arquivo) > 0)
    {
        if((strcmp(aluguel.placa, carro.placa) == 0) && (carro.alugado == 1)){
            encontrado1 = 1;

            strcpy(carro.placa, aluguel.placa);

            carroDevolve.id = carro.id;
            strcpy(carroDevolve.modelo, carro.modelo);
            strcpy(carroDevolve.placa, carro.placa);
            carroDevolve.ano = carro.ano;
            carroDevolve.preco = carro.preco;
            carroDevolve.alugado = 0;
            carroDevolve.ativo = 1;

            fseek(arquivo, -sizeof(Carro), SEEK_CUR);
            fwrite(&carroDevolve, sizeof(Carro), 1, arquivo);
            printf("\n-----------------------------------------------------------\n");   
            printf("Carro devolvido com sucesso!! \n");
            printf("-----------------------------------------------------------\n");
            break;
        }
    }
    if(encontrado1!= 1){
        printf("-----------------------------------------------------------\n");   
        printf("Carro já devolvido ou inexistente.\n"); 
    }

    while (fread(&aluguel, sizeof(Aluguel), 1, alugados) > 0)
    {
        if((strcmp(carro.placa, aluguel.placa) == 0) && (aluguel.ativo == 1)){
            encontrado2 = 1;

            strcpy(aluguelDevolve.placa, aluguel.placa);
            strcpy(aluguelDevolve.nome, aluguel.nome);
            strcpy(aluguelDevolve.cnh, aluguel.cnh);
            strcpy(aluguelDevolve.dataaluguel, aluguel.dataaluguel);
            strcpy(aluguelDevolve.datadevolucao, aluguel.datadevolucao);
            aluguelDevolve.ativo = 0;

            fseek(alugados, -sizeof(Aluguel), SEEK_CUR);
            fwrite(&aluguelDevolve, sizeof(Aluguel), 1, alugados);
            fclose(arquivo);
            fclose(alugados);
            break;
        }
    }
    if(encontrado2!= 1 && encontrado1!=0){
        fclose(arquivo);
        fclose(alugados);
        printf("\n-----------------------------------------------------------\n");   
        printf("Carro ja devolvido ou inexistente. \n");
        printf("-----------------------------------------------------------\n");   
    }
}
