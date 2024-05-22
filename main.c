#include "agenda.h"
#include <stdio.h>

int main() {
    Contato listaContatos[MAX_CONTACTS];
    int totalContatos = 0;
    int opcao;

    carregarAgenda(listaContatos, &totalContatos);
    do {
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
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(listaContatos, &totalContatos);
                salvarAgenda(listaContatos, totalContatos); // Salvar após adicionar contato
                break;
            case 2:
                listarContatosPorTipo(listaContatos, totalContatos, PESSOAL);
                break;
            case 3:
                listarContatosPorTipo(listaContatos, totalContatos, TRABALHO);
                break;
            case 4:
                deletarContato(listaContatos, &totalContatos);
                salvarAgenda(listaContatos, totalContatos); // Salvar após deletar contato
                break;
            case 5:
                salvarAgenda(listaContatos, totalContatos);
                break;
            case 6:
                carregarAgenda(listaContatos, &totalContatos);
                break;
            case 7:
                alterarContato(listaContatos, totalContatos);
                salvarAgenda(listaContatos, totalContatos);
                break;
            case 8:
                salvarAgenda(listaContatos, totalContatos);
                printf("Você está saindo :(\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 8);

    return 0;
}
