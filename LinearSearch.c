/*
		LinearSearch.c
		Sujan
*/

#include <stdio.h>
#include <stdlib.h>

//Prototypes
void InputArray(int A[20], int N);
int LinearSearch(int A[20], int N, int SN);
void PrintArray(int A[20], int N);

main()
{
	int A[20], N, SN, Index;
	
	printf("Enter size:\n");
	scanf("%d", &N);
	
	printf("Enter %d Numbers:\n", N);
	InputArray(A,N);
	
	printf("Enter Search Number:\n");
	scanf("%d", &SN);
	
	printf("Numbers are:\n");
	PrintArray(A,N);
	
	Index=LinearSearch(A, N, SN);
	if (Index==-1){
		printf("Not Found.");
	}else{
		printf("%d Found at %d position.", SN, Index);
	}
	
}

// Input Numbers
void InputArray(int A[20], int N)
{
	int i;
	for (i=1;i<=N;i++) {
		scanf("%d",&A[i]);
	}
	printf("\n");
}

// Perform Search
int LinearSearch(int A[20], int N, int SN)
{
	int i;
	for (i=1;i<=N-1;i++){
		if (A[i]==SN){
			return i;
		}
	}
	
	return -1;
}

// Print Numbers
void PrintArray(int A[20], int N)
{
	int i;
	for (i=1;i<=N;i++) {
		printf("%d\t",A[i]);
	}
	printf("\n");
}
