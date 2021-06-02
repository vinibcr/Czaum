
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void  Copia (FILE *A, FILE *B);
FILE *Abre (string prompt, string modo);

typedef char *string;

int main (void)
{
   printf ("Este programa faz uma cópia do arquivo dado.\n");
   FILE *A, *B;
   A = Abre ("Arquivo velho: ", "r");
   B = Abre ("Arquivo novo: ", "w");
   Copia (A, B);
   fclose (A);
   fclose (B);
   return EXIT_SUCCESS;
}

void Copia (FILE *A, FILE *B)
{
   int ch;
   while ((ch = getc (A)) != EOF)
       putc (ch, B);
}

FILE *Abre (string prompt, string modo)
{
   string nomeDoArq;
   FILE *resultado;
   while (true) {
       printf ("%s", prompt); 
       nomeDoArq = readLine (stdin);
       resultado = fopen (nomeDoArq, modo);
       if (resultado != NULL) break;
       printf ("Não posso abrir o arquivo %s\n", nomeDoArq);
   }
   return resultado;
}