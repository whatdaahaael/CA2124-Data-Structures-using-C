#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

typedef struct StackType {
    int A[SIZE];
    int Top;
} STACK;

STACK S;

void InitStack();
void Fibonacci(int N);
void Push(int Num);
void Display();
int Pop();

int main() 
{
    int N;
    InitStack();
    printf("Enter N:\n");
    scanf("%d", &N);
    Fibonacci(N);
    Display();
	
}

void InitStack() 
{
    S.Top = -1;
}

void Push(int Num) 
{
    if (S.Top == SIZE - 1) {
        printf("Stack Overflow.\n");
        return;
    }
    S.A[++S.Top] = Num;
}

int Pop() {
    if (S.Top == -1) 
	{
        printf("Stack Underflow.\n");
        return -1;
    }
    return S.A[S.Top--];
}

void Fibonacci(int N)
{
	int F1, F2, F3, i=3;
	Push(0);
	Push(1);
	while(i<=N){
		F2=Pop();
		F1=Pop();
		F3=F1+F2;
		Push(F1);
		Push(F2);
		Push(F3);
		i++;
	}
}

void Display()
{
	int i=0;
	while(i<=S.Top){
		printf("%d ", S.A[i]);
		i++;
	}
}
