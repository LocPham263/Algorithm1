#include <stdio.h>
#include <string.h>
#include <iostream> 
using namespace std;
#define LEN 100005

typedef struct Process{
	char name[100];
	int time;
} Process;

typedef struct Queue{
	int head = 0;
	int tail = 0;
	Process P[LEN+1];

	void enqueue(Process p){
		if(tail + 1 == LEN) tail = 0;
		else tail++;
		P[tail-1] = p;
	};
	void dequeue(){
		if(head + 1 == LEN) head = 0;
		else head++;
	};
	int isEmpty(){
		if(tail == head) return 1;
		else return 0;
	};
} Queue;
Queue q;

int main(){
	// Total execution time
	int sum = 0;
	// Number of processes n and time slot t
	int n, t;
	scanf("%d %d",&n, &t);
	// Initialise data for queue
	int i=0;
	for(i=0; i<n; i++){
		scanf("%s", q.P[i].name);
		scanf("%d", &q.P[i].time);
		q.enqueue(q.P[i]);
	}

	printf("\n");
	// Round-Robin Scheduling implementation
	for(i=0;;i++){
		// If the process can be completely done
		if(q.P[i].time <= t){
			q.P[i].time = sum + q.P[i].time;
			sum = q.P[i].time;
			printf("%s %d\n", q.P[i].name, q.P[i].time);
			q.dequeue();
		}
		// If the time slot is not enough to complete the current process
		else{
			q.P[i].time = q.P[i].time - t;
			sum = sum + t;
			q.dequeue();
			q.enqueue(q.P[i]);
		}
		// If all processes are completely done (Queue empty)
		if(q.isEmpty() == 1) break;
	}
}