#include <stdio.h>
#include <stdlib.h>
#include "LISTA.h"
#include "FILA.h"
#include "TAREFA.h"

typedef struct TAREFA Tarefa;

void menu(int *escolha,lista **listaTarefas,lista **listaPendentes,lista **listaConcluidas){

    printf(" 1- Adicionar uma nova tarefa\n");
    printf(" 2- Modificar tarefa\n");
    printf(" 3- Concluir tarefa\n");
    printf(" 4- Atualizar status de uma tarefa\n");
    printf(" 5- Visualizar tarefas pendentes\n");
    printf(" 6- Visualizar tarefas concluidas\n");
    printf(" 7- Visualizar tarefas com atraso e sem atraso\n");
    printf(" 8- Sair do programa\n\n -> ");
    scanf("%d",escolha);
    system("cls");
    switch(*escolha){
        case 1:

            *listaTarefas=insereLista(*listaTarefas,AdicionaValoresTarefa());

            break;
        case 2:

            modificaTarefa(*listaTarefas,listaPendentes,0);
            break;
        case 3:
            concluirTarefa(listaTarefas,listaConcluidas);
            printf("\n");
            break;
        case 4:
            modificaTarefa(*listaTarefas,listaPendentes,1);
            break;
        case 5:

            imprimeLista(*listaPendentes);

            printf("\n");

            break;
        case 6:
            imprimeLista(*listaConcluidas);
            printf("\n");
            break;
        case 7:
            imprimeComSemAtraso(*listaTarefas);
            printf("\n");

            break;
        case 8:
            break;
        case 9:
            ordenaLista(listaTarefas);
            printf("\n");

            imprimeLista(*listaTarefas);
            printf("\n");
            break;


    }

}
int main()
{
    lista* ListaTarefas=CriaLista(), *listaPendentes=CriaLista(),*listaConcluidas=CriaLista();

    int escolha;

    do{
        menu(&escolha,&ListaTarefas,&listaPendentes,&listaConcluidas);



    }while(escolha!=8);


    return 0;
}
