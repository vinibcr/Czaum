#include<stdio.h>
#include<stdlib.h>
int main(){

char gabarito[10] = { 'b', 'd', 'a', 'c', 'a', 'b', 'd', 'a', 'c', 'a' };
char resp[10];
char aluno[20];
int qta=0;
int nota;
int y, i;


printf("Informe a quantidade de alunos: ");
scanf("%d", &qta);


for(i=1; i<=qta;i++){
nota=0;
printf("informe o nome do aluno:\n");
scanf(" %s", aluno);
for(y=0;y<10;y++){
printf("Informe a resposta da pergunta %d: ", y+1);
scanf("%s", &resp[y]);
}
for(y=0;y<10;y++){
if(resp[y]==gabarito[y])
{
nota = nota + 1;
}
}
printf("A nota do aluno  %s eh: %d\n\n", aluno, nota);
}

return 0;
}
