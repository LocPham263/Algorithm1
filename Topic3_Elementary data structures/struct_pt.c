#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_pt.h"

void init(student *a, int i){
   // Input marks 
   a->marks = rand() %10 + 1;
   // Input student name
   char s[20] = "Student.no";
   strcpy(a->name,s);
   a->order = i+1;
}

void struct_sort(student a[], int n){
   student k;
   init(&k,0);
   for(int i=0; i<n-1; i++){
      for(int j=i+1; j<n; j++){
         if(a[i].marks < a[j].marks){
            // k = a[i].marks;
            struct_copy(&k,&a[i]);
            // a[i].marks = a[j].marks;
            struct_copy(&a[i],&a[j]);
            // a[j].marks = k;
            struct_copy(&a[j],&k);
         }
      }
   }
}

void struct_copy(student *a, student *b){
   a->marks = b->marks;
   a->order = b->order;
}

void struct_printer(student a[], int n){
   for(int i=0; i<n; i++){
      printf("%s%d      Marks: %d \n", a[i].name, a[i].order, a[i].marks);
   }
}

int* statistic(student a[], int n){
   static int statistic[3];
   for(int i=0; i<n; i++){
      if(a[i].marks >= 8) statistic[0]++;
      else if(a[i].marks >=5) statistic[1]++;
      else statistic[2]++;
   }
   return statistic;
}