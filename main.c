#include <stdio.h>

typedef struct{
    int data;
    void *next;
} Node;

Node *head = NULL;

//Add
Node *add(int data){
    Node *new = NULL;
    if (head == NULL){
        new = malloc(sizeof(Node));
        if (new == NULL){
            printf("Error allocating memory\n");
            return NULL;
        }
        new->data = data;
        new->next = NULL;
        head = new;
    }

    else{
        new = malloc(sizeof(Node));
        if (new == NULL){
            printf("Error allocating memory\n");
            return NULL;
        }
        new->data = data;
        new->next = head;
        head = new;
    }
    return new;
}

//Delete

//Insert

//Print

void printMenu(){
    printf("You have the following options:\n");
    printf("1. Add\n");
    printf("2. Delete\n");
    printf("3. Insert\n");
    printf("4. Print\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main(int argc, char*argv[]){
    int choice;
    while (choice != 5){
        printMenu();
        if (scanf("%d", &choice) == 1 && choice < 5 && choice > 0){
            switch (choice){
                case 1:
                    //Add
                case 2:
                    //delete
                case 3:
                    //insert
                case 4:
                    //print
                case 5:
                    break;
            }
        }
    }
    
    return 0;
}