#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int count = 0;
int count1 = 0;

typedef struct Node{
    int val;
    struct Node* next;
} Node;

typedef struct Graph{
    Node** tree;   
} Graph;

Node* newNode(int val){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

Graph* newGraph(int graphSize){
    Graph* G = (Graph*) malloc(sizeof(Graph));
    G->tree = (Node**) malloc(graphSize*sizeof(Node*));
    
    for(int i=0; i<graphSize; i++)
        G->tree[i] = newNode(i);  
    return G;
}

void DFS_preorder(Graph* G, int graphSize, int root){
    Node* temp = G->tree[root];
    printf(" %d",root);

    if(temp->next->val != -1)
        DFS_preorder(G,graphSize,temp->next->val);
    temp = temp->next;
    if(temp->next->val != -1)
        DFS_preorder(G,graphSize,temp->next->val);
}

void DFS_inorder(Graph* G, int graphSize, int root){
    Node* temp = G->tree[root];

    if(temp->next->val != -1)
        DFS_inorder(G,graphSize,temp->next->val);
    printf(" %d",root);
    temp = temp->next;
    if(temp->next->val != -1)
        DFS_inorder(G,graphSize,temp->next->val);
}

void DFS_postorder(Graph* G, int graphSize, int root){
    Node* temp = G->tree[root];

    if(temp->next->val != -1)
        DFS_postorder(G,graphSize,temp->next->val);
    temp = temp->next;
    if(temp->next->val != -1)
        DFS_postorder(G,graphSize,temp->next->val);
    printf(" %d",root);
}

int findRoot(Graph* G, int graphSize){
    for(int i=0; i<graphSize; i++){
        bool b = 0;
        for(int j=0; j<graphSize; j++){
            if(j!=i){
                Node* tmp = G->tree[j];
                while(tmp->next !=NULL){
                    tmp = tmp -> next;
                    if(tmp->val == i){
                        b = 1;
                        break;
                    }
                }
            }
        }
        if(b == 0) return i;
    }
}

void printGraph(Graph* G, int graphSize){
    for(int i=0; i<graphSize; i++){
        Node* tmp = G->tree[i];
        while(tmp != NULL){
            printf("%d ",tmp->val);
            tmp = tmp -> next;
        }
        printf("\n");
    }
}

int main(){
    int n;
    scanf("%d",&n);
    Graph* G = newGraph(n);

    // Input the other vertices into the graph
    for(int i=0; i<n; i++){
        int order;
        scanf("%d",&order);

        Node* temp = G->tree[order];
        for(int j=0; j<2; j++){
            int tmp;
            scanf("%d",&tmp);

            Node* N = newNode(tmp);
            temp->next = N;
            temp = N;
        }
    }
    int root = findRoot(G,n);
    G->tree[root]->val = root;
    // printf("\n");
    // printGraph(G,n);
    printf("Preorder\n");
    DFS_preorder(G,n,root);
    printf("\nInorder\n");
    DFS_inorder(G,n,root);
    printf("\nPostorder\n");
    DFS_postorder(G,n,root);
    printf("\n");

    return 0;
}