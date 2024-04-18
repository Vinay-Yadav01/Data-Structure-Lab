#include <stdio.h>
#include<time.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return rear == MAX_SIZE - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue() {
    int value;
    printf("Enter the value to be enqueued: ");
    scanf("%d", &value);
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    int value = queue[front];
    front++;
    printf("%d Dequeued successfully.\n", value);
}

void traverse() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int getFront() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue[front];
}

int main() {
    clock_t start = clock();
    int choice;
    printf("\nPerform operations on the Queue:");
    printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.Is Full\n5.Is Empty\n6.Front Element\n7.Size of Queue\n8.End");
    printf("\n\nEnter the choice: ");
    scanf("%d", &choice);
    while (choice != 8)
    {
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            traverse();
            break;
        case 4:
            printf("%d\n", isFull());
            break;
        case 5:
            printf("%d\n", isEmpty());
            break;
        case 6:
            getFront();
            break;
        case 7:
            printf("%d\n", rear + 1);
            break;
        default:
            printf("\nInvalid choice!!");
        }

        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
    }
    enqueue(10);
    enqueue(20);
    enqueue(30);
    traverse();
    dequeue();
    traverse();
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_spent);
    return 0;
}