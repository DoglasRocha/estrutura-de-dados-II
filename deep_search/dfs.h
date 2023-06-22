#pragma once
#include "graph.h"

#define NIL -1
#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define VERMELHO 3

typedef struct dps
{
    int cor, descoberta, finalizacao, pai;
} DFS;

void inicializaNoBusca(DFS *no);
void busca_profundidade_arestas(GrafoA *G);
void DFS_visit_arestas(GrafoA *G, int atual, DFS *V, int *tempo);
void busca_profundidade_componentes(GrafoA *G);
void DFS_visit_componentes(GrafoA *G, int atual, DFS *V, int *tempo);
void busca_profundidade_bipartido(GrafoA *G);
void DFS_visit_bipartido(GrafoA *G, int atual, DFS *V, int *tempo);