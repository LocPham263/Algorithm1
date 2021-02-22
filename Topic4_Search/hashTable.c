#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5
typedef struct Item{
    int key;
    int data;
} Item;

Item* hashArray[SIZE];

void Insert(int key, int data);
int Search(int key);
void Delete(int key);
void printHash();

int main(){
    Insert(3,2);
    Insert(4,3);
    Insert(8,7);
    Insert(1,0);
    Insert(6,5);
    printHash();
    // printf("%d\n",Search(8));
    Delete(8);
    printHash();
    return 0;
}

void Insert(int key, int data){
    // Initialise new item
    Item* item = (Item*) malloc(sizeof(Item));
    item->key = key;
    item->data = data;
    // Translate to actual index
    int index = key % SIZE;
    // Hashing search and linear probing
    // Try to find an empty slot to insert (either NULL or DUMMY item)
    while(hashArray[index] != NULL && hashArray[index]->key != -1){
        // Move to the next item
        index++;
        // Make sure all elements are fitted inside the Hash table
        index = index % SIZE;
    }
    // Insert item
    hashArray[index] = item;
}

int Search(int key){
    // Translate to actual index
    int index = key % SIZE;
    int counter = 0;
    // Hashing search and linear probing
    // Try to find the desired slot until reaching the end of the hash array
    while(hashArray[index] != NULL && counter < SIZE){
        if(hashArray[index]->key == key) return hashArray[index]->data;
        // Move to the next item
        index++;
        counter++;
        // Make sure all elements are fitted inside the Hash table
        index = index % SIZE;
    }
    return -1;
}

void Delete(int key){
    // Translate to actual index
    int index = key % SIZE;
    int counter = 0;
    // Hashing search and linear probing
    // Try to find the desired slot until reaching the end of the hash array
    while(hashArray[index] != NULL && counter < SIZE){
        if(hashArray[index]->key == key){
            hashArray[index]->key = -1;
            return;
        }
        index++;
        counter++;
        // Make sure all elements are fitted inside the Hash table
        index = index % SIZE;
    }
}

void printHash(){
    int index = 0;
    while(index < SIZE){
        if(hashArray[index]->key != -1) printf("%d %d\n",hashArray[index]->key,hashArray[index]->data);
        else printf("~ ~\n");
        index++;
    }
    printf("\n");
}