/*
		OrderedLinkedList.c
		Sujan
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h> // NECESSARY FOR POINTERS

// Struct
typedef struct ListType{
	int Data;
	struct ListType *Next;
}LISTNODE;

// Global Variable
LISTNODE *Head;

// Prototypes
void InitializeList();
void InsertLinkedList(int Num);
void DisplayList(); // {10->20->30->40...}
void DeleteNumber(int Num);
int LinearSearch(int Num);
int Size();
void Menu(int *Choice);

main()
{
	int Choice, Num, Max, Found, NumNodes;
	
	InitializeList();
		
	while(1){
		
		Menu(&Choice);
		
		switch(Choice){
			case 1:
				printf("Enter Num:\n");
				scanf("%d",&Num);
				InsertLinkedList(Num);
				break;
			case 2:
				printf("List is:\n");
				DisplayList();
				break;
			case 3:
				printf("Enter Num:\n");
				scanf("%d",&Num);
				DeleteNumber(Num);
				break;
			case 4:
				printf("Enter Num:\n");
				scanf("%d",&Num);
				Found=LinearSearch(Num);
				if (Found==1){
					printf("Number is found\n");
				}else{
					printf("Number not found\n");
				}
				break;
			case 5:
				NumNodes=Size();
				if(NumNodes==-1){
					printf("List is Empty\n");
				}else{
					printf("There are %d Nodes\n", NumNodes);
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
void InitializeList()
{
	Head=NULL;
}

// 1. Insert into List
void InsertLinkedList(int Num)
{
	LISTNODE *Prev, *Curr, *Node;
	
	Node=(LISTNODE*)malloc(sizeof(LISTNODE));
	Node->Data=Num;
	Node->Next=NULL;
	
	// Case 1 - No Head
	if(Head==NULL){
		Head=Node;
		return;
	}
	
	// Case 2
	if(Num<=Head->Data){
		Node->Next=Head;
		Head=Node;
		return;
	}
	Curr=Head;
	while(Curr && Num>=Curr->Data){
		Prev=Curr;
		Curr=Curr->Next;
	}
	Prev->Next=Node;
	Node->Next=Curr;
}

// 2. Display Contents of List
void DisplayList()
{
	LISTNODE *Curr;
	
	// Case 1: No List
	if(Head==NULL){
		printf("Empty.\n");
		return;
	}
	
	
	// Case 2: List is available
	Curr=Head;
	while(Curr != NULL){
		printf("%d ", Curr->Data);
		if(Curr->Next!=NULL){ // 20->30->40->50
			printf("-> ");
		}
		Curr=Curr->Next;
	}
	printf("\n");
}

// 3. Delete Number
void DeleteNumber(int Num)
{
	LISTNODE *Prev, *Curr;
	Prev=Curr=Head;
	
	// Case 1: No List
	if(Head == NULL){
		printf("No List...\n");
		free(Curr);
		return;
	}
	
	// Case 2: Number at Head of list
	if(Num == Curr->Data){
		Head=Curr->Next;
		free(Curr);
		printf("%d Deleted from List.\n", Num);
		return;
	}
	
	while(Curr->Data != Num && Curr->Next!=NULL){
		Prev = Curr;
		Curr = Curr->Next;
	}
	
	// Case 3: Number in between
	if(Curr->Data==Num){
		Prev->Next=Curr->Next;
		free(Curr);
		printf("%d Deleted from List.\n", Num);
		return;
	} else {
		printf("%d not found in the list.", Num);
	}	
}

// 4. Linear Search
int LinearSearch(int Num)
{
	LISTNODE *Curr;
	
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

// 5. Size
int Size()
{
	LISTNODE *Curr;
	int Count=0;
	
	// Case 1: No list
	if(Head==NULL){
		return -1;
	}
	
	// Case 2: Only one number
	if (Head->Next == NULL) {
        return 1;
    }
    
    // Case 3: Full List
	Curr=Head;
	while(Curr!=NULL){
		Count+=1;
		Curr=Curr->Next;
	}
	return Count;
}

// Menu
void Menu(int *Choice)
{
	system("cls");
	printf("\t\tLINKED LIST\n");
	printf("Menu:\n");
	printf("1. Insert Number\n2. Display List\n3. Delete A Number\n4. Search Number\n5. Size\n6. Exit\n");
	printf("\nEnter Choice: ");
	scanf("%d", Choice);
	printf("\n\n\n\n\n\n");
}
