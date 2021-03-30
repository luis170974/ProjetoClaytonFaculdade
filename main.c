#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct lista {
    int numero_conta;
    char nome_pessoa[40];
    float saldo_pessoa;
    struct lista* prox;
} Lista;

Lista* inserir_pessoa(Lista* primeiro);
void listar_pessoa(Lista* primeiro);
Lista* excluir_pessoa(Lista* primeiro);
void alterar_pessoa(Lista* primeiro);
void limpa_linha(void);

int main() {


    Lista *primeiro= NULL;
    char opcao;

    while(opcao!='5')
    {

//Menu
        printf("\t\t\tBANCO DA CAIXA , VEM PRA CAIXA VOCE TAMBEM        \n");
        printf("        1 - Novo                         \n");
        printf("        2 - Listar                       \n");
        printf("        3 - Excluir cadastro             \n");
        printf("        4 - Alterar cadastro             \n");
        printf("        5 - Sair                         \n");
        printf("\n\n\n\n");
//Lendo menu
        opcao = getch();

//Menu de opções
        switch(opcao)
        {
        case '1':

//Inserindo a Conta.
            fflush(stdin);
            system("cls");
            printf("\t\t\t          NOVO CADASTRO     \n");
            primeiro= inserir_pessoa(primeiro);
            getch();
            system("cls");
            break;
        case '2':

//Listando os Cadastros.
            system ("cls");
            printf("\t\t\t     CONTAS CADASTRADAS     \n");
            listar_pessoa(primeiro);
            getch();
            system("cls");
            break;
        case '3':


            system ("cls");
            printf("\t\t\t       EXCLUIR CADASTROS    \n");
            primeiro= excluir_pessoa(primeiro);
            getch();
            system("cls");
            break;

        case '4':


            system ("cls");
            printf("\t\t\t       ALTERAR CADASTRADOS   \n");
            printf("\t\t\t      |\n");

            alterar_pessoa(primeiro);
            getch();
            system("cls");
            break;

        case '5':


            opcao='5';
            break;
        default:

            system("cls");
            break;
        }
    }
}

void limpa_linha() {
    scanf("%*[^\n]");
    scanf("%*c");
}

Lista* inserir_pessoa(Lista* primeiro) {

    Lista Pessoa;
    Lista *atual = primeiro;
    char identificador = 'F';

    printf("  Numero da Conta: ");
    scanf("%d", &Pessoa.numero_conta);
    limpa_linha();
    printf ("\n");
    printf("  Nome: ");
    fgets(Pessoa.nome_pessoa, 40, stdin);
    printf ("\n");
    printf("  Saldo: ");
    scanf("%f", &Pessoa.saldo_pessoa);
    limpa_linha();

    printf ("\n");

    for (atual = primeiro; atual != NULL; atual = atual->prox) {
        if (atual->numero_conta == Pessoa.numero_conta) {
            identificador = 'V';
            break;
        }
    }

    if ( identificador != 'V' && (strlen(Pessoa.nome_pessoa) != 1)) {


        Lista* NovaPessoa = malloc (sizeof(Lista));
        strcpy(NovaPessoa->nome_pessoa, Pessoa.nome_pessoa);
        NovaPessoa->saldo_pessoa = Pessoa.saldo_pessoa;
        NovaPessoa->numero_conta = Pessoa.numero_conta;
        NovaPessoa->prox = primeiro;
        printf("  Cadastro feito com sucesso <3 <3.");
        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return NovaPessoa;
    } else {
        printf("  Cadastro invalido!");
        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return primeiro;
    }
}


void listar_pessoa(Lista* primeiro) {

    Lista* atual;


    for (atual = primeiro ; atual != NULL; atual = atual->prox) {
        printf("\n  Conta: ");
        printf("%d", atual->numero_conta);
        printf("\n  Nome: ");
        printf("%s", atual->nome_pessoa);
        printf("  Saldo: ");
        printf("%.2f", atual->saldo_pessoa);
        printf("\n\n");
    }
    if ( primeiro == NULL)
        printf("  Nenhum Cliente Cadastrado.");
    printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}

Lista* excluir_pessoa(Lista* primeiro) {

    Lista *anterior = NULL;
    Lista *atual = primeiro;
    int numero_conta = 0;


    printf("  Digite o codigo do cliente para exclusao: ");
    scanf("%d",&numero_conta);
    limpa_linha();


    while( atual != NULL && atual->numero_conta != numero_conta) {
        anterior = atual;
        atual = atual->prox;
    }


    if (atual == NULL) {
        printf("\n  Cliente nao encontrado.");
        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return primeiro;
    }


    if (anterior == NULL) {
        printf("\n  Conteudo excluido com sucesso.");
        primeiro= atual->prox;

    } else {
        printf("\n  Conteudo excluido com sucesso.");
        anterior->prox= atual->prox;
    }


    free(atual);
    printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
    return primeiro;
}


void alterar_pessoa(Lista *primeiro) {

    int numero_conta2;
    char nome_pessoa2[40];
    float saldo_sub2;
    Lista *atual = primeiro;
    int encontrado;


    printf("  Digite o codigo do cliente para a alteracao: ");
    scanf("%d", &numero_conta2);
    limpa_linha();

    encontrado = 0;

    for (atual = primeiro; atual != NULL; atual = atual->prox) {
        if (atual->numero_conta == numero_conta2) {
            encontrado = 1;
            printf("\n  Novo nome: ");
            fgets(nome_pessoa2, 40, stdin);
            strcpy(atual->nome_pessoa, nome_pessoa2);
            printf("\n  Novo Saldo: ");
            scanf("%f", &saldo_sub2);
            limpa_linha();
            printf ("\n");
            atual->saldo_pessoa = saldo_sub2;
            printf("Dados alterados com sucesso!");
        }
    }
    if (!encontrado) {
        printf("\nCliente nao encontrado!");
    }

    printf("\n\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}
