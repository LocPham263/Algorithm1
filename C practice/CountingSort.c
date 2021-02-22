#include <stdio.h>
#include <stdlib.h>

void CountingSort(int A[], int n, int B[], int k){
    int C[k+1];
    for(int i=0; i<=k; i++)
        C[i] = 0;
    for(int i=0; i<n; i++)
        C[A[i]]++;
    for(int i=1; i<=k; i++)
        C[i] = C[i] + C[i-1];
    
    int x=0;
    if(C[0]!=0){
        int y=C[0];
        while(y!=0){
            B[x] = 0;
            x++;
            y--;
        }
    }
    for(int i=1; i<=k; i++){
        if(C[i]-C[i-1]!=0){
            int y=C[i]-C[i-1];
            while(y!=0){
                B[x] = i;
                x++;
                y--;
            }
        }    
    }
}

void printArray(int A[], int n){
    for(int i=0; i<n; i++)
        printf("%d ",A[i]);
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    int A[n], B[n];
    int max=0;
    for(int i=0; i<n; i++){
        scanf("%d",&A[i]);
        if(max < A[i])
            max = A[i];
    }
    CountingSort(A,n,B,max);
    printArray(B,n);
    
    return 0;
}