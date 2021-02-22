#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    int data;
    struct Node* next;
} Node;

static Node* head = NULL;

void insertFirst(int key, int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

Node* findNode(int pos){
    Node* currentNode = head;
    Node* prevNode = currentNode;
    int i;
    for(i=1; i<=pos; i++){
        if(currentNode == NULL) return NULL;
        else currentNode = currentNode->next;
    }
    prevNode = head;
    while(currentNode != NULL){
        currentNode = currentNode->next;
        prevNode = prevNode->next;
    }
    return prevNode;
}

void printList(){
    Node* currentNode = NULL;
    for(currentNode = head; currentNode!=NULL; currentNode = currentNode->next){
        printf("Node %d data %d\n",currentNode->key,currentNode->data);    
    }
    printf("\n\n");
}

int main(int argc, char *argv[]){
    int pos = atoi(argv[1]);
    int a=0, b=10;
    printf("\n------------Initialise linked list------------\n");
    while(a!=b){
        insertFirst(a,b);
        a++;
        b--;
    }
    printList();

    printf("\n------------The %dth node from the tail ------------\n", pos);
    Node* result = findNode(pos);
    if(result == NULL) printf("Invalid input, exceed the list's length\n\n");
    else printf("Node %d data %d\n\n",result->key,result->data);
    
    return 0;
}