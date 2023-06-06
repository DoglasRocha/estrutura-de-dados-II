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

/*Função para inserir uma aresta direcionada no grafo construído com matriz de adjacências*/
void insere_aresta_direcionado_grafo_mat(GrafoM *G, int vertice1, int vertice2, int peso)
{
    if (vertice1 >= G->V || vertice2 >= G->V)
        return;

    G->E++;
    G->Mat[vertice1][vertice2] = peso;
}

/*Função para inserir uma aresta nao direcionada no grafo construído com matriz de adjacências*/
void insere_aresta_nao_direcionado_grafo_mat(GrafoM *G, int vertice1, int vertice2, int peso)
{
    insere_aresta_direcionado_grafo_mat(G, vertice1, vertice2, peso);
    insere_aresta_direcionado_grafo_mat(G, vertice2, vertice1, peso);
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
NoA *criaNo(int info, int peso)
{
    NoA *no = (NoA *)malloc(sizeof(NoA));
    no->id = info;
    no->next = NULL;
    no->weight = peso;

    return no;
}

/*Função que insere aresta direcionada na lista de adjacências de um grafo*/
void insere_aresta_direcionado_grafo_adj(GrafoA *G, int vertice1, int vertice2, int peso)
{
    NoA *aux;
    if (vertice1 >= G->V || vertice2 >= G->V)
        return;

    G->E++;
    aux = G->Adj[vertice1];
    if (aux == NULL)
        G->Adj[vertice1] = criaNo(vertice2, peso);
    else
    {
        while (aux->next != NULL)
            aux = aux->next;

        aux->next = criaNo(vertice2, peso);
    }
}

/*Função para inserir uma aresta nao direcionada no grafo construído com lista de adjacências*/
void insere_aresta_nao_direcionado_grafo_adj(GrafoA *G, int vertice1, int vertice2, int peso)
{
    insere_aresta_direcionado_grafo_adj(G, vertice1, vertice2, peso);
    insere_aresta_direcionado_grafo_adj(G, vertice2, vertice1, peso);
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
            printf("%2d: (w:%2d), ", aux->id, aux->weight);
            aux = aux->next;
        }
        printf("\n");
    }
}

/*  Função para contar arestas que incidem sobre um determinado vertice numa
    matriz de adjacencias */
void contar_arestas_incidents_mat(GrafoM *G, int vertice)
{
    int sum = 0;
    if (vertice >= G->V)
        return;

    for (int i = 0; i < G->V; i++)
        if (G->Mat[i][vertice])
            sum++;

    printf("Número de arestas adjacentes ao vértice %d: %d\n", vertice, sum);
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
void contar_arestas_que_saem_mat(GrafoM *G, int vertice)
{
    int sum = 0;
    if (vertice >= G->V)
        return;

    for (int i = 0; i < G->V; i++)
        if (G->Mat[vertice][i])
            sum++;

    printf("Número de arestas que saem do vértice %d: %d\n", vertice, sum);
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
    matriz de adjacencia */
void listar_vertices_adjacentes_mat(GrafoM *G, int vertice)
{
    if (vertice >= G->V)
        return;

    printf("Vértices adjacentes ao vértice %d: ", vertice);

    for (int i = 0; i < G->V; i++)
        if (G->Mat[vertice][i])
            printf("%d ", i);

    printf("\n");
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
