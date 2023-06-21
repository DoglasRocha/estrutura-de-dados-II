#pragma once
#include "graph.h"

#define NIL -1
#define BRANCO 0
#define CINZA 1
#define PRETO 2

typedef struct dps
{
    int cor, descoberta, finalizacao, pai;
} DFS;

void inicializaNoBusca(DFS no);
void busca_profundidade(GrafoA *G);
void DFS_visit(GrafoA *G, int atual, DFS *V, int *tempo);