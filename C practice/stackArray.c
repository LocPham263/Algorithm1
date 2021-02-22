#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10

int stack[SIZE];
int top = 0;

bool isEmpty(){
    return top == 0;
}

bool isFull(){
    return top > SIZE;
}

void push(int data){
    if(!isFull()){
        stack[top] = data;
        top++;
    }else
        printf("Stack is full!\n");
}

int pop(){
    if(!isEmpty()){
        top--;
        return stack[top];
    }else
        printf("Stack is empty!\n");
}

void printStack(){
    int count = top;
    while(!isEmpty()){
        top--;
        printf("%d ",stack[top]);
    }
    printf("\n");
    top = count;
}

int main(){
    int mode;
    int data = 0;
    while(1){
        scanf("%d",&mode);
        switch (mode){
        case 0:
            push(data);
            data++;
            printStack();
            break;
        case 1:
            pop();
            printStack();
            break;
        default:
            break;
        }
    }
    return 0;
}