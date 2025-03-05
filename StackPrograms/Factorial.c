#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 2

typedef struct StackType {
    long A[SIZE];
    int Top;
} STACK;

STACK S;

void InitStack();
long Factorial(int Num);
void Push(long Num);
long Pop();

int main() {
    int Num;
    long Fact;
    
    printf("Enter Number:\n");
    scanf("%d", &Num);
    Fact=Factorial(Num);
    printf("%d! = %ld\n", Num, Fact);
	
}

void InitStack() {
    S.Top = -1;
}

long Factorial(int Num){
	int i;
	long Fact;
	Push(1);
	for(i=1;i<=Num;i++){
		Fact=Pop()*i;
		Push(Fact);
	}
	return Fact;
}
void Push(long Num) {
    if (S.Top == SIZE - 1) {
        printf("Stack Overflow.\n");
        return;
    }
    S.A[++S.Top] = Num;
}

long Pop() {
    if (S.Top == -1) {
        printf("Stack Underflow.\n");
        return -1;
    }
    return S.A[S.Top--];
}

