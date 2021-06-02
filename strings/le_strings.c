#include <stdio.h>
#define qte 5
int main () {
  char string[qte][20];
  int i;
  for (i = 0; i < qte; i++) {
    gets (string[i]);
  }
  for (i = 0; i < qte; i++)
  puts(string[i]);
}

