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
void ImprimeTarefa(tarefa* recebida){
    printf("\n 1- Codigo : %d",recebida->Codigo);
    printf("\n 2- Nome : %s",recebida->Nome);
    printf("\n 3- Projeto a qual faz parte : %s",recebida->Projeto);
    printf("\n 4- Data de inicio : %d/%d/%d",recebida->Inicio->Dia,recebida->Inicio->Mes,recebida->Inicio->Ano);
    printf("\n 5- Data de termino: %d/%d/%d",recebida->Termino->Dia,recebida->Termino->Mes,recebida->Termino->Ano);
    printf("\n 6- Status: %d",recebida->Status);
    printf("\n 7- Prioridade: %d",recebida->Prioridade);
}

void modificaTarefa(tarefa* recebida){
    int escolha;
    ImprimeTarefa(recebida);
    printf("\n Qual topico deseja modificar? ");
    scanf("%d",&escolha);
    if(escolha==1 || escolha==4){
        printf("\n Esse topico nao pode ser alterado");
    }
    switch(escolha){
        case 2:
            printf("\n Novo nome: ");
            scanf("%[^\n]",recebida->Nome);
            break;
        case 3:
            printf("\n Novo projeto a que pertence: ");
            scanf("%[^\n]",recebida->Projeto);
            break;
        case 5:
            printf("\n Nova data de termino: ");
            scanf("%d",&recebida->Termino->Dia);
            scanf("%d",&recebida->Termino->Mes);
            scanf("%d",&recebida->Termino->Ano);
            break;
        case 6:
            printf("\n Novo status");
            scanf("%d",&recebida->Status);
            break;
        case 7:
            printf("\n Novs prioridade");
            scanf("%d",&recebida->Prioridade);
            break;
    }



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





#endif // TAREFA_H_INCLUDED
