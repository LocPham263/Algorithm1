#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b){
	int n = b/2;
	int result;
	if(a%b==0) return b;
	else{
		for(int i=1; i<=n; i++){
			int flag = (a%i==0) & (b%i==0);
			if(flag == 1) result = i; 	
		}
		return result;
	}
}

int main(int argc, char const *argv[]){
	// Input 2 natural numbers 
	int a,b;
	scanf("%d %d", &a, &b);
	if(a>=b) printf("%d\n", gcd(a,b));
	else	 printf("%d\n", gcd(b,a));
	return 0;
}