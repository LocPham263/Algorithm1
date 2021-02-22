#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 3;
    char b = 'a';
    void* p;
    p = &a;
    printf("%d\n",*(int*)p);
    p = &b;
    printf("%c\n",*(char*)p);
    return 0;
}