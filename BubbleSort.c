/*
		BubbleSort.c
		Sujan
*/

#include <stdio.h>
#include <stdlib.h>

//Prototypes
void InArr(int A[20], int N);
void BuSort(int A[20], int N);
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
	BuSort(A,N);
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
void BuSort(int A[20], int N)
{
	int i,j;
	for(i=1;i<=N-1;i++){
		for(j=1;j<=N-i;j++){
			if(A[j]>A[j+1]){
				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
}

// Print Numbers
void PrArr(int A[20], int N)
{
	int i;
	for(i=1;i<=N;i++) {
		printf("%d\n",A[i]);
	}
	printf("\n");
}
