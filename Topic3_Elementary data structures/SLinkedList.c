#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insertFirst(int key, int data){
    // Allocate memory for the new node 
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertNode(int in_pos, int key, int data){
    // Allocate dynamic memory for newNode
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    newNode->data = data;
    // Search in the list to find the insert position
    Node *currentNode = head;
    while(currentNode->key != in_pos){
        if(currentNode == NULL) break;
        else currentNode = currentNode->next;
    }
    // Insert the node into the in_pos position
    if(currentNode != NULL){
        Node* bufferNode = currentNode->next;
        currentNode->next = newNode;
        newNode->next = bufferNode;
    }
}

void deleteFirst(){
    Node* currentNode = head;
    head = head->next;
    free(currentNode);
}

void deleteNode(int key){
    Node* currentNode = head;
    Node* prevNode = NULL;
    for(currentNode = head;currentNode != NULL; currentNode = currentNode->next){
        if(currentNode->key == key){
            if(head->key == key){
                deleteFirst();
                break;
            }
            else{
                prevNode->next = currentNode->next;
                free(currentNode);
                break;
            }
        }
        else prevNode = currentNode;
    }
}

Node* findNode(int key){
    Node* currentNode = head;
    // Check if the list is empty or not
    if(head == NULL) return NULL;
    // Find the node
    while(currentNode->key != key){
        if(currentNode->next == NULL) return NULL;
        else currentNode = currentNode->next; 
    }
    // Return the result
    return currentNode;
}

void printNode(Node* p){
    printf("key=%d  data=%d\n\n",p->key, p->data);
}

void printList(){
    Node* currentNode = head;
    while(currentNode != NULL){
        printf("key=%d  data=%d\n",currentNode->key,currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main(){
    insertFirst(1,9);
    insertFirst(2,8);
    insertFirst(3,7);
    insertFirst(5,5);

    printList();

    // printNode(findNode(3));

    // while(head != NULL) deleteFirst();
    deleteNode(3);
    // insertNode(5,4,6);
    printList();

    return 0;
}