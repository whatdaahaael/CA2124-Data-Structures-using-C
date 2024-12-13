/*
		LinkedList.c
		Sujan
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h> // NECESSARY FOR POINTERS

// Struct
typedef struct ListType{
	int Data;
	struct ListType *Next;
}LN;

// Global Variable
LN *Head;

// Prototypes
void InitList();
void InLL(int Num);
void DisList(LN *Head); // {10->20->30->40...}
void DelNum(int Num);
int LinSea(int Num);
int MaxNo();
void Menu(int *Choice);

main()
{
	int Choice, Num, Max;
	
	InitList();
		
	while(1){
		
		Menu(&Choice);
		
		switch(Choice){
			case 1:
				printf("Enter Num:\n");
				scanf("%d",&Num);
				InLL(Num);
				break;
			case 2:
				printf("List is:\n");
				DisList(Head);
				break;
			case 3:
				printf("Enter Num:\n");
				scanf("%d",&Num);
				DelNum(Num);
				break;
			case 4:
				printf("Enter Num:\n");
				scanf("%d",&Num);
				int Found=LinSea(Num);
				if (Found==1){
					printf("Number is found\n");
				}else{
					printf("Number not found\n");
				}
				break;
			case 5:
				Max=MaxNo();
				if(Max==-1){
					printf("List is Empty\n");
				}else{
					printf("%d is the greatest\n",Max);
				}
				break;
			    	
			case 6:
				exit('1');
			default:
				printf("Invalid Choice.\n");
				break;
		}
		
		printf("\n\nPress Enter to continue...\n");
		getch();
	}

}

// Initialize List
void InitList()
{
	Head=NULL;
}

// 1. Insert into List
void InLL(int Num)
{
	LN *Prev, *Curr, *Node;
	
	Node=(LN*)malloc(sizeof(LN));
	Node->Data=Num;
	Node->Next=NULL;
	
	// Case 1 - No Head
	if(Head==NULL){
		Head=Node;
		return;
	}
	
	// Case 2
	Curr=Head;
	while(Curr != NULL){
		Prev=Curr;
		Curr=Curr->Next;
	}
	Prev->Next=Node;
}

// 2. Display Contents of List
void DisList(LN *Head)
{
	LN *Curr;
	
	if(Head==NULL){
		printf("Empty.\n");
		return;
	}
	
	Curr=Head;
	while(Curr != NULL){
		printf("%d ", Curr->Data);
		if(Curr->Next!=NULL){
			printf("-> ");
		}
		Curr=Curr->Next;
	}
	printf("\n");
}

// 3. Delete a Number
void DelNum(int Num)
{
	LN *Prev, *Curr;
	
	// List is Empty
	if(Head==NULL){
		printf("List Empty.\n");
		return;
	}
	
	Curr=Head;
	while (Curr!=NULL && Curr->Data!=Num) {
        Prev=Curr;
        Curr=Curr->Next;
    }
    
    // Number Does not exist
	if(Curr==NULL){
		printf("Number does not Exist.\n");
		return;
	}
	
	// Located at head
	if(Prev == NULL) {
        Head = Curr->Next;
    } else { // Located elsewhere
        Prev->Next = Curr->Next;
    }
    printf("Number Deleted.\n");
}

// 4. Linear Search
int LinSea(int Num)
{
	LN *Curr;
	
	//case 1: No list
	if(Head==NULL){
		return -1;
	}
	
	Curr=Head;
	while(Curr!=NULL){
		if(Curr->Data==Num){
			return 1;
		}
		Curr=Curr->Next;
	}
	return -1;
}

// 5. Max Number
int MaxNo()
{
	LN *Curr;
	int Max;
	
	// Case 1: No list
	if(Head==NULL){
		return -1;
	}
	
	// Case 2: Only one number
	if (Head->Next == NULL) {
		Max=Head->Data;
        return Max;
    }
    
    // Case 3: Full List
	Curr=Head;
	Max=Curr->Data;
	while(Curr!=NULL){
		if(Max<Curr->Data){
			Max=Curr->Data;
		}
		Curr=Curr->Next;
	}
	return Max;
}

// Menu
void Menu(int *Choice)
{
	system("cls");
	printf("\t\tLINKED LIST\n");
	printf("Menu:\n");
	printf("1. Insert Number\n2. Display List\n3. Delete A Number\n4. Search Number\n5. Max Number\n6. Exit\n");
	printf("\nEnter Choice: ");
	scanf("%d", Choice);
	printf("\n\n\n\n\n\n");
}
