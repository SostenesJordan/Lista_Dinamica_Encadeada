#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h" //inclui as funcoes assinadas

int main()
{
    Lista* li = cria_lista(); //Declarando um ponteiro para um ponteiro
    struct aluno dados_aluno;
    int matricula_aluno, posicao;
    int opcao;
    int i = 1;
    while(i == 1){
        system("cls");
        menu();
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Digite a Matricula: ");
                scanf("%d", &dados_aluno.matricula);
                printf("Digite o nome do aluno: ");
                fseek(stdin,0,SEEK_END);
                scanf("%[^\n]", dados_aluno.nome);
                printf("Digite a Nota 01: ");
                scanf("%f", &dados_aluno.n1);
                printf("Digite a Nota 02: ");
                scanf("%f", &dados_aluno.n2);
                printf("Digite a Nota 03: ");
                scanf("%f", &dados_aluno.n3);
                printf("Digite a Nota 04: ");
                scanf("%f", &dados_aluno.n4);
                dados_aluno.media = calcular_media(dados_aluno);
                if(verificar_matricula(li, dados_aluno)){
                    msg_matricula_existente();
                } else if(verificar_notas(dados_aluno)) {
                    msg_digite_notas_validas();
                } else if (insere_lista_final(li, dados_aluno)){
                    msg_elemento_inserido_com_sucesso();
                }
                break;
            case 2:
                printf("Digite a Matricula: ");
                scanf("%d", &dados_aluno.matricula);
                printf("Digite o nome do aluno: ");
                fseek(stdin,0,SEEK_END);
                scanf("%[^\n]", dados_aluno.nome);
                printf("Digite a Nota 01: ");
                scanf("%f", &dados_aluno.n1);
                printf("Digite a Nota 02: ");
                scanf("%f", &dados_aluno.n2);
                printf("Digite a Nota 03: ");
                scanf("%f", &dados_aluno.n3);
                printf("Digite a Nota 04: ");
                scanf("%f", &dados_aluno.n4);
                dados_aluno.media = calcular_media(dados_aluno);
                if(verificar_matricula(li, dados_aluno)){
                    msg_matricula_existente();
                } else if(verificar_notas(dados_aluno)) {
                    msg_digite_notas_validas();
                } else if(insere_lista_inicio(li, dados_aluno)) {
                    msg_elemento_inserido_com_sucesso();
                }
                break;
            case 3:
                printf("Digite a Matricula: ");
                scanf("%d", &dados_aluno.matricula);
                printf("Digite o nome do aluno: ");
                fseek(stdin,0,SEEK_END);
                scanf("%[^\n]", dados_aluno.nome);
                printf("Digite a Nota 01: ");
                scanf("%f", &dados_aluno.n1);
                printf("Digite a Nota 02: ");
                scanf("%f", &dados_aluno.n2);
                printf("Digite a Nota 03: ");
                scanf("%f", &dados_aluno.n3);
                printf("Digite a Nota 04: ");
                scanf("%f", &dados_aluno.n4);
                dados_aluno.media = calcular_media(dados_aluno);
                if(verificar_matricula(li, dados_aluno)){
                    msg_matricula_existente();
                } else if(verificar_notas(dados_aluno)) {
                    msg_digite_notas_validas();
                } else if(insere_lista_ordenada(li, dados_aluno)) {
                    msg_elemento_inserido_com_sucesso();
                }
                break;
            case 4:
				if(lista_vazia(li))
                {
                    msg_lista_vazia();
                    break;
                } else if(remove_lista_final(li)){
                    msg_removida_do_final();
                    break;
                } else {
                    msg_falha_na_remocao();
                    break;
                }
            case 5:
				if(lista_vazia(li))
                {
                    msg_lista_vazia();
                    break;
                } else if(remove_lista_inicio(li)){
                    msg_removida_do_inicio();
                    break;
                } else {
                    msg_falha_na_remocao();
                    break;
                }
            case 6:
				if(lista_vazia(li))
                {
                    msg_lista_vazia();
                    break;
                } else {
                    printf("\nDigite a matricula a ser removida: ");
                    scanf("%d", &matricula_aluno);
                    remove_lista(li, matricula_aluno);
                    break;
                }
            case 7:
				if(lista_vazia(li))
                {
                    msg_lista_vazia();
                    break;
                } else {
                    printf("\nDigite a posicao a ser buscada: ");
                    scanf("%d", &posicao);
                    consulta_lista_pos(li, posicao, &dados_aluno);
                    system("pause");
                    break;
                }
            case 8:
				if(lista_vazia(li))
                {
                    msg_lista_vazia();
                    break;
                } else {
                    printf("\nDigite a matricula a ser buscada: ");
                    scanf("%d", &matricula_aluno);
                    consulta_lista_mat(li, matricula_aluno, &dados_aluno);
                    system("pause");
                    break;
                }
            case 9:
				if(lista_vazia(li))
                {
                    msg_lista_vazia();
                    break;
                } else {
                    imprime_lista(li);
                    system("pause");
                    break;
                }
            case 10:
				if(lista_vazia(li))
                {
                    msg_lista_vazia();
                    break;
                } else {
                    printf("O tamanho da Lista e: %d\n", tamanho_lista(li));
                    system("pause");
                    break;
                }
            case 11:
                printf("\n\t\tSaindo...\n\n");
                i = 0;
                break;
            default:
                printf("\n\nOpcao Invalida, tente novamente!\n\n");
                system("pause");
                break;
        }
    }
    libera_lista(li);
    system("pause");
    printf("\n\n\n\n");
}
