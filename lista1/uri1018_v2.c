
#include <stdio.h>
int main() {

int valor,troco, A , B , C , D , E , F;

scanf("%d",&valor);
troco = valor;
A= troco / 100;
troco = troco - (A *100);
B = troco / 50;
troco = troco - (B* 50);
C = troco / 20;
troco = troco - (C* 20);
D = troco /10;
troco = troco -(D * 10);
E = troco / 5;
troco = troco - (E* 5);
F= troco / 2;
troco = troco - (F* 2);
printf("%d\n",valor);
printf("%d nota(s) de R$ 100,00\n",A);
printf("%d nota(s) de R$ 50,00\n",B);
printf("%d nota(s) de R$ 20,00\n",C);
printf("%d nota(s) de R$ 10,00\n",D);
printf("%d nota(s) de R$ 5,00\n",E);
printf("%d nota(s) de R$ 2,00\n",F);
printf("%d nota(s) de R$ 1,00\n",troco);

return 0;
}

