#include "struct_pt.c"

int main(){
   // Input the number of students in the class
   int n;
   printf("\nInput the number of students in the class: ");
   scanf("%d",&n);
   // Initialise data for students in the class
   student stu[n];
   for(int i=0; i<n; i++){
      init(&stu[i], i);
   }
   // Sort students' marks in the list
   struct_sort(stu,n);
   // Print out the final result
   printf("\n\n------------Final result--------------\n");
   struct_printer(stu,n);
   printf("\n");
   printf("-------------Statistic----------------\n");
   int *p = statistic(stu,n);
   printf("G_student: %d\n", *p);
   printf("M_student: %d\n", *(p+1));
   printf("B_student: %d\n", *(p+2));
   printf("\n");
   return 0;
}

