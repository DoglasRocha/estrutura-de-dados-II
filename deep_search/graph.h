#pragma once

#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA
{
    int id;           /*Identificador armazenado no nó. */
    struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA
{
    int E;     /* Quantidade de arestas. */
    int V;     /* Quantidade de vértices. */
    NoA **Adj; /* Lista de adjacências. */
} GrafoA;

GrafoA *criar_grafo_adj(int tamanho);
void liberarNo(NoA *no);
void liberar_grafo_adj(GrafoA *G);
NoA *criaNo(int info);
void insere_aresta_direcionada_grafo_adj(GrafoA *G, int origem, int destino);
void insere_aresta_nao_direcionada_grafo_adj(GrafoA *G, int vertice1, int vertice2);
void imprime_grafo_adj(GrafoA *G);
void contar_arestas_incidentes_adj(GrafoA *G, int vertice);
void contar_arestas_que_saem_adj(GrafoA *G, int vertice);
void listar_vertices_adjacentes_adj(GrafoA *G, int vertice);