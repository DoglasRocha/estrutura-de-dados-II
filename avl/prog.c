#include "avl.h"

int main () {

   Arvore *AVL = NULL;

   /*AVL = inserir (AVL, 'Q');
   AVL = inserir (AVL, 'Z');
   AVL = inserir (AVL, 'B');
   AVL = inserir (AVL, 'Y');
   AVL = inserir (AVL, 'T');
   AVL = inserir (AVL, 'M');
   AVL = inserir (AVL, 'E');
   AVL = inserir (AVL, 'W');
   AVL = inserir (AVL, 'X');
   AVL = inserir (AVL, 'S');
   AVL = inserir (AVL, 'F');
   AVL = inserir (AVL, 'G');
   AVL = inserir (AVL, 'A');
   AVL = inserir (AVL, 'H');
   AVL = inserir (AVL, 'N');
   AVL = inserir (AVL, 'O');
   AVL = inserir (AVL, 'P');
   AVL = inserir (AVL, 'R');

   //imprimir_in_order (AVL, 0);

   AVL = remover (AVL, 'A');
   AVL = remover (AVL, 'H');
   AVL = remover (AVL, 'E');
   AVL = remover (AVL, 'W');
   AVL = remover (AVL, 'G');
   AVL = remover (AVL, 'N');
   AVL = remover (AVL, 'P');
   AVL = remover (AVL, 'O');*/

   // 0
   AVL = inserir(AVL, 14);

   // 1
   AVL = inserir(AVL, 5);
   AVL = inserir(AVL, 28);

   // 2
   AVL = inserir(AVL, 2);
   AVL = inserir(AVL, 8);
   AVL = inserir(AVL, 18);
   AVL = inserir(AVL, 33);

   imprimir_in_order (AVL, 0);

   return 0;
}
