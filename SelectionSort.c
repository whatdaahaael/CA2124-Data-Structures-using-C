/*
		SeSort.c
		Sujan
*/

#include <stdio.h>
#include <stdlib.h>

//Prototypes
void InArr(int A[20], int N);
void SeSort(int A[20], int N);
void PrArr(int A[20], int N);

main()
{
	int A[20], N, i, j, temp=0;
	
	printf("Enter size:\n");
	scanf("%d",&N);
	
	printf("Enter %d Numbers:\n",N);
	InArr(A,N);
	
	printf("Numbers are:\n");
	PrArr(A,N);
	
	printf("Sorted Numbers are:\n");
	SeSort(A,N);
	PrArr(A,N);
	
}

// Input Numbers
void InArr(int A[20], int N)
{
	int i;
	for(i=1;i<=N;i++) {
		scanf("%d",&A[i]);
	}
	printf("\n");
}

// Perform Sort
void SeSort(int A[20], int N)
{
	int i,j,Min,Loc;
	for(i=1;i<=N-1;i++){
		Min=A[i];
		Loc=i;
		for(j=i+1;j<=N;j++){
			if(A[j]<Min){
				Min=A[j];
				Loc=j;
			}
		}
		A[Loc]=A[i];
		A[i]=Min;
	}
}

// Print Numbers
void PrArr(int A[20], int N)
{
	int i;
	for(i=1;i<=N;i++) {
		printf("%d\t",A[i]);
	}
	printf("\n");
}
