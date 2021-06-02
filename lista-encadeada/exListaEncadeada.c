/*
Angelo Monte Serrat Bonini R.A:191026077
*/

#include <stdio.h>
// #include <conio.h>
#include <string.h>
int main ()
{
int menu, k = 0, n,j,cont;
cont = 0;
struct cadastro {
char nome[20];
int rg;
char profissao[30];
char nasicmento[20];};
cadastro c[50], aux, c2[50];

while (menu!=5)
{

printf ("\n 1 - cadastrar usuaŕio\n 2 - atender usuaŕio\n 3 - listar usuarios na fila\n 4 - listar usuarios atendidos\n 5 - sair\n");
scanf ("%d", &menu);


switch (menu)
{
case 1:
fflush(stdin);

printf ("nome: ");
scanf ("%s", &c[k].nome);
printf ("rg: ");
scanf ("%d", &c[k].rg);
printf ("profissao: ");
scanf ("%s", &c[k].profissao);
printf ("Digite a data de nascimento: ");
scanf ("%d", &c[k].nasicmento[20]);
k++;
cont++;
break;

case 2:
fflush(stdin);
if(cont==0)
{
printf("Nao ha usuarios!");
}

else{
j=0;
while(j < k-1){
c2[j] = c[j];
c[j] = c[j+1];
j++;
}
k--;
cont--;
}
break;
case 3:
if(cont==0)
{
printf("Nao ha usuarios!");
}
else{

for (j=0; j<=k-1; j++)
printf ("\n nome: %s \n rg: %d \n profissao: %s\n data de nascimento: %d", c[j].nome, c[j].rg, c[j].profissao, c[j].nasicmento[20]);
}
break;
case 4:

for (k = 0; k <=cont-1; k++)
for (n = 0; n <=cont-1; n++)
{
if(strcoll(c2[n].nome, c2[n+1].nome) > 0)
{
aux =c2[n];
c2[n] = c2[n+1];
c2[n+1] = aux;
}
}
for (n=0; n<=k-1; n++)
printf ("\n nome: %s \n rg: %d \n profissao: %s\n data de nascimento: %d", c2[n].nome, c2[n].rg, c2[n].profissao, c2[n].nasicmento[20]);

break;

default:
if(menu!=5){
printf("Opcao invalida");
}
break;

}

}
}