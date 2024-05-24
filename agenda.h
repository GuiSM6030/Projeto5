#ifndef AGENDA_H // Verifica se AGENDA_H não foi definido anteriormente
#define AGENDA_H // Define AGENDA_H para evitar múltiplas inclusões do mesmo arquivo de cabeçalho

#define MAX_CONTACTS 255 // Define o número máximo de contatos que podem ser armazenados na agenda

// Define um tipo enumerado para diferenciar os tipos de listas de contatos
typedef enum {PESSOAL, TRABALHO} TipoLista;

// Define uma estrutura para armazenar as informações de um contato
typedef struct {
    char nome[50]; // Armazena o nome do contato
    char sobrenome[50]; // Armazena o sobrenome do contato
    char email[100]; // Armazena o email do contato
    char telefone[15]; // Armazena o telefone do contato
    TipoLista tipo; // Armazena o tipo de lista (PESSOAL ou TRABALHO)
} Contato;

// Declaração das funções utilizadas na agenda

// Função para adicionar um contato à lista
void adicionarContato(Contato lista[], int *totalContatos);

// Função para listar todos os contatos
void listarContatos(Contato lista[], int totalContatos);

// Função para deletar um contato da lista
void deletarContato(Contato lista[], int *totalContatos);

// Função para salvar a lista de contatos em um arquivo
void salvarAgenda(Contato lista[], int totalContatos);

// Função para carregar a lista de contatos a partir de um arquivo
void carregarAgenda(Contato lista[], int *totalContatos);

// Função para validar o formato do email
int validarEmail(const char *email);

// Função para verificar se um telefone já existe na lista de contatos
int telefoneExiste(const Contato lista[], int totalContatos, const char *telefone);

// Função para alterar as informações de um contato existente
void alterarContato(Contato lista[], int totalContatos);

#endif // Final da verificação de inclusão múltipla do arquivo de cabeçalho
