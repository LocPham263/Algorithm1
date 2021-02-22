#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void enqueue(int data);
int dequeue();
bool isEmpty();
bool isFull();

#define size 100005
#define n 1000
int queue[size];
int left = 0;
int right = 0;

int main(){
    int counter = 0;
    int cur_time = 0;

    // Input the number of processes and quantum period
    int input[2];
    scanf("%d %d",&input[0], &input[1]);
    
    // Input process and time
    char name[input[0]][n];
    int order[input[0]];
    for(int i=0; i<input[0]; i++){
        int e_time;
        scanf("%s %d",name[i],&e_time);
        enqueue(e_time);
        order[i] = i;
    }

    // Execution
    while(!isEmpty()){
        if(queue[left] <= input[1]){
            cur_time = cur_time + queue[left];
            printf("%s %d\n",name[order[counter]],cur_time);
            dequeue();
            counter++;
        }
        else{
            cur_time = cur_time + input[1];
            enqueue(dequeue()-input[1]);
            
            int buffer = order[counter];
            for(int i=counter; i<input[0]-1; i++){
                order[i] = order[i+1];
            }
            order[input[0]-1] = buffer;
        }
    }
    return 0;
}

void enqueue(int data){
    if(!isFull()){
        queue[right] = data;
        right++;
    }
}

int dequeue(){
    if(!isEmpty()){
        int data = queue[left];
        left++;
        return data;
    }
}

bool isEmpty(){
    return left == right;
}

bool isFull(){
    return right == size;
}