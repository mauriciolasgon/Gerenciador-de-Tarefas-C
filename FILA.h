#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "TAREFA.h"

/* FUNÇÕES DE MANIPULAÇÃO DE PFILA

Fila* CriaFila()  CRIA A FILA

int VaziaFila (Fila* f) VERIFICA SE A FILA ESTÁ VAIZA

void InsereFila (Fila* f, int v) INSERÇÃO

int RetiraFila (Fila* f) REMOÇÃO

Fila* liberaFila (Fila* f) LIBERA A FILA

void imprimeFila (Fila* f)IMPRIME A FILA
*/
typedef struct TAREFA no;

typedef struct fila
{
    no * ini;
    no * fim;
} Fila;

int VaziaFila (Fila* f)
{
    if (f->ini==NULL) return 1;
    return 0;

}


Fila* CriaFila ()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

no* ins_fim (no* fim, no* nova)
{
    nova->Prox=NULL;
    if (fim != NULL){ /* verifica se lista não estava vazia */
        fim->Prox = nova;
    }
    return nova;
}

void InsereFila (Fila* f, no* novaTarefa)
{
    f->fim = ins_fim(f->fim,novaTarefa);
    if (f->ini==NULL){ /* fila antes vazia? */
        f->ini = f->fim;
    }
}

no* retira_ini (no* ini)
{
    no* p = ini->Prox;
    free(ini);
    return p;
}

no* RetiraFila (Fila* f)
{
    no* tarefa;
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    tarefa = f->ini;

    f->ini = retira_ini(f->ini);
    if (f->ini == NULL){
        f->fim = NULL;
    } /* fila ficou vazia? */
    return tarefa;
}

void imprimeFila (Fila* f)
{
    no* q;
    printf("\n\t\t");
    for (q=f->ini; q!=NULL; q=q->Prox)
    {
        printf("%d - ",q->Codigo);
    }
    printf("\n");
}


Fila* liberaFila (Fila* f)
{
    no* q = f->ini;
    while (q!=NULL)
    {
        no* t = q->Prox;
        free(q);
        q = t;
    }
    free(f);
    return NULL;
}

#endif // FILA_H_INCLUDED
