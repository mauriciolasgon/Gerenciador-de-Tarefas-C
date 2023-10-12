#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "TAREFA.h"
#include "FILA.h"
#include <time.h>
typedef struct Lista{
    tarefa *tarefa;
}lista;

lista * CriaLista(){
    lista *novaLista=(lista*)malloc(sizeof(lista));
    novaLista->tarefa=NULL;
    return novaLista;
}

int VaziaLista (lista* f)
{
    if (f->tarefa==NULL) return 1;
    return 0;

}

void imprimeLista(lista * l){
    for(tarefa*aux=l->tarefa;aux!=NULL;aux=aux->Prox){
        printf("%d ", aux->Codigo);
        printf("--");
    }
}




tarefa * RetiraTarefaLista(lista* recebida,int codigo ){
    tarefa *auxT;
    tarefa *anterior=recebida->tarefa,*prox;
    for(tarefa *aux=recebida->tarefa;aux!=NULL;aux=aux->Prox){
        if(aux->Codigo==codigo){
            auxT=aux;
            prox=aux->Prox;
            anterior->Prox=prox;
            if(recebida->tarefa==auxT){
                recebida->tarefa=prox;
            }

        }

        anterior=aux;
    }
    return auxT;

}


lista* insereLista(lista* recebida,tarefa* novaTarefa){

        novaTarefa->Prox=recebida->tarefa;
        recebida->tarefa=novaTarefa;


    return recebida;
}




int contaLista(lista* l){
    int n=0;
    for(tarefa* aux=l->tarefa;aux!=NULL;aux=aux->Prox){
        n++;
    }
    return n;
}
int verificaLista(lista* l1,lista* l2){
    int teste=0,x;
    for(tarefa* aux=l1->tarefa;aux!=NULL;aux=aux->Prox){
        for(tarefa *aux2=l2->tarefa;aux2!=NULL;aux2=aux2->Prox){
            if(aux->Codigo==aux2->Codigo){
                teste++;
            }
        }
    }
    x=contaLista(l1);
    if(x==teste){
        return 1;
    }
    else{
        return 0;
    }
}

void liberaLista(lista *l){
    lista *aux=l;
    while(l!=NULL){
        tarefa* q=aux->tarefa->Prox;
        free(aux);
        aux->tarefa=q;
    }
}



tarefa * achaTarefaLista(lista* recebida,int codigo){
    tarefa* taf=CriaTarefa();
    for(tarefa* aux=recebida->tarefa;aux!=NULL;aux=aux->Prox){
        if(aux->Codigo==codigo){
            taf=aux;
        }
    }
    return taf;
}



void concluirTarefa(lista** tarefas,lista** concluidas){
    if(!VaziaLista(*tarefas)){
    tarefa * tarefa;
    int cod,v;
    imprimeLista(*tarefas);
    printf("\n Digite o codigo da tarefa que deseja concluir ou digite 'v' para voltar\n");
    scanf("%d",&cod);
    v=getchar();
    if(v!='v'){
    tarefa=achaTarefaLista(*tarefas,cod);
    while(tarefa==NULL){
        printf("\nCodigo invalido\n-> ");
        scanf("%d",&cod);
        v=getchar();
        tarefa=achaTarefaLista(*tarefas,cod);
    }
    tarefa=RetiraTarefaLista(*tarefas,cod);
    fflush(stdin);
    printf("\nData de termino : ");
    scanf("%d%d%d", &tarefa->Termino->Dia,&tarefa->Termino->Mes,&tarefa->Termino->Ano);

    *concluidas=insereLista(*concluidas,tarefa);
    }
    }
    else{
        printf("\nA lista de tarefas esta vazia\n");
    }
}




void modificaTarefa(lista* listaTarefas,lista**pendentes,int aux){
    int codigo,x,voltar;
    tarefa* recebida,*tafPen;

    if(aux==0){
        if(!VaziaLista(listaTarefas)){
            int escolha;
            imprimeLista(listaTarefas);
            printf(" \nDigite o codigo da tarefa que deseja modificar ou digite 'v' para voltar:  \n");
            scanf("%d",&codigo);
            voltar=getchar();
            if(voltar!='v'){
                recebida=achaTarefaLista(listaTarefas,codigo);
                while(recebida==NULL){
                    printf("\nTarefa nao encontrada....\nDigite o codigo novamente -> ");
                    scanf("%d",&codigo);
                    voltar=getchar();
                    recebida=achaTarefaLista(listaTarefas,codigo);
                }

                ImprimeTarefa(recebida);
                printf("\n Qual topico deseja modificar? ");
                scanf("%d",&escolha);
                if(escolha==1 || escolha==4 || escolha==6){
                    printf("\n Esse topico nao pode ser alterado");
                }
                switch(escolha){
                    case 2:
                        fflush(stdin);
                        printf("\n Novo nome: ");
                        scanf("%[^\n]",recebida->Nome);
                        break;
                    case 3:
                        fflush(stdin);
                        printf("\n Novo projeto a que pertence: ");
                        scanf("%[^\n]",recebida->Projeto);
                        break;
                    case 5:
                        printf("\n Nova data de termino: ");
                        scanf("%d%d%d", &recebida->Termino->Dia,&recebida->Termino->Mes,&recebida->Termino->Ano);
                        break;

                    case 7:
                        printf("\n Nova prioridade");
                        scanf("%d",&recebida->Prioridade);
                        do{
                            printf("Prioridade invalida\n Insira novamente....\n");
                            scanf("%d", &recebida->Prioridade);
                        }while(recebida->Prioridade<1 || recebida->Prioridade>3);
                        break;
            }
            }

        }
        else{
            printf(" Nao existem tarefas na lista de tarefas");
            printf("\n");
            }
    }
    else{
            if(!VaziaLista(listaTarefas)||!VaziaLista(*pendentes)){
            printf("Lista de tarefas:\n ");
            imprimeLista(listaTarefas);
            printf("\nTarefas pendentes:\n ");
            imprimeLista(*pendentes);

            printf(" \nDigite o codigo da tarefa que deseja modificar ou digite 'v' para voltar:  \n");
            scanf("%d",&codigo);
            voltar=getchar();
            if(voltar!='v'){
                recebida=achaTarefaLista(listaTarefas,codigo);
                tafPen=achaTarefaLista(*pendentes,codigo);

                while(recebida==NULL && tafPen==NULL){
                    printf("\nTarefa nao encontrada....\nDigite o codigo novamente -> ");
                    scanf("%d",&codigo);
                    voltar=getchar();
                    recebida=achaTarefaLista(listaTarefas,codigo);
                    tafPen=achaTarefaLista(*pendentes,codigo);
                }

                printf("\n1- Adicionar pendencia a tarefa\n2- Retirar pendencia da tarefa\n");
                scanf("%d",&x);
                if(x==1  && (!VaziaLista(listaTarefas) || !VaziaLista(*pendentes))){
                    if(tafPen!=NULL){
                        printf("\nEssa tarefa ja esta pendente\n");
                    }
                    else{
                    recebida->Status=-1;
                    *pendentes=insereLista(*pendentes,RetiraTarefaLista(listaTarefas,recebida->Codigo));
                    printf("\n Pendencia adicionada com sucesso!!");
                    }
                }
                else if(x==2 && (!VaziaLista(listaTarefas) || !VaziaLista(*pendentes))){
                    if(recebida!=NULL){
                        printf("\nA tarefa nao esta na lista de pendencia\n");
                    }
                    else{
                    tafPen=RetiraTarefaLista(*pendentes,tafPen->Codigo);
                    x=verificaTarefaAtrasada(tafPen);
                    listaTarefas=insereLista(listaTarefas,tafPen);
                    printf("\n Pendencia retirada com sucesso!!");
                    }
                }
            else{
                printf("Opcao invalida\n");
            }
        }
            }
        else{
            printf(" Nao existem tarefas na lista de tarefas");
            printf("\n");
            }

    }



}

void ordenaLista(lista** recebida){
    Fila *p1=CriaFila(),*p2=CriaFila(),*p3=CriaFila();
    lista* l1=*recebida;
    //atenção logica do for
    for(tarefa* aux=l1->tarefa;aux!=NULL;aux=l1->tarefa){
        if(aux->Prioridade>=1 && aux->Prioridade<=3 ){
            if(aux->Prioridade==1){
                InsereFila(p1,RetiraTarefaLista(l1,aux->Codigo));
            }
            else if(aux->Prioridade==2){
                InsereFila(p2,RetiraTarefaLista(l1,aux->Codigo));
            }
            else if(aux->Prioridade==3){
                InsereFila(p3,RetiraTarefaLista(l1,aux->Codigo));
        }
        }
    }


    ordenaFilaTermino(p1);
    ordenaFilaTermino(p2);
    ordenaFilaTermino(p3);

    *recebida=mergeFilaPrioridades(p1,p2,p3);



}
void imprimeComSemAtraso(lista *recebida){

    if(!VaziaLista(recebida)){
        lista  *atrasada=CriaLista();
        tarefa* prox=recebida->tarefa->Prox;
        for(tarefa* aux=recebida->tarefa;aux!=NULL;aux=prox){
            if(aux->Status==1){
                atrasada=insereLista(atrasada,RetiraTarefaLista(recebida,aux->Codigo));
                prox=recebida->tarefa;

            }
            else{
            prox=aux->Prox;
            }

        }

        printf("\n Tarefas atrasadas: ");
        imprimeLista(atrasada);
        printf("\n Tarefas em dia: ");
        imprimeLista(recebida);


        for(tarefa* aux=atrasada->tarefa;aux!=NULL;aux=atrasada->tarefa){
            recebida=insereLista(recebida,RetiraTarefaLista(atrasada,aux->Codigo));
        }
    }
    else{
        printf("\n A lista de tarefas concluidas esta vazia");
    }
}

void imprimeListaeTarefas(lista *recebida){
    tarefa* taf;
    int visualizar,enter;

    if(!VaziaLista(recebida)){
        imprimeLista(recebida);
        printf("\nCaso queira visualizar uma tarefa digite seu codigo ou apenas digite 's' para sair\n-> ");
        scanf("%d",&visualizar);
        enter=getchar();

        while(enter!='s'){
            taf=achaTarefaLista(recebida,visualizar);
            if(taf!=NULL){
                ImprimeTarefa(taf);
            }
            else{
                printf("\nEssa tarefa nao foi encontrada\n ");
                }
            printf("\nCodigo-> ");
            scanf("%d",&visualizar);
            enter=getchar();
        }
            }
    else{
        printf("\nA lista esta vazia");
        }
}




#endif // LISTA_H_INCLUDED
