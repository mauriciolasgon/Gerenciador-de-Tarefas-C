#ifndef TAREFA_H_INCLUDED
#define TAREFA_H_INCLUDED
typedef struct Data{
    int Mes;
    int Ano;
    int Dia;
}data;

typedef struct TAREFA{
     int Codigo;
     char Nome[30];
     char Projeto[30];
     struct Data *Inicio;
     struct Data *Termino;
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

tarefa* AdicionaValoresTarefa(){
    tarefa* recebida=(tarefa*)malloc(sizeof(tarefa));

    data* inicio=(data*)malloc(sizeof(data)),*termino=(data*)malloc(sizeof(data));

    printf(" Digite o codigo: \n");
    scanf(" %d", &recebida->Codigo);
    printf(" Nome da tarefa:  \n");
    scanf(" %[^\n]", recebida->Nome);
    fflush(stdin);
    printf(" Nome do projeto:  \n");
    scanf(" %[^\n]", recebida->Projeto);
    fflush(stdin);
    printf(" Data de inicio:  \n");
    scanf(" %d", &inicio->Dia);
    printf("/");
    scanf(" %d", &inicio->Mes);
    printf("/");
    scanf(" %d", &inicio->Ano);
    recebida->Inicio=inicio;
    printf(" Data de termino:  \n");
    scanf(" %d/", &termino->Dia);
    scanf(" %d/", &termino->Mes);
    scanf(" %d/", &termino->Ano);
    recebida->Termino=termino;
    printf(" Status:  \n");
    scanf(" %d", &recebida->Status);
    printf(" Prioridade:  \n");
    scanf(" %d", &recebida->Prioridade);
    return recebida;
}

void imprimeTarefa(tarefa* recebida){
    printf("\n%d",recebida->Codigo);
    printf("\n%s",recebida->Nome);
    printf("\n%d",recebida->Inicio->Dia);
}



#endif // TAREFA_H_INCLUDED
