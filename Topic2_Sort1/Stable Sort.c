#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Array_Print(int N, char A[][2]);
void String_Copy1(char s[], char A[][2], int N);
void String_Copy2(char B[][2], char A[][2], int Nb, int Na);
void String_Copy3(char A[][2], char s[], int Na);
void S2A(int N, char A[][2], int B[]);
void Bubble_Sort(int N, char A[][2]);
void Selection_Sort(int N, char A[][2]);

int main(int argc, char const *argv[]){
	// Input the total number of cards
	int N;
	scanf("%d", &N);
	// Input cards
	char str[N][2];
	char str1[N][2];
	for(int i=0; i<N; i++){
		scanf("%s", str[i]);
		String_Copy2(str1,str,i,i);
	}

	// Bubble Sort
	Bubble_Sort(N,str);
	// Selection_Sort
	Selection_Sort(N,str1);
	return 0;
}

void Array_Print(int N, char A[][2]){
	for(int i=0; i<N; i++){
		printf("%c", A[i][0]);
		printf("%c ", A[i][1]);
	}
	printf("\n");
}
// str -> s
void String_Copy1(char s[], char A[][2], int N){
	for(int i=0; i<2; i++){
		s[i] = A[N][i];
	}
}
// str -> str
void String_Copy2(char B[][2], char A[][2], int Nb, int Na){
	for(int i=0; i<2; i++){
		B[Nb][i] = A[Na][i];
	}
}
// s -> str
void String_Copy3(char A[][2], char s[], int Na){
	for(int i=0; i<2; i++){
		A[Na][i] = s[i];
	}
}

void S2A(int N, char A[][2], int B[]){
	for(int i=0; i<N; i++){
		char s[2];
		String_Copy1(s,A,i);
		// char *p = s;
		B[i] = atoi(&s[1]);
	}
}

void Detector(int Search[], int Save[], int N, int Search_sounter, int counter){
	for(int i=Search_sounter; i<N-1; i++){
		for(int j=i+1; j<N; j++){
			if(Search[i] == Search[j]){
				Save[counter] = i; 
				counter++;
				Save[counter] = j;
				Search_sounter = j;
				Detector(Search,Save,N,Search_sounter,counter);
				break;
			}
		}
	}
}

void Bubble_Sort(int N, char A[][2]){
	int B[N];
	S2A(N,A,B);
	int Save[]
	int int_x, int_y, int_z;
	char char_x, char_y;

	for(int i=0; i<N-1; i++){
		for(int j=N-1; j>=i+1; j--){
			int k = B[j];
			char s[2]; 
			String_Copy1(s,A,j);
			if(B[j-1] > B[j]){
				B[j] = B[j-1];
				B[j-1] = k;
				String_Copy2(A,A,j,j-1);
				String_Copy3(A,s,j-1);
			}
		}
	}

	for(int i=0; i<N-1; i++){
		for(int j=i+1; j<N; j++){
			if(B[i] == int_z && B[j] == int_z){
				if(A[i][0] == char_x && A[j][0] == char_y){
					if()
				}
				else if(A[j][0] == char_x && A[i][0] == char_y){

				}
				break;
			}
		}
	}

	Array_Print(N,A);
}

void Selection_Sort(int N, char A[][2]){
	int B[N];
	S2A(N,A,B);
	for(int i=0; i<N-1; i++){
		int min = i;
		for(int j=i+1; j<N; j++){
			if(B[j] < B[min]) min = j;
		}
		if(min != i){
			int k = B[min];
			B[min] = B[i];
			B[i] = k;

			char s[2];
			String_Copy1(s,A,min);
			String_Copy2(A,A,min,i);
			String_Copy3(A,s,i);
		}
	}
	Array_Print(N,A);
}