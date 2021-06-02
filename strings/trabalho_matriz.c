#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int lin[50];
int col[50];
int quant = 0;
int soma = 10;
int subtrat = 20;
int produto = 30;


int ler (int matriz[50][50][50]){
   if(quant <= 9){
    int i, j;
  	printf("\ndigite o numero de linhas da matriz: ");
	scanf("%d", &lin[quant]);
	printf("\ndigite o numero de colunas da matriz: ");
	scanf("%d",&col[quant]);
	printf("\n");
	  for(i = 0; i < lin[quant]; i++)
	  {
	  	for (j = 0; j < col[quant]; j++)
		  {
	  		printf("matriz [%d][%d]: ", i+1, j+1);
	  		scanf("%d", &matriz[quant][i][j]);
	  	  }
      }
        quant++;
} else printf("\n numero maximo de matrizes alcancado\n");
}


int imprimir (int matriz[50][50][50]){
	int op, i, k, j, posic = 1;
	do { 
	printf("\n1. matrizes inseridas.\n");
	printf("2. matrizes somadas.\n");
	printf("3. matrizes subtradidas.\n");
	printf("4. matrizes multiplicadas.\n");
	printf("Qual opcao voce deseja:");
	scanf("%d", &op);
	   }while ((op > 4) || (op < 1));
	if (op == 1){
		if(quant > 0){
		  for(i = 0; i<quant;i++) {
		    printf("\n%d) matriz inserida: \n", i +1);
		    for (k = 0; k < lin[i]; k++) {
              for (j = 0; j < col[i]; j++)
               printf ("%3d ",matriz[i][k][j]);
               printf ("\n");
                                         }
                                   }
		              }else printf("nao existe  matriz");
	} else if(op == 2){
		if(soma > 10){
		  for(i = 10; i<soma;i++) {
		    printf("%d) matriz somada: \n", posic);
		    for (k = 0; k < lin[i]; k++) {
              for (j = 0; j < col[i]; j++)
               printf ("%3d ",matriz[i][k][j]);
               printf ("\n");
                                         }
            posic++;
                                   }
		              }else printf("nao existe matriz");

         	} else if(op == 3){
		if(subtrat > 20){
		  for(i = 20; i<subtrat;i++) {
		    printf("%d) matriz subtraida: \n", posic);
		    for (k = 0; k < lin[i]; k++) {
              for (j = 0; j < col[i]; j++)
               printf ("%3d ",matriz[i][k][j]);
               printf ("\n");
                                         }
            posic++;
                                   }
		              }else printf("nao existe matriz ");

         	} else if(op == 4){
		if(produto > 30){
		  for(i = 30; i<produto;i++) {
		    printf("%d) matriz multiplicada: \n", posic);
		    for (k = 0; k < lin[i]; k++) {
              for (j = 0; j < col[i]; j++)
               printf ("%3d ",matriz[i][k][j]);
               printf ("\n");
                                         }
            posic++;
                                   }
		              }else printf("\nnao existe matriz \n");

         	}
	
	
	}
	
int somamatriz ( int matriz [50][50][50]){
		int op, i, k, j, l, m, posic = 1, som1, som2, res, sair = 0;
        	if(quant > 0){
		    for(i = 0; i<quant;i++) {
		      printf("%d) matriz inserida: \n", i +1);
		       for (k = 0; k < lin[i]; k++) {
               for (j = 0; j < col[i]; j++)
                printf ("%3d ",matriz[i][k][j]);
                printf ("\n");
                                         }
                                   }
                            
   	do   {
	       do  {
		   printf("\nqual matrizes deseja somar?\nprimeira matriz:");
	       scanf("%d", &som1);
	         }while ((som1 > quant) ||  (som1 <1));
	       fflush(stdin);
	       do   {
		   printf("segunda matriz:");
	       scanf("%d", &som2);
	          }while((som2 > quant) || (som2 < 1));
	       if((col[som1 -1] != col[som2 -1]) || (lin[som1 -1] != lin[som2 - 1])){
	        printf("insira duas matrizes de mesma ordem");
	        printf("\ndeseja sair ? (1/0): ");
	        scanf("%d", &sair);}
	     }while(((col[som1 -1] != col[som2 -1]) || (lin[som1 -1] != lin[som2 - 1])) && (sair != 1));
	     if ( sair == 0){
	     lin[soma] = lin[som1-1];
	     col[soma] = col[som1 -1];
	      for (k = 0; k < lin[som1 -1]; k++) {
              for (j = 0; j < col[som1 -1]; j++){
                matriz[soma][k][j] = (matriz[som1 - 1][k][j] + matriz[som2 - 1][k][j]);
			   printf ("%3d ",matriz[soma][k][j]);}
               printf ("\n"); }
              soma ++;   	
		 }           
										
	 }else printf("\ninsira matriz\n");
}
		
int transposta (int matriz[50][50][50]){
	int op, i, k, j, l, m, posic = 1, transp;
	do { 
	printf("\n1. matrizes inseridas.\n");
	printf("2. matrizes somadas.\n");
	printf("3. matrizes subtradidas.\n");
	printf("4. matrizes multiplicadas.\n");
	printf("Qual opcao voce deseja:");
	scanf("%d", &op);
	   }while ((op > 4) || (op < 1));
	if (op == 1){
		if(quant > 0){
		  for(i = 0; i<quant;i++) {
		    printf("%d) matriz inserida: \n", i +1);
		    for (k = 0; k < lin[i]; k++) {
              for (j = 0; j < col[i]; j++)
               printf ("%3d ",matriz[i][k][j]);
               printf ("\n");
                                         }
                                   }
		  
                                 
            do {
			    printf("De qual matriz você deseja fazer a transposta ?: ");
			    fflush(stdin);
                scanf("%d", &transp);
			} while ((transp > quant) || (transp <= 0 ));
			  for (l = 0; l < col[transp - 1]; l++) {
              for (m = 0; m < lin[transp - 1]; m++)
               printf ("%3d ",matriz[transp - 1][m][l]);
               printf ("\n");
                                         }
                                   
			  
		              }else printf("\nnao existe matriz\n");
	} else if(op == 2){
		if(soma > 10){
		  for(i = 10; i<soma;i++) {
		    printf("%d) matriz somada: \n", posic);
		    for (k = 0; k < lin[i]; k++) {
              for (j = 0; j < col[i]; j++)
               printf ("%3d ",matriz[i][k][j]);
               printf ("\n");
                                         }
            posic++;}
            		  
                                 
            do {
			    printf("De qual matriz você deseja fazer a transposta ?: ");
			    fflush(stdin);
                scanf("%d", &transp);
			} while ((transp > soma - 10) || (transp <= 0 ));
			  for (l = 0; l < col[transp + 9]; l++) {
              for (m = 0; m < lin[transp + 9]; m++)
               printf ("%3d ",matriz[transp + 9][m][l]);
               printf ("\n");
                                         }
                                   
		              }else printf("\nnao existe matriz \n");

         	} else if(op == 3){
		if(subtrat > 20){
		  for(i = 20; i<subtrat;i++) {
		    printf("%d) matriz subtraida: \n", posic);
		    for (k = 0; k < lin[i]; k++) {
              for (j = 0; j < col[i]; j++)
               printf ("%3d ",matriz[i][k][j]);
               printf ("\n");
                                         }
            posic++;
                                   }
                                   do {
			    printf("De qual matriz você deseja fazer a transposta ?: ");
			    fflush(stdin);
                scanf("%d", &transp);
			} while ((transp > subtrat - 20) || (transp <= 0 ));
			  for (l = 0; l < col[transp + 19]; l++) {
              for (m = 0; m < lin[transp + 19]; m++)
               printf ("%3d ",matriz[transp + 19][m][l]);
               printf ("\n");
                                         }
		              }else printf("\nnao existe matriz \n");

         	} else if(op == 4){
		if(produto > 30){
		  for(i = 30; i<produto;i++) {
		    printf("%d) matriz multiplicada: \n", posic);
		    for (k = 0; k < lin[i]; k++) {
              for (j = 0; j < col[i]; j++)
               printf ("%3d ",matriz[i][k][j]);
               printf ("\n");
                                         }
            posic++;
                                   }
                                   do {
			    printf("De qual matriz você deseja fazer a transposta ?: ");
			    fflush(stdin);
                scanf("%d", &transp);
			} while ((transp > produto - 30) || (transp <= 0 ));
			  for (l = 0; l < col[transp + 29]; l++) {
              for (m = 0; m < lin[transp + 29]; m++)
               printf ("%3d ",matriz[transp + 29][m][l]);
               printf ("\n");
                                         }
		              }else printf("\nnao existe matriz\n");

         	}
	
	
	}	

int submatriz ( int matriz [50][50][50]){
		int op, i, k, j, l, m, posicao = 1, som1, som2, res,sair = 0;
        	if(quant > 0){
		    for(i = 0; i<quant;i++) {
		      printf("%d) matriz inserida: \n", i +1);
		       for (k = 0; k < lin[i]; k++) {
               for (j = 0; j < col[i]; j++)
                printf ("%3d ",matriz[i][k][j]);
                printf ("\n");
                                         }
                                   }
                            
   	do   {
	       do  {
		   printf("\nqual matrizes deseja subtrair?\nprimeira matriz:");
	       scanf("%d", &som1);
	         }while ((som1 > quant) ||  (som1 <1));
	       fflush(stdin);
	       do   {
		   printf("segunda matriz:");
	       scanf("%d", &som2);
	          }while((som2 > quant) || (som2 < 1));
	       if((col[som1 -1] != col[som2 -1]) || (lin[som1 -1] != lin[som2 - 1])){
	        printf("insira duas matrizes de mesma ordem");
	        printf("\ndeseja sair ? (1/0): ");
	        scanf("%d", &sair);}
	}   while(((col[som1 -1] != col[som2 -1]) || (lin[som1 -1] != lin[som2 - 1])) && (sair != 1));
	    if(sair == 0 )   {
	     lin[subtrat] = lin[som1-1];
	     col[subtrat] = col[som1-1];
	       for (k = 0; k < lin[som1 -1]; k++) {
              for (j = 0; j < col[som1 -1]; j++){
                matriz[subtrat][k][j] = (matriz[som1 - 1][k][j] - matriz[som2 - 1][k][j]);
			   printf ("%3d ",matriz[subtrat][k][j]);}
               printf ("\n"); }
              subtrat ++;   	
		 }                 
										
	 }else printf("\ninsira alguma matriz\n");
}
	
int multmatriz ( int matriz [50][50][50]){
		int op, i, k, j, s, mult1, mult2, res, sair = 0;
        	if(quant > 0){
		    for(i = 0; i<quant;i++) {
		      printf("%d matriz inserida: \n", i +1);
		       for (k = 0; k < lin[i]; k++) {
               for (j = 0; j < col[i]; j++)
                printf ("%3d ",matriz[i][k][j]);
                printf ("\n");
                                         }
                                   }
     do{                       
   	do   {
	       printf("qual matrizes deseja multiplicar?\nprimeira matriz:");
	       scanf("%d", &mult1);
	         }while ((mult1 > quant) ||  (mult1 <1));
	       fflush(stdin);
	       do   {
		   printf("segunda matriz:");
	       scanf("%d", &mult2);
	          }while((mult2 > quant) || (mult2 < 1));
	       if((col[mult1 -1] != lin[mult2 -1])){
	        printf("insira duas matrizes, no qual o numero de colunas da primeira matriz igual ao numero de linhas da segunda\n");
	        printf("\ndeseja sair ? (1/0): ");
	        scanf("%d", &sair);}
	     }while((col[mult1 -1] != lin[mult2 -1]) && (sair != 1));
	     if(sair == 0)  {
		 lin[produto] = lin[mult1 -1];
	     col[produto] = col [mult2 - 1];
	      for (k = 0; k < lin[mult1 -1]; k++) {
              for (j = 0; j < col[mult2 -1]; j++){
                for (s = 0; s < col[mult1 - 1]; s++)
                   matriz[produto][k][j] = matriz[produto][k][j] + (matriz[mult1 -1][k][s]*matriz[mult2 - 1][s][j]);
			    printf ("%3d ",matriz[produto][k][j]);}
               printf ("\n"); }
              produto++; }
		}else printf("\ninsira alguma matriz\n");
										
	 }

	 int matrizsim (int matriz [50][50][50]){
	 	int op, i, k, j, l, m, cont = 0, transp;
	 	if(quant > 0){
		  for(i = 0; i<quant;i++) {
		    printf("%d) matriz inserida: \n", i +1);
		    for (k = 0; k < lin[i]; k++) {
              for (j = 0; j < col[i]; j++)
               printf ("%3d ",matriz[i][k][j]);
               printf ("\n");
                                         }
                                   }
            do {
			    printf("qual matriz voce deseja ver se e simetrica?");
			    fflush(stdin);
                scanf("%d", &transp);
			} while ((transp > quant) || (transp <= 0 ));
			  for (l = 0; l < col[transp - 1]; l++) {
              for (m = 0; m < lin[transp - 1]; m++){
               if((matriz[transp - 1][m][l]) != (matriz[transp - 1][l][m]))
                 cont++;}
                                         }
             if (cont == 0)
              printf("Matriz e simetrica\n");
               else printf("matriz nao e simetrica");
		              }else printf("\ninsira alguma matriz\n");
	 }	 
	
	int quadradomagico (int matriz [50][50][50]){
		int op, i, k, j, cont = 0, quad, res [20],x, y = 0;
		for (x = 0; x < 20; x++)
		 res [x] = 0;
	 	if(quant > 0){
		  for(i = 0; i<quant;i++) {
		    printf("%d matriz inserida: \n", i +1);
		    for (k = 0; k < lin[i]; k++) {
              for (j = 0; j < col[i]; j++)
               printf ("%3d ",matriz[i][k][j]);
               printf ("\n");
                                         }
                                   }
            do {
			    printf("qual matriz voce deseja saber se e quadrado magico?: ");
			    fflush(stdin);
                scanf("%d", &quad);
			} while ((quad > quant) || (quad <= 0 ));
			
			if (lin[quad - 1] == col[quad -1]){
			   for (k = 0; k < lin[quad - 1]; k++) {
                 for (j = 0; j < col[quad - 1]; j++){
                 res[y] = res[y] + matriz[quad-1][k][j];
               
              	}
				  
				  if(res[y] == res[y-1])
				  cont++;
				  
				  y++;}
			
				  
			if(cont == (lin[quad -1] - 1)){
				 for (k = 0; k < lin[quad - 1]; k++) {
                 for (j = 0; j < col[quad - 1]; j++){
                 res[y] = res[y] + matriz[quad-1][j][k];
               
              	}
				  
				  if(res[y] == res[y-1])
				  cont++;
				  
				  y++;
				
			}
		}
			
			
			if (cont == (lin[quad - 1] + col[quad - 1] - 1)){
				for (k = 0; k < lin[quad - 1]; k++) {
                 for (j = 0; j < col[quad - 1]; j++){
                if(k == j) 
				res[y] = res[y] + matriz[quad-1][k][j];
			    if (k+j == (lin[quad-1] -1))
				 res[y+1] = res[y+1] + matriz[quad-1][k][j];}
				  
				  if(res[y] == res[y-1])
				  cont++;
				  if(res[y +1] == res[y-1])
				  cont++;
				
			}
				
			}	   
			if(cont == (lin[quad -1] + col [quad -1]+ 1)) 
			  printf("A matriz e um quadrado magico");
			else printf("a matriz nao e um quadrado magico");
	       	 
	
	}else printf(" insira uma matriz com o numero de linhas iguao ao de colunas");


	}else printf("insira alguma matriz");
}

	int  quadlatino(int matriz[50][50][50]){
	
	int i, j, k, matlat, conferir = 1, y, cont = 0;
	if(quant > 0){
		  for(i = 0; i<quant;i++) {
		    printf("%d matriz inserida: \n", i +1);
		    for (k = 0; k < lin[i]; k++) {
              for (j = 0; j < col[i]; j++)
               printf ("%3d ",matriz[i][k][j]);
               printf ("\n");
                                         }
                                   }
            do {
			    printf("qual matriz você deseja saber se e latina?: ");
			    fflush(stdin);
                scanf("%d", &matlat);
			} while ((matlat > quant) || (matlat <= 0 ));

            if(lin[matlat-1] == col [matlat -1]){
			  {for(k=0; k < lin[matlat-1]&& conferir == 1;k++){
			   for(y=0; y < col[matlat-1]; y++){
			    for(j=0; j < col[matlat-1] && conferir == 1;j++){
			    	if(y + 1 == matriz[matlat-1][k][j])
			    	cont++;}
			    		if(cont != 1)
			    	  conferir = 0;
			    	  cont = 0;
			
			
				}
			
				
				
			}
			
				 	  
			 for(k=0; k < lin[matlat-1]&& conferir == 1;k++){
			   for(y=0; y < col[matlat-1]; y++){
			    for(j=0; j < col[matlat-1] && conferir == 1;j++){
			    	if(y + 1 == matriz[matlat-1][j][k])
			    	cont++;}
			    		if(cont != 1)
			    	  conferir = 0;
			    	  cont = 0;
			
			
				}
			
				
				
			}
				
				if(conferir == 1)
				  printf("a matriz e latina");
				  else printf("a matriz nao e latina");
			     
            	
			  }
			                        
        }else printf("insira uma matriz com o numero de linhas igual ao de colunas");
                  } else printf("insira alguma matriz");
}

		int  permutacao(int matriz[50][50][50]){
	
	int i, j, k, matlat, conferir = 1, y = 0, cont = 0;
	if(quant > 0){
		  for(i = 0; i<quant;i++) {
		    printf("%d matriz inserida: \n", i +1);
		    for (k = 0; k < lin[i]; k++) {
              for (j = 0; j < col[i]; j++)
               printf ("%3d ",matriz[i][k][j]);
               printf ("\n");
                                         }
                                   }
            do {
			    printf("qual matriz você deseja saber se e de permutacao?: ");
			    fflush(stdin);
                scanf("%d", &matlat);
			} while ((matlat > quant) || (matlat <= 0 ));

            if(lin[matlat-1] == col [matlat -1]){
			  {for(k=0; k < lin[matlat-1]&& conferir == 1;k++){
			    for(j=0; j < col[matlat-1] && conferir == 1;j++){
			    	if(y == matriz[matlat-1][k][j])
			    	cont++;}
			    		if(cont != (col[matlat-1])-1)
			    	  conferir = 0;
			    	  cont = 0;
			
			
				
			
				
				
			}
			
				 	  
			 for(k=0; k < lin[matlat-1]&& conferir == 1;k++){
			    for(j=0; j < col[matlat-1] && conferir == 1;j++){
			    	if(y == matriz[matlat-1][j][k])
			    	cont++;}
			    		if(cont != (col[matlat-1])-1)
			    	  conferir = 0;
			    	  cont = 0;
			
			
				}
			
				
				
			}
				
				if(conferir == 1)
				  printf("a matriz e de permutacao");
				  else printf("a matriz nao e de permutacao");
			     
            	
			  
			                        
        }else printf("insira uma matriz com o numero de linhas igual ao de colunas");
                  } else printf("insira alguma matriz");
}

	int menu (int matmat){
		int cont = 0;
	char op;
	do{if(cont == 0) {
	   printf("\n  **inserir matriz**\n    imprimir matriz\n    Transpor matriz\n    Somar matriz\n    subtrair matriz\n    Multiplicar matriz\n    Verificar simetria\n    Verificar quadrado magico\n    verificar matriz latino\n    verificar matriz de permutacao\n    ajuda\n    sair\n\n\n <f11> ajuda    <esc>sair ");
        do {
	       op = getch ();
	       }  while((op != 72) && (op != 80) && (op != 13) && (op != 27) && (op != -123));		
	              }  else if(cont == 1) {
	   printf("\n    inserir matriz\n  **imprimir matriz**\n    Transpor matriz\n    Somar matriz\n    subtrair matriz\n    Multiplicar matriz\n    Verificar simetria\n    Verificar quadrado magico\n    verificar matriz latino\n    verificar matriz de permutacao\n    ajuda\n    sair\n\n\n <f11> ajuda    <esc>sair ");
        do {
	       op = getch ();
	       }  while((op != 72) && (op != 80) && (op != 13) && (op != 27) && (op != -123));
	          } else if(cont == 2) {
	   printf("\n    inserir matriz\n    imprimir matriz\n  **Transpor matriz**\n    Somar matriz\n    subtrair matriz\n    Multiplicar matriz\n    Verificar simetria\n    Verificar quadrado magico\n    verificar matriz latino\n    verificar matriz de permutacao\n    ajuda\n    sair\n\n\n <f11> ajuda    <esc>sair ");
        do {
	       op = getch ();
	       }  while((op != 72) && (op != 80) && (op != 13) && (op != 27) && (op != -123));
	          }  else if(cont == 3) {
	   printf("\n    inserir matriz\n    imprimir matriz\n    Transpor matriz\n  **Somar matriz**\n    subtrair matriz\n    Multiplicar matriz\n    Verificar simetria\n    Verificar quadrado magico\n    verificar matriz latino\n    verificar matriz de permutacao\n    ajuda\n    sair\n\n\n <f11> ajuda    <esc>sair ");
        do {
	       op = getch ();
	       }  while((op != 72) && (op != 80) && (op != 13) && (op != 27) && (op != -123));
	          }  else if(cont == 4) {
	   printf("\n    inserir matriz\n    imprimir matriz\n    Transpor matriz\n    Somar matriz\n  **subtrair matriz**\n    Multiplicar matriz\n    Verificar simetria\n    Verificar quadrado magico\n    verificar matriz latino\n    verificar matriz de permutacao\n    ajuda\n    sair\n\n\n <f11> ajuda    <esc>sair ");
        do {
	       op = getch ();
	       }  while((op != 72) && (op != 80) && (op != 13) && (op != 27) && (op != -123));
	          }  else if(cont == 5) {
	   printf("\n    inserir matriz\n    imprimir matriz\n    Transpor matriz\n    Somar matriz\n    subtrair matriz\n  **Multiplicar matriz**\n    Verificar simetria\n    Verificar quadrado magico\n    verificar matriz latino\n    verificar matriz de permutacao\n    ajuda\n    sair\n\n\n <f11> ajuda    <esc>sair ");
        do {
	       op = getch ();
	       }  while((op != 72) && (op != 80) && (op != 13) && (op != 27) && (op != -123));
	          } else if(cont == 6) {
	   printf("\n    inserir matriz\n    imprimir matriz\n    Transpor matriz\n    Somar matriz\n    subtrair matriz\n    Multiplicar matriz\n  **Verificar simetria**\n    Verificar quadrado magico\n    verificar matriz latino\n    verificar matriz de permutacao\n    ajuda\n    sair\n\n\n <f11> ajuda    <esc>sair ");
        do {
	       op = getch ();
	       }  while((op != 72) && (op != 80) && (op != 13) && (op != 27) && (op != -123));
	          } else if(cont == 7) {
	   printf("\n    inserir matriz\n    imprimir matriz\n    Transpor matriz\n    Somar matriz\n    subtrair matriz\n    Multiplicar matriz\n    Verificar simetria\n  **Verificar quadrado magico**\n    verificar matriz latino\n    verificar matriz de permutacao\n    ajuda\n    sair\n\n\n <f11> ajuda    <esc>sair ");
        do {
	       op = getch ();
	       }  while((op != 72) && (op != 80) && (op != 13) && (op != 27) && (op != -123));
	          } else if(cont == 8) {
	   printf("\n    inserir matriz\n    imprimir matriz\n    Transpor matriz\n    Somar matriz\n    subtrair matriz\n    Multiplicar matriz\n    Verificar simetria\n    Verificar quadrado magico\n  **verificar matriz latino**\n    verificar matriz de permutacao\n    ajuda\n    sair\n\n\n <f11> ajuda    <esc>sair ");
        do {
	       op = getch ();
	       }  while((op != 72) && (op != 80) && (op != 13) && (op != 27) && (op != -123));
	          } else if(cont == 9) {
	   printf("\n    inserir matriz\n    imprimir matriz\n    Transpor matriz\n    Somar matriz\n    subtrair matriz\n    Multiplicar matriz\n    Verificar simetria\n    Verificar quadrado magico\n    verificar matriz latino\n  **verificar matriz de permutacao**\n    ajuda\n    sair\n\n\n <f11> ajuda    <esc>sair ");
        do {
	       op = getch ();
	       }  while((op != 72) && (op != 80) && (op != 13) && (op != 27) && (op != -123));
	          } else if(cont == 10) {
	   printf("\n    inserir matriz\n    imprimir matriz\n    Transpor matriz\n    Somar matriz\n    subtrair matriz\n    Multiplicar matriz\n    Verificar simetria\n    Verificar quadrado magico\n    verificar matriz latino\n    verificar matriz de permutacao\n  **ajuda**\n    sair\n\n\n <f11> ajuda    <esc>sair ");
        do {
	       op = getch ();
	       }  while((op != 72) && (op != 80) && (op != 13) && (op != 27) && (op != -123));
	          }  else if(cont == 11) {
	   printf("\n    inserir matriz\n    imprimir matriz\n    Transpor matriz\n    Somar matriz\n    subtrair matriz\n    Multiplicar matriz\n    Verificar simetria\n    Verificar quadrado magico\n    verificar matriz latino\n    verificar matriz de permutacao\n    ajuda\n  **sair**\n\n\n <f11> ajuda    <esc>sair ");
        do {
	       op = getch ();
	       }  while((op != 72) && (op != 80) && (op != 13) && (op != 27) && (op != -123));
	          }
	    if(op == 80)
	      cont++;
	    if(op == 72)
	      cont--;
	    if (op == 27)
	      cont = 11;
	    if (op == -123)
	      cont = 10;
	    if(cont == 12)
	       cont = 0;
	     else if (cont == -1)
	      cont = 11;
	      
	system("CLS");
	
	}while((op != 13) && (op != 27) && (op != -123));
	
return cont;
	      
	}
	


int main (){
	int sel, op, matriz [50][50][50];
	getch();
	system("CLS");
	
    do
	  {sel = ((menu(op)) + 1) ;
      switch (sel)  {
      	case 1:  ler(matriz);
      	         break;
      	case 2: imprimir(matriz);
		        break;
		case 3: transposta (matriz);
		        break;
		case 4 : somamatriz (matriz);
		         break;
		case 5 : submatriz (matriz);
		         break;
		case 6 : multmatriz (matriz);
		         break;
		case 7 : matrizsim (matriz);
		         break;
		case 8 : quadradomagico (matriz);
		        break;
		case 9: quadlatino (matriz);
		        break;
		case 10: permutacao (matriz);
		        break;
	    case 11 : printf("voce pode inserir ate 10 matrizes no programa.\no menu eh intuitivo, boa sorte!");
	              break;
		case 12: exit (0);
		          break;      
	               } 
	    getch();
	    system("CLS");
	}while(sel != 12);
	
	
	
}
