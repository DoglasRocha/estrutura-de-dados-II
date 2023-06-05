#include "graph.h"

/*Função para criar um grafo com lista de adjacências.*/
GrafoA *criar_grafo_adj(int tamanho)
{
    int v;
    GrafoA *G = (GrafoA *)malloc(sizeof(GrafoA));
    G->E = 0;
    G->V = tamanho;
    G->Adj = (NoA **)malloc(tamanho * sizeof(NoA *));
    for (v = 0; v < G->V; v++)
    {
        G->Adj[v] = NULL;
    }
    return G;
}

/*Função para criar um grafo com matriz de adjacências.*/
GrafoM *criar_grafo_mat(int tamanho)
{
    int v;
    GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
    G->E = 0;
    G->V = tamanho;
    G->Mat = (int **)malloc(tamanho * sizeof(int *));
    for (v = 0; v < G->V; v++)
    {
        G->Mat[v] = (int *)malloc(tamanho * sizeof(int));
        for (int i = 0; i < G->V; i++)
            G->Mat[v][i] = 0;
    }
    return G;
}

/*Função que libera recursivamente uma lista de adjacências*/
void liberarNo(NoA *no)
{
    if (no == NULL)
        return;
    liberarNo(no->next);
    free(no);
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_adj(GrafoA *G)
{
    int v;
    for (v = 0; v < G->V; v++)
    {
        if (G->Adj[v] != NULL)
        {
            liberarNo(G->Adj[v]);
        }
    }
    free(G->Adj);
    free(G);
}

/*Função para destruir um grafo construído com matriz de adjacências.*/
void liberar_grafo_mat(GrafoM *G)
{
    int v;
    for (v = 0; v < G->V; v++)
    {
        if (G->Mat[v] != NULL)
        {
            free(G->Mat[v]);
        }
    }
    free(G->Mat);
    free(G);
}

/*Função para inserir um vertice direcionado no grafo construído com matriz de adjacências*/
void insere_vertice_direcionado_grafo_mat(GrafoM *G, int aresta1, int aresta2)
{
    if (aresta1 >= G->V || aresta2 >= G->V)
        return;

    G->E++;
    G->Mat[aresta1][aresta2] = 1;
}

/*Função para inserir um vertice nao direcionado no grafo construído com matriz de adjacências*/
void insere_vertice_nao_direcionado_grafo_mat(GrafoM *G, int aresta1, int aresta2)
{
    insere_vertice_direcionado_grafo_mat(G, aresta1, aresta2);
    insere_vertice_direcionado_grafo_mat(G, aresta2, aresta1);
}

/*Função para imprimir um grafo construído com matriz de adjacẽncias*/
void imprime_grafo_mat(GrafoM *G)
{
    printf("  \t");
    for (int i = 0; i < G->V; i++)
        printf("%2d ", i);
    printf("\n\n");

    for (int i = 0; i < G->V; i++)
    {
        printf("%2d\t", i);
        for (int j = 0; j < G->V; j++)
            printf("%2d ", G->Mat[i][j]);
        printf("\n");
    }
}

/*Função para criar nó*/
NoA *criaNo(int info)
{
    NoA *no = (NoA *)malloc(sizeof(NoA));
    no->id = info;
    no->next = NULL;

    return no;
}

/*Função que insere vertice direcionado na lista de adjacências de um grafo*/
void insere_vertice_direcionado_grafo_adj(GrafoA *G, int aresta1, int aresta2)
{
    NoA *aux;
    if (aresta1 >= G->V || aresta2 >= G->V)
        return;

    G->E++;
    aux = G->Adj[aresta1];
    if (aux == NULL)
        G->Adj[aresta1] = criaNo(aresta2);
    else
    {
        while (aux->next != NULL)
            aux = aux->next;

        aux->next = criaNo(aresta2);
    }
}

/*Função para inserir um vertice nao direcionado no grafo construído com lista de adjacências*/
void insere_vertice_nao_direcionado_grafo_adj(GrafoA *G, int aresta1, int aresta2)
{
    insere_vertice_direcionado_grafo_adj(G, aresta1, aresta2);
    insere_vertice_direcionado_grafo_adj(G, aresta2, aresta1);
}

/*Função para imprimir um grafo construído com lista de adjacẽncias*/
void imprime_grafo_adj(GrafoA *G)
{
    NoA *aux;
    for (int i = 0; i < G->V; i++)
    {
        printf("%2d -> ", i);
        aux = G->Adj[i];
        while (aux != NULL)
        {
            printf("%2d ", aux->id);
            aux = aux->next;
        }
        printf("\n");
    }
}
