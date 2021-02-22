#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    long key;
    struct Node* next;
} Node;

static Node* head = NULL;

void insert(long key){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = head;
    head = newNode;
}

void deleteFirst(){
    Node* currentNode = head;
    if(head==NULL) return;
    head = head->next;
    free(currentNode);
}

void delete(long key){
    if(head == NULL) return;
    if(head->key == key){
        deleteFirst();
        return;
    }
    Node* cur = head;
    while (cur->next != NULL){
        if(cur->next->key == key){
            Node* temp = cur->next;
            cur->next = temp->next;
            free(temp);
            return;
        }
    }
}

void deleteLast(){
    Node* currentNode = head;
    Node* prevNode = NULL;
    if(head->next == NULL){
        deleteFirst();
        return;
    }
    while(currentNode->next != NULL){
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    prevNode->next = NULL;
    free(currentNode);
}

void printList(){
    Node* currentNode = head;

    for(currentNode = head; currentNode!=NULL; currentNode = currentNode->next){
        printf("%ld ",currentNode->key);    
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
        printList();
    }
    // printList();
    return 0;
}

