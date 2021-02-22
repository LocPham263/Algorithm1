#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool b = 0;

void solve(int A[], int i, int M){
    if(b == 0){
        if(M - A[i] == 0)
            b = 1;
        else if(A[i] == '\0')
            b = 0;
        else{
            if(M-A[i] > 0)
                solve(A,i+1,M-A[i]);
            solve(A,i+1,M);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int A[n+1];
    for(int i=0; i<n; i++)
        scanf("%d",&A[i]);
    A[n] = '\0';

    int q;
    scanf("%d",&q);
    int Q[q];
    for(int i=0; i<q; i++){
        scanf("%d",&Q[i]);
        solve(A,0,Q[i]);
        if(b == 1){
            printf("yes\n");
            b = 0;
        }else
            printf("no\n");
    }

    return 0;
}