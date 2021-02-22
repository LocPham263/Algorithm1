#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100

int stack[SIZE];
int top = 0;

bool isEmpty(){
    return top == 0;
}

bool isFull(){
    return top > SIZE;
}

void push(int data){
    if(!isFull()){
        stack[top] = data;
        top++;
    }else
        printf("Stack is full!\n");
}

int pop(){
    if(!isEmpty()){
        top--;
        return stack[top];
    }else
        printf("Stack is empty!\n");
}

int main(){
    char input[300];
    scanf("%[^\n]s",input);
    for(int i=0; input[i]!='\0'; i++){
        switch (input[i]){
            case '+':
                push(pop() + pop());
                break;
            case '-':
                push(-(pop() - pop()));
                break;
            case '*':
                push(pop() * pop());
                break;
            case ' ': break;
            default:
                {
                    int j = i;
                    char tmp[100];
                    while(input[j] != ' '){
                        tmp[j-i] = input[j];
                        j++;
                    }
                    tmp[j-i] = '\0';
                    push(atoi(tmp));
                    i=j;
                }
                break;
        }
    }
    
    printf("%d\n",stack[0]);
    return 0;
}