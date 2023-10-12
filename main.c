#include <stdio.h>
#include <stdlib.h>
#include "LISTA.h"
#include "FILA.h"
#include "TAREFA.h"

typedef struct TAREFA Tarefa;

void menu(int *escolha,lista **listaTarefas,lista **listaPendentes,lista **listaConcluidas){
    tarefa *taf;
    int x;
    system("cls");
    printf(" 1- Adicionar uma nova tarefa\n");
    printf(" 2- Modificar tarefa\n");
    printf(" 3- Concluir tarefa\n");
    printf(" 4- Atualizar status de uma tarefa\n");
    printf(" 5- Visualizar tarefas pendentes\n");
    printf(" 6- Visualizar tarefas concluidas\n");
    printf(" 7- Visualizar tarefas com atraso e sem atraso\n");
    printf(" 8- Sair do programa\n\n -> ");
    scanf("%d",escolha);

    switch(*escolha){
        case 1:
            taf=AdicionaValoresTarefa();

            // x recebe valor da função
            x=verificaTarefaAtrasada(taf);
            *listaTarefas=insereLista(*listaTarefas,taf);

            printf("\n");
            system("pause");

            break;
        case 2:
            modificaTarefa(*listaTarefas,listaPendentes,0);
            printf("\n");
            system("pause");
            break;
        case 3:
            concluirTarefa(listaTarefas,listaConcluidas);
            ordenaLista(listaConcluidas);
            printf("\n");
            system("pause");
            break;
        case 4:
            modificaTarefa(*listaTarefas,listaPendentes,1);
            ordenaLista(listaPendentes);
            printf("\n");
            system("pause");
            break;
        case 5:
            imprimeListaeTarefas(*listaPendentes);
            printf("\n");
            system("pause");

            break;
        case 6:
            imprimeListaeTarefas(*listaConcluidas);
            printf("\n");
            system("pause");
            break;
        case 7:
            imprimeComSemAtraso(*listaConcluidas);
            ordenaLista(listaConcluidas);
            printf("\n");
            system("pause");

            break;
        case 8:
            break;

    }
    if(*escolha<1 || *escolha>8){
        printf("\nOpcao invalida\n");
        system("pause");
    }

}
int main()
{
    lista* ListaTarefas=CriaLista(), *listaPendentes=CriaLista(),*listaConcluidas=CriaLista();

    int escolha;

    do{
        menu(&escolha,&ListaTarefas,&listaPendentes,&listaConcluidas);



    }while(escolha!=8);
    system("cls");
    printf("Feito por :\n Mauricio\n Renan\n Tiago");


    return 0;
}
