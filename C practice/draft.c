#include <stdio.h>
#include <stdlib.h>

int main(){
    int* p1;

    for(int i=0; i<2; i++){
        int n = i;
        p1 = &n;
        printf("%d\n",p1);
    }
    
    return 0;
}