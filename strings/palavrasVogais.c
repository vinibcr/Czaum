int main(void) {
    char frase[30];
    int consoantes = 0;

    printf("Digite uma frase:");
    scanf("%[^\n]",frase);

    for (int i = 0; frase[i] != '\0'; i++){
        char c = frase[i];
        // se for maiúscula, converte para minúscula (excluí o "A", porque nesse caso nem precisa contabilizar)
        if ('B' <= c && c <= 'Z') c += 32;
        if ('b' <= c && c <= 'z') { // só testo se estiver neste intervalo
            switch(c) { // como já deixei o "a" de fora, não preciso mais testar aqui
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    break; // se for vogal, não faz nada
                default: // é consoante
                    consoantes++;
            }
        }
    }

    printf("A quantidade de consoantes na frase '%s' é %d\n", frase, consoantes);
    printf("A quantidade de palavras terminadas em voagis é %d\n", frase - consoantes );
    return 0;
}