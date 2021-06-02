//funcao conta vogais string
int vogais(string[]){
	char vogais[]= "aeiouAEIOU";
	int numeroVogais = 0;
	int i, j;
	for(i=0;string[i] != '/0';i++){
		for(j=0;vogais[j]!='/0',j++){
			if(string[i]==vogais[j]){
				numeroVogais++;
				break;
			}
		}
	}
	return numeroVogais;
}
