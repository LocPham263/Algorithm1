#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // Allocate dynamic memory
    char *dyn;
    dyn = (char*) malloc(30 * sizeof(char));
    strcpy(dyn, "123 465 789");
    strcat(dyn," 987 654 321");
    printf("%s\n",dyn);

    // Static memory
    char sta[30];
    strcpy(sta, "123 456 789\n");
    printf("%s\n",sta);
    return 0;
    
}