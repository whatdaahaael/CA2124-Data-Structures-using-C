/*------------------------
		Queue.c
		Sujan
------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h> // NECESSARY FOR POINTERS

// Struct
typedef struct QueueType{
    int Data;
    struct QueueType *Next;
} QUEUENODE;

// Global Variable
QUEUENODE *Front, *Rear;

// Prototypes
void InitQueue();
void EnQueue(int Num);
void DisplayQueue();
int Dequeue();
void Menu(int *Choice);

int main()
{
    int Choice, Num;

    InitQueue();
		
	while(1){
		
		Menu(&Choice);
		
		switch(Choice){
			case 1:
				printf("Enter Num:\n");
				scanf("%d",&Num);
				EnQueue(Num);
				break;
			case 2:
				printf("Queue is:\n");
				DisplayQueue();
				break;
			case 3:
				Num=DeQueue();
				if(Num!=-9999)
					printf("%d Number Dequeued", Num);
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

// Initialize Queue
void InitQueue()
{
    Front=NULL;
    Rear=NULL;
}

// Enqueue a Number
void EnQueue(int Num)
{
    QUEUENODE *Node;
    Node=(QUEUENODE*)malloc(sizeof(QUEUENODE));
    Node->Data=Num;
    Node->Next=NULL;

    // Case 1: Queue is empty
    if(Rear==NULL){
        Rear=Node;
        Front=Node;
        return;
    }

    // Case 2: General
    Rear->Next=Node;
    Rear=Node;
}

// Display Queue
void DisplayQueue()
{
    QUEUENODE *Q;

    // Case 1: Queue is Empty
    if(Front==NULL){
        printf("Queue is empty...\n");
        return;
    }

    // Case 2: Print the full Queue
    Q=Front;
    while(Q){
        printf("%d ", Q->Data);
        if(Q->Next!=NULL){
            printf("| ");
        }
        Q=Q->Next;
    }
    printf("\n");
}

// DeQueue the Front Number
int DeQueue() {
    int Num;
    QUEUENODE *Temp;

    // Case 1: Queue is Empty
    if (Front == NULL) {
        printf("Queue is empty...\n");
        return -9999;
    }

    Num = Front->Data;
    Temp = Front;
    Front = Front->Next;

    free(Temp);

    // Edge Case: If queue becomes empty
    if (Front == NULL) {
        Rear = NULL;
    }

    return Num;
}

// Menu
void Menu(int *Choice)
{
	system("cls");
	printf("\t\tQUEUE\n\tLinked List Implementation\n");
	printf("Menu:\n");
	printf("1. Enqueue Number\n2. Display Queue\n3. Dequeue\n4. Exit\n");
	printf("\nEnter Choice: ");
	scanf("%d", Choice);
	printf("\n\n\n\n\n\n");
}
