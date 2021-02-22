#include <stdio.h>
#include <stdlib.h>

void swap(int A[], int x, int y){
    int buff = A[x];
    A[x] = A[y];
    A[y] = buff;
}

int Divide(int A[], int low, int high){
    int i = low-1;
    for(int j=low; j<high; j++){
        if(A[j] <= A[high]){
            i++;
            swap(A,j,i);
        }
    }
    swap(A,i+1,high);

    return i+1;
}

int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0; i<n; i++)
        scanf("%d",&A[i]);

    int pivot = Divide(A,0,n-1);
    printf("\n");
    
    for(int i=0; i<n; i++){
        if(i == pivot)
            printf("[%d] ",A[i]);
        else
            printf("%d ",A[i]);
    }
    printf("\n");

    return 0;
}