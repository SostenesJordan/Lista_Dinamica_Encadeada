//Arquivo ListaDinEncad.c
#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h" //inclui as funcoes assinadas

//Definindo a estrutura da lista
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem; //ponteiro criado para facilitar em algumas operacoes de buscas e alteracoes


Lista* cria_lista(){
    Lista* li = (Lista*)malloc(sizeof(Lista)); //alocando memoria
    if(li != NULL)
        *li = NULL; //inicio apontando para null
    return li;
}


void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox; //inicio da lista agora recebe o prox elemento
            free(no); //o primeiro elemento eh liberado da lista. Este processo acontece ate a lista for vazia
        }
        free(li); //liberando a "cabeca" da lista, ou seja, o ponteiro inicial.
    }
}


int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li; //node auxiliar que recebe o primeiro elemento da lista
    while(no != NULL){
        cont++;
        no = no->prox; //percorre a lista elemento por elemento ate no ser null e vai incrementando a variavel cont em cada elemento valido
    }
    return cont;
}


int lista_vazia(Lista* li){
    if(li == NULL || *li == NULL)
        return 1;

    return 0;
}


float calcular_media(struct aluno al){
    float media_notas;
    media_notas = (al.n1 + al.n2 + al.n3 + al.n4)/4;
    return media_notas;
}


int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL) //verifica se eh valida
        return 0;
    Elem* no; //cria novo elemento para a lista
    no = (Elem*) malloc(sizeof(Elem)); //reserva espaco na memoria para a lista
    if(no == NULL)
        return 0;
    no->dados = al;//copiando os dados a ser inseridos para a estrutura al
    no->prox = (*li);//dizendo que o proximo elemento eh a propria lista
    *li = no; //inicio da lista passa a ser no novo node inserido
    return 1;
}


int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)//verifica se eh valida
        return 0;
    Elem *no; 
    no = (Elem*) malloc(sizeof(Elem));//reserva espaco na memoria para a lista
    if(no == NULL)
        return 0;
    no->dados = al;//copiando os dados a ser inseridos para a estrutura al
    no->prox = NULL;//proximo elemento ao nodde sera null pq sera onde o dado vai ser inserido
    if((*li) == NULL){//se lista for vazia, insere no início
        *li = no;
    }else{ 
        Elem *aux;//criando ponteiro auxiliar
        aux = *li;//copiando informacao da "cabeca" da lista para o auxiliar percorrer a lista com seguranca
        while(aux->prox != NULL){//enquanto o proximo ponteiro nao for null, entao auxiliar recebe proximo elemento
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}


int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));//reserva espaco na memoria para a lista
    if(no == NULL)
        return 0;
    no->dados = al;//copiando os dados para a estrutura al
    if((*li) == NULL){//lista vazia: insere no início
        no->prox = NULL;
        *li = no;
        return 1;
    } else { 
        Elem *ant, *atual = *li; //criando dois ponteiros auxiliares, um ATUAL apontando para o inicio da lista e outro ANTerior
        while(atual != NULL && atual->dados.matricula < al.matricula){ //enquanto valor for diferente de null E menor do que o elemento que deseja inserir
            ant = atual;//anterior passa a valer atual
            atual = atual->prox; //atual passa a valer proximo valor da lista
        }
        if(atual == *li){//insere no início
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}


void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        exibe_consulta(no); //funcao encontrada em mensagens.c
        no = no->prox;
    }
}


int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    *li = no->prox;//ponteiro do inicio da lista passsa a valer o proximo valor do node
    free(no);//liberando o node
    return 1;
}


int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li)) {
        *li = no->prox;
    } else {
        ant->prox = no->prox;
    }
    free(no);//liberando o node
    return 1;
}


int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elem *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL){ //não encontrado
        msg_matricula_nao_encontrado(mat); //funcao encontrada em mensagens.c
        return 0;
    }

    if(no == *li){ 
        *li = no->prox;
        msg_removida_a_matricula(mat); //funcao encontrada em mensagens.c
    } else {
        ant->prox = no->prox;
        msg_removida_a_matricula(mat); //funcao encontrada em mensagens.c
    }
    free(no);
    return 1;
}


int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
    {
        msg_posicao_nao_encontrado(pos); //funcao encontrada em mensagens.c
        return 0;
    }
    else{
        *al = no->dados;
        exibe_consulta(al); //funcao encontrada em mensagens.c
        return 1;
    }
}


int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL)
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL){
        msg_matricula_nao_encontrado(mat); //funcao encontrada em mensagens.c
        return 0;
    }
    else{
        *al = no->dados;
        exibe_consulta(al); //funcao encontrada em mensagens.c
        return 1;
    }
}


//Verifica se ja existe
int verificar_matricula(Lista* li, struct aluno al){
    Elem *no = *li;
    int i = 1;
    while(no != NULL){
        if(no->dados.matricula  == al.matricula)
        {
            return 1;
        } else {
            no = no->prox;
            i++;
        }
    }
    return 0;
}


float verificar_notas(struct aluno al){
    if(al.n1 < 0 || al.n1 > 10){
        return 1;
    } else if (al.n2 < 0 || al.n2 > 10){
        return 1;
    } else if (al.n3 < 0 || al.n3 > 10){
        return 1;
    } else if (al.n4 < 0 || al.n4 > 10){
        return 1;
    }
    return 0;
}
