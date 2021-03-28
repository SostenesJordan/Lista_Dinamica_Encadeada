//Arquivo ListaDinEncad.h
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3,n4,media;
};
typedef struct elemento* Lista; // elemento eh definido em ListaDinEncad.c

//Funcoes do arquivo ListaDinEncad.c
Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);

int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);

void imprime_lista(Lista* li);

int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int remove_lista(Lista* li, int mat);

int consulta_lista_pos(Lista* li, int pos, struct aluno *al);
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);
int verificar_matricula(Lista* li, struct aluno al);

float calcular_media(struct aluno al);
float verificar_notas(struct aluno al);


//funcoes do arquivo mensagens.c
void menu();
int exibe_consulta(struct aluno *al);
void msg_lista_vazia();
void msg_removida_do_inicio();
void msg_removida_do_final();
int msg_removida_a_matricula(int mat);
int msg_matricula_nao_encontrado(int mat);
int msg_posicao_nao_encontrado(int pos);
void msg_matricula_existente();
void msg_elemento_inserido_com_sucesso();
void msg_digite_notas_validas();

