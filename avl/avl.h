#ifndef _AVL_H
#define _AVL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   // char chave // quest 1
   // int chave // quest 2
   char chave[10]; // quest 3
   int altura;
   struct node* esq;
   struct node* dir;
} No, Arvore;

int maior (int esq, int dir);

int altura (Arvore* a);

int atualizar_altura (Arvore *a);

int balanceamento (Arvore *a);

Arvore* rotacao_simples_esq (Arvore* a);

Arvore* rotacao_simples_dir (Arvore* a);

Arvore* rotacao_dupla_esq (Arvore* a);

Arvore* rotacao_dupla_dir (Arvore* a);

Arvore* atualizar_fb_dir (Arvore *a);

Arvore* atualizar_fb_esq (Arvore *a);

Arvore* inserir (Arvore *a, int chave);

Arvore* remover (Arvore *a, int chave);

void imprimir_in_order (Arvore* a, int nivel);

#endif
