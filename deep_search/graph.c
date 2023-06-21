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

/*Função para criar nó*/
NoA *criaNo(int info)
{
    NoA *no = (NoA *)malloc(sizeof(NoA));
    no->id = info;
    no->next = NULL;

    return no;
}

/*Função que insere aresta direcionada na lista de adjacências de um grafo*/
void insere_aresta_direcionada_grafo_adj(GrafoA *G, int origem, int destino)
{
    NoA *aux;
    if (origem >= G->V || origem >= G->V)
        return;

    G->E++;
    aux = G->Adj[origem];
    if (aux == NULL)
        G->Adj[origem] = criaNo(destino);
    else
    {
        if (aux->id == destino)
            return;

        while (aux->next != NULL)
        {
            if (aux->next->id == destino)
                return;
            aux = aux->next;
        }

        aux->next = criaNo(destino);
    }
}

/*Função para inserir uma aresta nao direcionada no grafo construído com lista de adjacências*/
void insere_aresta_nao_direcionada_grafo_adj(GrafoA *G, int vertice1, int vertice2)
{
    insere_aresta_direcionada_grafo_adj(G, vertice1, vertice2);
    insere_aresta_direcionada_grafo_adj(G, vertice2, vertice1);
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
            printf("%2d, ", aux->id);
            aux = aux->next;
        }
        printf("\n");
    }
}

/*  Função para contar arestas que incidem sobre um determinado vertice numa
    lista de adjacencias */
void contar_arestas_incidentes_adj(GrafoA *G, int vertice)
{
    int sum = 0;
    if (vertice >= G->V)
        return;

    for (int i = 0; i < G->V; i++)
    {
        for (NoA *aux = G->Adj[i]; aux != NULL; aux = aux->next)
            if (aux->id == vertice)
                sum++;
    }

    printf("Número de arestas adjacentes ao vértice %d: %d\n", vertice, sum);
}

/*  Função para contar arestas que saem de um determinado vertice numa
    matriz de adjacencias */
void contar_arestas_que_saem_adj(GrafoA *G, int vertice)
{
    int sum = 0;
    if (vertice >= G->V)
        return;

    for (NoA *aux = G->Adj[vertice]; aux != NULL; aux = aux->next)
        sum++;

    printf("Número de arestas adjacentes ao vértice %d: %d\n", vertice, sum);
}

/*  Função que lista os vértices adjacentes a um determinado vertice numa
    lista de adjacencia */
void listar_vertices_adjacentes_adj(GrafoA *G, int vertice)
{
    if (vertice >= G->V)
        return;

    printf("Vértices adjacentes ao vértice %d: ", vertice);

    for (NoA *aux = G->Adj[vertice]; aux != NULL; aux = aux->next)
        printf("%d ", aux->id);

    printf("\n");
}
