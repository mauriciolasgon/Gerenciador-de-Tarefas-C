#include <stdio.h>
#include <stdlib.h>
#include "LISTA.h"
#include "FILA.h"
#include "TAREFA.h"
typedef struct TAREFA Tarefa;
int main()
{
    Fila *fila1=CriaFila();
    InsereFila(fila1,AdicionaValoresTarefa());
    InsereFila(fila1,AdicionaValoresTarefa());

    imprimeFila(fila1);


    return 0;
}
