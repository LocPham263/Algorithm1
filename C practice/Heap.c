#include <stdio.h>
#include <stdlib.h>

void swap(int Heap[], int i, int j);
void Heapify(int Heap[], int heap_size, int i);
void Heap_BottomUp(int Heap[], int heap_size);
void rootDeletion(int Heap[], int heap_size);
void HeapSort(int Heap[], int heap_size);
void Insert(int Heap[], int heap_size, int key);
void printHeap(int Heap[], int heap_size);

int main(){
    int heap_size = 0;
    int n;
    scanf("%d",&n);
    int Heap[100];
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        Insert(Heap,heap_size,x);
        heap_size++;
    }
    printf("\n");

    // Heap_BottomUp(Heap,n);
    printHeap(Heap,heap_size);

    HeapSort(Heap,heap_size);
    printHeap(Heap,heap_size);

    Insert(Heap,heap_size,30);
    heap_size++;
    printHeap(Heap,heap_size);

    // HeapSort(Heap,n);
    // printHeap(Heap,n);
    return 0;
}

void swap(int Heap[], int i, int j){
    int buff;
    buff = Heap[i];
    Heap[i] = Heap[j];
    Heap[j] = buff;
}

void Heapify(int Heap[], int heap_size, int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int parent = i;

    if(Heap[parent] < Heap[left] && left < heap_size)
        parent = left;
    if(Heap[parent] < Heap[right] && right < heap_size)
        parent = right;
    if(parent != i){
        swap(Heap,parent,i);
        if(parent < heap_size/2)
            Heapify(Heap,heap_size,parent);
    }
}

void Heap_BottomUp(int Heap[], int heap_size){
    int i=heap_size/2-1;
    while(i>=0){
        Heapify(Heap,heap_size,i);
        i--;
    }
}

void rootDeletion(int Heap[], int heap_size){
    swap(Heap,0,heap_size-1);
    Heapify(Heap,heap_size-1,0);
}

void HeapSort(int Heap[], int heap_size){
    while(heap_size > 1){
        rootDeletion(Heap,heap_size);
        heap_size--;
    }
}

void Insert(int Heap[], int heap_size, int key){
    Heap[heap_size] = key;
    heap_size++;
    // Should be implemented by BottomUp_Heapify 
    // to save execution time
    // But in this case, it is acceptable to just use Heap_BottomUp
    Heap_BottomUp(Heap,heap_size);
}

void printHeap(int Heap[], int heap_size){
    for(int i=0; i<heap_size; i++)
        printf("%d ",Heap[i]);
    printf("\n");
}
