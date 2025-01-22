/*------------------------
		CircularQueue.c
		Sujan
------------------------*/
#include <stdio.h>
#include <stdlib.h>

// Struct
typedef struct QueueType {
    int Data;
    struct QueueType *Next;
} CIRQUEUENODE;

// Global Variables
CIRQUEUENODE *Front, *Rear;

// Prototypes
void InitQueue();
void EnQueue(int Num);
void DisplayQueue();
int DeQueue();
void Menu(int *Choice);

int main() {
    int Choice, Num;

    InitQueue();

    while (1) {
        Menu(&Choice);

        switch (Choice) {
            case 1:
                printf("Enter Num:\n");
                scanf("%d", &Num);
                EnQueue(Num);
                break;
            case 2:
                printf("Queue is:\n");
                DisplayQueue();
                break;
            case 3:
                Num = DeQueue();
                if (Num == -1) {
                    printf("Queue is empty...\n");
                } else {
                    printf("%d Number Dequeued", Num);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice.\n");
                break;
        }

        printf("\n\nPress Enter to continue...\n");
        getchar();
        getchar();
    }

    return 0;
}

// Initialize Queue
void InitQueue() {
    Front = NULL;
    Rear = NULL;
}

// Enqueue a Number
void EnQueue(int Num) {
    CIRQUEUENODE *Node;
    Node = (CIRQUEUENODE *)malloc(sizeof(CIRQUEUENODE));
    Node->Data = Num;
    Node->Next = NULL;

    // Case 1: Queue is empty
    if (Rear == NULL) {
        Front = Node;
        Rear = Node;
        Rear->Next = Front;
        return;
    }

    // Case 2: General
    Rear->Next = Node;
    Rear = Node;
    Rear->Next = Front;
}

// Display Queue
void DisplayQueue() {
    CIRQUEUENODE *Curr;

    // Case 1: Queue is Empty
    if (Front == NULL) {
        printf("Queue is empty...\n");
        return;
    }

    // Case 2: Print the full Queue
    Curr = Front;
    do {
        printf("%d ", Curr->Data);
        if(Curr->Next!=Front){
            printf("| ");
        }
        Curr = Curr->Next;
    } while (Curr != Front);
    printf("\n");
}

// Dequeue the Front Number
int DeQueue() {
    int Num;
    CIRQUEUENODE *Curr;

    // Case 1: Queue is Empty
    if (Front == NULL) {
        return -1;
    }

    // Case 2: Only one element
    if (Front == Rear) {
        Num = Front->Data;
        free(Front);
        Front = Rear = NULL;
        return Num;
    }

    // Case 3: General case
    Curr = Front;
    Num = Curr->Data;
    Front = Curr->Next;
    Rear->Next = Front;
    free(Curr);

    return Num;
}

// Menu
void Menu(int *Choice) {
    system("cls");
    printf("\t\tQUEUE\n\tLinked List Implementation\n");
    printf("Menu:\n");
    printf("1. Enqueue Number\n2. Display Queue\n3. Dequeue\n4. Exit\n");
    printf("\nEnter Choice: ");
    scanf("%d", Choice);
    printf("\n\n\n\n\n\n");
}
