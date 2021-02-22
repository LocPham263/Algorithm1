#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 4

int queue[100];
int right = 0, left = 0;

bool isEmpty(){
    return (right == left) && (right != 0); 
}

bool isFull(){
    return (left-right) == SIZE;
}

void Enqueue(int data){
    if(!isFull()){
        queue[left] = data;
        left++;
    }else
        printf("Queue is full!\n");
}

int Dequeue(){
    if(!isEmpty()){
        right++;
        return queue[right-1];
    }else
        printf("Queue is empty!\n");
}

void printQueue(){
    if(!isEmpty()){
        for(int i=right; i<left; i++)
            printf("%d ",queue[i]);
        printf("\n");
    }else
        printf("Queue is empty!\n");
}

int main(){
    int mode, data=0;
    while(1){
        scanf("%d",&mode);
        switch (mode){
        case 0:
            Dequeue();
            printQueue();
            break;
        case 1:
            Enqueue(data);
            printQueue();
            data++;
            break;
        default:
            break;
        }
    }
    return 0;
}