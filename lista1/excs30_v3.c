#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
float salario;
float coeficiente;
printf("digite o salario:\n");
scanf("%f", &salario);
coeficiente= salario/100;
printf("o trabalhador recebe %f salarios minimos\n", coeficiente);




system("pause");
}
