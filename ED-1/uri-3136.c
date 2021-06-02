#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct stack
{
    long long int head;
    long long int element[99999];
} Stack;

Stack createstack(){
    Stack primaryStack;
    primaryStack.head = -1;

    return primaryStack;
}

bool vazia(Stack *primaryStack){
    return (primaryStack->head == -1);
}

void push(Stack *primaryStack, long long int data){
    primaryStack->head++;
    primaryStack->element[primaryStack->head] = data;
}

void pushRam(Stack *primaryStack, Stack *ram, int number){
    primaryStack->head++;
    primaryStack->element[primaryStack->head] = ram->element[number];
}

void pop(Stack *primaryStack, Stack *ram, int index){
    ram->head++;
    ram->element[index] = primaryStack->element[primaryStack->head];
    primaryStack->head--;
}

void add(Stack *primaryStack){
    long long int sum = primaryStack->element[primaryStack->head] + primaryStack->element[(primaryStack->head - 1)];
    primaryStack->head -= 1;
    primaryStack->element[primaryStack->head] = sum;
}

void mul(Stack *primaryStack){
    long long int mul = primaryStack->element[primaryStack->head] * primaryStack->element[(primaryStack->head - 1)];
    primaryStack->head--;
    primaryStack->element[primaryStack->head] = mul;
}

void divStack(Stack *primaryStack){
    long long int aux = primaryStack->element[(primaryStack->head - 1)] / primaryStack->element[primaryStack->head];
    primaryStack->head--;
    primaryStack->element[primaryStack->head] = aux;
}

void sub(Stack *primaryStack){
    long long int sum = primaryStack->element[(primaryStack->head - 1)] - primaryStack->element[(primaryStack->head)];
    primaryStack->head--;
    primaryStack->element[primaryStack->head] = sum;
}

void Print(Stack *primaryStack){
    printf("%lld\n", primaryStack->element[(primaryStack->head)]);
    primaryStack->head--;
}

int main(){
    int quant, number;
    char commands[60], *token;
    Stack Ram, primaryStack;

    scanf("%d", &quant);
    while (quant--){
        scanf("%s", commands);


        if (commands[0] == 'p' && commands[1] == 'u' && commands[2] == 's' && commands[3] == 'h'){
            token = strtok(commands, "push_");
            if (token[0] == 'R'){
      
                token = strtok(token, "R");
                number = atoi(token);
                pushRam(&primaryStack, &Ram, number);
            }
            else
            {
                // PUSH
                token = strtok(token, "_");
                number = atoi(token);
                push(&primaryStack, number);
            }
        }
        else if (commands[0] == 'p' && commands[1] == 'o' && commands[2] == 'p'){
            token = strtok(commands, "pop_R");
            number = atoi(token);
            pop(&primaryStack, &Ram, number);
        }
        else if (strcmp(commands, "add") == 0){
            add(&primaryStack);
        }
        else if (strcmp(commands, "mul") == 0){
            mul(&primaryStack);
        }
        else if (strcmp(commands, "div") == 0){
            divStack(&primaryStack);
        }
        else if (strcmp(commands, "sub") == 0){
            sub(&primaryStack);
        }
        else if (strcmp(commands, "print") == 0){
            Print(&primaryStack);
        }
    }
    system("pause");
}