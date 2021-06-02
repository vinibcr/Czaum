#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main (){
float km, horas;
scanf("%f %f", &horas, &km);
printf("%.3f\n", km*horas/12);
return 0;
}
