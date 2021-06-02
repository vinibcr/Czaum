#include <stdio.h>
int main (){

  int tempo, PA, PB, cont = 0, f;
  float G1, G2;
  scanf("%d", &tempo);
  for (f = 0; f < tempo; f++) {
scanf("%d %d %f %f", &PA, &PB, &G1, &G2);

    while (PA <= PB && cont < 101){
      PA += (int)((PA*G1)/100);
      PB += (int)((PB*G2)/100);
      cont++;
    }
    if (cont > 100) {
      printf("Mais de 1 seculo.\n");
    }
    else {
      printf("%d anos.\n", cont);
    }
    cont = 0;
}
return 0;
}
