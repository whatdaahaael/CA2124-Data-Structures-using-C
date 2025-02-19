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
TREENODE* SearchBinTree(int Num, int *Found);
int isLeafNode(TREENODE *Root);
void DisplayLeafNodes(TREENODE *Root);
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
				Node=SearchBinTree(Num, &Found);
				if(Found==-1){
					printf("Not Found.\n");
				} else {
					printf("Found.\n");
				}
				break;
			case 6:
				DisplayLeafNodes(Root);
				break;
			case 7:
				printf("Enter Num:\n");
				scanf("%d",&Num);
				Node=SearchBinTree(Num, &Found);
				if(Found==-1){
					printf("Not Found.\n");
				} else {
					printf("Found.\n");
					if(isLeafNode(Node)==1){
						printf("Is Leaf Node.\n");
					}else{
						printf("Is not Leaf Node.\n");
					}
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
TREENODE* SearchBinTree(int Num, int *Found)
{
	TREENODE *Curr;
	
	// Case 1 - No Tree
	if(Root==NULL){
		*Found=-1;
		return NULL;
	}
	
	Curr = Root;
	while(Curr){
		if(Curr->Data == Num){
			*Found=1;
			return Curr;
		} else {
			if(Num < Curr->Data){
				Curr=Curr->Left;
			} else {
				Curr=Curr->Right;
			}
		}
	}
	*Found=-1;
	return NULL;
}

// Checking if a node is a leaf node
int isLeafNode(TREENODE *Root)
{
	if(Root->Left == NULL && Root->Right == NULL){
		return 1;
	}
	return 0;
}

// 6. Displaying Leaf Nodes
void DisplayLeafNodes(TREENODE *Root)
{
	// Case 1 - No Tree
	if(Root==NULL){
		return;
	}
	
	if(isLeafNode(Root)){
		printf("%d Is a leaf Node\n", Root->Data);
	}
	DisplayLeafNodes(Root->Left);
	DisplayLeafNodes(Root->Right);
	
}

// Menu
void Menu(int *Choice)
{
	system("cls");
	printf("\t\tBINARY SEARCH TREE\n");
	printf("Menu:\n");
	printf("1. Insert Number\n2. PreOrder\n3. InOrder\n4. PostOrder\n5. Search Number\n6. Display All Leaf Nodes\n7. Search for a number and check if it is a leaf node.\n8. Exit\n");
	printf("\nEnter Choice: ");
	scanf("%d", Choice);
	printf("\n\n\n\n\n\n");
}
