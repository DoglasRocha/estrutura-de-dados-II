#include "dfs.h"

void inicializaNoBusca(DFS *no)
{
    no->cor = BRANCO;
    no->pai = NIL;
    no->descoberta = no->finalizacao = 0;
}

void busca_profundidade_arestas(GrafoA *G)
{
    int aux, tempo = 0;
    DFS *V = (DFS *)malloc(G->V * sizeof(DFS));
    for (aux = 0; aux < G->V; aux++)
        inicializaNoBusca(&V[aux]);

    for (aux = 0; aux < G->V; aux++)
        if (V[aux].cor == BRANCO)
            DFS_visit_arestas(G, aux, V, &tempo);

    free(V);
    V = NULL;
}

void DFS_visit_arestas(GrafoA *G, int atual, DFS *V, int *tempo)
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
            DFS_visit_arestas(G, aux->id, V, tempo);
        }
        else
            printf("Aresta outra : (%2d - %2d)\n", atual, aux->id);
    }
    V[atual].cor = PRETO;
    V[atual].finalizacao = ++(*tempo);
}

void busca_profundidade_componentes(GrafoA *G) 
{
    int aux, tempo = 0;
    DFS *V = (DFS *) malloc(G->V * sizeof(DFS));
    for (aux = 0; aux < G->V; aux++)
        inicializaNoBusca(&V[aux]);

    for (aux = 0; aux < G->V; aux++)
        if (V[aux].cor == BRANCO) {
            printf("Componente: ");
            DFS_visit_componentes(G, aux, V, &tempo);
            printf("\n");
        }

    free(V);
}

void DFS_visit_componentes(GrafoA *G, int atual, DFS *V, int *tempo)
{
    printf("%2d ", atual);

    V[atual].cor = CINZA;
    (*tempo)++;
    V[atual].descoberta = *tempo;

    for (NoA *aux = G->Adj[atual]; aux != NULL; aux = aux->next)
        if (V[aux->id].cor == BRANCO)
        {

            V[aux->id].pai = atual;
            DFS_visit_componentes(G, aux->id, V, tempo);
        }
    

    V[atual].cor = PRETO;
    V[atual].finalizacao = ++(*tempo);
}

void busca_profundidade_bipartido(GrafoA *G) {
    int aux, tempo = 0, nao_bipartido = 0;
    DFS *V = (DFS *) malloc(G->V * sizeof(DFS));
    for (aux = 0; aux < G->V; aux++)
        inicializaNoBusca(&V[aux]);

    for (aux = 0; aux < G->V; aux++)
        if (V[aux].cor == BRANCO) 
            DFS_visit_bipartido(G, aux, V, &tempo);

    for (aux = 0; aux < G->V; aux++)
    {
        for (NoA *node = G->Adj[aux]; node != NULL; node = node->next)
            if (V[node->id].cor == V[aux].cor)
                nao_bipartido = 1;
    }

    printf("O grafo %sé bipartido.\n", nao_bipartido ? "não " : "");

    free(V);
}

void DFS_visit_bipartido(GrafoA *G, int atual, DFS *V, int *tempo) {
    if (V[atual].pai == -1)
        V[atual].cor = PRETO;
    else
        V[atual].cor = V[atual].cor == PRETO ? VERMELHO : PRETO;

    (*tempo)++;
    V[atual].descoberta = *tempo;

    for (NoA *aux = G->Adj[atual]; aux != NULL; aux = aux->next)
        if (V[aux->id].cor == BRANCO)
        {
            V[aux->id].pai = atual;
            DFS_visit_bipartido(G, aux->id, V, tempo);
        }
    
    V[atual].finalizacao = ++(*tempo);
}
