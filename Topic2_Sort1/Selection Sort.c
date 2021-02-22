#include <stdio.h>
#include <stdlib.h>

void Array_Print(int N, int A[]){
	for(int i=0; i<N; i++){
		if(i==N-1) printf("%d", A[i]);
		else 	   printf("%d ", A[i]);
	}
	printf("\n");
}

int Selection_Sort(int N, int A[]){
	int counter = 0;
	for(int i=0; i<N-1; i++){
		int min = i;
		for(int j=i+1; j<N; j++){
			if(A[j] < A[min]) min = j;
		}
		if(min != i){
			counter++;
			int k = A[min];
			A[min] = A[i];
			A[i] = k;
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
	// Selection_Sort 
	int counter = Selection_Sort(N,A);
	printf("%d\n", counter);
	return 0;
}