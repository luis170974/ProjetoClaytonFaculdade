#define MAX 10

struct aluno{
    int matricula;
    char nome [30];
    float n1, n2, n3;
};

typedef struct lista* Lista;

//Estrutura inicial da lista
Lista* cria_lista();
void libera_lista();

//Informacoes da Lista
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);

//Insercoes de elementos
int insere_lista_final(Lista* li, struct  aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);

//Exibir dados
void imprime_lista(Lista* li);

//Remocões de elementos
int remover_lista_final(Lista* li);
int remover_lista_inicio(Lista* li);
int remover_lista(Lista* li, int mat);

//Consultas de Elementos
int consultar_lista_pos(Lista* li, int pos, struct aluno *al);
int consultar_lista_mat(Lista* li, int mat, struct aluno *al);

//Mensagens
void menu();
void show_menu_principal();
void show_menu_principal();
void show_mensagem_saida();
void show_mensagem_default();
