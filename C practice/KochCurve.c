#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point{
    double x;
    double y;
} Point;

typedef struct Vertex{
    Point p;
    struct Vertex* next;
} Vertex;

Vertex* head = NULL;
Vertex* tail = NULL;

Point vertex(Point p1, Point p2){
  double s60 = sin(60 * M_PI / 180.0);    
  double c60 = cos(60 * M_PI / 180.0);

  Point v = {
    c60 * (p1.x - p2.x) - s60 * (p1.y - p2.y) + p2.x,
    s60 * (p1.x - p2.x) + c60 * (p1.y - p2.y) + p2.y
  };

  return v;
}

void KochCurve(Vertex* A, Vertex* B){
    Vertex* a = (Vertex*) malloc(sizeof(Vertex));
    a -> p.x = A -> p.x + (B->p.x - A->p.x)/3;
    a -> p.y = A -> p.y + (B->p.y - A->p.y)/3;
    
    Vertex* b = (Vertex*) malloc(sizeof(Vertex));
    b -> p.x = A -> p.x + 2*(B->p.x - A->p.x)/3;
    b -> p.y = A -> p.y + 2*(B->p.y - A->p.y)/3;

    Vertex* c = (Vertex*) malloc(sizeof(Vertex));
    c -> p = vertex(b->p,a->p);

    A->next = a;
    a->next = c;
    c->next = b;
    b->next = B;

    if(B->next != NULL)
        KochCurve(B,B->next);
}

void printCurve(){
    Vertex* tmp = head;
    while(tmp!=NULL){
        printf("%f %f\n",tmp->p.x,tmp->p.y);
        tmp = tmp->next;
    }
}

int main(){
    head = (Vertex*) malloc(sizeof(Vertex));
    head -> p.x = 0;
    head -> p.y = 0;

    tail = (Vertex*) malloc(sizeof(Vertex));
    tail -> p.x = 100;
    tail -> p.y = 0;

    head -> next = tail;
    tail -> next = NULL;

    int n;
    scanf("%d",&n);

    for(int i=1; i<=n; i++)         
        KochCurve(head,head->next);
    printCurve();

    return 0;
}
