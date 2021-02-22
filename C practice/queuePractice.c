#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100000

int counter = 0;

typedef struct process{
    char name[10];
    int t;
} process;

typedef struct Node{
    process P;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

bool isEmpty(){
    return counter == 0; 
}

bool isFull(){
    return counter == SIZE;
}

void Enqueue(Node* tmp){
    if(!isFull()){
        tmp -> next = NULL;

        if(isEmpty())
            tail = head = tmp;    
        else{
            tail -> next = tmp;
            tail = tmp;
        }
        counter++;
    }else
        printf("Queue is full!\n");
}

Node* Dequeue(){
    if(!isEmpty()){
        Node* tmp = head;
        if(tail == head) 
            tail = head -> next;
        head = head -> next;
        counter--;
        return tmp;
    }else
        printf("Queue is empty!\n");
}

void printQueue(){
    if(!isEmpty()){
        int ram = counter;
        Node* tmp = head;
        while(!isEmpty()){
            printf("%s/%d ",tmp->P.name,tmp->P.t);
            tmp = tmp -> next;
            counter--;
        }
        printf("\n");
        counter = ram;
    }else
        printf("Queue is empty!\n");
}

int main(){
    // Number of process n 
    unsigned int n;
    // Time slot assigned for each process
    int q;
    scanf("%d %d",&n,&q);

    for(int i=1; i<=n; i++){
        Node* newNode = (Node*) malloc(sizeof(Node));
        scanf("%s %d",newNode->P.name,&newNode->P.t);
        Enqueue(newNode);
    }
    
    printf("\n");
    unsigned int period = 0;
    while(!isEmpty()){
        if(head->P.t <= q){
            period = period + head->P.t;
            printf("%s %d\n",head->P.name,period);
            Dequeue();
        }else{
            period = period + q;
            head->P.t = head->P.t - q;
            Enqueue(Dequeue());
        }
    }
    
    // printQueue();
    
    return 0;
}