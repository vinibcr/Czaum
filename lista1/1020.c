#include <stdio.h>
int main(){
 double N;
 int cem , cinquenta , vinte , dez , cinco , dois;
 int umr,cinquentac , vintecincoc , dezc , cincoc ,umc;
 int troco,centavos;
 scanf("%lf",&N);
 troco = (N);
 centavos = ((N - troco) * 100);
 cem = troco / 100;
 troco = troco - (cem * 100);
 cinquenta = troco / 50;
 troco = troco - (cinquenta * 50);
 vinte = troco / 20;
 troco = troco - (vinte * 20);
 dez = troco / 10;
 troco = troco -(dez * 10);
 cinco = troco / 5;
 troco = troco - (cinco * 5);
 dois = troco / 2;
 troco = troco - (dois * 2);
 umr = troco / 1;
 
 cinquentac = centavos / 50;
 centavos = centavos % 50;
 vintecincoc = centavos / 25;
 centavos = centavos % 25;
 dezc = centavos / 10;
 centavos = centavos % 10;
 cincoc = centavos / 05;
 centavos = centavos % 05;
 umc = centavos / 1;
 printf("NOTAS:\n");
 printf("%d nota(s) de R$ 100.00\n",cem);
 printf("%d nota(s) de R$ 50.00\n",cinquenta);
 printf("%d nota(s) de R$ 20.00\n",vinte);
 printf("%d nota(s) de R$ 10.00\n",dez);
 printf("%d nota(s) de R$ 5.00\n",cinco);
 printf("%d nota(s) de R$ 2.00\n",dois);
 printf("MOEDAS:\n");
 printf("%d moeda(s) de R$ 1.00\n",umr);
 printf("%d moeda(s) de R$ 0.50\n",cinquentac);
 printf("%d moeda(s) de R$ 0.25\n",vintecincoc);
 printf("%d moeda(s) de R$ 0.10\n",dezc);
 printf("%d moeda(s) de R$ 0.05\n",cincoc);
 printf("%d moeda(s) de R$ 0.01\n",umc);
 return 0;
}
