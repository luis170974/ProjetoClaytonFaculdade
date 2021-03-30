#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

void menu();

// Apresenta o menu interativo principal.
void show_menu_principal() {
    printf("-------------------------------------\n");
    printf("Lista Dinâmica Encadeada\n");
    printf("-------------------------------------\n");
    printf("Escolha a função à ser executada:\n\n");
    printf("1 - Inserir elemento no Final\n");
    printf("2 - Inserir elemento no Início\n");
    printf("3 - Inserir elemento Ordenado\n");
    printf("4 - Remover elemento do Final\n");
    printf("5 - Remover elemento do Início\n");
    printf("6 - Remover elemento\n");
    printf("7 - Consultar elemento pela posição\n");
    printf("8 - Consultar elemento pela matrícula\n");
    printf("9 - Exibir lista\n");
    printf("10 - Exibir tamanho da lista\n");
    printf("11 - Sair\n");
    printf("-------------------------------------\n");
    printf("Opção: ");
}


void show_mensagem_saida(){
    printf("\nAté logo!!!\n");

void show_mensagem_default(){ 
    printf("\nOpção inválida! Parando execução...\n");
}
