#include <stdlib.h>

typedef struct reg *no;
struct reg {
           int info;
           struct reg *prox;
};
//------------------------------------------------------
// Mostra os elementos da lista circular
//------------------------------------------------------
void mostra_lista (no lista) {
  if (lista == NULL) {
      printf ("\nLista vazia"); 
      return;          
  }   
  no p = lista;
  printf ("\nElementos da lista: ");
  do {
    printf ("%d ",p->info);
    p = p->prox;
  } while (p != lista);
 }
 //-------------------------------------------------
 // Conta o numero de elementos da lista circular
 //-------------------------------------------------
int conta_nos (no lista) {
  if (lista == NULL)
     return 0;  
  no p = lista;
  int n=0;
  do {
    n++;
    p = p->prox;
  } while (p != lista);
  return n;
 }
//-------------------------------------------------
// Inclui um elemento no inicio da lista circular
//-------------------------------------------------
void inclui_inicio (no *lista, int info) {
  no p = (no) malloc(sizeof(struct reg));
  p->info = info;
  if (!*lista) {  // if (*lista == NULL)
       p->prox = p;
       *lista = p;
  }    
  else {
      no q = *lista;  // q deve ser posicionado no ultimo no da lista
      while (q->prox != *lista)
        q = q->prox;
      q->prox = p;
      p->prox = *lista;   
      *lista = p;
  }
}
//-------------------------------------------------
// Inclui um elemento no final da lista circular
//-------------------------------------------------
void inclui_final (no *lista, int info) {
  no p = (no) malloc(sizeof(struct reg));
  p->info = info;
  if (!*lista) {  // if (*lista == NULL)
       p->prox = p;
       *lista = p;
  }    
  else {
      no q = *lista;  // q deve ser posicionado no ultimo no da lista
      while (q->prox != *lista)
        q = q->prox;
      q->prox = p;
      p->prox = *lista;   
  }
}
//-------------------------------------------------
// Remove elemento do inicio da lista circular
//-------------------------------------------------
int remove_inicio (no *lista) {
  if (!*lista)
    return 0;
  if ((*lista)->prox == *lista) {  // lista com apenas um elemento
      free (*lista);
      *lista = NULL;                 
  }  
  else {
      no q = *lista;
      while (q->prox != *lista)
        q = q->prox;
      no p = *lista;
      *lista = p->prox;
      q->prox = *lista;
      free (p);
  }  
  return 1;
}
//-------------------------------------------------
int main () {
  int info;
  char resp;
  no lista = NULL;  
  do {
    printf ("\nDigite um numero inteiro: ");
    scanf ("%d",&info);
    inclui_final (&lista,info);
    mostra_lista (lista);
    printf ("\nContinua (S/N)?");
    do {
      resp = toupper(getchar());
    } while (resp!='N' && resp!='S');
  } while (resp!='N');
  mostra_lista (lista);
  printf ("\nQte de elementos da lista: %d",conta_nos(lista));
  remove_inicio (&lista);
  printf ("\n\nRemocao do 1o. elemento da lista realizada!\n");
  mostra_lista (lista);
  printf ("\nQte de elementos da lista: %d",conta_nos(lista));
}
