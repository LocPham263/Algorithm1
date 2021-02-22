#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    printf("%s \n", argv[0]);
    printf("%s \n", argv[1]);
    printf("%d\n", atoi(argv[1])+1);
    return 0;
}