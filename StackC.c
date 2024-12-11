#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

// Stack Data Type
typedef struct StackType{
	int A[SIZE];
	int Top;
}STACK;

STACK S;

// Prototyeps
void Push(int Num);
int fnIsStackEmpty();
int Pop();
void DisplayStack();
void fnMenu(int *Choice);

void main(){
	int Num, Choice;
	S.Top=0;
	
	fnMenu(&Choice);
	while(Choice){
		switch(Choice){
			case 1:
				printf("Enter a Number: ");
				scanf("%d", &Num);
				Push(Num);
				getch();
				break;
			case 2:
				if(!fnIsStackEmpty()){
					Num=Pop();
					printf("Deleted Item=%d\n", Num);
				} else {
					printf("Stack is Empty.\n");
				}
				getch();
				break;
			case 3:
				DisplayStack();
				getch();
				break;
			case 4:
				exit(1);
			default:
				printf("Invalid Choice.\n");
		}
		fnMenu(&Choice);
	}
}

// Pushing/Entering items in Stack
void Push(int Num) {
	
	S.Top++;
	int Pos=S.Top;
	
	if(S.Top==SIZE) {
		printf("Stack Overflow!!\n");
		return;
	} else {
		S.A[Pos]=Num;
	}
}

// Checking if Stack is Empty
int fnIsStackEmpty(){
	if(S.Top==0){
		return 1;
	} else{
		return 0;
	}
}

// Removing one elment from the Stack
int Pop(){
	int Pos, Num;
	
	Pos=S.Top;
	Num=S.A[Pos];
	S.Top--;
	
	return Num;
}

void DisplayStack(){
	int i;
	
	if(fnIsStackEmpty()){
		printf("Stack is Empty.\n");
		return;	
	}
	for(i=S.Top;i>=1;i--){
		printf("%d\n",S.A[i]);
	}
}

void fnMenu(int *Choice){
	system("cls");
	printf("Enter Choice:\n");
	printf("1. Push\n2. Pop\n3. Display Stack\n4. Exit\n");
	scanf("%d", Choice);
}
