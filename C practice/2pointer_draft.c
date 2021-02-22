#include <stdio.h>
// static int a[3] = {1,2,3};

void pt_func(int** array){
    static int a[3] = {1,2,3};
    printf("%d %d\n", *array,a);
    *array = a;
    printf("%d %d\n", *array,a);
    // return array;
}

int main(){
    int* p;
    pt_func(&p);
    for(int i=0; i<3; i++){
        printf("%d ",p[i]);
        printf("\n");
    }
    printf("\n");
    return 0;
}


