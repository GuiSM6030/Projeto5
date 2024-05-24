#include "agenda.h"
#include <stdio.h>

int main() {
    Contato listaContatos[MAX_CONTACTS]; // Declaração de um array para armazenar os contatos
    int totalContatos = 0; // Variável para rastrear o número total de contatos
    int opcao; // Variável para armazenar a opção escolhida pelo usuário

    carregarAgenda(listaContatos, &totalContatos); // Carrega os contatos da agenda a partir de um arquivo

    // Loop principal do menu
    do {
        // Exibe o menu de opções para o usuário
        printf("\nMenu:\n");
        printf("1. Adicionar contato\n");
        printf("2. Listar contatos pessoais\n");
        printf("3. Listar contatos de trabalho\n");
        printf("4. Deletar contato\n");
        printf("5. Salvar agenda\n");
        printf("6. Carregar agenda\n");
        printf("7. Alterar contato\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário

        // Executa ações com base na opção escolhida pelo usuário
        switch (opcao) {
            case 1:
                adicionarContato(listaContatos, &totalContatos); // Adiciona um novo contato
                salvarAgenda(listaContatos, totalContatos); // Salva a agenda após adicionar o contato
                break;
            case 2:
                listarContatosPorTipo(listaContatos, totalContatos, PESSOAL); // Lista contatos pessoais
                break;
            case 3:
                listarContatosPorTipo(listaContatos, totalContatos, TRABALHO); // Lista contatos de trabalho
                break;
            case 4:
                deletarContato(listaContatos, &totalContatos); // Deleta um contato
                salvarAgenda(listaContatos, totalContatos); // Salva a agenda após deletar o contato
                break;
            case 5:
                salvarAgenda(listaContatos, totalContatos); // Salva a agenda
                break;
            case 6:
                carregarAgenda(listaContatos, &totalContatos); // Carrega a agenda a partir de um arquivo
                break;
            case 7:
                alterarContato(listaContatos, totalContatos); // Altera um contato existente
                salvarAgenda(listaContatos, totalContatos); // Salva a agenda após alterar o contato
                break;
            case 8:
                salvarAgenda(listaContatos, totalContatos); // Salva a agenda antes de sair
                printf("Você está saindo :(\n"); // Mensagem de saída
                break;
            default:
                printf("Opção inválida!\n"); // Mensagem de erro para opção inválida
        }
    } while (opcao != 8); // Continua o loop até que a opção 8 (sair) seja escolhida

    return 0; // Retorna 0 para indicar que o programa terminou corretamente
}

