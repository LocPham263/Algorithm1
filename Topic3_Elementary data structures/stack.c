#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isEmpty();
bool isFull();
void push(int data);
int pop();
void printStack();

typedef struct Stack{
    int size;
    int counter;
    int* stack;
} Stack;

Stack s;

int main(){
    // Initialise stack
    scanf("%d",&s.size);
    s.stack = (int*) malloc(s.size*sizeof(int));
    s.counter = -1;

    push(1);
    push(2);
    push(3);
    printStack();
    pop();
    pop();
    pop();
    pop();
    printStack();

    free(s.stack);
    return 0;
}

void push(int data){
    if(!isFull()){
        s.counter++;
        *(s.stack + s.counter) = data;  
    }else printf("Error, the stack is full\n");
}

int pop(){
    if(!isEmpty()){
        int data =  *(s.stack + s.counter);
        s.counter--;
        return data;
    }else printf("Error, the stack is Empty!!!\n");
}

bool isEmpty(){
    if(s.counter == -1) return true;
    else return false;
}

bool isFull(){
    if(s.counter == s.size) return true;
    else return false; 
}

void printStack(){
    for(int i=0; i<=s.counter; i++){
        printf("%d ",*(s.stack+i));
    }
    printf("\n");
}