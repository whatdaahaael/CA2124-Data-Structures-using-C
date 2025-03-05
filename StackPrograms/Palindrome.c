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
void Palindrome(char Sen[SIZE]);
char Pop();

int main() 
{
    char Sen[SIZE];
    int i, len;
    
    printf("Enter word without spaces and in small letters:\n");
    fgets(Sen, SIZE, stdin);
    
    InitStack();
    Palindrome(Sen);
}

void InitStack() 
{
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

void Palindrome(char Sen[SIZE])
{
	char New[SIZE];
	int i, len;
	
    len = strlen(Sen);
    if (Sen[len - 1] == '\n')
        Sen[--len] = '\0';
    
	for (i = 0; i < len; i++) {
        Push(Sen[i]);
    }

    for (i = 0; i < len; i++) {
        New[i] = Pop();
    }
    New[len] = '\0'; 
	
	if(strcmp(Sen, New)==0){
		printf("%s is Palindrome.\n", Sen);
	} else {
		printf("%s is not Palindrome.\n", Sen);
	}
}
