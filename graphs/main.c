#include "graph.h"

void questao1()
{
    printf("Questão 1:\n\n");

    int Va = 6; /*Número de vértices*/
    GrafoA *Ga = criar_grafo_adj(Va);

    int Vm = 6; /*Número de vértices*/
    GrafoM *Gm = criar_grafo_mat(Vm);

    // 0
    insere_vertice_nao_direcionado_grafo_mat(Gm, 0, 1);
    insere_vertice_nao_direcionado_grafo_mat(Gm, 0, 2);
    insere_vertice_nao_direcionado_grafo_mat(Gm, 0, 5);

    // 1
    insere_vertice_nao_direcionado_grafo_mat(Gm, 1, 2);
    insere_vertice_nao_direcionado_grafo_mat(Gm, 1, 3);

    // 2
    insere_vertice_nao_direcionado_grafo_mat(Gm, 2, 3);
    insere_vertice_nao_direcionado_grafo_mat(Gm, 2, 4);

    // 3
    insere_vertice_nao_direcionado_grafo_mat(Gm, 3, 4);

    // 4
    insere_vertice_nao_direcionado_grafo_mat(Gm, 4, 5);

    printf("Matriz de adjacências:\n");
    imprime_grafo_mat(Gm);

    // 0
    insere_vertice_nao_direcionado_grafo_adj(Ga, 0, 1);
    insere_vertice_nao_direcionado_grafo_adj(Ga, 0, 2);
    insere_vertice_nao_direcionado_grafo_adj(Ga, 0, 5);

    // 1
    insere_vertice_nao_direcionado_grafo_adj(Ga, 1, 2);
    insere_vertice_nao_direcionado_grafo_adj(Ga, 1, 3);

    // 2
    insere_vertice_nao_direcionado_grafo_adj(Ga, 2, 3);
    insere_vertice_nao_direcionado_grafo_adj(Ga, 2, 4);

    // 3
    insere_vertice_nao_direcionado_grafo_adj(Ga, 3, 4);

    // 4
    insere_vertice_nao_direcionado_grafo_adj(Ga, 4, 5);

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
    insere_vertice_direcionado_grafo_mat(Gm, 0, 1);
    insere_vertice_direcionado_grafo_mat(Gm, 0, 5);

    // 1
    insere_vertice_direcionado_grafo_mat(Gm, 1, 2);
    insere_vertice_direcionado_grafo_mat(Gm, 1, 3);

    // 2
    insere_vertice_direcionado_grafo_mat(Gm, 2, 0);
    insere_vertice_direcionado_grafo_mat(Gm, 2, 4);

    // 3
    insere_vertice_direcionado_grafo_mat(Gm, 3, 2);

    // 4
    insere_vertice_direcionado_grafo_mat(Gm, 4, 3);

    // 5
    insere_vertice_direcionado_grafo_mat(Gm, 5, 4);

    printf("Matriz de adjacências:\n");
    imprime_grafo_mat(Gm);

    // 0
    insere_vertice_direcionado_grafo_adj(Ga, 0, 1);
    insere_vertice_direcionado_grafo_adj(Ga, 0, 5);

    // 1
    insere_vertice_direcionado_grafo_adj(Ga, 1, 2);
    insere_vertice_direcionado_grafo_adj(Ga, 1, 3);

    // 2
    insere_vertice_direcionado_grafo_adj(Ga, 2, 0);
    insere_vertice_direcionado_grafo_adj(Ga, 2, 4);

    // 3
    insere_vertice_direcionado_grafo_adj(Ga, 3, 2);

    // 4
    insere_vertice_direcionado_grafo_adj(Ga, 4, 3);

    // 5
    insere_vertice_direcionado_grafo_adj(Ga, 5, 4);

    printf("\nLista de adjacências:\n");
    imprime_grafo_adj(Ga);

    liberar_grafo_adj(Ga);
    liberar_grafo_mat(Gm);
}

/* */
int main()
{
    questao1();
    questao2();

    return 0;
}