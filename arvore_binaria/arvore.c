#include "arvore.h"


Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}

int arv_tem_filhas(Arvore *a) {
    return (a->dir || a->esq); 
}

//========= Exercício 2 - pré-ordem ====
void percorre_pre_ordem(Arvore *a) {
    if (!verifica_arv_vazia(a)) {
        printf("%c", a->info);
        percorre_pre_ordem(a->esq);
        percorre_pre_ordem(a->dir);
    }
}

//========= Exercício 2 - in-ordem ====
void percorre_in_ordem(Arvore *a) {
    if (!verifica_arv_vazia(a)) {
        percorre_in_ordem(a->esq);
        printf("%c", a->info);
        percorre_in_ordem(a->dir);
    }
}

//========= Exercício 2 - pós-ordem ====
void percorre_pos_ordem(Arvore *a) {
    if (!verifica_arv_vazia(a)) {
        percorre_pos_ordem(a->esq);
        percorre_pos_ordem(a->dir);
        printf("%c", a->info);
    }
}

//========= Exercício 3 - pertence ====
int pertence_arv(Arvore *a, char c) {
    if (!verifica_arv_vazia(a)) {
        if (a->info == c) return 1;
        return (pertence_arv(a->esq, c) || pertence_arv(a->dir, c));
    }

    return 0;
}

//========= Exercício 4 - conta nós ====
int conta_nos (Arvore *a) {
    int cont = 0;
    if (!verifica_arv_vazia(a)) {
        cont++;
        cont += conta_nos(a->esq);
        cont += conta_nos(a->dir);
    }

    return cont;
}

//========= Exercício 5 - calcula altura ====
int calcula_altura_arvore (Arvore *a) {
    int altura = 1, aux_d, aux_e;
    if (!verifica_arv_vazia(a)) {
        aux_e = calcula_altura_arvore(a->esq);
        aux_d = calcula_altura_arvore(a->dir);

        altura = aux_e > aux_d ? altura + aux_e : altura + aux_d;
        return altura;
    }

    return -1;
}

//========= Exercício 6 - conta folhas ====
int conta_nos_folha (Arvore *a) {
    int qtd_folhas = 0;

    if (!verifica_arv_vazia(a)) {
        if (!arv_tem_filhas(a)) 
            qtd_folhas++;

        qtd_folhas += conta_nos_folha(a->esq);
        qtd_folhas += conta_nos_folha(a->dir);
    }

    return qtd_folhas;
}


int main (int argc, char *argv[]) {

   Arvore *a = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );	

    printf("Pré ordem: "); percorre_pre_ordem(a); // abdcef
    printf("\nPós ordem: "); percorre_pos_ordem(a); // dbefca
    printf("\nIn ordem: "); percorre_in_ordem(a); // bdaecf
    printf("\n");

    printf("O caracter 'g' pertence à arvore: %s\n", pertence_arv(a, 'g') ? "sim" : "não");
    printf("A árvore tem: %i nós\n", conta_nos(a));
    printf("A árvore tem altura: %i\n", calcula_altura_arvore(a));
    printf("A árvore tem: %i nós folha\n", conta_nos_folha(a));
    
   arv_libera (a);

   return 0;
}
