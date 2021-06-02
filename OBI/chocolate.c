#include <stdio.h>
#include <math.h>

int main() {

	int lado, pedacos=0;
	scanf("%d", &lado);
	while (lado >= 2) {
		lado = lado/2;
		pedacos++;
	}
	pedacos = pedacos * 2;
	printf("%d", pow(2, pedacos));
	return 0;
}
