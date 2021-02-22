#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void enqueue(int data);
int dequeue();
void printQueue();
bool isEmpty();
bool isFull();

#define size 100
int queue[size];
int left = 0;
int right = 0;

int main(){
    for(int i=1; i<=3; i++){
        enqueue(i);
    }
    printQueue();
    dequeue();
    printQueue();
    enqueue(4);
    printQueue();
    dequeue(); dequeue(); dequeue();
    printQueue();
    dequeue();
    printQueue();
    return 0;
}

void enqueue(int data){
    if(!isFull()){
        queue[right] = data;
        right++;
    }
}

int dequeue(){
    if(!isEmpty()){
        int data = queue[left];
        left++;
        return data;
    }
}

bool isEmpty(){
    return left == right;
}

bool isFull(){
    return right == size;
}

void printQueue(){
    for(int i=left; i<right; i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}