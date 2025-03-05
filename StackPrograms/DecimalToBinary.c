#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef struct StackType {
    int A[SIZE];
    int Top;
} STACK;

STACK S;

void InitStack();
void DecimalToBinary(int N);
void Push(int Num);
void Display();
int Pop();

int main() 
{
    int N;
    
    printf("Enter a decimal number > 0:\n");
    scanf("%d", &N);
    DecimalToBinary(N);
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

int Pop()
{
    if (S.Top == -1) 
	{
        printf("Stack Underflow.\n");
        return -1;
    }
    return S.A[S.Top--];
}

void DecimalToBinary(int N)
{
	while (N > 0) {
        Push(N % 2); // Store remainder
        N /= 2;
    }
}

void Display()
{
    printf("Binary Equivalent: ");
    while (S.Top != 0) {
        printf("%d", Pop());
    }
    printf("\n");
}
