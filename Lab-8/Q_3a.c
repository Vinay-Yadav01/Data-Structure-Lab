#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* deque) {
    return (deque->front == NULL);
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front = newNode;
    }
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

// Function to delete an element from the front of the deque
void deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return;
    }
    struct Node* temp = deque->front;
    deque->front = deque->front->next;
    free(temp);
    if (deque->front == NULL) {
        deque->rear = NULL;
    }
}

// Function to display the elements of the deque
void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return;
    }
    struct Node* temp = deque->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Deque deque;
    deque.front = deque.rear = NULL;

    // Example usage
    insertFront(&deque, 1);
    insertFront(&deque, 2);
    insertRear(&deque, 3);
    insertRear(&deque, 4);
    display(&deque);

    deleteFront(&deque);
    display(&deque);

    return 0;
}