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

void concluirTarefa(lista** pendentes,lista** concluidas){
    tarefa * tarefa;
    int cod;
    imprimeLista(*pendentes);
    printf("\n Digite o codigo da tarefa que deseja concluir");
    scanf("%d",&cod);
    tarefa=RetiraTarefaLista(*pendentes,cod);

    printf("\n Data de termino : ");
    scanf("%d",&tarefa->Termino->Dia);
    scanf("%d",&tarefa->Termino->Mes);
    scanf("%d",&tarefa->Termino->Ano);

    *concluidas=insereLista(*concluidas,tarefa);


}

tarefa * achaTarefaLista(lista* recebida,int codigo){
    tarefa* taf;
    for(tarefa* aux=recebida->tarefa;aux!=NULL;aux=aux->Prox){
        if(aux->Codigo==codigo){
            taf=aux;
        }
    }
    return taf;
}

void modificaTarefa(lista* listaTarefas,lista**pendentes,int aux){
    int codigo;
    tarefa* recebida=CriaTarefa();
    if(!VaziaLista(listaTarefas)){
        imprimeLista(listaTarefas);
        printf(" \nDigite o codigo da tarefa que deseja modificar:  \n");
        scanf("%d",&codigo);
        recebida=achaTarefaLista(listaTarefas,codigo);
        if(aux==0){
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
            else{
                printf("\n Digite o novo status da tarefa: ");
                scanf("%d",&recebida->Status);
                if(recebida->Status==-1){
                        *pendentes=insereLista(*pendentes,RetiraTarefaLista(listaTarefas,recebida->Codigo));
                }
            }
    }
    else
        {
        printf(" Nao existem tarefas");
        printf("\n");
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







#endif // LISTA_H_INCLUDED
