#include <stdio.h>
#include <stdlib.h>

void Array_Print(int N, int A[]){
	for(int i=0; i<N; i++){
		if(i==N-1) printf("%d", A[i]);
		else 	   printf("%d ", A[i]);
	}
	printf("\n");
}

int Bubble_Sort(int N, int A[]){
	int counter = 0;
	for(int i=0; i<N-1; i++){
		for(int j=N-1; j>=i+1; j--){
			int k = A[j];
			if(A[j-1] > A[j]){
				counter++ ;
				A[j] = A[j-1];
				A[j-1] = k;
			}
		}
	}
	Array_Print(N,A);
	return counter;
}

int main(int argc, char const *argv[])
{
	// Input the total number of elements
	int N;
	scanf("%d", &N);
	// Input elements in the list
	int A[N];
	for(int i=0; i<N; i++){
		scanf("%d", &A[i]);
	}
	// Bubble Sort
	int counter = Bubble_Sort(N,A);
	printf("%d\n", counter);
	return 0;
}