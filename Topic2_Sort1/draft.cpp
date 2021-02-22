#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream> 
using namespace std;

int end(char a){
	for(int i=48; i<58; i++) if(a == i) return 0;
	if(a == 32) return 0;
	else if(a == 42) return 0;
	else if(a == 43) return 0;
	else if(a == 45) return 0;
	else return 1;
}

int strlenght(char a[]){
	for(int i=0;;i++){
		if(end(a[i]) == 1) return i; 
	}
}

int main(int argc, char const *argv[])
{
	char a[5];
	scanf("%[^\n]s",a);
	printf("%d\n", strlenght(a));
	return 0;
}