#include <stdio.h>
#include <stdlib.h>

int PN_Detector(int n){
	for(int i=2; i*i<=n; i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int counter = 0;
	// Input the total number of elements
	int N;
	scanf("%d", &N);
	// Input elements in the list
	int A[N];
	for(int i=0; i<N; i++){
		scanf("%d", &A[i]);
	}
	// Count the number of prime number in the list
	for(int i=0; i<N; i++){
		if(PN_Detector(A[i])==1) counter++;
	}
	printf("%d\n", counter);
	return 0;
}