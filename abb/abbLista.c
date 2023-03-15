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

    if (a->esq == NULL && a->dir == NULL) {
        free(a);
        a = NULL;
    }
    else if ()

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


//========= Q2 - max =====

//========= Q3 - imprime_decrescente =====


//========= Q4 - maior ramo =====


void pre_order (Arvore* a) {
   if (a != NULL) {
      printf("%d ", a->info);
      pre_order (a->esq);
      pre_order (a->dir);
   } 
}

int main () {

   int i;

   Arvore *a = cria_arvore_vazia ();

   //inserir
   //....

   printf("\n");
   pre_order (a);	
   printf("\n");


   // ====== Q5 ====

   return 0;
}
