#include "dfs.h"

void inicializaNoBusca(DFS no)
{
    no.cor = BRANCO;
    no.pai = NIL;
    no.descoberta = no.finalizacao = 0;
}

void busca_profundidade(GrafoA *G)
{
    int aux, tempo = 0;
    DFS *V = (DFS *)malloc(G->V * sizeof(DFS));
    for (aux = 0; aux < G->V; aux++)
        inicializaNoBusca(V[aux]);

    for (aux = 0; aux < G->V; aux++)
        if (V[aux].cor == BRANCO)
            DFS_visit(G, aux, V, &tempo);

    printf("\nComponente: ");
    for (int i = 1, aux = 0, fim = 0; i < tempo; i++)
    {
        for (int j = 0; j < G->V; j++)
        {
            if (i == V[j].descoberta)
            {
                printf("%2d ", j);
                j = 0;
                i++;
            }
            else if (j == G->V - 1)
                aux++;
        }

        if ((aux) == (i - fim) / 2)
        {
            printf("\nComponente: ");
            fim = i;
            aux = 0;
        }
    }
    printf("\n");

    free(V);
}

void DFS_visit(GrafoA *G, int atual, DFS *V, int *tempo)
{
    V[atual].cor = CINZA;
    (*tempo)++;
    V[atual].descoberta = *tempo;

    for (NoA *aux = G->Adj[atual]; aux != NULL; aux = aux->next)
    {
        if (V[aux->id].cor == BRANCO)
        {
            printf("Aresta arvore: (%2d - %2d)\n", atual, aux->id);
            V[aux->id].pai = atual;
            DFS_visit(G, aux->id, V, tempo);
        }
        else
            printf("Aresta outra : (%2d - %2d)\n", atual, aux->id);
    }
    V[atual].cor = PRETO;
    V[atual].finalizacao = ++(*tempo);
}
