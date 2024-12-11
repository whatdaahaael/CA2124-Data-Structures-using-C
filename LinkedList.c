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
void Menu(int *Choice);

main()
{
	int Choice, Num;
	
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
void InitList(){
	Head=NULL;
}

// Insert into List
void InLL(int Num){
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

void DisList(LN *Head){
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

void DelNum(int Num){
	LN *Prev, *Curr;
	
	if(Head==NULL){
		printf("List Empty.\n");
		return;
	}
	
	Curr=Head;
	while (Curr!=NULL && Curr->Data!=Num) {
        Prev=Curr;
        Curr=Curr->Next;
    }
    
	if(Curr==NULL){
		printf("Number does not Exist.\n");
		return;
	}
	
	if(Prev == NULL) {
        Head = Curr->Next;
    } else {
        Prev->Next = Curr->Next;
    }
    printf("Number Deleted.\n");
}

void Menu(int *Choice){
	system("cls");
	printf("Enter Choice:\n");
	printf("1. Insert Number\n2. Display List\n3. Delete A Number\n4. Exit\n");
	scanf("%d", Choice);
	printf("\n\n\n\n\n\n");
}
