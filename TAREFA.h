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
    printf("\n 1- Codigo : %d",recebida->Codigo);
    printf("\n 2- Nome : %s",recebida->Nome);
    printf("\n 3- Projeto a qual faz parte : %s",recebida->Projeto);
    printf("\n 4- Data de inicio : %d/%d/%d",recebida->Inicio->Dia,recebida->Inicio->Mes,recebida->Inicio->Ano);
    printf("\n 5- Data de termino: %d/%d/%d",recebida->Termino->Dia,recebida->Termino->Mes,recebida->Termino->Ano);
    printf("\n 6- Status: %d",recebida->Status);
    printf("\n 7- Prioridade: %d",recebida->Prioridade);
}



tarefa* AdicionaValoresTarefa(){
    tarefa* recebida=(tarefa*)malloc(sizeof(tarefa));
    data* Data=(data*)malloc(sizeof(data));
    data* termino=(data*)malloc(sizeof(data));
    time_t  agora;
    struct tm *p;

    time(&agora);
    p=localtime(&agora);



    printf(" Digite o codigo: \n");
    scanf(" %d", &recebida->Codigo);
    printf(" Nome da tarefa:  \n");
    scanf(" %[^\n]", recebida->Nome);
    fflush(stdin);
    printf(" Nome do projeto:  \n");
    scanf(" %[^\n]", recebida->Projeto);
    fflush(stdin);
    printf(" Data de inicio:  \n");

    Data->Dia=p->tm_mday;

    Data->Mes=p->tm_mon+1;

    Data->Ano=p->tm_year+1900;
    recebida->Inicio=Data;



    printf(" %d/%d/%d\n",recebida->Inicio->Dia,recebida->Inicio->Mes,recebida->Inicio->Ano);
    printf(" Data de termino:  \n");
    scanf(" %d", &termino->Dia);
    scanf(" %d", &termino->Mes);
    scanf(" %d", &termino->Ano);
    recebida->Termino=termino;
    printf(" Status:  \n");
    scanf(" %d", &recebida->Status);
    printf(" Prioridade:  \n");
    scanf(" %d", &recebida->Prioridade);
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
            aux->Status=-1;
            verifica=-1;
    }
    else if(aux->Termino->Ano == atual->tm_year){
        if(aux->Termino->Mes < atual->tm_mon){
            aux->Status=-1;
            verifica=-1;
        }
        else if(aux->Termino->Mes == atual->tm_mon){
            if(aux->Termino->Dia < atual->tm_mday){
                aux->Status=-1;
                verifica=-1;
            }
        }
    }

    return verifica;

}





#endif // TAREFA_H_INCLUDED
