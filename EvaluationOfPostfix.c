#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define SIZE 20

typedef struct StackType {
    float Oprd[SIZE];
    int Top;
} STACK;
STACK S;

void InitStack();
void PushOp(float Num);
float PopOp();
void Process(char Optr);
float EvalFix(char PostFix[]);

int main() 
{
    char PostFix[SIZE];
    float Result;

    InitStack();
    printf("Enter a Postfix Expression:\n");
    fgets(PostFix, SIZE, stdin);
    PostFix[strcspn(PostFix, "\n")] = 0;

    Result = EvalFix(PostFix);
    printf("\nResult = %5.2f\n", Result);
}

void InitStack()
{
    S.Top = -1;
}

void PushOp(float Num)
{
    if (S.Top == SIZE - 1) {  
        printf("Overflow.\n");
        return;
    }
	S.Oprd[++S.Top] = Num;
}

float PopOp()
{
    if (S.Top == -1){
    	printf("Underflow.\n");
        return -1;
	}
    return S.Oprd[S.Top--];
}

void Process(char Optr)
{
    float Result = 0;
    float Num2 = PopOp();
    float Num1 = PopOp();

    switch (Optr) {
        case '+': 
			Result = Num1 + Num2; 
			break;
        case '-': 
			Result = Num1 - Num2; 
			break;
        case '*': 
			Result = Num1 * Num2; 
			break;
        case '^': 
			Result = pow(Num1, Num2); 
			break;
        case '/':
            if (Num2 != 0)
                Result = Num1 / Num2;
            else {
                printf("Divide by zero error.\n");
                return;
            }
            break;
    }
    PushOp(Result);
}

float EvalFix(char PostFix[])
{
    char Ch;
    float Num;
    int i = 0;

    while ((Ch = PostFix[i++]) != '\0') {
        if (Ch >= '0' && Ch <= '9')
            PushOp(Ch - '0');
        else if (strchr("+-/*^", Ch))
            Process(Ch);
    }
    return PopOp();
}
