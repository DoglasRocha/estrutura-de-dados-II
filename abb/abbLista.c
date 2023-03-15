#include "abbLista.h"

Arvore* cria_arvore_vazia (void) {
   return NULL;
}

void arvore_libera (Arvore* a) {
   if (a != NULL) {
      arvore_libera (a->esq);
      arvore_libera (a->dir);
      free(a);
   }
}

//========= Q1 - inserir
Arvore* inserir (Arvore *a, int v) {
   if (a == NULL) {
       a = (Arvore *) malloc(sizeof(Arvore));
       a->info = v;
       a->esq = a->dir = NULL;
   }
   else if (v < a->info) 
       a->esq = inserir(a->esq, v);

   else
        a->dir = inserir(a->dir, v);

   return a;
}

//========= Q1 - remover
Arvore* remover (Arvore *a, int v) {
    if (a == NULL)
        return a;

    else if (v > a->info)
        a->dir = remover(a->dir, v);

    else if (v < a->info)
        a->esq = remover(a->esq, v);

    else if (a->esq == NULL && a->dir == NULL) {
        free(a);
        a = NULL;
    }
    else if (a->esq == NULL) {
        Arvore *tmp = a;
        a = a->dir;
        free(tmp);
    }   
    else if (a->dir == NULL) {
        Arvore *tmp = a;
        a = a->esq;
        free(tmp);
    }
    else {
        Arvore *tmp = a->esq;
        while (tmp->dir != NULL)
            tmp = tmp->dir;
        a->info = tmp->info;
        tmp->info = v;
        a->esq = remover(a->esq, v);
    }

   return a;
}


//========= Q1 - busca
int buscar (Arvore *a, int v) {
    if (a == NULL)
        return 0;

    else if (v < a->info)
        return buscar(a->esq, v);

    else if (v > a->info)
        return buscar(a->dir, v);
  
    return 1; 
}

//========= Q2 - min =====
int min(Arvore *a) {
    while (a->esq != NULL) 
        a = a->esq;

    return a->info;
}

//========= Q2 - max =====
int max(Arvore *a) {
    while (a->dir != NULL)
        a = a->dir;

    return a->info;
}

//========= Q3 - imprime_decrescente =====
void imprime_decrescente (Arvore *a) {
    if (a != NULL) {
        imprime_decrescente(a->dir);
        printf("%d ", a->info);
        imprime_decrescente(a->esq);
    }
}

//========= Q4 - maior ramo =====
int getMax(int v1, int v2) {
    return v1 > v2 ? v1 : v2;
}

int maior_ramo (Arvore *a) {
    if (a != NULL) 
        return a->info + getMax(maior_ramo(a->esq), maior_ramo(a->dir));

    return 0;
}

void pre_order (Arvore* a) {
   if (a != NULL) {
      printf("%d ", a->info);
      pre_order (a->esq);
      pre_order (a->dir);
   } 
}

int main () {

   int i;

    Arvore *a = cria_arvore_vazia();
    a = inserir(a, 50);
    a = inserir(a, 30);
    a = inserir(a, 90);
    a = inserir(a, 20);
    a = inserir(a, 40);
    a = inserir(a, 95);
    a = inserir(a, 10);
    a = inserir(a, 35);
    a = inserir(a, 45);
    
    printf("\n");
    printf("Imprimindo em pré ordem: ");
    pre_order (a);	
    printf("\n");

    printf("Minimo: %d, Máximo: %d\n", min(a), max(a));

    printf("\n");
    printf("Imprimindo em ordem descrescente: ");
    imprime_decrescente(a);	
    printf("\n");

    printf("Soma do maior ramo: %d\n", maior_ramo(a));

    // ====== Q5 ======
    clock_t inicio;

    // em ordem
    Arvore *b;
    for (int i = 0; i < 99999; i++)
        b = inserir(b, i);

    inicio = clock();
    buscar(b, 100000);
    printf("Tempo de busca em árvore degenerada: %fs\n",
        (double) (clock() - inicio) / CLOCKS_PER_SEC);

    // aleatorio
    Arvore *c;
    srand(time(NULL));

    for (int i = 0; i < 99999; i++)
        c = inserir(c, rand() % 100000);

    inicio = clock();
    buscar(c, 100000);
    printf("Tempo de busca em árvore aleatória: %fs\n",
        (double) (clock() - inicio) / CLOCKS_PER_SEC);

    /* a árvore em que são inseridos os valores em ordem crescente se 
    torna uma árvore degenerada, com complexidade O(n) */
    /* já a arvore em que são inseridos os valores em ordem aleatória 
    tem uma distribuição, o que não a torna degenerada,
    possibilitando uma pesquisa mais rápida */

   return 0;
}

