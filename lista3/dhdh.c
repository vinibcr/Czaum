#include <stdio.h>
#include <math.h>

int primo(int x){
    int i, raiz;
    if(x<2){
        return 0;
	}
    if(x==2){
        return 1;
	}
    if(x%2==0){
        return 0;
	}
    raiz=sqrt(x);
    for(i=3; i<=raiz; i+=2){
        if(x%i==0){
            return 0;
		}
    }
    return 1;
}
int main()
{
    int X,a,N;
    scanf("%d", &N);
    for(a=1;a<=N;a++)
    {
        scanf("%d", &X);
        if(1==primo(X))
            printf("%d eh primo\n", X);
        else if(0==primo(X))
            printf("%d nao eh primo\n", X);
    }
    return 0;
}

