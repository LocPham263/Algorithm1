#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Card{
    char suit;
    int val;
} Card;

void structCpy(Card A[], Card B[], int n){
    for(int i=0; i<n; i++){
        A[i].suit = B[i].suit;
        A[i].val = B[i].val;
    }
}

void structSwap(Card* A, Card* B){
    Card tmp = *A;
    *A = *B;
    *B = tmp;
}

void BubbleSort(Card A[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=n-1; j>i; j--){
            if(A[j].val < A[j-1].val)
                structSwap(A+j-1,A+j);
        }
    }    
}

void SelectionSort(Card A[], int n){
    for(int i=0; i<n; i++){
        int min = i;
        for(int j=i; j<n; j++){
            if(A[min].val > A[j].val)
                min = j;
        }
        structSwap(A+i,A+min);
    }
}

// A is the sorted array 
// B is the original array
bool stableTest(Card A[], Card B[], int n){
    int countA = 0;
    while(countA < n-1){
        if(A[countA].val == A[countA+1].val){
            int countRan = countA;
            while(A[countRan].val == A[countRan+1].val && countRan < n-1)
                countRan++;
            int countB = 0;
            while(countRan - countA >= 0){
                if(B[countB].val == A[countA].val){
                    if(B[countB].suit != A[countA].suit)
                        return 0;
                    countA++;
                }
                countB++;
            }
            countA--;
        }
        countA++;
    }
    return 1;
}

void printCard(Card A[], int n){
    for(int i=0; i<n; i++)
        printf("%c%d ",A[i].suit,A[i].val);
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    Card card[n], card1[n], card2[n];
    for(int i=0; i<n; i++){
        char input[3];
        scanf("%s",input);
        card[i].suit = input[0];
        card[i].val = atoi(&input[1]);
    }

    structCpy(card1,card,n);
    structCpy(card2,card,n);

    // Bubble Sort result
    BubbleSort(card1,n);
    printCard(card1,n);
    if(stableTest(card1,card,n) == 1)
        printf("Stable\n");
    else
        printf("Not stable\n");

    // Selection sort result
    SelectionSort(card2,n);
    printCard(card2,n);
    if(stableTest(card2,card,n) == 1)
        printf("Stable\n");
    else
        printf("Not stable\n");

    return 0;
}