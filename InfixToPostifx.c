#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // for isalnum()

#define SIZE 30

typedef struct StackType {
    int Optrs[SIZE];
    int Top;
} STACK;

STACK S;

void InitStack();
void Push(int Optr);
int Pop();
int StackExist();
int Precedence(char Optr);
char *InfixToPost(char Infix[]);

int main() {
    char InFix[30], *PostFix;

    InitStack();
    printf("Program to convert infix to postfix\n");

    printf("\n\nEnter InFix:\n");
    gets(InFix);

    PostFix = InfixToPost(InFix);

    printf("\n\nPostFix:\n");
    puts(PostFix);
    return 0;
}

void InitStack() {
    S.Top = -1;
}

void Push(int Optr) {
    if (S.Top == SIZE - 1) {  
        printf("Overflow.\n");
        return;
    }
    S.Optrs[++S.Top] = Optr;
}

int Pop() {
    if (S.Top == -1) { 
        printf("Underflow.\n");
        return -1;
    }
    return S.Optrs[S.Top--];
}

int Precedence(char Optr) {
    int P;
    switch (Optr) {
        case '^':
            P = 5;
            break;
        case '*':
        case '/':
            P = 4;
            break;
        case '+':
        case '-':
            P = 3;
            break;
        case '(':
            P = 2;
            break;
        case ')':
            P = 1;
            break;
        default:
            printf("Invalid Expression: %c\n", Optr);
            break;
    }
    return P;
}

char *InfixToPost(char InFix[]) {
    int i = 0, j = 0;
    char Optr, OptrStack;
    static char Postfix[30];

    while ((Optr = InFix[j]) != '\0') {
        if (Optr == '(') {
            Push(Optr);
        } else if (isalnum(Optr)) {
            Postfix[i++] = Optr;
            Postfix[i++] = ' ';
        } else if (strchr("+-*/^", Optr)) {
            while (S.Top != -1 && Precedence(OptrStack = Pop()) >= Precedence(Optr)) {
                Postfix[i++] = OptrStack;
                Postfix[i++] = ' ';
            }
            Push(OptrStack);
            Push(Optr);
        } else if (Optr == ')') {
            while (S.Top != -1 && (OptrStack = Pop()) != '(') {
                Postfix[i++] = OptrStack;
                Postfix[i++] = ' ';
            }
        }
        j++;
    }

    while (S.Top != -1) {
        Postfix[i++] = Pop();
        Postfix[i++] = ' ';
    }
    Postfix[i] = '\0';
    return Postfix;
}
