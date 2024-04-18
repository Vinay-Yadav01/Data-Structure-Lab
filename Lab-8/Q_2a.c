#include <stdio.h>
#include<time.h>

#define MAX_SIZE 100

int deque[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return front==(rear+1)%MAX_SIZE;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void push_front(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot pushed.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    deque[rear] = value;
}

void pop_front() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    front++;
}

void pop_back() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    front++;
}

void traverse() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i=(i+1)%MAX_SIZE) {
        printf("%d ", deque[i]);
    }
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
    push_front(5);
    push_front(7);
    push_front(9);
    traverse();
    pop_back();
    traverse();
    printf("Front: %d\n", getFront());
    printf("Rear: %d\n", getRear());
    pop_front();
    traverse();
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_spent);
    return 0;
}