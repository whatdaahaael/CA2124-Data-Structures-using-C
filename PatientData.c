/*------------------------
		PatientData.c
		Sujan
------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h> // NECESSARY FOR POINTERS
#include <string.h>

// Patient Data
typedef struct PType{
	char PName[36];
	char PID[36];
	char Sickness[36];
}PATIENT;
// Struct
typedef struct QueueType{
    PATIENT P;
    struct QueueType *Next;
} QUEUENODE;

// Global Variable
QUEUENODE *Front, *Rear;

// Prototypes
void InitQueue();
void EnQueue(PATIENT P);
void DisplayPatient(PATIENT P);
void DisplayQueue();
PATIENT DeQueue(int *Empty);
void Menu(int *Choice);

int main()
{
    int Choice, Empty;
    char ID[36];
	PATIENT PT;
    InitQueue();
		
	while(1){
		
		Menu(&Choice);
		
		switch(Choice){
			case 1:
				printf("Enter Patient ID:\n");
				scanf("%s", PT.PID);
				printf("Enter Patient Name:\n");
				scanf("%s", PT.PName);
				printf("Enter Patient Sickness:\n");
				scanf("%s", PT.Sickness);
				EnQueue(PT);
				break;
			case 2:
				printf("Patients Data:\n");
				DisplayQueue();
				break;
			case 3:
				PT=DeQueue(&Empty);
				if(Empty==-1){
					printf("Patients data is empty...\n");
				}else{
					DisplayPatient(PT);
        			printf("Has Been Discharged.\n");
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

// Initialize Queue
void InitQueue()
{
    Front=NULL;
    Rear=NULL;
}

// Enqueue a Number
void EnQueue(PATIENT PT)
{
    QUEUENODE *Node;
    Node=(QUEUENODE*)malloc(sizeof(QUEUENODE));
    Node->P=PT;
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

// Displaying Individual Patient Info
void DisplayPatient(PATIENT P)
{
	printf("ID\t| Name\t| Sickness\n");
    printf("%s\t| %s\t| %s\n", P.PID, P.PName, P.Sickness);
}
// Display Queue
void DisplayQueue()
{
    QUEUENODE *Curr;

    // Case 1: Queue is Empty
    if(Front==NULL){
        printf("is empty...\n");
        return;
    }

    // Case 2: Print the full Queue
    Curr=Front;
    printf("ID\t| Name\t| Sickness\n");
    while(Curr){
        printf("%s\t| %s\t| %s\n", Curr->P.PID,Curr->P.PName,Curr->P.Sickness);
        Curr=Curr->Next;
    }
    printf("\n");
}

// DeQueue the Front Number
PATIENT DeQueue(int *Empty) {
    PATIENT P;
    QUEUENODE *Curr;

    // Case 1: Queue is Empty
    if (Front == NULL) {
    	*Empty=-1;
        return P;
    }

    P = Front->P;
    Curr = Front;
    Front = Front->Next;

    free(Curr);

    // Edge Case: If queue becomes empty
    if (Front == NULL) {
        Rear = NULL;
    }
	
	*Empty=0;
    return P;
}

// Menu
void Menu(int *Choice)
{
	system("cls");
	printf("\t\tPATIENT DATA(QUEUE)\n\tLinked List Implementation\n");
	printf("Menu:\n");
	printf("1. Enqueue Patient\n2. Display Patient Data\n3. Dequeue\n4. Exit\n");
	printf("\nEnter Choice: ");
	scanf("%d", Choice);
	printf("\n\n\n\n\n\n");
}
