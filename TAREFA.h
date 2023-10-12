#ifndef TAREFA_H_INCLUDED
#define TAREFA_H_INCLUDED
#include "LISTA.h"
#include <time.h>
typedef struct Lista lista;
typedef struct Data{
    int Dia;
    int Mes;
    int Ano;
}data;


typedef struct TAREFA{
     int Codigo;
     char Nome[30];
     char Projeto[30];
     data *Inicio;
     data *Termino;
     int Status;
     int Prioridade;
     struct TAREFA *Prox;

}tarefa;

data* CriaData(){
    return NULL;
}
tarefa * CriaTarefa(){
    return NULL;
}
void ImprimeTarefa(tarefa* recebida){
    printf("\n 1- Codigo : %d ",recebida->Codigo);
    printf("\n 2- Nome : %s ",recebida->Nome);
    printf("\n 3- Projeto a qual faz parte : %s ",recebida->Projeto);
    printf("\n 4- Data de inicio : %d/%d/%d ",recebida->Inicio->Dia,recebida->Inicio->Mes,recebida->Inicio->Ano);
    printf("\n 5- Data de termino: %d/%d/%d ",recebida->Termino->Dia,recebida->Termino->Mes,recebida->Termino->Ano);
    printf("\n 6- Status: %d ",recebida->Status);
    printf("\n 7- Prioridade: %d ",recebida->Prioridade);
}



tarefa* AdicionaValoresTarefa(){
    tarefa* recebida=(tarefa*)malloc(sizeof(tarefa));
    data* inicio=(data*)malloc(sizeof(data));
    data* termino=(data*)malloc(sizeof(data));

    printf(" Digite o codigo: ");
    scanf(" %d", &recebida->Codigo);
    printf("\n Nome da tarefa: ");
    scanf(" %[^\n]", recebida->Nome);
    fflush(stdin);
    printf("\n Nome do projeto: ");
    scanf(" %[^\n]", recebida->Projeto);
    fflush(stdin);
    printf("\n Data de inicio: ");

    scanf("%d%d%d", &inicio->Dia,&inicio->Mes,&inicio->Ano);
    recebida->Inicio=inicio;

    printf("\n Data de termino: ");
    scanf(" %d%d%d", &termino->Dia,&termino->Mes,&termino->Ano);
    recebida->Termino=termino;
    recebida->Status=0;
    printf("\n Prioridade: ");
    scanf("%d", &recebida->Prioridade);
    while(recebida->Prioridade<1 || recebida->Prioridade>3){
    printf("Prioridade invalida\n Insira novamente....\n");
    scanf(" %d", &recebida->Prioridade);
    }

    return recebida;
}

int verificaTarefaAtrasada(tarefa* aux){
    int verifica=0;
    time_t  agora;
    struct tm *atual;

    time(&agora);
    atual=localtime(&agora);
    atual->tm_year=atual->tm_year+1900;
    atual->tm_mon=atual->tm_mon+1;

    if(aux->Termino->Ano < atual->tm_year){
            aux->Status=1;
            verifica=1;
    }
    else if(aux->Termino->Ano == atual->tm_year){
        if(aux->Termino->Mes < atual->tm_mon){
            aux->Status=1;
            verifica=1;
        }
        else if(aux->Termino->Mes == atual->tm_mon){
            if(aux->Termino->Dia < atual->tm_mday){
                aux->Status=1;
                verifica=1;
            }
        }
    }

    return verifica;

}





#endif // TAREFA_H_INCLUDED
