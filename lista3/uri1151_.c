#include <stdio.h>
int main()
{
    int fibo;
	int cont;
	int num1=0;
	int num2=1;
	int numf=0;
    scanf("%d", &fibo);
    for(cont=1; cont<fibo; cont++){
        if(cont%2==1){
            printf("%d ",numf);
            numf=num1+num2;
            num1=numf;
        }
        else if(cont==2)
            printf("%d ",numf);
        else if(cont%2==0)
        {
            printf("%d ",numf);
            numf=num1+num2;
            num2=numf;
        }
    }
    printf("%d\n",numf);
    return 0;
}
