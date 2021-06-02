#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int nasc;
   int rg;
   char nome[20];
   char profissao[20];
   struct node *next;
};

struct node *cabeca = NULL;
struct node *atual = NULL;

void printList() {
   struct node *ptr = cabeca;
   printf("\n[ ");
   while(ptr != NULL) {
      printf("(%d,%d, %s, %s ) ",ptr->rg,ptr->nasc, ptr->nome[20],ptr->profissao[20] );
      ptr = ptr->next;
   }
	
   printf(" ]");
}

void insertFirst(int rg, int nasc, char nome, char profissao) {
   struct node *link = (struct node*) malloc(sizeof(struct node));	
   link->rg = rg;
   link->nasc = nasc;
   link->nome = nome;
	link->profissao = profissao;
   link->next = cabeca;
	
   cabeca = link;
}

struct node* deleteFirst() {

   struct node *tempLink = cabeca;
	
   cabeca = cabeca->next;
	
   return tempLink;
}

bool isEmpty() {
   return cabeca == NULL;
}

int length() {
   int length = 0;
   struct node *atual;
	
   for(atual = cabeca; atual != NULL; atual = atual->next) {
      length++;
   }
	
   return length;
}

struct node* find(int rg) {

   struct node* atual = cabeca;

   if(cabeca == NULL) {
      return NULL;
   }
   while(atual->rg != rg) {
	
      if(atual->next == NULL) {
         return NULL;
      } else {
         atual = atual->next;
      }
   }      
	
   return atual;
}

struct node* delete(int rg) {

   struct node* atual = cabeca;
   struct node* previous = NULL;
	
   if(cabeca == NULL) {
      return NULL;
   }
   while(atual->rg != rg) {
      if(atual->next == NULL) {
         return NULL;
      } else {
         previous = atual;
         atual = atual->next;
      }
   }
   if(atual == cabeca) {
      cabeca = cabeca->next;
   } else {
      previous->next = atual->next;
   }    
   return atual;
}

void main() {
   insertFirst(1,10061999, "luis", "marcineiro" );
   insertFirst(2,20061989, "elias", "estudante" );
   insertFirst(3,30061996, "joana", "motorista" );
   insertFirst(4,1061979, "claudio", "artista");
   insertFirst(5,40061991, "ana", "programadora" );
   insertFirst(6,56061969, "maria", "dentista" ); 

   printf(" Lista Original: "); 
   printList();

   while(!isEmpty()) {            
      struct node *temp = deleteFirst();
      printf("\ valor deletado:");
      printf("(%d,%d) ",temp->rg,temp->nasc);
   }  
	
   printf("\nLista com todos os items deletados: ");
   printList();
 insertFirst(1,10061999, "luis", "marcineiro" );
   insertFirst(2,20061989, "elias", "estudante" );
   insertFirst(3,30061996, "joana", "motorista" );
   insertFirst(4,1061979, "claudio", "artista");
   insertFirst(5,40061991, "ana", "programadora" );
   insertFirst(6,56061969, "maria", "dentista" ); 
   
   printf("\n Lista restaurada : ");
   printList();
   printf("\n");  

   struct node *foundLink = find(4);
	
   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->rg,foundLink->nasc, foundLink->nome[20],foundLink->profissao[20] );
      printf("\n");  
   } else {
      printf("elemento não encontrado.");
   }

   delete(4);
   printf("Lista depois de deletar um item : ");
   printList();
   printf("\n");
   foundLink = find(4);
	
   if(foundLink != NULL) {
      printf("Elemento encontrado: ");
      printf("(%d,%d) ",foundLink->rg,foundLink->nasc, foundLink->nome[20],foundLink->profissao[20]);
      printf("\n");
   } else {
      printf("Elemento nao encontrado.");
   }
	
   printf("\n");
   printList();
	
}