#pragma once

#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA
{
    int id;           /*Identificador armazenado no nó. */
    int weight;       /* Peso da aresta */
    struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA
{
    int E;     /* Quantidade de arestas. */
    int V;     /* Quantidade de vértices. */
    NoA **Adj; /* Lista de adjacências. */
} GrafoA;

/*Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM
{
    int E;     /* Quantidade de arestas. */
    int V;     /* Quantidade de vértices. */
    int **Mat; /* Matrix de adjacências. */
} GrafoM;

GrafoA *criar_grafo_adj(int tamanho);
GrafoM *criar_grafo_mat(int tamanho);
void liberarNo(NoA *no);
void liberar_grafo_adj(GrafoA *G);
void liberar_grafo_mat(GrafoM *G);
void insere_aresta_direcionado_grafo_mat(GrafoM *G, int vertice1, int vertice2, int peso);
void insere_aresta_nao_direcionado_grafo_mat(GrafoM *G, int vertice1, int vertice2, int peso);
void imprime_grafo_mat(GrafoM *G);
NoA *criaNo(int info, int peso);
void insere_aresta_direcionado_grafo_adj(GrafoA *G, int vertice1, int vertice2, int peso);
void insere_aresta_nao_direcionado_grafo_adj(GrafoA *G, int vertice1, int vertice2, int peso);
void imprime_grafo_adj(GrafoA *G);
void contar_arestas_incidents_mat(GrafoM *G, int vertice);
void contar_arestas_incidentes_adj(GrafoA *G, int vertice);
void contar_arestas_que_saem_mat(GrafoM *G, int vertice);
void contar_arestas_que_saem_adj(GrafoA *G, int vertice);
void listar_vertices_adjacentes_mat(GrafoM *G, int vertice);
void listar_vertices_adjacentes_adj(GrafoA *G, int vertice);