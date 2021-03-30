#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

struct lista{
    int qtd;
    struct aluno dados[MAX];
};

Lista* cria_lista(){
    Lista *li;
    li = (Lista*)malloc(sizeof(struct lista));
    if(li != NULL )
        li->qtd = 0;
    return li;
}

void libera_lista(Lista* li){
    free(li);
}

//Implementando funcao que retorna o tamanho da lista
int tamanho_lista(Lista* li){
    if(li == NULL)
        return -1;
    else
        return li->qtd;
}

int lista_cheia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == MAX);
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}

//Funcao para Inserir no Final
int insere_lista_final(Lista* li, struct  aluno al){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX){ //Lista Cheia
        printf("\n\nLista Cheia\n\n");
        return 0;
    }
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

//Funcao para inserir no Inicio
int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;

    if(li->qtd == MAX){ //lista cheia
        printf("\n\nLista Cheia\n\n");
        return 0;
    }

    int i;
    for(i = li->qtd-1; i >= 0; i--)
        li->dados[i+1] = li->dados[i];

    li->dados[0] = al;
    li->qtd++;
    return 1;
}

//Funcao para inserir de forma Ordenada
int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;

    if(li->qtd == MAX){ //lista cheia
        printf("\n\nLista Cheia\n\n");
        return 0;
    }

    int k, i = 0;

    while(i < li->qtd && li->dados[i].matricula < al.matricula)
        i++;

    for(k = li->qtd-1; k >= i; k--)
        li->dados[k+1] = li->dados[k];

    li->dados[i] = al;
    li->qtd++;
    return 1;
}

//Funcao para Exibir a Lista
void imprime_lista(Lista* li){
    if(li == NULL)
        return 0;

    int i;
    printf("------------------------------\n");
    for(i = 0; i < li->qtd; i++){
        printf("Matricula: %d\n", li->dados[i].matricula);
        printf("Nome: %s\n", li->dados[i].nome);
        printf("Notas: %.2f - %.2f - %.2f\n",
               li->dados[i].n1,
               li->dados[i].n2,
               li->dados[i].n3);
        printf("------------------------------\n");
    }
}

//Funcao que remove elemento do final
int remover_lista_final(Lista* li){
    if(li == NULL || li->qtd == 0)
        return 0;

    li->qtd--;
    return 1;
}

//Funcao que remove elemento do inicio
int remover_lista_inicio(Lista* li){
    if(li == NULL || li->qtd == 0)
        return 0;

    int k = 0;
    for(k = 0; k < li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];

    li->qtd--;
    return 1;
}

//Funcao que remove elemento do meio
int remover_lista(Lista* li, int mat){
    if(li == NULL || li->qtd == 0)
        return 0;

    int k, i = 0;
    while(i < li->qtd && li->dados[i].matricula != mat)
        i++;

    if(i == li->qtd){ //Elemento nao encontrado
        printf("\n\nMatricula nao encontrada\n\n");
        system("pause");
        return 0;
    }

    for(k = i; k < li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];

    li->qtd--;
    printf("\nRemovida a matricula >> %d << da Lista\n", mat);
    return 1;
}

//Funcao para consultar pela posição
int consultar_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0 || pos > li->qtd)
        return 0;

    *al = li->dados[pos-1];
    printf("--------------------------------\n");
    printf("Matricula: %d\n", li->dados[pos-1].matricula);
    printf("Nome: %s\n", li->dados[pos-1].nome);
    printf("Notas: %.2f - %.2f - %.2f\n",
           li->dados[pos-1].n1,
           li->dados[pos-1].n2,
           li->dados[pos-1].n3);
    printf("--------------------------------\n");
    return 1;
}


//Funcao para consultar pela matricula
int consultar_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL || li->qtd == 0)
        return 0;

    int i = 0;
    while(i < li->qtd && li->dados[i].matricula != mat)
        i++;

    if(i == li->qtd){ //Elemento nao encontrado
        printf("\n\nMatricula nao encontrada\n\n");
        system("pause");
        return 0;
    }

    *al = li->dados[i];
    printf("--------------------------------\n");
    printf("Matricula: %d\n", li->dados[i].matricula);
    printf("Nome: %s\n", li->dados[i].nome);
    printf("Notas: %.2f - %.2f - %.2f\n",
           li->dados[i].n1,
           li->dados[i].n2,
           li->dados[i].n3);
    printf("--------------------------------\n");
    return 1;
}


