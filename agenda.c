#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída em C para usar funções como printf() e scanf().
#include <stdlib.h> // Inclui a biblioteca padrão de funções utilitárias em C, como malloc() e free().
#include <string.h> // Inclui a biblioteca padrão de manipulação de strings em C, como strcpy() e strcmp().
#include "agenda.h" // Inclui o arquivo de cabeçalho agenda.h, que contém definições de estruturas e protótipos de funções.

// Função para verificar se um telefone já existe na lista de contatos
int telefoneExiste(const Contato lista[], int totalContatos, const char *telefone) {
    for (int i = 0; i < totalContatos; i++) {
        if (strcmp(lista[i].telefone, telefone) == 0) {
            return 1; // Telefone já existe
        }
    }
    return 0; // Telefone não existe
}

// Função para validar se o email contém "@" e ".com"
int validarEmail(const char *email) {
    const char *arroba = strchr(email, '@');
    const char *pontoCom = strstr(email, ".com");

    // Verifica se "@" está presente e ".com" está presente e vem após "@"
    if (arroba != NULL && pontoCom != NULL && pontoCom > arroba) {
        return 1; // Email válido
    }
    return 0; // Email inválido
}

// Função para adicionar um contato à lista de contatos
void adicionarContato(Contato lista[], int *totalContatos) {
    if (*totalContatos < MAX_CONTACTS) { // Verifica se há espaço para mais contatos
        Contato novoContato;
        printf("Digite o nome: ");
        scanf("%s", novoContato.nome);
        printf("Digite o sobrenome: ");
        scanf("%s", novoContato.sobrenome);

        // Solicita o email até ser um email válido
        do {
            printf("Digite o email: ");
            scanf("%s", novoContato.email);
            if (!validarEmail(novoContato.email)) {
                printf("Email inválido! O email deve conter '@' e '.com'.\n");
            }
        } while (!validarEmail(novoContato.email));

        // Solicita o telefone até ser um telefone único
        do {
            printf("Digite o telefone: ");
            scanf("%s", novoContato.telefone);
            if (telefoneExiste(lista, *totalContatos, novoContato.telefone)) {
                printf("Telefone já existe! Por favor, digite um telefone único.\n");
            }
        } while (telefoneExiste(lista, *totalContatos, novoContato.telefone));

        // Solicita o tipo de lista (Pessoal ou Trabalho)
        printf("Escolha o tipo de lista:\n");
        printf("1. Pessoal\n");
        printf("2. Trabalho\n");
        int escolha;
        scanf("%d", &escolha);
        if (escolha == 1)
            novoContato.tipo = PESSOAL;
        else if (escolha == 2)
            novoContato.tipo = TRABALHO;
        else {
            printf("Opção inválida! Usando lista pessoal por padrão.\n");
            novoContato.tipo = PESSOAL;
        }

        lista[*totalContatos] = novoContato; // Adiciona o novo contato à lista
        (*totalContatos)++; // Incrementa o contador de contatos
        printf("Contato adicionado com sucesso!\n");
    } else {
        printf("A lista de contatos está cheia!\n"); // Mensagem de erro se a lista estiver cheia
    }
}

// Função para listar todos os contatos
void listarContatos(Contato lista[], int totalContatos) {
    if (totalContatos == 0) {
        printf("A lista de contatos está vazia!\n");
    } else {
        printf("Lista de contatos:\n");
        for (int i = 0; i < totalContatos; i++) {
            printf("%d: %s %s, Email: %s, Telefone: %s, Lista: %s\n", 
                i+1, lista[i].nome, lista[i].sobrenome, lista[i].email, 
                lista[i].telefone, lista[i].tipo == PESSOAL ? "Pessoal" : "Trabalho");
        }
    }
}

// Função para listar contatos por tipo (Pessoal ou Trabalho)
void listarContatosPorTipo(Contato lista[], int totalContatos, TipoLista tipoLista) {
    int encontrados = 0;
    printf("Lista de contatos %s:\n", tipoLista == PESSOAL ? "pessoais" : "de trabalho");
    for (int i = 0; i < totalContatos; i++) {
        if (lista[i].tipo == tipoLista) {
            printf("%d: %s %s, Email: %s, Telefone: %s\n", 
                encontrados+1, lista[i].nome, lista[i].sobrenome, lista[i].email, lista[i].telefone);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("Nenhum contato %s encontrado.\n", tipoLista == PESSOAL ? "pessoal" : "de trabalho");
    }
}

// Função para alterar um contato existente
void alterarContato(Contato lista[], int totalContatos) {
    if (totalContatos == 0) {
        printf("A lista de contatos está vazia!\n");
        return;
    }

    char telefone[15];
    printf("Digite o número de telefone do contato que deseja alterar: ");
    scanf("%s", telefone);

    for (int i = 0; i < totalContatos; i++) {
        if (strcmp(lista[i].telefone, telefone) == 0) {
            printf("Digite o novo nome: ");
            scanf("%s", lista[i].nome);
            printf("Digite o novo sobrenome: ");
            scanf("%s", lista[i].sobrenome);

            // Solicita o novo email até ser válido
            do {
                printf("Digite o novo email: ");
                scanf("%s", lista[i].email);
                if (!validarEmail(lista[i].email)) {
                    printf("Email inválido! O email deve conter '@' e '.com'.\n");
                }
            } while (!validarEmail(lista[i].email));

            char novoTelefone[15];
            // Solicita o novo telefone até ser único
            do {
                printf("Digite o novo telefone: ");
                scanf("%s", novoTelefone);
                if (telefoneExiste(lista, totalContatos, novoTelefone) && strcmp(novoTelefone, telefone) != 0) {
                    printf("Telefone já existe! Por favor, digite um telefone único.\n");
                }
            } while (telefoneExiste(lista, totalContatos, novoTelefone) && strcmp(novoTelefone, telefone) != 0);

            strcpy(lista[i].telefone, novoTelefone); // Atualiza o telefone

            printf("Contato alterado com sucesso!\n");
            return;
        }
    }
    printf("Contato não encontrado!\n");
}

// Função para deletar um contato
void deletarContato(Contato lista[], int *totalContatos) {
    if (*totalContatos == 0) {
        printf("A lista de contatos está vazia!\n");
        return;
    }

    char telefone[15];
    printf("Digite o número de telefone do contato que deseja deletar: ");
    scanf("%s", telefone);

    for (int i = 0; i < *totalContatos; i++) {
        if (strcmp(lista[i].telefone, telefone) == 0) {
            for (int j = i; j < *totalContatos - 1; j++) {
                lista[j] = lista[j + 1]; // Desloca os contatos para preencher o espaço vazio
            }
            (*totalContatos)--; // Decrementa o contador de contatos
            printf("Contato deletado com sucesso!\n");
            return;
        }
    }
    printf("Contato não encontrado!\n");
}

// Função para carregar a agenda a partir de um arquivo
void carregarAgenda(Contato lista[], int *totalContatos) {
    FILE *arquivo; // Declara um ponteiro para um arquivo.
    arquivo = fopen("agenda.bin", "rb"); // Abre o arquivo "agenda.bin" para leitura binária.
    if (arquivo == NULL) { // Verifica se houve erro ao abrir o arquivo.
        printf("Erro ao abrir o arquivo!\n"); // Exibe uma mensagem de erro caso não seja possível abrir o arquivo.
        return; // Retorna da função em caso de erro.
    }
    *totalContatos = fread(lista, sizeof(Contato), MAX_CONTACTS, arquivo); // Lê os contatos do arquivo para a lista de contatos.
    fclose(arquivo); // Fecha o arquivo após a leitura.
    printf("Sua agenda foi carregada com sucesso!\n"); // Exibe uma mensagem indicando que a agenda foi carregada com sucesso.
}

// Função para salvar a agenda em um arquivo
void salvarAgenda(Contato lista[], int totalContatos) {
    FILE *arquivo; // Declara um ponteiro para um arquivo.
    arquivo = fopen("agenda.bin", "wb"); // Abre o arquivo "agenda.bin" para escrita binária.
    if (arquivo == NULL) { // Verifica se houve erro ao abrir o arquivo.
        printf("Erro ao abrir o arquivo!\n"); // Exibe uma mensagem de erro caso não seja possível abrir o arquivo.
        return; // Retorna da função em caso de erro.
    }
    fwrite(lista, sizeof(Contato), totalContatos, arquivo); // Escreve os contatos da lista no arquivo.
    fclose(arquivo); // Fecha o arquivo após a escrita.
    printf("Agenda salva com sucesso!\n"); // Exibe uma mensagem indicando que a agenda foi salva com sucesso.
}
