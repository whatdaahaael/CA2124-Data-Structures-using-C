#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

typedef struct StackType {
    char A[SIZE];
    int Top;
} STACK;

STACK S;

void InitStack();
void Push(char Num);
char Pop();

int main() {
    char Sen[SIZE], New[SIZE];
    int i, len;
    
    printf("Enter sentence:\n");
    fgets(Sen, SIZE, stdin);
    
    len = strlen(Sen);
    if (Sen[len - 1] == '\n')
        Sen[--len] = '\0';

    InitStack();
    for (i = 0; i < len; i++) {
        Push(Sen[i]);
    }

    for (i = 0; i < len; i++) {
        New[i] = Pop();
    }
    New[len] = '\0'; 

    printf("Reversed sentence: %s\n", New);
}

void InitStack() {
    S.Top = -1;
}

void Push(char Ch) {
    if (S.Top == SIZE - 1) {
        printf("Stack Overflow.\n");
        return;
    }
    S.A[++S.Top] = Ch;
}

char Pop() {
    if (S.Top == -1) {
        printf("Stack Underflow.\n");
        return '\0';
    }
    return S.A[S.Top--];
}

