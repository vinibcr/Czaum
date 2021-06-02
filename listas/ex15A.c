#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char frase[100];
    int i,tamanho;

    printf("Informe uma frase\n");
    gets(frase);
    tamanho = strlen(frase);

    printf("\nFrase invertida:\n\n");
    for ( i = tamanho; i >= 0; i--)
    {
        printf ("%c",frase[i]);
    }
    printf("\n\n");
    system ("pause");
    return 0;
}
