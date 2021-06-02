#include <stdio.h>
#define max 30
int main(){
    char str[max];
    int i, j, count = 0, vezes = 0, c = 1;

    puts("Informe a String");
    gets(str);

    while (str[count] != '\0'){
        count++;
    }

    for(i = 0; i < count; i++){ 
        vezes = 1; 
        for(j = i+1; j < count; j++){ 
            if(str[i] == str[j]){ 
               vezes++;
            } else
                break;
        }   
        if(i == 0) 
          c = 1; 
        else{
          for(j = i - 1; j >= 0; j--){ 
            if(str[i] != str[j])
              c = 1;
            else{ 
              c = 0;
              break;
            }
          }
        }
        if(c == 1)
        printf("\n%c : %d", str[i], vezes);
    }


}
