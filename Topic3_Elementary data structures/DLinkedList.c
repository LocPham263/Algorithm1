#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    int key;
    struct Node* next;
    struct Node* prev;
} Node;

static Node* head = NULL;
static Node* tail = NULL;

void insertFirst(int key, int data);
void insertLast(int key, int data);
void insert(int pos, int key, int data);
void deleteFirst();
void deleteLast();
void delete(int key);
void printFW();
void printBW();


int main(){
    // insertFirst(1,9);
    // insertFirst(2,8);
    // insertFirst(3,7);
    insertLast(1,9);
    insertLast(2,8);
    insertLast(3,7);
    insert(3,9,9);
    insert(9,8,8);
    delete(3);
    // deleteLast();
    // deleteLast();
    printFW();
    //printBW();
}

void insertLast(int key, int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->key = key;

    if(head == NULL){
        head = newNode;
    }
    else{
        tail->next = newNode;
    }
    newNode->prev = tail;
    newNode->next = NULL;
    tail = newNode;
}

void insertFirst(int key, int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->key = key;

    if(head == NULL){
        tail = newNode;
    }
    else{
        head->prev = newNode;
    }
    newNode->prev = NULL;
    newNode->next = head;
    head = newNode;
}

void insert(int pos, int key, int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->key = key;
    
    Node* currentNode = head;
    while(currentNode->key != pos){
        if(currentNode == tail) return;
        else currentNode = currentNode->next;
    }
    if(currentNode == tail) insertLast(key, data);
    else{
        Node* buffer = currentNode;
        currentNode = currentNode->next;
        buffer->next = newNode;
        newNode->prev = buffer;
        currentNode->prev = newNode;
        newNode->next = currentNode;
    }
}

void deleteFirst(){
    Node* currentNode = head;  
    // If the list is empty
    if(head == NULL) return;
    // If the list only has 1 node left
    if(head->next == NULL){
        head = NULL;
        tail = NULL;
    }
    else{
        head = head->next;
        head->prev = NULL;
    }
    free(currentNode);
}

void deleteLast(){
    Node* currentNode = tail;
    // If the list is empty
    if(head == NULL) return;
    // If the list only has 1 node left
    if(tail->prev == NULL){
        head = NULL;
        tail = NULL;
    }
    else{
        tail = tail->prev;
        tail->next = NULL;
    }
    free(currentNode);
}

void delete(int key){
    Node* currentNode = head;
    if(head == NULL) return;
    while(currentNode->key != key){
        if(currentNode == tail) return;
        else currentNode = currentNode->next;
    }
    if(currentNode == tail) deleteLast();
    else if(currentNode == head) deleteFirst();
    else{
        Node* buffer1 = currentNode->prev;
        Node* buffer2 = currentNode->next;
        buffer1->next = buffer2;
        buffer2->prev = buffer1;
        free(currentNode);
    } 
}

void printFW(){
    Node* currentNode = head;
    while(currentNode != NULL){
        printf("Node: %d  data: %d\n",currentNode->key,currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void printBW(){
    Node* currentNode = tail;
    while(currentNode != NULL){
        printf("Node: %d  data: %d\n",currentNode->key,currentNode->data);
        currentNode = currentNode->prev;
    }
    printf("\n");
}