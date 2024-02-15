#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int val;
    struct node *next;
} Node;

void print(Node *head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("%d",temp->val);
    printf("\n");
}

Node* insertAtBegin(Node* head, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = head;
    Node* temp = head;
    while(temp->next != head){
        temp=temp->next;
    }
    temp->next=newNode;
    head=newNode;
    return head;
}

int main()
{
    clock_t start = clock();
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    head->val = 0;
    Node *temp = head;
    int num;
    printf("Enter number of Nodes: ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        int value;
        printf("Enter %d value: ", i + 1);
        scanf("%d", &value);
        if (temp->val == 0)
        {
            temp->val = value;
            temp->next = NULL;
        }
        else
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->val = value;
            newNode->next = NULL;
            temp->next = newNode;
            temp = temp->next;
        }
    }
    temp->next = head;
    printf("The linked list is: ");
    print(head);
    int value;
    printf("Enter value to add at the starting: ");
    scanf("%d",&value);
    head = insertAtBegin(head,value);
    printf("The linked list after adding at the start: ");
    print(head);
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time Taken: %lf \n", time);
    return 0;
}