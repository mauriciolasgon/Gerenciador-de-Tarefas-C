#include <stdio.h>
#include <stdlib.h>
#include "LISTA.h"
#include "FILA.h"
#include "TAREFA.h"


typedef struct TAREFA Tarefa;

void menu(int *escolha,lista **listaPendentes){
    int codigo;
    Tarefa *tarefa=CriaTarefa();
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
            *listaPendentes=insereLista(*listaPendentes,AdicionaValoresTarefa());
            break;
        case 2:
            if(!VaziaLista(*listaPendentes)){
                imprimeLista(*listaPendentes);
                printf(" \nDigite o codigo da tarefa que deseja modificar:  \n");
                scanf("%d",&codigo);
                tarefa=RetiraTarefaLista(*listaPendentes,codigo);
                modificaTarefa(tarefa);
            }
            else{
                printf(" Nao existem tarefas");
            }
            break;
        case 3:
            // conluirTarefa(tarefa);
            break;
        case 4:
            // atualizaStatus(tarefa);
            break;
        case 5:
            // imprimeTarefasPendentes();
            break;
        case 6:
            // imprimeTarefasConcluidas();
            break;
        case 7:
            // imprimeComSemAtraso();
            break;
        case 8:
            break;


    }

}
int main()
{
    lista* ListaTarefas=CriaLista(), *listaPendentes=CriaLista();
    Fila * FilaPrioridade1=CriaFila(),*FilaPrioridade2=CriaFila(),*FilaPrioridade3=CriaFila(),*FilaPrioridades=CriaFila();
    int escolha;

    do{
        menu(&escolha,&listaPendentes);
        system("cls");


    }while(escolha!=8);


    return 0;
}
