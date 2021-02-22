#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    long data;
    struct Node* next;
    struct Node* prev;
} Node;

static Node* head = NULL;
static Node* tail = NULL;

void insert(long data);
void delete(long key);
void deleteFirst();
void deleteLast();
void printFW();
int Opcode(char cmd[]);

int main(){
    long n;
    scanf("%ld",&n);
    char cmd[30];
    fgets(cmd,30,stdin);
    for(int i=1; i<=n; i++){
        fgets(cmd,30,stdin);
        switch (Opcode(cmd)){
            case 1: {insert(atoi(&cmd[7])); break;}
            case 2: {delete(atoi(&cmd[7])); break;}
            case 3: {deleteFirst(); break;}
            case 4: deleteLast(); 
        }
        // printFW();
    }
    printFW();
    return 0;
}

void insert(long data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;

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

void delete(long data){
    Node* currentNode = head;
    if(head == NULL) return;
    while(currentNode->data != data){
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
        printf("%ld", currentNode->data);
        currentNode = currentNode->next;
        if(currentNode == NULL) printf("");
        else printf(" ");
    }
    printf("\n");
}

int Opcode(char cmd[]){
    if(cmd[6] == ' '){
        if(cmd[0] == 'i') return 1;
        else return 2;
    }
    else{
        if(cmd[6] == 'F') return 3;
        else return 4;
    }
}