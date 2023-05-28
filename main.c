#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* data;
    void* next;
} Node;

Node* head = NULL;

// Add
Node* add(const char* data) {
    Node* new = malloc(sizeof(Node));
    if (new == NULL) {
        printf("Error allocating memory\n");
        return NULL;
    }

    new->data = malloc(strlen(data) + 1);
    if (new->data == NULL) {
        printf("Error allocating memory\n");
        free(new);
        return NULL;
    }

    strcpy(new->data, data);
    new->next = head;
    head = new;
    return new;
}

// Delete
int delete(const char* data) {
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->data, data) == 0) {
            if (prev == NULL) {
                head = temp->next;
                free(temp->data);
                free(temp);
                return 1;
            } else {
                prev->next = temp->next;
                free(temp->data);
                free(temp);
                return 1;
            }
        }
        prev = temp;
        temp = temp->next;
    }
    return 0;
}

// Print
void print() {
    Node* temp = head;
    while (temp != NULL) {
        printf(" < %s", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printMenu() {
    printf("\nYou have the following options:\n");
    printf("1. Add\n");
    printf("2. Delete\n");
    printf("3. Insert\n");
    printf("4. Print\n");
    printf("5. Exit\n");
    printf("\nEnter your choice: ");
}

int main() {
    int choice = 0;
    char data[100];

    while (choice != 5) {
        printMenu();
        if (scanf("%d", &choice) == 1 && choice < 5 && choice > 0) {
            switch (choice) {
                case 1:
                    printf("Enter the data to add: ");
                    scanf("%s", data);
                    add(data);
                    break;
                case 2:
                    printf("Enter the data to delete: ");
                    scanf("%s", data);
                    if (delete(data) == 0) {
                        printf("Data not found\n");
                    }
                    break;
                case 3:
                    // insert
                    break;
                case 4:
                    print();
                    break;
                case 5:
                    printf("Exiting...\n");
                    break;
            }
        }
    }

    // Free allocated memory
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    return 0;
}
