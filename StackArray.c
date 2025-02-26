#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef struct StackType{
	int A[SIZE];
	int Top;
}STACK;

STACK S;

void InitStack();
void Push(int Num);
void Display();
int Pop();
int StackExist();
void Menu(int *Choice);

main()
{
	int Choice, Num, N, i, Found;
	
	InitStack();
		
	while(1){
		
		Menu(&Choice);
		
		switch(Choice){
			case 1:
				printf("Enter Size:\n");
				scanf("%d", &N);
				for(i=0; i<N; i++){
					scanf("%d",&Num);
					Push(Num);
				}
				break;
			case 2:
				printf("Stack is:\n");
				Display();
				break;
			case 3:
				Num=Pop();
				if(Num!=-1){
					printf("%d Removed.\n", Num);
				}
				break;
			case 4:
				exit('1');
			default:
				printf("Invalid Choice.\n");
				break;
		}
		printf("\n\nPress Enter to continue...\n");
		getch();
	}
}

void InitStack()
{
	S.Top=0;
}

void Push(int Num)
{
	if(StackExist()==1){
		printf("Overflow.\n");
		return;
	}
	
	S.Top++;
	S.A[S.Top]=Num;
}

void Display()
{
	int i;
	
	if(StackExist()==-1){
		printf("Stack is Empty.\n");
		return;	
	}
	
	for(i=S.Top;i>0;i--){
		printf("%d\n", S.A[i]);
	}
}

int Pop()
{
	if(StackExist()==-1){
		printf("Underflow.\n");
		return -1;
	}
	
	int Num=S.A[S.Top];
	S.Top--;
	return Num;
}

int StackExist()
{
    if (S.Top == 0)    // Stack is empty
        return -1; 
    if (S.Top == SIZE - 1)  // Stack is full
        return 1; 
    return 0;  // Stack has elements
}

void Menu(int *Choice)
{
	system("cls");
	printf("\t\tSTACK\n");
	printf("Menu:\n");
	printf("1. Push\n2. Display Stack\n3. Pop\n4. Exit\n");
	printf("\nEnter Choice: ");
	scanf("%d", Choice);
	printf("\n\n\n\n\n\n");
}
