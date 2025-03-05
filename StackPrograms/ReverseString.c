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
void ReverseString(char Sen[SIZE]);

int main() 
{
    char Sen[SIZE];
    
    printf("Enter sentence:\n");
    fgets(Sen, SIZE, stdin);
    
    InitStack();
    ReverseString(Sen);
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

void ReverseString(char Sen[SIZE])
{
	char New[SIZE];
	int i, len;
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
