#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "TAREFA.h"
#include "LISTA.h"

/* FUNÇÕES DE MANIPULAÇÃO DE PFILA

Fila* CriaFila()  CRIA A FILA

int VaziaFila (Fila* f) VERIFICA SE A FILA ESTÁ VAIZA

void InsereFila (Fila* f, int v) INSERÇÃO

int RetiraFila (Fila* f) REMOÇÃO

Fila* liberaFila (Fila* f) LIBERA A FILA

void imprimeFila (Fila* f)IMPRIME A FILA
*/

typedef struct fila
{
    tarefa * ini;
    tarefa * fim;
} Fila;

int VaziaFila (Fila* f)
{
    if (f->ini==NULL) return 1;
    return 0;

}
// funçoes da biblioteca lista usadas nessa biblioteca
lista*CriaLista();
lista* insereLista(lista* recebida,tarefa* novaTarefa);

Fila* CriaFila ()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

tarefa* ins_fim (tarefa* fim, tarefa* nova)
{
    nova->Prox=NULL;
    if (fim != NULL){ /* verifica se lista não estava vazia */
        fim->Prox = nova;
    }
    return nova;
}

void InsereFila (Fila* f, tarefa* novaTarefa)
{
    f->fim = ins_fim(f->fim,novaTarefa);
    if (f->ini==NULL){ /* fila antes vazia? */
        f->ini = f->fim;
    }
}

tarefa* retira_ini (tarefa* ini)
{
    tarefa* p = ini->Prox;

    return p;
}

tarefa* RetiraFila (Fila* f)
{
    tarefa *taf;
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    taf = f->ini;

    f->ini = retira_ini(f->ini);
    if (f->ini == NULL){
        f->fim = NULL;
    } /* fila ficou vazia? */
    return taf;
}

int contaFila(Fila *f){
    int n=0;
    for(tarefa*aux=f->ini;aux!=NULL;aux=aux->Prox){
        n++;
    }
    return n;
}

void imprimeFila (Fila* f)
{
    tarefa* q;
    printf("\n\t\t");
    for (q=f->ini; q!=NULL; q=q->Prox)
    {
        printf("%d - ",q->Codigo);
    }
    printf("\n");
}


Fila* liberaFila (Fila* f)
{
    tarefa* q = f->ini;
    while (q!=NULL)
    {
        tarefa* t = q->Prox;
        free(q);
        q = t;
    }
    free(f);
    return NULL;
}


lista* mergeFilaPrioridades(Fila* f1, Fila* f2,Fila *f3){
    lista * prioridades=CriaLista();
    // atencao logica dos for
    if(!VaziaFila(f3)){
        for(tarefa *aux=f3->ini;aux!=NULL;aux=f3->ini){
            prioridades=insereLista(prioridades,RetiraFila(f3));
        }
    }
    if(!VaziaFila(f2)){
        for(tarefa *aux=f2->ini;aux!=NULL;aux=f2->ini){
            prioridades=insereLista(prioridades,RetiraFila(f2));
        }
    }
    if(!VaziaFila(f1)){
        for(tarefa *aux=f1->ini;aux!=NULL;aux=f1->ini){
            prioridades=insereLista(prioridades,RetiraFila(f1));
        }
    }
    return prioridades;
}

void ordenaFilaTermino(Fila *recebida){
    int n=contaFila(recebida),i=0;
    tarefa *troca,**vet;
    vet=(tarefa**)malloc(n*sizeof(tarefa));

    while(!VaziaFila(recebida)){
        vet[i]=RetiraFila(recebida);
        i++;
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            if(vet[i]->Termino->Ano > vet[j]->Termino->Ano){
                troca=vet[i];
                vet[i]=vet[j];
                vet[j]=troca;
            }
            else if(vet[i]->Termino->Ano == vet[j]->Termino->Ano){
                    if(vet[i]->Termino->Mes > vet[j]->Termino->Mes){
                        troca=vet[i];
                        vet[i]=vet[j];
                        vet[j]=troca;

                    }
                    else if(vet[i]->Termino->Mes == vet[j]->Termino->Mes){
                            if(vet[i]->Termino->Dia > vet[j]->Termino->Dia){
                                troca=vet[i];
                                vet[i]=vet[j];
                                vet[j]=troca;
                            }

                    }
                }

    }

    for(int i=0;i<n;i++){
        InsereFila(recebida,vet[i]);
    }

    free(vet);
}


#endif // FILA_H_INCLUDED
