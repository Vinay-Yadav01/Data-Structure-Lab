#include <stdio.h>
#include <stdlib.h>

// Structure for deque node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an element at the front of the deque
void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert an element at the rear of the deque
void insertRear(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete an element from the front of the deque
void deleteFront(struct Node** head) {
    if (*head == NULL) {
        printf("Deque is empty.\n");
    } else {
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
    }
}

// Function to delete an element from the rear of the deque
void deleteRear(struct Node** head) {
    if (*head == NULL) {
        printf("Deque is empty.\n");
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        if (temp->prev != NULL) {
            temp->prev->next = NULL;
        } else {
            *head = NULL;
        }
        free(temp);
    }
}

// Function to display the elements of the deque
void display(struct Node* head) {
    if (head == NULL) {
        printf("Deque is empty.\n");
    } else {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Node* deque = NULL;

    // Insert elements at the front
    insertFront(&deque, 1);
    insertFront(&deque, 2);
    insertFront(&deque, 3);

    // Insert elements at the rear
    insertRear(&deque, 4);
    insertRear(&deque, 5);
    insertRear(&deque, 6);

    // Display the deque
    printf("Deque: ");
    display(deque);

    // Delete elements from the front
    deleteFront(&deque);
    deleteFront(&deque);

    // Delete elements from the rear
    deleteRear(&deque);
    deleteRear(&deque);

    // Display the deque
    printf("Deque after deletion: ");
    display(deque);

    return 0;
}