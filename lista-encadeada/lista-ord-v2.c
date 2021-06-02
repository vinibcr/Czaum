#include <stdlib.h>
typedef struct reg *no;
struct reg {
           int info;
           struct reg *prox;
};
no lista;
//------------------------------------------------------   
// Cria uma lista vazia
//------------------------------------------------------
void cria_lista (no *lista) {
  *lista = NULL;
} 
//------------------------------------------------------
// Mostra os elementos da lista
//------------------------------------------------------
void mostra_lista (no lista) {
  no p = lista;
  printf ("\n\nElementos da lista: ");
  while (p) {  // while (p != NULL)
    printf ("%d ",p->info);
    p = p->prox;
  }
}
//------------------------------------------------------
// Inclui um elemento numa lista ordenada
//------------------------------------------------------
void inclui_ordenada (no *lista, int info){
  // criacao do no
  no p = (no) malloc(sizeof(struct reg));
  p->info = info;
  // se lista for vazia ou elemento menor que o primeiro elemento da lista
  if (*lista == NULL || info <= (*lista)->info){
    p->prox = *lista;
    *lista = p;
  }     
  else {
    no q = *lista, r;
    while (q != NULL && q->info < info){
      r = q;
      q = q->prox;
    }      
    p->prox = q; 
    r->prox = p;
  } 
}
//------------------------------------------------------
// Remove um elemento de uma lista simplesmente encadeada ordenada
//------------------------------------------------------
int remove_elem_ordenada (no *lista, int elem) {
  if (!*lista || elem < (*lista)->info)
    return 0;
  if (elem == (*lista)->info) {
    no q = *lista;
    *lista = (*lista)->prox;
    free (q);
    return 1;
  }
  no q = *lista, r;
  do {
    r = q;        
    q = q->prox;
  } while (q != NULL && q->info < elem);
  if (q == NULL || q->info != elem)
    return 0;
  r->prox = q->prox;
  free (q);
  return 1;
}
//------------------------------------------------------
// Remove todos elementos de uma lista simplesmente encadeada ordenada
//------------------------------------------------------
int remove_todos_elem_ordenada (no *lista, int elem) {
  int achou = 0;
  if (!*lista || elem < (*lista)->info)
    return achou;
  while ((*lista)!= NULL && elem == (*lista)->info) {
    no q = *lista;
    *lista = (*lista)->prox;
    free (q);
    achou = 1;
  }
  no q = *lista, r;
  // Se elemento estiver no meio da lista
  while (q != NULL && q->info <= elem) {
    r = q;        
    q = q->prox;
    if (q!= NULL && q->info == elem){
      r->prox = q->prox;
      free (q);
      q = r;          
      achou = 1;
    }
  };
  return achou;
}
//------------------------------------------------------
// Programa Principal
//------------------------------------------------------
int main () {
  int info;
  char resp;
  cria_lista (&lista);
  do {
    printf ("\nDigite um numero inteiro: ");
    scanf ("%d",&info);
    inclui_ordenada (&lista,info);
    mostra_lista (lista);
    printf ("\n\n\nContinua (S/N)? ");   
    do {
      resp = toupper(getch());
    } while (resp!='N' && resp!='S');
  } while (resp!='N');
  mostra_lista (lista);
  // Remove elementos na lista ordenada
  printf ("\n\nR E M O C A O");
  do {
    printf ("\n\nDigite o elemento que deseja remover: ");
    scanf ("%d",&info);
    if (remove_todos_elem_ordenada (&lista,info))
      printf ("-> %d removido.",info);
    else  
      printf ("-> elemento %d nao pertence a lista.",info);    
    mostra_lista (lista);
    printf ("\n\nContinua (S/N)? ");   
    do {
      resp = toupper(getch());
    } while (resp!='N' && resp!='S');
  } while (resp!='N');
  getch();
}      
