#include "graph.h"
#include "dfs.h"

/* */
void questao2()
{
    // alocando grafo
    GrafoA *grafo = criar_grafo_adj(12);

    // montando grafo
    insere_aresta_direcionada_grafo_adj(grafo, 0, 1); // 0
    insere_aresta_direcionada_grafo_adj(grafo, 0, 3); // 0

    insere_aresta_direcionada_grafo_adj(grafo, 1, 2); // 1

    insere_aresta_direcionada_grafo_adj(grafo, 2, 5); // 2

    insere_aresta_direcionada_grafo_adj(grafo, 4, 1); // 4

    insere_aresta_direcionada_grafo_adj(grafo, 5, 4); // 5
    insere_aresta_direcionada_grafo_adj(grafo, 5, 6); // 5

    insere_aresta_direcionada_grafo_adj(grafo, 6, 0); // 6
    insere_aresta_direcionada_grafo_adj(grafo, 6, 3); // 6
    insere_aresta_direcionada_grafo_adj(grafo, 6, 4); // 6

    insere_aresta_direcionada_grafo_adj(grafo, 7, 8); // 7

    insere_aresta_direcionada_grafo_adj(grafo, 9, 10); // 9

    insere_aresta_direcionada_grafo_adj(grafo, 10, 11); // 10

    insere_aresta_direcionada_grafo_adj(grafo, 11, 9); // 11

    // deep search
    busca_profundidade(grafo);

    // libera grafo
    liberar_grafo_adj(grafo);
}

int main()
{
    questao2();
    return 0;
}