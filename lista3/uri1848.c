#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
     char piscada[10];
	 int a = 3;
     int numero;
	 char caw[] = "caw";
     while(a--){
     	 numero = 0;

	     while(1){
	         scanf("%s", piscada);
	         scanf("%s", caw);

             if(!strcmp(piscada, caw)) 
			 break;

	         if(piscada[0] == '*') 
			 numero += 4;
	      	 if(piscada[1] == '*') 
			   numero += 2;
	      	 if(piscada[2] == '*') 
			   numero += 1;

	     } 

	     printf("%d\n", numero);
	 }

	 return 0;
}
