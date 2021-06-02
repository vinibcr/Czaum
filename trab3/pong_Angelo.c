#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define y 21
#define x 75
void inicia(char campo[y][x] , int bolax, int bolay, int iniplay, int fimplay, int inicomp, int fimcomp);
void borda(char campo[y][x]);
void jogador (char campo[y][x], int iniplay, int fimplay);
void comp(char campo[y][x], int inicomp, int fimcomp );
void bola(char campo[y][x], int bolax, int bolay);
void scancampo(char campo[y][x]);
void gameloop(char campo[y][x] , int bolax, int bolay, int iniplay, int fimplay, int inicomp, int fimcomp, int mudx, int mudy, int mudcomp);
void draw(char campo[y][x]);
void input(char campo[y][x], int *bolax, int *bolay, int *iniplay, int *fimplay, int *inicomp, int *fimcomp, int *mudx, int *mudy, int *mudcomp, int *gol);
void update(char campo[y][x] , int bolax, int bolay, int iniplay, int fimplay, int inicomp, int fimcomp);

int main(){
	int bolax, bolay;
	int iniplay, fimplay;
	int inicomp, fimcomp;
	int mudx, mudy, mudcomp;
	char campo[y][x];
	bolax = 37;
	bolay = 10;
	
	iniplay = 8;
	fimplay = 12;
	
	inicomp = 4;
	fimcomp = 18;
	
	mudx = -1;
	mudy = -1;
	mudcomp = -1;
	printf("USE A TECLA 8 PARA SUBIR E 2 PARADESCER\n");
	inicia(campo,bolax,bolay,iniplay,fimplay,inicomp,fimcomp);
	gameloop(campo,bolax,bolay,iniplay,fimplay,inicomp,fimcomp,mudx,mudy,mudcomp);
	system("pause");
	return 0;
}
void inicia(char campo[y][x] , int bolax, int bolay, int iniplay, int fimplay, int inicomp, int fimcomp){
	borda(campo);
	jogador(campo,iniplay,fimplay);
	comp(campo,inicomp,fimcomp);
	bola(campo,bolax,bolay);
}

void borda(char campo[y][x]){
	int i, j;
	for(i=0;i<y;i++){
		for(j=0;j<x;j++){
			if(i == 0 || i == y-1){
				campo[i][j] = '-';
			}else if(j == 0 || j == x-1){
				campo[i][j] = '|';
			}else{
				campo[i][j] = ' ';
			}
		}
	}
}

void jogador (char campo[y][x], int iniplay, int fimplay){
	int i, j;
	for(i = iniplay; i <= fimplay; i++){
		for(j=2; j <=3; j++){
			campo[i][j] = '#';
		}
	}
	
}
void comp(char campo[y][x], int inicomp, int fimcomp ){
	int i,j;
	for(i=inicomp;i<fimcomp;i++){
		for(j=x-4;j<=x-3;j++){
			campo[i][j] = '#';
		}
	}
}
void bola(char campo[y][x], int bolax, int bolay){
campo[bolay][bolax] = '0';	
	
}

void scancampo(char campo[y][x]){
	int i, j;
	for(i = 0; i<y;i++){
		for(j = 0; j<x;j++){
			printf("%c", campo[i][j]);
		}
		printf("\n");
	}
}
void gameloop(char campo[y][x] , int bolax, int bolay, int iniplay, int fimplay, int inicomp, int fimcomp, int mudx, int mudy, int mudcomp){
	int gol=0;
		do{
			printf("USE A TECLA 8 PARA SUBIR E 2 PARA DESCER\n");
		draw(campo);
		input(campo, &bolax, &bolay, &iniplay, &fimplay, &inicomp, &fimcomp, &mudx, &mudy, &mudcomp, &gol);
		update(campo,bolax,bolay,iniplay,fimplay,inicomp,fimcomp);
		Sleep(10);
	}
	while(gol==0);
}
void draw(char campo[y][x]){
	system("cls");
	scancampo(campo);
}
void input(char campo[y][x], int *bolax, int *bolay, int *iniplay, int *fimplay, int *inicomp, int *fimcomp, int *mudx, int *mudy, int *mudcomp, int *gol){
int i;
char key;
if(*bolay==1 || *bolay==y-2){
	*mudy *= -1;
	
}
if(*bolax==1 || *bolax==x-2){
	*gol = 1;
}	
	if(*bolax==4){
		for(i = (*iniplay); i <=(*fimplay);i++){
			if(i==(*bolay)){
				*mudx *= -1;
			}
		}
	}
	if(*bolax==x-5){
		for(i = (*inicomp); i <=(*fimcomp); i++){
			if(i == (*bolay)){
				*mudx *= -1;
			}
		}
	}
	if(*inicomp==1 || *fimcomp==y-1){
		*mudcomp*= -1;
	}
	if(*gol ==0){
	
	*bolax += (*mudx);
	*bolay += (*mudy);
	*inicomp += (*mudcomp);
	*fimcomp += (*mudcomp);
	if(kbhit()==1){
		key = getch();
		if(key=='8'){
			if(*iniplay != 1){
				*iniplay -=1;
				*fimplay -=1;
			}
		}
		if(key=='2'){
		if(*fimplay != y-2){
			*iniplay += 1;
			*fimplay += 1;
		}	
		}
	}
}
	
}
void update(char campo[y][x] , int bolax, int bolay, int iniplay, int fimplay, int inicomp, int fimcomp){
		borda(campo);
	jogador(campo,iniplay,fimplay);
	comp(campo,inicomp,fimcomp);
	bola(campo,bolax,bolay);
}





