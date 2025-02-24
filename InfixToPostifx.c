#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30

typedef struct StackType{
	int Optrs[SIZE];
	int Top;
}STACK;

STACK S;

void InitStack();
void Push(int Optr);
int Pop();
int StackExist();
int Precedence(char Optr);
char *InfixToPost(char Infix[]);

main()
{
	char InFix[30], *PostFix;
	
	InitStack();
	printf("Program to convert infix to postix\n");
	
	printf("\n\nEnter InFix:\n");
	gets( InFix);
	
	PostFix=InfixToPost(InFix);
	
	printf("\n\nPostFix:\n");
	puts(PostFix);
	getch();
	
	
}

void InitStack()
{
	S.Top=0;
}

void Push(int Optr)
{
	if(StackExist()==0){
		printf("Overflow.\n");
		return;
	}
	
	S.Top++;
	S.Optrs[S.Top]=Optr;
}

int Pop()
{
	int Optr;
	if(StackExist()==-1){
		printf("Underflow.\n");
		return -1;
	}
	
	Optr=S.Optrs[S.Top];
	S.Top--;
	return Optr;
}

int StackExist()
{
    if (S.Top == 0)    // Stack is empty
        return -1; 
    if (S.Top == SIZE - 1)  // Stack is full
        return 0; 
    return 1;  // Stack has elements
}

int Precedence(char Optr)
{
	int P;
	switch(Optr){
		case '^':
			P=5;
			break;
		case '*':
		case '/':
			P=4;
			break;
		case '+':
		case '-':
			P=3;
			break;
		case '(':
			P=2;
			break;
		case ')':
			P=1;
			break;
	}
	return P;
}

char *InfixToPost(char InFix[])
{
	int i, j;
	char Optr, OptrStack, Prec, PrecStack;
	static char Postfix[30];
	i=0;
	j=0;
	while((Optr=InFix[j]) != '\0'){
		if(Optr=='('){
			Push(Optr);
		} else if(Optr>='A' && Optr<='Z' || Optr>='a' && Optr<='z' || Optr>='0' && Optr<='9' ){
			Postfix[i++]=Optr;
			Postfix[i++]=' ';
		} else if(strchr("+-*/^", Optr)){
			if(StackExist()==-1){//StackEmpty()
				Push(Optr);
			} else {
				do{
					OptrStack=Pop();
					Prec=Precedence(Optr);
					PrecStack=Precedence(OptrStack);
					if(PrecStack>=Prec){
						Postfix[i++]=OptrStack;
						Postfix[i++]=' ';
					}
				} while(StackExist()==1 && PrecStack>=Prec);//!StackEmpty()
				
				if(PrecStack<Prec){
					Push(OptrStack);
					Push(Optr);
				} else {
					Push(Optr);
				}
			}
		} else if(Optr==')'){
			OptrStack=Pop();
			while(OptrStack!='(' && StackExist()==1){//!StackEmpty()
				Postfix[i++]=OptrStack;
				Postfix[i++]=' ';
				OptrStack=Pop();
			}
		}
		j++;
	}
	while(StackExist()==1){//!StackEmpty()
		Postfix[i++]=Pop();
		Postfix[i++]=' ';
	}
	Postfix[i]='\0';
	return Postfix;
}

