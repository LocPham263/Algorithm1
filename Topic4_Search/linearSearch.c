#include <stdio.h>
#include <stdlib.h>

void printArray(int S[], int n){
    for(int i=0; i<n; i++){
        printf("%d ",S[i]);
    }
    printf("\n");
}

void bubbleSort(int S[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(S[i] < S[j]){
                int buffer = S[i];
                S[i] = S[j];
                S[j] = buffer;
            }
        }
    }
}

int linearSearch(int S[], int T[], int n, int q){
    int counter=0;
    bubbleSort(S,n);
    for(int i=0; i<n; i++){
        if(i!=n-1 && S[i]==S[i+1]) continue;
        for(int j=0; j<q; j++){
            if(S[i] == T[j]){
                counter++;
                break;
            }
        }
    }
    return counter;
}

int main(){
    // Input n
    int n;
    scanf("%d",&n);
    // Input S
    int S[n];
    for(int i=0; i<n; i++){
        scanf("%d",&S[i]);
    }
    // Inpupt q
    int q;
    scanf("%d",&q);
    // Input T
    int T[q];
    for(int i=0; i<q; i++){
        scanf("%d",&T[i]);
    }
    // Execution
    printf("\n%d\n",linearSearch(S,T,n,q));
    return 0;    
}