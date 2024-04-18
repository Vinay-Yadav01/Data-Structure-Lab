#include <stdio.h>
#include<time.h>

#define MAX_SIZE 100

int deque[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void push_front(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot push.\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = MAX_SIZE - 1;
    } else {
        front = front - 1;
    }
    deque[front] = value;
}

void push_back(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot push.\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == MAX_SIZE - 1) {
        rear = 0;
    } else {
        rear = rear + 1;
    }
    deque[rear] = value;
}

void pop_front() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front = front + 1;
    }
}

void traverse() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d ", deque[i]);
    printf("\n");
}

int getFront() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return -1;
    }
    return deque[front];
}

int getRear() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return -1;
    }
    return deque[rear];
}

int main() {
    clock_t start = clock();
    push_front(1);
    push_back(5);
    push_front(9);
    traverse();
    pop_front();
    traverse();
    printf("Front: %d\n", getFront());
    printf("Rear: %d\n", getRear());
    push_back(7);
    traverse();
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_spent);
    return 0;
}