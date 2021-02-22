#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int count = 0;
int count1 = 0;

typedef struct Node{
    int val;
    int parent;
    int sibling;
    int degree;
    int height;
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
        if(tmp->next->val != -1){
            tmp = tmp->next;
            // Enqueue 1 node
            queue[right] = tmp->val; 
            // Determine parent and depth of added node
            G->tree[queue[right]]->parent = queue[left];
            G->tree[queue[right]]->depth = G->tree[queue[left]]->depth + 1;
            right++;
            if(tmp->next->val != -1){
                Node* tmp1 = tmp->next;
                queue[right] = tmp1->val;
                G->tree[queue[right]]->parent = queue[left];
                G->tree[queue[right]]->depth = G->tree[queue[left]]->depth + 1;
                G->tree[queue[right]]->sibling = queue[right-1];
                G->tree[queue[right-1]]->sibling = queue[right];
                G->tree[queue[left]]->degree = 2;
                right++;
            }else{
                G->tree[queue[right-1]]->sibling = -1;
                G->tree[queue[left]]->degree = 1;
            }
        }
        else{
            tmp = tmp->next;
            if(tmp->next->val != -1){
                tmp = tmp->next;
                queue[right] = tmp->val;
                G->tree[queue[right]]->parent = queue[left];
                G->tree[queue[right]]->depth = G->tree[queue[left]]->depth + 1;
                G->tree[queue[right]]->sibling = -1;
                G->tree[queue[left]]->degree = 1;
                right++;
            }else
                G->tree[queue[left]]->degree = 0;
        }
        // Dequeue 1 node
        left++;
    }
}

void DFS(Graph* G, int graphSize, int root){
    Node* temp = G->tree[root];
    int degree = temp->degree;

    if(degree == 0){
        if(count1 > count)
            count = count1; 
    }else{
        for(int i=0; i<degree; i++){
            count1++;
            temp = temp->next;
            if(temp->val != -1)        
                DFS(G,graphSize,temp->val);
            else
                DFS(G,graphSize,temp->next->val);
            count1--;
        }
    }

}

void findHeight(Graph* G, int graphSize){
    for(int i=0; i<graphSize; i++){
        DFS(G,graphSize,i);
        G->tree[i]->height = count;
        count = count1 = 0; 
    }
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

void printInfo(Graph* G, int graphSize){
    for(int i=0; i<graphSize; i++){
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
                i, G->tree[i]->parent, G->tree[i]->sibling,
                G->tree[i]->degree, G->tree[i]->depth, G->tree[i]->height);
        
        Node* tmp = G->tree[i]->next;
        if(tmp->val != -1 || tmp->next->val != -1){
            if(G->tree[i]->depth == 0)
                printf("root\n");
            else
                printf("internal node\n");
        }
        else{
            if(G->tree[i]->depth == 0)
                printf("root\n");
            else
                printf("leaf\n");
        }
        
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
    G->tree[root]->parent = -1;
    G->tree[root]->sibling = -1;
    G->tree[root]->depth = 0;
    G->tree[root]->val = root;
    // printf("\n");
    // printGraph(G,n);
    printf("\n");
    BFS(G,n,root);
    findHeight(G,n);
    printInfo(G,n);

    return 0;
}