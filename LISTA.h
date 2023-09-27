#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "TAREFA.h"

typedef struct TAREFA lista;

lista * CriaLista(){
    return NULL;
}
int VaziaLista (lista* f)
{
    if (f==NULL) return 1;
    return 0;

}

lista * RetiraTarefaLista(tarefa* recebida,int codigo ){
    lista *tarefa;
    for( lista* aux=recebida;aux!=NULL;aux=aux->Prox){
        if(aux->Codigo==codigo){
            tarefa=aux;
        }
    }
    return tarefa;

}

lista* insereLista(lista* recebida,lista* novaTarefa){
    novaTarefa->Prox=recebida;
    return novaTarefa;
}
void imprimeLista(lista* l){
    for(lista*aux=l;aux!=NULL;aux=aux->Prox){
        printf("%d ", aux->Codigo);
        printf("--");
    }
}

int contaLista(lista* l){
    int n=0;
    for(lista* aux=l;aux!=NULL;aux=aux->Prox){
        n++;
    }
    return n;
}
int verificaLista(lista* l1,lista* l2){
    int teste=0,x;
    for(lista* aux=l1;aux!=NULL;aux=aux->Prox){
        for(lista *aux2=l2;aux2!=NULL;aux2=aux2->Prox){
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
        lista* q=aux->Prox;
        free(aux);
        aux=q;
    }
}






#endif // LISTA_H_INCLUDED
