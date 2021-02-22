#include <stdio.h>
#include <stdlib.h>

void swap(int A[], int x, int y){
    int buff = A[x];
    A[x] = A[y];
    A[y] = buff;
}

int Divide(int A[], int low, int high){
    int size = high - low;
    int leftBuffer[size], rightBuffer[size];
    int leftCount = 0, rightCount = 0;
    
    for(int i=low; i<high; i++){
        if(A[i] <= A[high]){
            leftBuffer[leftCount] = A[i];
            leftCount++;
        }else{
            rightBuffer[rightCount] = A[i];
            rightCount++;
        }
    }

    for(int i=0; i<leftCount; i++)
        A[low+i] = leftBuffer[i];
    
    A[low+leftCount] = A[high];
    
    for(int i=0; i<rightCount; i++)
        A[low+leftCount+1+i] = rightBuffer[i];
    
    return low+leftCount;
}

void QuickSort(int A[], int low, int high){
    if(low < high){
        int mid = Divide(A,low,high);
        QuickSort(A,low,mid-1);
        QuickSort(A,mid+1,high);
    }
}

void printArray(int A[], int n, int pivot){
    for(int i=0; i<n; i++){
        if(A[i] == pivot)
            printf("[%d] ",A[i]);
        else
            printf("%d ",A[i]);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0; i<n; i++)
        scanf("%d",&A[i]);
    
    int pivot = A[n-1];

    QuickSort(A,0,n-1);
    printf("\n");
    printArray(A,n,pivot);

    return 0;
}