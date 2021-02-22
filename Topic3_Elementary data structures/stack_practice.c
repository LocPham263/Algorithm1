#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isEmpty();
bool isFull();
void push(int data);
int pop();
void printStack();
int Opcode(char c);

#define size 300
typedef struct Stack{
    int counter;
    int* stack;
} Stack;

Stack s;

int main(){
    // Initialise input
    char input[400];
    scanf("%[^\n]s",input);
    // Initialise stack
    s.stack = (int*) malloc(size*sizeof(int));
    s.counter = -1;
    
    for(int i=0; input[i]!=NULL; i=i+2){
        switch(Opcode(input[i])){
            case 1: {push(pop() + pop()); break;}
            case 2: {push((-1)*(pop() - pop())); break;}
            case 3: {push(pop() * pop()); break;}
            case 4: {
                int j=i;
                while(input[i+1]!=' ') {i++;}
                char sub[i-j+1];
                for(int c=0; c<=i-j; c++) {sub[c] = input[j+c];}
                push(atoi(sub));
            }
        }
        // printStack();
        if(input[i+1]==NULL) break;
    }
    printStack();    

    free(s.stack);
    return 0;
}

void push(int data){
    if(!isFull()){
        s.counter++;
        *(s.stack + s.counter) = data;  
    }else printf("Error, the stack is full\n");
}

int pop(){
    if(!isEmpty()){
        int data =  *(s.stack + s.counter);
        s.counter--;
        return data;
    }else printf("Error, the stack is Empty!!!\n");
}

bool isEmpty(){
    if(s.counter == -1) return true;
    else return false;
}

bool isFull(){
    if(s.counter == size) return true;
    else return false; 
}

int Opcode(char c){
    switch(c){
        case '+': return 1;
        case '-': return 2;
        case '*': return 3;
        default: return 4;
    }
}

void printStack(){
    for(int i=0; i<=s.counter; i++){
        printf("%d ",*(s.stack+i));
    }
    printf("\n");
}