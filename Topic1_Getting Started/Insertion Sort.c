#include<stdio.h>
#include<stdlib.h>

void Array_Print(int N, int A[]){
	for(int i=0; i<N; i++){
		if(i == N-1) printf("%d", A[i]);
		else printf("%d ", A[i]);
	}
	printf("\n");
}

void Insertion_Sort(int N, int A[]){
	int k,i,j;
	for(i=1; i<N; i++){
		k = A[i];
		if(A[i-1] > A[i]){
			A[i] = A[i-1];
			A[i-1] = k;
		}
		for(j=i-1; j>=0; j--){
			if(A[j-1] > A[j]){
				A[j] = A[j-1];
				A[j-1] = k;
			}
			else break;
		}
		Array_Print(N,A);
	}
}

int main(int argc, char const *argv[]){
	// Input the number of elements in array A
	int N;
	scanf("%d", &N);
	// Input elements in array A
	int A[N+1];
	for(int i=0; i<N; i++){
		scanf("%d", &A[i]);
	} 
	// printf("\n");
	Array_Print(N,A);
	// Insertion Sort
	Insertion_Sort(N,A);
	return 0;
}