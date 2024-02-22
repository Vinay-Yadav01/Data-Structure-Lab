#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int val;
    struct node *next;
    struct node *prev;
} Node;

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

Node* insert(Node *head, int key, int value)
{
    Node *temp = head;
    while (temp->val != key)
    {
        temp = temp->next;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = temp->next;
    temp->next->prev=newNode;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

int main()
{
    clock_t start = clock();
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    head->prev = NULL;
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
            temp->prev = NULL;
        }
        else
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->val = value;
            newNode->next = NULL;
            temp->next = newNode;
            newNode->prev = temp;
            temp = temp->next;
        }
    }
    temp = head;
    printf("The linked list is: ");
    print(temp);
    int key,value;
    printf("Enter the key: ");
    scanf("%d",&key);
    printf("Enter the value: ");
    scanf("%d",&value);
    head = insert(head,key,value);
    printf("Linked list after Inserting a node: ");
    temp = head;
    print(temp);
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time Taken: %lf \n", time);
    return 0;
}
