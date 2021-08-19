// #include <bits.h>
#include <stdio.h>
#include <math.h>

//Caio Castilho Donato Regal



//Variaveis
float Matriz[10][10],VetorIndependente[10],AproximacaoInicial[10]= {0},MaxIteracoes=10,Iteracoes,MatrizG[10][10]; // variaveis de argumento
float MatrizL[10][10],MatrizU[10][10];// matrizes L e U
float X[10]= {0},Y[10]= {0},XI[10][10]= {0},YI[10][10]= {0},c;
int det,opcao,opcaoI;// variavies de controle do sistema
int i,j,k;// variaveis de looping U
int I,J,K;// variaveis de controle opera�oes
int il,jl=0,kl;//variavies de looping para calcular L
int OrdemMatriz;
int naux,jaux;
int MatrizIdentidade [10][10] = {
	{1,0,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0},
	{0,0,0,0,0,1,0,0,0,0},
	{0,0,0,0,0,0,1,0,0,0},
	{0,0,0,0,0,0,0,1,0,0},
	{0,0,0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,0,0,0,1},
};
void getCofator(float Matriz[][10], float temp[][10], int l, int c, int OrdemMatriz) {
	int i = 0, j = 0,linha,col;
	for (linha = 0; linha < OrdemMatriz; linha++) {
		for (col = 0; col < OrdemMatriz; col++) {
			if (linha != l && col != c) { // copiando pra temp as que nao sao da linha/coluna escolhida
				temp[i][j++] = Matriz[linha][col];
				if (j == OrdemMatriz - 1) {
					j = 0;
					i++;
				}
			}
		}
	}
}

float Determinante (int OrdemMatriz, float Matriz[10][10]) {
	int D = 0;
	if (OrdemMatriz == 1)//matriz tamanho 1
		return Matriz[0][0];

	float temp[10][10];//matriz temporaria sem linha/col escolhida
	int sinal = 1,f;


	for (f = 0; f <OrdemMatriz; f++) {
		getCofator(Matriz, temp, 0, f, OrdemMatriz);
		D += sinal * Matriz[0][f] * Determinante(OrdemMatriz - 1,temp);
		sinal = -sinal;
	}

	return D;
}
/**
 * @brief problemas
 * 
 */
void SistemaTriangularSuperior (int OrdemMatriz,float MatrizU[][10],float Y[],float X[]) {
	for(i=OrdemMatriz-1; i>=0; i--) {
		X[i]= Y[i];
		for(j=i+1; j<OrdemMatriz; j++) {
			X[i]-=MatrizU[i][j]*X[j];
		}
		X[i]/=MatrizU[i][i];
	}
	printf("\n\n[X]: \n");
	for(i=0; i<OrdemMatriz; i++) {
		printf("%9.3f",X[i]);
	}
}


void SistemaTriangularInferior (int OrdemMatriz,float MatrizL[][10],float VetorIndependente[],float Y[]) {
	for(i=0; i<OrdemMatriz; i++) {
		Y[i]=VetorIndependente[i];
		for(j=0; j<i; j++) {
			Y[i]-=MatrizL[i][j]*Y[j];
		}
		Y[i]=Y[i]/MatrizL[i][i];
	}
	printf("\n\n[Y]: \n");
	for(i=0; i<OrdemMatriz; i++) {
		printf("%9.3f",Y[i]);
	}
}

void DecomposicaoLU (int OrdemMatriz, float Matriz[][10],float VetorIndependente[],float X[]) {
	float SomaU=0,SomaL=0;

	for(i=0; i!=OrdemMatriz; i++) {
		for (jl=0; jl!=OrdemMatriz; jl++) {
			if (i==0) { // primeira linha uij = aij
				for (j=0; j!=OrdemMatriz; j++) {
					MatrizU[i][j]=Matriz[i][j];
				}
				for (il=0; il!=OrdemMatriz; il++) {
					MatrizL[il][0] = (Matriz[il][0] / MatrizU[0][0]); // Li1 = ai1/ui1
				}
			} else {
				if(i<=jl) { // superior
					for(j=jl; j!=OrdemMatriz; j++) {
						for(k=0; k<=i-1; k++) {
							SomaU= SomaU + MatrizL[i][k] * MatrizU [k][j]; // somatorio Lik * ukj
						}
						MatrizU[i][j] = Matriz[i][j] - SomaU ; //  uj = aij - somatoria L ik * ukj
						if(i==j) {
							MatrizL[i][j] = 1; // criando os 1 da Matriz L

						}
						SomaU=0;// zera somatorio U
					}
				}
				if (i>jl && jl!=0) { // inferior
					//for(j=0;j!=jl;j++){
					for(kl=0; kl<=jl-1; kl++) {
						SomaL= SomaL + MatrizL[i][kl] * MatrizU[kl][jl]; // somatorio Lik * Ukj
					}
					MatrizL[i][jl] = (Matriz[i][jl] - SomaL) / MatrizU[jl][jl] ;  // lij = ( aij - somatoria Lik * ukj)/ ujj
					MatrizU[i][jl] = 0; // criando os 0 da matriz U
					SomaL=0;
					//}
				}
			}
		}
	}

	printf("[L]: \n");
	for(i=0; i<OrdemMatriz; i++) {
		for(j=0; j<OrdemMatriz; j++)
			printf("%9.3f",MatrizL[i][j]);
		printf("\n");
	}
	printf("\n\n[U]: \n");
	for(i=0; i<OrdemMatriz; i++) {
		for(j=0; j<OrdemMatriz; j++)
			printf("%9.3f",MatrizU[i][j]);
		printf("\n");
	}
	for(i=0; i<OrdemMatriz; i++) {
		Y[i]=VetorIndependente[i];
		for(j=0; j<i; j++) {
			Y[i]-=MatrizL[i][j]*Y[j];
		}
	}
	SistemaTriangularInferior(OrdemMatriz,MatrizL,VetorIndependente,Y);
	SistemaTriangularSuperior(OrdemMatriz,MatrizU,Y,X);

}

void Cholesky (int OrdemMatriz,float Matriz[][10],float VetorIndependente[],float X[]) {

	for ( i = 0; i < OrdemMatriz; i++) {// Calculando Matriz L
		for ( j = 0; j <= i; j++) {
			float SomaCholesky = 0;

			if (j == i) {// soma diagonal
				for ( k = 0; k < j; k++)
					SomaCholesky += pow(MatrizL[j][k], 2);
				MatrizL[j][j] = sqrt(Matriz[j][j] -  SomaCholesky);
			} else {

				for ( k = 0; k < j; k++) // calculando Lij com Ljj
					SomaCholesky += (MatrizL[i][k] * MatrizL[j][k]);
				MatrizL[i][j] = (Matriz[i][j] - SomaCholesky) /MatrizL[j][j];
			}
		}
	}


	printf (" L  \t\t\t\t\t\t\t");
	printf("Transposta\n");
	for ( i = 0; i < OrdemMatriz; i++) {
		printf("\n");
		for ( j = 0; j < OrdemMatriz; j++)
			printf("%9.3f \t",MatrizL[i][j]) ;
		printf("\t");

		for ( j = 0; j < OrdemMatriz; j++) {
			MatrizU[i][j]=MatrizL[j][i];
			printf("%9.3f \t",MatrizU[i][j]);
		}

	}
	SistemaTriangularInferior(OrdemMatriz,MatrizL,VetorIndependente,Y);
	SistemaTriangularSuperior (OrdemMatriz,MatrizU,Y,X);

}

void GaussCompacto (int OrdemMatriz,float Matriz[][10],float VetorIndependente[],float X[]) {
	for(i=0; i<OrdemMatriz; i++) {

		Matriz[i][j] = VetorIndependente[i];

	}
	for (i=0; i<OrdemMatriz; i++) {
		printf( " \n \n \n\ A");
		printf("%f",VetorIndependente[i]);
	}
	float SomaU=0,SomaL=0;
	for(i=0; i!=OrdemMatriz; i++) {
		for (jl=0; jl!=OrdemMatriz; jl++) {
			if (i==0) { // primeira linha uij = aij
				for (j=0; j!=OrdemMatriz+1; j++) {
					MatrizU[i][j]=Matriz[i][j];
				}
				for (il=0; il!=OrdemMatriz; il++) {
					MatrizL[il][0] = (Matriz[il][0] / MatrizU[0][0]); // Li1 = ai1/ui1
				}
			} else {
				if(i<=jl) { // superior
					for(j=jl; j!=OrdemMatriz+1; j++) {
						for(k=0; k<=i-1; k++) {
							SomaU= SomaU + MatrizL[i][k] * MatrizU [k][j]; // somatorio Lik * ukj
						}
						MatrizU[i][j] = Matriz[i][j] - SomaU ; //  uj = aij - somatoria L ik * ukj
						if(i==j) {
							MatrizL[i][j] = 1; // criando os 1 da Matriz L

						}
						SomaU=0;// zera somatorio U
					}
				}
				if (i>jl && jl!=0) { // inferior
					//for(j=0;j!=jl;j++){
					for(kl=0; kl<=jl-1; kl++) {
						SomaL= SomaL + MatrizL[i][kl] * MatrizU[kl][jl]; // somatorio Lik * Ukj
					}
					MatrizL[i][jl] = (Matriz[i][jl] - SomaL) / MatrizU[jl][jl] ;  // lij = ( aij - somatoria Lik * ukj)/ ujj
					MatrizU[i][jl] = 0; // criando os 0 da matriz U
					SomaL=0;// zera somatorio L
					//}
				}
			}
		}
	}

	printf("\n\n[A]: \n");
	for(i=0; i<OrdemMatriz; i++) {
		for(j=0; j<OrdemMatriz+1; j++)
			printf("%9.3f",Matriz[i][j]);
		printf("\n");
	}
	printf("\n\n[U]: \n");
	for(i=0; i<OrdemMatriz; i++) {
		for(j=0; j<OrdemMatriz+1; j++)
			printf("%9.3f",MatrizU[i][j]);
		printf("\n");

	}
	SistemaTriangularInferior(OrdemMatriz,MatrizL,VetorIndependente,Y);
	SistemaTriangularSuperior(OrdemMatriz,MatrizU,Y,X);
}

void GaussJordan (int OrdemMatriz,float MatrizG[][10],float VetorIndependente[],float X[]) {
	for(j=1; j<=OrdemMatriz; j++) {
		for(i=1; i<=OrdemMatriz; i++) {
			if(i!=j) {
				c=MatrizG[i][j]/MatrizG[j][j];
				for(k=1; k<=OrdemMatriz+1; k++) {
					MatrizG[i][k]=MatrizG[i][k]-c*MatrizG[j][k];
				}
			}
		}
	}
	printf("\n\n[X]: \n");
	for(i=1; i<=OrdemMatriz; i++) {
		X[i]=MatrizG[i][OrdemMatriz+1]/MatrizG[i][i];
		printf("%9.3f",X[i]);
	}
}

void Jacobi (int OrdemMatriz,float Matriz[][10],float VetorIndependente[],float AproximacaoInicial[],int MaxIteracoes,float X[]) {

	float SomaJ=0;
	printf("\n A[]\n");
	for(i=0; i<OrdemMatriz; i=i+1) {
		for(j=0; j<OrdemMatriz; j=j+1) {
			printf(" %9.3f ",Matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\nB[]\n");
	for(i=0; i<OrdemMatriz; i=i+1) {
		printf(" %9.3f ",VetorIndependente[i]);
	}
	printf("\n");

	for(k=0; k<=MaxIteracoes; k++) {
		for(i=0; i<OrdemMatriz; i=i+1) {
			SomaJ = 0;
			for(j=0; j<OrdemMatriz; j=j+1) {
				if(j!=i) {
					SomaJ = SomaJ+Matriz[i][j]*AproximacaoInicial[j];
				}
			}
			X[i] = (VetorIndependente[i]-SomaJ)/Matriz[i][i];
		}

		for(j=0; j<OrdemMatriz; j=j+1) {
			AproximacaoInicial[j] = X[j];
		}

	}
	printf("\nX[] Com %d Iteracoes \n",k-1);
	for(i=0; i<OrdemMatriz; i=i+1) {
		printf(" %9.3f ",X[i]);
	}
	printf("\n");
}

void GaussSeidel (int OrdemMatriz,float Matriz[][10],float VetorIndependente[],int AproximacaoInicial[],float e,int MaxIteracoes,float Solucao[],int Iteracoes) {

}

void MatrizInversa (int OrdemMatriz,float Matriz[][10],float XI[][10]) {
	float SomaU=0,SomaL=0;
	printf("\nDigite '1' para utilizar o metodo da decomposicao LU ou '2' para utilizar o metodo de Gauss Compacto");
	scanf("%d",&opcaoI);

	if (opcaoI==1) {
		j= OrdemMatriz;
		jaux= j;

		for(i=0; i<OrdemMatriz; i++) {
			for (k=0; k<OrdemMatriz; k++) {
				Matriz[i][j] = MatrizIdentidade[i][k];
				j++;
			}
			j=jaux;
		}
		naux=OrdemMatriz;
		for(i=0; i!=OrdemMatriz; i++) {
			for (jl=0; jl!=OrdemMatriz; jl++) {
				if (i==0) { // primeira linha uij = aij
					for (j=0; j!=OrdemMatriz+1; j++) {
						MatrizU[i][j]=Matriz[i][j];
					}
					for (il=0; il!=OrdemMatriz; il++) {
						MatrizL[il][0] = (Matriz[il][0] / MatrizU[0][0]); // Li1 = ai1/ui1
					}
				} else {
					if(i<=jl) { // superior
						for(j=jl; j!=OrdemMatriz*2; j++) {
							for(k=0; k<=i-1; k++) {
								SomaU= SomaU + MatrizL[i][k] * MatrizU [k][j]; // somatorio Lik * ukj
							}
							MatrizU[i][j] = Matriz[i][j] - SomaU ; //  uj = aij - somatoria L ik * ukj
							if(i==j) {
								MatrizL[i][j] = 1; // criando os 1 da Matriz L

							}
							SomaU=0;// zera somatorio U
						}
					}
					if (i>jl && jl!=0) { // inferior
						//for(j=0;j!=jl;j++){
						for(kl=0; kl<=jl-1; kl++) {
							SomaL= SomaL + MatrizL[i][kl] * MatrizU[kl][jl]; // somatorio Lik * Ukj
						}
						MatrizL[i][jl] = (Matriz[i][jl] - SomaL) / MatrizU[jl][jl] ;  // lij = ( aij - somatoria Lik * ukj)/ ujj
						MatrizU[i][jl] = 0; // criando os 0 da matriz U
						SomaL=0;// zera somatorio L
						//}
					}
				}
			}
		}
		printf("\n\n[A]: \n");
		for(i=0; i<OrdemMatriz; i++) {
			for(j=0; j<OrdemMatriz*2; j++)
				printf("%9.3f",Matriz[i][j]);
			printf("\n");
		}
		printf("[L]: \n");
		for(i=0; i<OrdemMatriz; i++) {
			for(j=0; j<OrdemMatriz; j++)
				printf("%9.3f",MatrizL[i][j]);
			printf("\n");
		}
		printf("\n\n[U]: \n");
		for(i=0; i<OrdemMatriz; i++) {
			for(j=0; j<OrdemMatriz*2; j++)
				printf("%9.3f",MatrizU[i][j]);
			printf("\n");
		}
		for(k=0; k<OrdemMatriz; k++) {
			for(i=0; i<OrdemMatriz*2; i++) {
				YI[i][k]=MatrizIdentidade[i][k];
				for(j=0; j<i; j++) {
					YI[i][k]-=MatrizL[i][j]*YI[j][k];
				}
			}
		}
		printf("\n\n[Y]: \n");
		for(i=0; i<OrdemMatriz; i++) {
			for(j=0; j<OrdemMatriz; j++)
				printf("%9.3f",YI[i][j]);
			printf("\n");

		}

		naux=OrdemMatriz;


		for(k=0; k<OrdemMatriz; k++) {
			for(i=OrdemMatriz-1; i>=0; i--) {
				XI[i][k]= YI[i][k];
				for(j=i+1; j<OrdemMatriz*2; j++) {
					XI[i][k]-=MatrizU[i][j]*XI[j][k];
				}
				XI[i][k]/=MatrizU[i][i];
			}
			naux++;
		}
		printf("\n\n[X]: \n");
		for(i=0; i<OrdemMatriz; i++) {
			for(j=0; j<OrdemMatriz; j++)
				printf("%9.3f",XI[i][j]);
			printf("\n");
		}

	} else if (opcaoI==2) {
		j= OrdemMatriz;
		jaux= j;
		for(i=0; i<OrdemMatriz; i++) {
			for (k=0; k<OrdemMatriz; k++) {
				Matriz[i][j] = MatrizIdentidade[i][k];
				j++;
			}
			j=jaux;
		}
		naux=OrdemMatriz;
		for(i=0; i!=OrdemMatriz; i++) {
			for (jl=0; jl!=OrdemMatriz; jl++) {
				if (i==0) { // primeira linha uij = aij
					for (j=0; j!=OrdemMatriz+1; j++) {
						MatrizU[i][j]=Matriz[i][j];
					}
					for (il=0; il!=OrdemMatriz; il++) {
						MatrizL[il][0] = (Matriz[il][0] / MatrizU[0][0]); // Li1 = ai1/ui1
					}
				} else {
					if(i<=jl) { // superior
						for(j=jl; j!=OrdemMatriz*2; j++) {
							for(k=0; k<=i-1; k++) {
								SomaU= SomaU + MatrizL[i][k] * MatrizU [k][j]; // somatorio Lik * ukj
							}
							MatrizU[i][j] = Matriz[i][j] - SomaU ; //  uj = aij - somatoria L ik * ukj
							if(i==j) {
								MatrizL[i][j] = 1; // criando os 1 da Matriz L

							}
							SomaU=0;// zera somatorio U
						}
					}
					if (i>jl && jl!=0) { // inferior
						//for(j=0;j!=jl;j++){
						for(kl=0; kl<=jl-1; kl++) {
							SomaL= SomaL + MatrizL[i][kl] * MatrizU[kl][jl]; // somatorio Lik * Ukj
						}
						MatrizL[i][jl] = (Matriz[i][jl] - SomaL) / MatrizU[jl][jl] ;  // lij = ( aij - somatoria Lik * ukj)/ ujj
						MatrizU[i][jl] = 0; // criando os 0 da matriz U
						SomaL=0;// zera somatorio L
						//}
					}
				}
			}
		}
		printf("\n\n[A]: \n");
		for(i=0; i<OrdemMatriz; i++) {
			for(j=0; j<OrdemMatriz*2; j++)
				printf("%9.3f",Matriz[i][j]);
			printf("\n");
		}
		printf("\n\n[U]: \n");
		for(i=0; i<OrdemMatriz; i++) {
			for(j=0; j<OrdemMatriz*2; j++)
				printf("%9.3f",MatrizU[i][j]);
			printf("\n");
		}
		for(k=0; k<OrdemMatriz; k++) {
			for(i=OrdemMatriz-1; i>=0; i--) {
				XI[i][k]= MatrizU[i][naux];
				for(j=i+1; j<OrdemMatriz*2; j++) {
					XI[i][k]-=MatrizU[i][j]*XI[j][k];
				}
				XI[i][k]/=MatrizU[i][i];
			}
			naux++;
		}
		printf("\n\n[X]: \n");
		for(i=0; i<OrdemMatriz; i++) {
			for(j=0; j<OrdemMatriz; j++)
				printf("%9.3f ",XI[i][j]);
			printf("\n");
		}



	} else {
	}
}
int main () {
	printf("Trabalho metodos numericos Sistemas lineares1\n");
	printf("Digite a Ordem da Matriz: ");
	scanf("%d",&OrdemMatriz);
	naux = OrdemMatriz;
	printf("\nEntre com os elementos da matriz:\n");
	for(i=0; i<OrdemMatriz; i++) {
		for(j=0; j<OrdemMatriz; j++) {
			printf("Enter A[%d][%d] element: ", i,j);
			scanf("%f",&Matriz[i][j]);
			MatrizG[i+1][j+1]=Matriz[i][j];
		}
	}


	printf("\n Digite o numero relacionado a operacao:");
	printf("\n  1 - Determinante ");
	printf("\n  2 - Sistema Triangular inferior ");
	printf("\n  3 - Sistema Triangular superior ");
	printf("\n  4 - Decomposicao L.U ");
	printf("\n  5 - Cholesky ");
	printf("\n  6 - Gauss Compacto ");
	printf("\n  7 - Gauss Jordan ");
	printf("\n  8 - Jacobi ");
	printf("\n  9 - Gauss Seidel ");
	printf("\n 10 - Matriz Inversa \n");
	scanf("\n%d",&opcaoI);

	switch(opcaoI) {

		case 1:
			printf("\n%9.3f",Determinante(OrdemMatriz,Matriz));
			break;
		case 2:
			printf("\n Digite os elementos do vetor dos termos independentes\n");
			for(i=0; i<OrdemMatriz; i++) {
				printf("B[%d] = ",i+1);
				scanf("%f",&VetorIndependente[i]);
				MatrizG[i+1][j+1]=VetorIndependente[i];
			}
			SistemaTriangularInferior(OrdemMatriz,MatrizL,VetorIndependente,Y);
			//SistemaTriangularSuperior(OrdemMatriz,Matriz,Y,X);
			break;
		case 3:
			printf("\n Digite os elementos do vetor dos termos independentes\n");
			for(i=0; i<OrdemMatriz; i++) {
				printf("B[%d] = ",i+1);
				scanf("%f",&VetorIndependente[i]);
				MatrizG[i+1][j+1]=VetorIndependente[i];
			}
			//SistemaTriangularInferior(OrdemMatriz,MatrizL,VetorIndependente,Y);
			SistemaTriangularSuperior(OrdemMatriz,Matriz,Y,X);
			break;
		case 4:
			printf("\n Digite os elementos do vetor dos termos independentes\n");
			for(i=0; i<OrdemMatriz; i++) {
				printf("B[%d] = ",i+1);
				scanf("%f",&VetorIndependente[i]);
				MatrizG[i+1][j+1]=VetorIndependente[i];
			}
			DecomposicaoLU(OrdemMatriz,Matriz,VetorIndependente,X);
			break;
		case 5:
			printf("\n Digite os elementos do vetor dos termos independentes\n");
			for(i=0; i<OrdemMatriz; i++) {
				printf("B[%d] = ",i+1);
				scanf("%f",&VetorIndependente[i]);
				MatrizG[i+1][j+1]=VetorIndependente[i];
			}
			Cholesky (OrdemMatriz,Matriz,VetorIndependente,X);
			break;
		case 6:
			printf("\n Digite os elementos do vetor dos termos independentes\n");
			for(i=0; i<OrdemMatriz; i++) {
				printf("B[%d] = ",i+1);
				scanf("%f",&VetorIndependente[i]);
				MatrizG[i+1][j+1]=VetorIndependente[i];
			}
			GaussCompacto(OrdemMatriz,Matriz,VetorIndependente,X);
			break;
		case 7:
			printf("\n Digite os elementos do vetor dos termos independentes\n");
			for(i=0; i<OrdemMatriz; i++) {
				printf("B[%d] = ",i+1);
				scanf("%f",&VetorIndependente[i]);
				MatrizG[i+1][j+1]=VetorIndependente[i];
			}
			GaussJordan(OrdemMatriz,MatrizG,VetorIndependente,X);
			break;
		case 8:
			printf("\n Digite os elementos do vetor dos termos independentes\n");
			for(i=0; i<OrdemMatriz; i++) {
				printf("B[%d] = ",i+1);
				scanf("%f",&VetorIndependente[i]);
				MatrizG[i+1][j+1]=VetorIndependente[i];
			}
			printf("\nDigite o maximo de itera��es: \n ");
			scanf("%d",&MaxIteracoes);
			printf("Digite a aproximacao inicial:");
			for(i=0; i<OrdemMatriz; i++) {
				printf("Xi[%d] = ",i+1);
				scanf("%f",&AproximacaoInicial[i]);
			}
			Jacobi(OrdemMatriz,Matriz,VetorIndependente,AproximacaoInicial,MaxIteracoes,X);
			break;
		case 9:

		case 10:
			MatrizInversa(OrdemMatriz,Matriz,XI);
	}

	getch();
 	return 0;


}
