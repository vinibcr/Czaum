#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	char nomes[30][20], aux[20];
	int i, j;
for (i = 0; i < 30; i++) {
   printf("\nNome %i: ", i+1);
   scanf("%s", nomes[i]);
}

for (i = 1; i < 30; i++) { /* 3 = qtde de palavras */
   for (j = 1; j < 30; j++) {
      // verifica se tem que ser depois, se for troca de posição
      if (strcmp(nomes[j - 1], nomes[j]) > 0) {
         strcpy(aux, nomes[j - 1]);
         strcpy(nomes[j - 1], nomes[j]);
         strcpy(nomes[j], aux);
      }
   }
}

// só mostrar a matriz
for (i = 0; i < 30; i++)
   printf("\n%s", nomes[i]);
	return 0;
}
