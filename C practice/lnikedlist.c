#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int key;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void insertFirst(int key){
    // Init new Node
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp -> key = key;
    tmp -> next = head;

    head = tmp;
    if(tail == NULL) tail = head;
}

void insertLast(int key){
    if(tail == NULL)
        insertFirst(key);
    else{
        // Init new Node
        Node* tmp = (Node*) malloc(sizeof(Node));
        tmp -> key = key;
        tmp -> next = NULL;
        
        tail -> next = tmp;
        tail = tmp;
    }
}

void insert(int key, int data){
    if(head == NULL) return;

    if(head->key == key) 
        insertFirst(data);
    else{
        Node* p = head;
        Node* px;
        while(p->key != key && p->next!=NULL){
            px = p;
            p = p->next;
        }

        if(p->next != NULL || tail->key == key){
            Node* tmp = (Node*) malloc(sizeof(Node));
            tmp -> key = data;
            tmp -> next = p;
            px -> next = tmp;
        }
    }
}

void deleteFirst(){
    if(head == NULL) return;
    else if(head->next == NULL){
        Node* tmp = head;
        head = NULL;
        tail = NULL;
        free(tmp);
    }
    else{
        Node* tmp = head;
        head = head -> next;
        free(tmp);
    }
}

void delete(int key){
    if(head == NULL) return;

    if(head->key == key) 
        deleteFirst();
    else{
        Node* p = head;
        Node* px;
        while(p->key != key && p->next != NULL){
            px = p;
            p = p->next;
        }
        
        if(p->next != NULL || tail->key == key){
            px -> next = p -> next;
            free(p);
        }
    }
}

void printList(){
    if(head != NULL){
        Node* tmp = head;
        while(tmp->next != NULL){
            printf("%d ",tmp->key);
            tmp = tmp->next;
        }
        printf("%d\n",tmp->key);
    }
    else 
        printf("Empty list\n");
}

int main(){
    insertFirst(0);
    insertFirst(1);
    insertFirst(2);
    insertLast(3);
    insertLast(4);
    insert(2,5);
    insert(0,6);
    insert(9,9);
    insert(4,7);
    printList();

    deleteFirst();
    printList();
    delete(2);
    delete(4);
    delete(0);
    delete(10);
    printList();
    return 0;
}
