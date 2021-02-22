#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node{
    int val;
    int parent;
    int depth;
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

void BFS(Graph* G, int graphSize, int root){
    int queue[graphSize];
    int left = 0, right = 0;
    
    // Insert root into queue
    queue[right] = root;
    right++;
    
    while(left < right){
        Node* tmp = G->tree[queue[left]];
        // While loop to add adjacent nodes into queue
        while(tmp->next != NULL){
            tmp = tmp->next;
            // Enqueue 1 node
            queue[right] = tmp->val; 
            // Determine parent and depth of added node
            G->tree[queue[right]]->parent = queue[left];
            G->tree[queue[right]]->depth = G->tree[queue[left]]->depth + 1;
            right++;
        } 
        // Dequeue 1 node
        left++;
    }
}

int findRoot(Graph* G, int graphSize){
    for(int i=0; i<graphSize; i++){
        bool b = 0;
        for(int j=0; j<graphSize; j++){
            if(j!=i){
                Node* tmp = G->tree[j];
                while(tmp->next != NULL){
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

void printInfo(Graph* G, int graphSize){
    for(int i=0; i<graphSize; i++){
        printf("node %d: parent = %d, depth = %d, ",
                i,G->tree[i]->parent,G->tree[i]->depth);
        
        Node* tmp = G->tree[i];
        if(tmp->next != NULL){
            if(tmp->depth == 0)
                printf("root, [");
            else
                printf("internal node, [");
            while(tmp->next != NULL){
                tmp = tmp->next;
                if(tmp -> next == NULL)
                    printf("%d]\n",tmp->val);
                else
                    printf("%d, ",tmp->val);
            }
        }
        else{
            if(tmp->depth == 0)
                printf("root, []\n");
            else
                printf("leaf, []\n");
        }
        
    }
}

int main(){
    int n;
    scanf("%d",&n);
    Graph* G = newGraph(n);

    // Input the other vertices into the graph
    for(int i=0; i<n; i++){
        int order, k;
        scanf("%d %d",&order,&k);

        Node* temp = G->tree[order];
        for(int j=0; j<k; j++){
            int tmp;
            scanf("%d",&tmp);

            Node* N = newNode(tmp);
            temp->next = N;
            temp = N;
        }
    }
    int root = findRoot(G,n);
    G->tree[root]->parent = -1;
    G->tree[root]->depth = 0;
    G->tree[root]->val = root;
    // printf("\n");
    // printGraph(G,n);
    printf("\n");
    BFS(G,n,root);
    printInfo(G,n);

    return 0;
}