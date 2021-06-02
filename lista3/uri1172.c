 #include <stdio.h>
int main()
{
    int v[10];
	int  cont;
	int k;
	
    for(k=0; k<10; k++){
        scanf("%d",&v[k]);
	}
    for(k=0; k<10; k++){
        if(v[k]<=0)
            v[k]=1;
    }
    for(k=0; k<10; k++)
        printf("X[%d] = %d\n",k,v[k]);
    return 0;
}
