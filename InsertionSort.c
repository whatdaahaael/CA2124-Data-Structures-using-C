/*
		InsertionSort.c
		Sujan
*/

#include <stdio.h>
#include <stdlib.h>

//Prototypes
void InArr(int A[20], int N);
void InSort(int A[20], int N);
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
	InSort(A,N);
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
void InSort(int A[20], int N)
{
	int i,j,X;
	for(i=2;i<=N;i++){
		X=A[i];
		j=i-1;
		while((X<A[j]) && (j>=1)){
			A[j+1]=A[j];
			j=j-1;
		}
		A[j+1]=X;
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
