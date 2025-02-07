/*
		BinarySearchTree.c
		Sujan
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h> // NECESSARY FOR POINTERS

// Struct
typedef struct TreeType{ 
	struct TreeType *Left;
	int Data;
	struct TreeType *Right;
}TREENODE;

// Global Variable
TREENODE *Root;

// Prototypes
void InitializeTree();
void InsertTreeNode(int Num);
void PreOrder(TREENODE *Root);
void InOrder(TREENODE *Root);
void PostOrder(TREENODE *Root);
int SearchBinTree(int Num);
int MaxNumber(TREENODE *Root);
int MinNumber(TREENODE *Root);
void Menu(int *Choice);

main()
{
	TREENODE *Node;
	int Choice, Num, Max, Min, Found;
	
	InitializeTree();
		
	while(1){
		
		Menu(&Choice);
		
		switch(Choice){
			case 1:
				printf("Enter Num:\n");
				scanf("%d",&Num);
				InsertTreeNode(Num);
				break;
			case 2:
				printf("Tree is:\n");
				PreOrder(Root);
				break;
			case 3:
				printf("Tree is:\n");
				InOrder(Root);
				break;
			case 4:
				printf("Tree is:\n");
				PostOrder(Root);
				break;
			case 5:
				printf("Enter Num:\n");
				scanf("%d",&Num);
				Found=SearchBinTree(Num);
				if(Found==-1){
					printf("Not Found.\n");
				} else {
					printf("Found.\n");
				}
				break;
			case 6:
				Min=MinNumber(Root);
				if(Min==-1){
					printf("List is Empty\n");
				}else{
					printf("%d is the least\n",Min);
				}
				break;
			case 7:
				Max=MaxNumber(Root);
				if(Max==-1){
					printf("List is Empty\n");
				}else{
					printf("%d is the greatest\n",Max);
				}
				break;
			case 8:
				exit(1);
			default:
				printf("Invalid Choice.\n");
				break;
		}
		
		printf("\n\nPress Enter to continue...\n");
		getchar();
		getchar();
	}

}

// Initialize List
void InitializeTree()
{
	Root=NULL;
}

// 1. Insert into Tree
void InsertTreeNode(int Num)
{
	TREENODE *Prev = NULL, *Curr, *Node;
	
	Node=(TREENODE*)malloc(sizeof(TREENODE));
	Node->Left=NULL;
	Node->Data=Num;
	Node->Right=NULL;
	
	// Case 1 - No Tree
	if(Root==NULL){
		Root=Node;
		return;
	}
	
	// Case 2
	Curr=Root;
	while(Curr){
		if(Num<Curr->Data){
			Prev=Curr;
			Curr=Curr->Left;
		} else if(Num>Curr->Data){
			Prev=Curr;
			Curr=Curr->Right;
		}
	}
	
	if(Num<Prev->Data){
		Prev->Left=Node;
	} else {
		Prev->Right=Node;
	}
}

// 2. PreOrder
void PreOrder(TREENODE *Root)
{
	if(Root){
		printf(" %d ", Root->Data);
		PreOrder(Root->Left);
		PreOrder(Root->Right);
	}
}

// 3. InOrder
void InOrder(TREENODE *Root)
{
	if(Root){
		InOrder(Root->Left);
		printf(" %d ", Root->Data);
		InOrder(Root->Right);
	}
}

// 4. PostOrder
void PostOrder(TREENODE *Root)
{
	if(Root){
		PostOrder(Root->Left);
		PostOrder(Root->Right);
		printf(" %d ", Root->Data);
	}
}

// 5. Searching
int SearchBinTree(int Num)
{
	TREENODE *Curr;
	
	Curr = Root;
	while(Curr){
		if(Curr->Data == Num){
			return 1;
		} else {
			if(Num < Curr->Data){
				Curr=Curr->Left;
			} else {
				Curr=Curr->Right;
			}
		}
	}
	return -1;
}

// 6. Minimum Number
int MinNumber(TREENODE *Root)
{
	TREENODE *Curr, *Prev;
	int Min;
	
	// Case 1: No Tree
	if(Root==NULL){
		return -1;
	}
	
	// Case 2: Only one number
	if (Root->Left == NULL) {
		Min=Root->Data;
        return Min;
    }
    
    // Case 3: Full Tree
	Curr=Root;
	Min=Root->Data;
	while(Curr){
		Prev=Curr;
		Curr=Curr->Left;
	}
	Min=Prev->Data;
	return Min;
}

// 7. Max Number
int MaxNumber(TREENODE *Root)
{
	TREENODE *Curr, *Prev;
	int Max;
	
	// Case 1: No Tree
	if(Root==NULL){
		return -1;
	}
	
	// Case 2: Only one number
	if (Root->Right == NULL) {
		Max=Root->Data;
        return Max;
    }
    
    // Case 3: Full Tree
	Curr=Root;
	Max=Root->Data;
	while(Curr){
		Prev=Curr;
		Curr=Curr->Right;
	}
	Max=Prev->Data;
	return Max;
}

// Menu
void Menu(int *Choice)
{
	system("cls");
	printf("\t\tBINARY SEARCH TREE\n");
	printf("Menu:\n");
	printf("1. Insert Number\n2. PreOrder\n3. InOrder\n4. PostOrder\n5. Search Number\n6. Min Number\n7. Max Number\n8. Exit\n");
	printf("\nEnter Choice: ");
	scanf("%d", Choice);
	printf("\n\n\n\n\n\n");
}
