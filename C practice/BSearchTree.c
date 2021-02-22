#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int root;
int order = 0;

typedef struct Node{
    int val;
    int left;
    int right;
    struct Node* next;
} Node;

typedef struct Graph{
    Node** tree;   
} Graph;

Node* newNode(int val){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = -1;
    newNode->right = -1;
    newNode->next = NULL;
    return newNode;
}

Graph* newGraph(int graphSize){
    Graph* G = (Graph*) malloc(sizeof(Graph));
    G->tree = (Node**) malloc(graphSize*sizeof(Node*));
    return G;
}

int findNode(Graph* G, int graphSize, int key){
    for(int i=0; i<graphSize; i++){
        if(G->tree[i]!=NULL && G->tree[i]->val == key)
            return i;
    }
    return graphSize-1;
}

void insert(Graph* G, int graphSize, int key){
    // G->tree[0] is the root of the tree
    Node* x = G->tree[0];
    Node* y = NULL;
    Node* z = newNode(key);

    while(x != NULL){
        y = x;
        if(z->val < x->val)
            x = G->tree[findNode(G,graphSize,x->left)];
        else
            x = G->tree[findNode(G,graphSize,x->right)];
    }
    z->next = y;

    if(y == NULL)
        G->tree[0] = z; 
    else if(z->val < y->val)
        y->left = z->val;
    else
        y->right = z->val;
    
    G->tree[order] = z;
    order++;
}

void DFS_preorder(Graph* G, int graphSize, int key){
    Node* temp = G->tree[findNode(G,graphSize,key)];
    printf(" %d",key);

    if(temp->left != -1)
        DFS_preorder(G,graphSize,temp->left);
    if(temp->right != -1)
        DFS_preorder(G,graphSize,temp->right);
}

void DFS_inorder(Graph* G, int graphSize, int key){
    Node* temp = G->tree[findNode(G,graphSize,key)];

    if(temp->left != -1)
        DFS_inorder(G,graphSize,temp->left);
    printf(" %d",key);
    if(temp->right != -1)
        DFS_inorder(G,graphSize,temp->right);
}

void printGraph(Graph* G, int graphSize){
    for(int i=0; i<graphSize; i++){
        Node* tmp = G->tree[i];
        printf("Node%d %d: %d %d\n",i,tmp->val,tmp->left,tmp->right);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    Graph* G = newGraph(n);

    // Determine root of the tree
    int count=0;
    for(int i=0; i<n; i++){
        char cmd[10];
        scanf("%s",cmd);
        if(strncmp(cmd,"insert",6) == 0){
            scanf("%d",&root);
            insert(G,n,root);
            count++;
            break;
        }
        count++;
    }
    // Input other nodes of the tree
    for(int i=count; i<n; i++){
        char cmd[10];
        int key;
        scanf("%s",cmd);
        if(strncmp(cmd,"insert",6) == 0){
            scanf("%d",&key);
            insert(G,n,key);
        }else if(strncmp(cmd,"print",5) == 0){
            printf("\n");
            DFS_inorder(G,n,root);
            printf("\n");
            DFS_preorder(G,n,root);
            printf("\n");
            printGraph(G,n);
        }
    }

    return 0;
}