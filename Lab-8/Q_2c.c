#include <stdio.h>
#include<time.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Deque;

void initDeque(Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

int isEmpty(Deque* deque) {
    return (deque->front == -1 && deque->rear == -1);
}

int isFull(Deque* deque) {
    return ((deque->rear + 1) % MAX_SIZE == deque->front);
}

void insertFront(Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    deque->arr[deque->front] = value;
}

void insertRear(Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }

    deque->arr[deque->rear] = value;
}

int deleteFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete.\n");
        return -1;
    }

    int value = deque->arr[deque->front];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }

    return value;
}

int deleteRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete.\n");
        return -1;
    }

    int value = deque->arr[deque->rear];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }

    return value;
}

void printDeque(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    int i = deque->front;
    printf("Deque: ");
    while (i != deque->rear) {
        printf("%d ", deque->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", deque->arr[i]);
}

int main() {
    clock_t start = clock();
    Deque deque;
    initDeque(&deque);
    insertFront(&deque, 1);
    insertFront(&deque, 2);
    insertRear(&deque, 3);
    insertRear(&deque, 4);

    printDeque(&deque);

    int frontValue = deleteFront(&deque);
    int rearValue = deleteRear(&deque);

    printf("Deleted front value: %d\n", frontValue);
    printf("Deleted rear value: %d\n", rearValue);

    printDeque(&deque);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_spent);
    return 0;
}