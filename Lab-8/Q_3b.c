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

int isEmpty(struct Deque* deque) {
    return (deque->front == NULL);
}

void insertFront(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front = newNode;
    }
}

void insertRear(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

int deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        exit(1);
    }
    struct Node* temp = deque->front;
    int data = temp->data;
    deque->front = deque->front->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    }
    free(temp);
    return data;
}

int deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        exit(1);
    }
    struct Node* temp = deque->rear;
    int data = temp->data;
    struct Node* current = deque->front;
    while (current->next != deque->rear) {
        current = current->next;
    }
    current->next = NULL;
    deque->rear = current;
    free(temp);
    return data;
}

void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return;
    }
    struct Node* current = deque->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Deque deque;
    deque.front = deque.rear = NULL;

    insertFront(&deque, 1);
    insertFront(&deque, 2);
    insertRear(&deque, 3);
    insertRear(&deque, 4);

    printf("Deque: ");
    display(&deque);

    printf("Deleted front element: %d\n", deleteFront(&deque));
    printf("Deleted rear element: %d\n", deleteRear(&deque));

    printf("Deque after deletion: ");
    display(&deque);

    return 0;
}