#include <stdio.h>
#include <stdlib.h>
#include<time.h>

typedef struct node {
    int val;
    struct node* next;
} Node;

void deleteNode(Node** head, int position) {
    if (*head == NULL) {
        return;
    }
    Node* temp = *head;
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        return;
    }
    Node* nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    clock_t start = clock();
    Node *head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    head->val = 0;
    Node *temp = head;
    for(int i=1;i<5;i++){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->val = i;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
    printf("The linked list is: ");
    print(head);
    int position;
    printf("Enter the position of the node to be deleted: ");
    scanf("%d", &position);
    deleteNode(&head, position);
    printf("Resultant Linked List: ");
    print(head);
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time Taken: %lf \n",time);
    return 0;
}
