typedef struct Student{
   int marks, order;
   char name[20];
} student;

void init(student *a, int i);
void struct_printer(student a[], int n);
void struct_sort(student a[], int n);
void struct_copy(student *a, student *b);
int* statistic(student a[], int n);

