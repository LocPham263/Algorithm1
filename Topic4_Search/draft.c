#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    int data;
} Node;

Node* test(Node* p, int k){
    p->key = p->key + k;
    p->data = p->data + k;
    return p;
}
void printNode(Node* p){
    printf("%d %d\n",p->key, p->data);
}
int main(){
    Node* p = (Node*) malloc(sizeof(Node));
    p->key = 1;
    p->data = 10;
    printNode(p);
    printNode(test(p,1));
    free(p);
    return 0;
}