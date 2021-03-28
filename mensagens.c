#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h" //inclui as funcoes assinadas


void menu(){
    printf("ACADEMICO: UELITON DE BRITO VIANA\n\n");
    printf("\n#########################################");
    printf("\n#   MENU - Lista Dinamica Encadeada     #");
    printf("\n#                                       #");
    printf("\n# Digite a opcao desejada               #");
    printf("\n#                                       #");
    printf("\n# 1  - Inserir Elemento no Final        #");
    printf("\n# 2  - Inserir Elemento no Inicio       #");
    printf("\n# 3  - Inserir Elemento no Ordenado     #");
    printf("\n# 4  - Remover Elemento do Final        #");
    printf("\n# 5  - Remover Elemento do Inicio       #");
    printf("\n# 6  - Remover Elemento                 #");
    printf("\n# 7  - Consultar Elemento pela Posicao  #");
    printf("\n# 8  - Consultar Elemento pela Matricula#");
    printf("\n# 9  - Exibir Lista                     #");
    printf("\n# 10 - Exibir o Tamanho da Lista        #");
    printf("\n# 11 - Sair                             #");
    printf("\n#########################################");
    printf("\n");
    printf("\nEscolha uma opcao para continuar >>: ");
}

int exibe_consulta(struct aluno *al){
    printf("-------------------------------\n");
    printf("Matricula: %d\n", al->matricula);
        printf("Nome: %s\n",  al->nome);
        printf("Notas: %.2f - %.2f - %.2f - %.2f\n",
               al->n1,
               al->n2,
               al->n3,
               al->n4);
        printf("Media: %.2f\n", al->media);
        printf("-------------------------------\n");
}

void msg_lista_vazia(){
    printf("\n\nLista Vazia\n\n");
    system("pause");
}

void msg_removida_do_inicio(){
    printf("\nElemento removido do inicio da lista com sucesso!\n\n");
    system("pause");
}

void msg_removida_do_final(){
    printf("\n\nElemento removido do final da lista com sucesso!\n\n");
    system("pause");
}

int msg_removida_a_matricula(int mat){
    printf("\n\nRemovida a matricula >> %d << da lista com sucesso!\n\n", mat);
    system("pause");
}

int msg_matricula_nao_encontrado(int mat){
    printf("\nElemento da matricula >> %d << nao encontrado\n\n", mat);
    system("pause");
}

void msg_falha_na_remocao(){
    printf("\n\nErro ao Remover elemento\n\n");
    system("pause");
}

int msg_posicao_nao_encontrado(int pos){
    printf("\n\nPosicao >> %d << nao encontrada, tente novamente\n\n", pos);
    system("pause");
}

void msg_matricula_existente(){
    printf("\n\nMatricula Existente, tente novamente\n\n");
    system("pause");
}

void msg_elemento_inserido_com_sucesso(){
    printf("\n\nElemento inserido com sucesso\n\n");
    system("pause");
}

void msg_digite_notas_validas(){
    printf("\n\nDigite Notas entre 0 e 10\n\n");
    system("pause");
}
