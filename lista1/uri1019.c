#include <stdio.h>
int main() {
int tempo, horas, converte, minutos, segundos;
converte=3600;
scanf("%d", &tempo);
horas=(tempo/converte);
minutos=(tempo -(converte*horas))/60;
segundos= (tempo-(converte*horas)-(minutos*60));
printf("%d:%d:%d\n",horas,minutos,segundos);
return 0;

}

