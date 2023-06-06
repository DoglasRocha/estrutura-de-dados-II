#include "graph.h"

void questao1()
{
    printf("Questão 1:\n\n");

    int Va = 6; /*Número de vértices*/
    GrafoA *Ga = criar_grafo_adj(Va);

    int Vm = 6; /*Número de vértices*/
    GrafoM *Gm = criar_grafo_mat(Vm);

    // 0
    insere_aresta_nao_direcionado_grafo_mat(Gm, 0, 1, 1);
    insere_aresta_nao_direcionado_grafo_mat(Gm, 0, 2, 1);
    insere_aresta_nao_direcionado_grafo_mat(Gm, 0, 5, 1);

    // 1
    insere_aresta_nao_direcionado_grafo_mat(Gm, 1, 2, 1);
    insere_aresta_nao_direcionado_grafo_mat(Gm, 1, 3, 1);

    // 2
    insere_aresta_nao_direcionado_grafo_mat(Gm, 2, 3, 1);
    insere_aresta_nao_direcionado_grafo_mat(Gm, 2, 4, 1);

    // 3
    insere_aresta_nao_direcionado_grafo_mat(Gm, 3, 4, 1);

    // 4
    insere_aresta_nao_direcionado_grafo_mat(Gm, 4, 5, 1);

    printf("Matriz de adjacências:\n");
    imprime_grafo_mat(Gm);

    // 0
    insere_aresta_nao_direcionado_grafo_adj(Ga, 0, 1, 1);
    insere_aresta_nao_direcionado_grafo_adj(Ga, 0, 2, 1);
    insere_aresta_nao_direcionado_grafo_adj(Ga, 0, 5, 1);

    // 1
    insere_aresta_nao_direcionado_grafo_adj(Ga, 1, 2, 1);
    insere_aresta_nao_direcionado_grafo_adj(Ga, 1, 3, 1);

    // 2
    insere_aresta_nao_direcionado_grafo_adj(Ga, 2, 3, 1);
    insere_aresta_nao_direcionado_grafo_adj(Ga, 2, 4, 1);

    // 3
    insere_aresta_nao_direcionado_grafo_adj(Ga, 3, 4, 1);

    // 4
    insere_aresta_nao_direcionado_grafo_adj(Ga, 4, 5, 1);

    printf("\nLista de adjacências:\n");
    imprime_grafo_adj(Ga);

    liberar_grafo_adj(Ga);
    liberar_grafo_mat(Gm);
}

void questao2()
{
    printf("\nQuestao 2:\n\n");

    int Va = 6; /*Número de vértices*/
    GrafoA *Ga = criar_grafo_adj(Va);

    int Vm = 6; /*Número de vértices*/
    GrafoM *Gm = criar_grafo_mat(Vm);

    // 0
    insere_aresta_direcionado_grafo_mat(Gm, 0, 1, 1);
    insere_aresta_direcionado_grafo_mat(Gm, 0, 5, 1);

    // 1
    insere_aresta_direcionado_grafo_mat(Gm, 1, 2, 1);
    insere_aresta_direcionado_grafo_mat(Gm, 1, 3, 1);

    // 2
    insere_aresta_direcionado_grafo_mat(Gm, 2, 0, 1);
    insere_aresta_direcionado_grafo_mat(Gm, 2, 4, 1);

    // 3
    insere_aresta_direcionado_grafo_mat(Gm, 3, 2, 1);

    // 4
    insere_aresta_direcionado_grafo_mat(Gm, 4, 3, 1);

    // 5
    insere_aresta_direcionado_grafo_mat(Gm, 5, 4, 1);

    printf("Matriz de adjacências:\n");
    imprime_grafo_mat(Gm);

    // 0
    insere_aresta_direcionado_grafo_adj(Ga, 0, 1, 1);
    insere_aresta_direcionado_grafo_adj(Ga, 0, 5, 1);

    // 1
    insere_aresta_direcionado_grafo_adj(Ga, 1, 2, 1);
    insere_aresta_direcionado_grafo_adj(Ga, 1, 3, 1);

    // 2
    insere_aresta_direcionado_grafo_adj(Ga, 2, 0, 1);
    insere_aresta_direcionado_grafo_adj(Ga, 2, 4, 1);

    // 3
    insere_aresta_direcionado_grafo_adj(Ga, 3, 2, 1);

    // 4
    insere_aresta_direcionado_grafo_adj(Ga, 4, 3, 1);

    // 5
    insere_aresta_direcionado_grafo_adj(Ga, 5, 4, 1);

    printf("\nLista de adjacências:\n");
    imprime_grafo_adj(Ga);

    liberar_grafo_adj(Ga);
    liberar_grafo_mat(Gm);
}

void questao3()
{
    printf("\nQuestao 3:\n\n");

    int Va = 6; /*Número de vértices*/
    GrafoA *Ga = criar_grafo_adj(Va);

    int Vm = 6; /*Número de vértices*/
    GrafoM *Gm = criar_grafo_mat(Vm);

    // 0
    insere_aresta_direcionado_grafo_mat(Gm, 0, 1, 1);
    insere_aresta_direcionado_grafo_mat(Gm, 0, 3, 5);

    // 1
    insere_aresta_direcionado_grafo_mat(Gm, 1, 3, 8);

    // 2
    insere_aresta_direcionado_grafo_mat(Gm, 2, 0, 5);
    insere_aresta_direcionado_grafo_mat(Gm, 2, 3, 4);

    // 3
    insere_aresta_direcionado_grafo_mat(Gm, 3, 3, 6);
    insere_aresta_direcionado_grafo_mat(Gm, 3, 4, 3);

    // 4
    insere_aresta_direcionado_grafo_mat(Gm, 4, 2, 7);
    insere_aresta_direcionado_grafo_mat(Gm, 4, 5, 9);

    // 5
    insere_aresta_direcionado_grafo_mat(Gm, 5, 0, 2);

    printf("Matriz de adjacências:\n");
    imprime_grafo_mat(Gm);
    contar_arestas_incidents_mat(Gm, 4);

    // 0
    insere_aresta_direcionado_grafo_adj(Ga, 0, 1, 1);
    insere_aresta_direcionado_grafo_adj(Ga, 0, 3, 5);

    // 1
    insere_aresta_direcionado_grafo_adj(Ga, 1, 3, 8);

    // 2
    insere_aresta_direcionado_grafo_adj(Ga, 2, 0, 5);
    insere_aresta_direcionado_grafo_adj(Ga, 2, 3, 4);

    // 3
    insere_aresta_direcionado_grafo_adj(Ga, 3, 3, 6);
    insere_aresta_direcionado_grafo_adj(Ga, 3, 4, 3);

    // 4
    insere_aresta_direcionado_grafo_adj(Ga, 4, 2, 7);
    insere_aresta_direcionado_grafo_adj(Ga, 4, 5, 9);

    // 5
    insere_aresta_direcionado_grafo_adj(Ga, 5, 0, 2);

    printf("\nLista de adjacências:\n");
    imprime_grafo_adj(Ga);
    contar_arestas_incidentes_adj(Ga, 5);

    liberar_grafo_adj(Ga);
    liberar_grafo_mat(Gm);
}

/* */
int main()
{
    questao1();
    questao2();
    questao3();

    return 0;
}