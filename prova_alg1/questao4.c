#include <stdio.h>
int main() {

int valor,troco, cem , cinquenta , vinte , dez , cinco , dois;
printf("digite o valor:\n");
scanf("%d",&valor);
if(valor>0){

troco = valor;
cem= troco / 100;
troco = troco - (cem *100);
cinquenta = troco / 50;
troco = troco - (cinquenta* 50);
vinte = troco / 20;
troco = troco - (vinte* 20);
dez = troco /10;
troco = troco -(dez * 10);
cinco = troco / 5;
troco = troco - (cinco* 5);
dois= troco / 2;
troco = troco - (dois* 2);
printf("Para %d, serao necessarias %d notas de 100, %d de 50, %d de 20, %d de 10, %d de 5, %d de 2 e %d de 1\n",valor, cem, cinquenta, vinte, dez, cinco, dois, troco);
printf("obrigado\n");
}else{
	printf("valor invalido\n");
}
return 0;
}

