#include<stdio.h>

int main(){
    char palavra[200];
    printf("Insira uma palavra: ");
    //scanf("%s", palavra);
    strcpy(palavra, "Como detectar a maior palavra de uma string");
    int tamanho = strlen(palavra);

    int maior=0, ini=0; //variaveis da maior palavra
    int cont=0, temp_ini=0; //variaveis do temporario
    int i;
    for (i = 0; i <=tamanho; i++){
        //se a frase terminou ou a palavra terminou
        if(i==tamanho || palavra[i] == ' '){
            if(maior<cont){
                maior=cont;
                ini=temp_ini;
            }
            cont=0;
            temp_ini=i+1;
        }
        else{
            cont++;
        }
    }

    printf("\nMaior palavra: ", ini);
    for (i = ini; i <ini+maior; i++)
        printf("%c", palavra[i]);
    return 0;
}