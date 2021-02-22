#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void fun(){
   int a=0;
   for(int i=0; i<10; i++){
      a++;
   }
}

int main(){
   clock_t t; 
    t = clock(); 
    fun(); 
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
    printf("fun() took %f seconds to execute \n", time_taken); 
   return 0;
}