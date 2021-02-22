#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int left, int right){
    int mid = (left+right)/2;
    int len1 = mid - left + 1;
    int len2 = right - mid;

    int A1[len1], A2[len2];
    for(int i=0; i<len1; i++)
        A1[i] = A[left+i];
    for(int i=0; i<len2; i++)
        A2[i] = A[mid+1+i];
    
    int counter1 = 0, counter2 = 0, counter = left;
    while(counter1 != len1 && counter2 != len2){
        if(A1[counter1] <= A2[counter2]){
            A[counter] = A1[counter1];
            counter++;
            counter1++;
        }else{
            A[counter] = A2[counter2];
            counter++;
            counter2++;
        }
    }

    while(counter1 != len1){
        A[counter] = A1[counter1];
        counter++;
        counter1++;
    }

    while(counter2 != len2){
        A[counter] = A2[counter2];
        counter++;
        counter2++;
    }
}

void mergeSort(int A[], int left, int right){
    if(left != right){
        int mid = (left+right)/2;

        mergeSort(A,left,mid);
        mergeSort(A,mid+1,right);
        merge(A,left,right);
    }
}

int main(){    
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0; i<n; i++)
        scanf("%d",&A[i]);
    mergeSort(A,0,n-1);
    for(int i=0; i<n; i++)
        printf("%d ",A[i]);
    printf("\n");

    return 0;
}