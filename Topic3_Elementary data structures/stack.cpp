#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream> 
using namespace std;

int end_num(char a){
	for(int i=48; i<58; i++){
		if(a == i) return 0;
	} 
	return 1;
}

int end(char a){
	int result;
	if(end_num(a) == 0) return 0;
	else if(a == 32) return 0;
	else if(a == 42) return 0;
	else if(a == 43) return 0;
	else if(a == 45) return 0;
	else return 1;
}

void strrev(int N, char a[]){
	char b[N+1];
	strcpy(b,a);
	for(int i=0; i<N; i++){
		a[i] = b[N-1-i];
	}
}

int strlenght(char a[]){
	for(int i=0;;i++){
		if(end(a[i]) == 1) return i; 
	}
}

typedef struct Stack{
	char stack[300];
	int process_stack[100];
	int s_counter, p_counter;
	void push(int x){
		process_stack[p_counter] = x;
		p_counter++;
	};
	int pop(){
		p_counter--;
		return process_stack[p_counter];
	};
} Stack;

int main(int argc, char const *argv[])
{
	int x;
	Stack stack;
	scanf("%[^\n]s",stack.stack);
	stack.s_counter = strlenght(stack.stack);
	strrev(stack.s_counter, stack.stack);
	stack.p_counter = 1;
	while(stack.s_counter != 0){
		stack.s_counter--;
		if(stack.stack[stack.s_counter] == '+'){
			x = stack.pop() + stack.pop();
			stack.push(x);
		}
		else if(stack.stack[stack.s_counter] == '-'){
			x = (-1)*stack.pop() + stack.pop();
			stack.push(x);
		}
		else if(stack.stack[stack.s_counter] == '*'){
			x = stack.pop() * stack.pop();
			stack.push(x);
		}
		else if(stack.stack[stack.s_counter] == ' ') continue;
		else{
			int counter = 1;
			int s_counter = stack.s_counter;
			while(end_num(stack.stack[s_counter - 1]) == 0){
				s_counter--;
				counter++;
			}
			char s[counter];
			for(int i=0; i<counter; i++){
				s[i] = stack.stack[stack.s_counter-i];
			}
			stack.push(atoi(s));
			stack.s_counter = stack.s_counter - counter + 1;
		}
	}
	char s[100];
	sprintf(s,"%d", stack.pop());
	printf("%s\n", s);
	return 0;
}