/*
		BinarySearch.c
		Sujan
*/

#include <stdio.h>
#include <stdlib.h>

//Prototypes
void InputArray(int A[20], int N);
int BinarySearch(int A[20], int N, int SN);
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
	
	Index=BinarySearch(A, N, SN);
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
int BinarySearch(int A[20], int N, int SN)
{
	int High, Low, Mid;
	High=N;
	Low=1;
	while (Low<=High){
		Mid=(High+Low)/2;
		if (A[Mid]==SN){
			return Mid;
			break;
		} else if (A[Mid]>SN) {
			High=Mid-1;
		} else {
			Low=Mid+1;
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
