//Vinicius Crepaldi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define MAX 10
#include <locale.h>
void mostraMatriz(double m[MAX][MAX], int tam){
    int i,j;
    for(i=0;i<tam;i++){
        printf("|");
        for(j=0;j<tam;j++){
            printf(" %.1lf",m[i][j]);
        }
        printf(" |\n");
    }    
}
//---------------------------------------------------------------------------------------------------------------------

void triangularInferior(double m[MAX][MAX], int tam, double b[MAX]){
	
	int i, j;
	double y[MAX], soma =0.0;
	
	
	y[0] = b[0]/m[0][0];
	
	for(i=1; i<=tam;i++){
	  soma=0.0;
	  for(j=0;j<i;j++) soma+=(m[i][j]*y[j]);
	  
	   y[i]=(b[i]-soma)/m[i][i];
   	  
	}
	
	
	for( i=0; i<tam;i++)
		printf("\n y %d = %.1lf", i+1, y[i]);
	
	
	getch();
}
//---------------------------------------------------------------------------------------------------------------------

void triangularSuperior(double m[MAX][MAX], int tam, double y[MAX]){
	
	int i, j, cont=0, a, z=1;
	double m2[MAX][MAX], x[MAX], aux[MAX], soma =0.0, aux2[MAX];
	
	for (i=0;i<tam;i++){
      a=tam-1;
	      for (j=0;j<tam;j++){
		      m2[i][j] = m[tam-z][a];
		      a--;
	      }
	      z++;
   }

   for (i=tam-1;i>=0;i--){
      aux[cont]= y[i];
	  cont++;    
   }
	
	
	x[0] = aux[0]/m2[0][0];
	
	for(i=1; i<=tam;i++){
	  soma=0.0;
	  for(j=0;j<i;j++){
		soma+=(m2[i][j]*x[j]);  
	  } 
	  
	  x[i]=(aux[i]-soma)/m2[i][i];   	      
	}
	cont=0;
	 for (i=tam-1;i>=0;i--){
      aux2[cont]= x[i];
	  cont++;    
   }

	for( i=0; i<tam;i++)
		printf("\n x %d = %.1lf", i+1, aux2[i]);

		getch();
}

//---------------------------------------------------------------------------------------------------------------------
void LU(double m[MAX][MAX], int tam, double b[MAX] ){
    
    int i,j, c=0;
    double a[MAX][MAX],aux[MAX][MAX];  
    double y[MAX], soma =0.0;
		
    
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            a[i][j]=0;
            aux[i][j]= m[i][j]; 
        }
    }
   
    for(j=0;j<tam;j++){      

        for(i=j+1;i<tam;i++){
            if(aux[i][j]==0)
            {
                printf("");
            }else
             {
                a[i][j]=aux[i][j]/aux[j][j];
                c=0;
                
                for(c=j;c<tam;c++)
                    aux[i][c]=aux[i][c]+aux[j][c]*(-1*(a[i][j]));                                      
            }      
            printf("\n");
        }
             
    }
    printf("\n\n*********RESULTADO FINAL**********\n");
    for(i=0;i<tam;i++) a[i][i]=1;
    printf("\n----Matriz L----\n");
    mostraMatriz(a, tam);
   
    printf("\n----Matriz U----\n");
    mostraMatriz(aux, tam);
   
    printf("\nLy = b\n");
    printf("Resultado: ");	
 	y[0] = b[0]/a[0][0];
	
	for(i=1; i<=tam;i++){
	  soma=0.0;
	  for(j=0;j<i;j++) soma+=(a[i][j]*y[j]);	  
	   y[i]=(b[i]-soma)/a[i][i];
	}
		for( i=0; i<tam;i++)
		printf("\n y %d = %.1lf", i+1, y[i]);

	
	
	 printf("\n\nUx = y\n");
    printf("Resultado: ");
    triangularSuperior(aux, tam, y);
   
  	getch();
		
}


//---------------------------------------------------------------------------------------------------------------------

void Determinante(double m2[MAX][MAX], int tam){
	int i, j, k, cont = 0;
    double aux=0.0, b=0.0, m[MAX][MAX] ;
	
	for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            m[i][j]=m2[i][j]; 
        }
    }
	
	
	for(i = 0; i < tam - 1; i++)
    {
        if(m[i][i] == 0)
        {
            for(k = i; k < tam; k++)
            {
                if(m[k][i] != 0)
                {
                    for(j = 0; j < tam; j++)
                    {
                        aux = m[i][j];
                        m[i][j] = m[k][j];
                        m[k][j] = aux;
                    }
                    k = tam;
                }
            }
            cont++;
        }
        else
        {
            for(k = i + 1; k < tam; k++)
            {
                b = -1 * m[k][i] / m[i][i];
                for(j = i; j < tam; j++)
                {
                    m[k][j] = m[k][j] + (b * m[i][j]);
                }
            }
        }
    }
    aux =1;
	for(i = 0; i < tam; i++){    
		aux *= m[i][i];     
	}
        
    printf("\nDeterminante = ");
    if(cont % 2 == 0)
        printf("%.1lf \n", aux);
    else
        printf("%.1lf \n", -1 * aux);
    
    	getch();
}

//---------------------------------------------------------------------------------------------------------------------

void Inversa(double m[MAX][MAX], int tam){
	int i, j;
	double m2[MAX][MAX];
	
	
	
	 for (i=0;i<tam;i++){
      for (j=0;j<tam;j++){
      m2[j][i] = m[i][j];
      }
  }
	
	printf("\n----Matriz Invertida----\n");
	for (i=0;i<tam;i++){
    	for (j=0;j<tam;j++){
      	  printf("%.1lf ",m2[i][j]);
		}
    printf("\n");
    } 
 	getch();
}

//---------------------------------------------------------------------------------------------------------------------

void gaussCompacto(double m[MAX][MAX], int tam, double b[MAX]){
	 int i,j, c=0;
    double a[MAX][MAX],aux[MAX][MAX];  
    double b2[MAX], soma =0.0;
		
    
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            a[i][j]=0;
            aux[i][j]= m[i][j]; 
        }
    }
   
    for(j=0;j<tam;j++){      

        for(i=j+1;i<tam;i++){
            if(aux[i][j]==0)
            {
                printf("");
            }else
             {
                a[i][j]=aux[i][j]/aux[j][j];
                c=0;
                
                for(c=j;c<tam;c++)
                    aux[i][c]=aux[i][c]+aux[j][c]*(-1*(a[i][j]));                                      
            }      
            printf("\n");
        }
             
    }
    
    b2[0] = b[0];
    
    for(i=1;i<tam;i++){
    	soma = 0.0;
    	for(j=0;j<i;j++){
			soma= soma + (a[i][j] * b2[j]);
		} 
		b2[i]= b[i] - soma;		
    }
    
    printf("\n----Matriz U----\n");
    mostraMatriz(aux, tam);
    printf("\n");
     printf("\n---- b' ----\n");
    for(j=0;j<tam;j++)
		printf("b' %d = %.1lf\n", j, b2[j]);		 
    printf("\n");
    
    printf("Resultado: ");
    triangularSuperior(aux, tam, b2);
    
    
    
    getch();
}

//---------------------------------------------------------------------------------------------------------------------

void menu (char *opcao)
{
  system ("cls");
  printf ("\n    OPÇÕES ");
  printf ("\n 1 - Calcular Determinante");
  printf ("\n 2 - Triangular Inferior");
  printf ("\n 3 - Triangular Superior");
  printf ("\n 4 - Decomposicao LU");
  printf ("\n 5 - Gauss Compacto");
  printf ("\n 6 - Matriz Inversa");
  printf ("\n 7 - Sair");
  printf ("\n\n Resp == ");
  do {
    *opcao = getch();
  } while (*opcao < '1' || *opcao > '7'); 
  printf ("%c",*opcao);   
}   

//---------------------------------------------------------------------------------------------------------------------
int main()
{ 
	setlocale(LC_ALL, "Portuguese");
  int tam, i, j, k, cont = 0;
  double m[MAX][MAX], b[MAX];
  char opcao;
  
  printf("Insira o tamanho da matriz: ");
  scanf("%d",&tam);
  
  for(i=0; i<tam;i++){
	  printf("\nInsira o elemento %d do termo independente = ", i+1);
	  scanf("%lf",&b[i]); 	  
  }
 
  
  printf("\nInsira os elementos da Matriz\n");
  for (i=0;i<tam;i++){
      for (j=0;j<tam;j++){
      printf("M[%d][%d] = ",i+1,j+1);
      scanf("%lf",&m[i][j]);
      }
  }
  
  
  
  
  do{
    menu(&opcao);
	printf("\n----Matriz Principal----\n");
    mostraMatriz(m, tam);
    switch (opcao) 
	{
      case '1': Determinante(m, tam);
                break;
      case '2': triangularInferior(m, tam, b);
                break;
      case '3': triangularSuperior(m, tam, b);
                break;
      case '4': LU(m, tam, b);
                break;
      case '5': gaussCompacto(m, tam, b);
                break;  
	  case '6': Inversa(m, tam);
                break;     
	  case '7': break;
      default: printf ("\nOpção inválida\n");
    }
  } while (opcao != '6');

 	return 0;
}
