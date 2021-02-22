#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10

typedef struct Node{
    struct Node* next;
    int data;
    int count;
} Node;

Node* top = NULL;

void push(int data);
int pop();
bool isEmpty();
bool isFull();
void printStack();

int main(){
    int data = 0;
    while(1){
        int mode;
        scanf("%d",&mode);

        switch (mode){
            case 0:
                push(data);
                data++;
                printStack();
                break;
            case 1:
                pop();
                data--;
                printStack();
                break;
            default:
                break;
        }
    }
    return 0;
}

bool isEmpty(){
    return top == NULL;
}

bool isFull(){
    return top->count == SIZE;
}

void push(int data){
    if(isEmpty()){
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode -> next = top;
        newNode -> data = data;
        newNode -> count = 1;
        top = newNode;
    }
    else if(!isFull()){
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode -> next = top;
        newNode -> data = data;
        newNode -> count = top -> count + 1;
        top = newNode;
    }else
        printf("Stach is full!\n");
}

int pop(){
    if(!isEmpty()){
        Node* tmp = top;
        top = top -> next;
        int data = tmp -> data;
        free(tmp);
        return data;
    }else
        printf("Stack is empty!\n");
}

void printStack(){
    Node* tmp = top;
    while(!isEmpty()){
        printf("%d ",top->data);
        top = top -> next;
    }
    printf("\n");
    top = tmp;
}