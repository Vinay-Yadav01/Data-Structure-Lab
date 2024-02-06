#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node {
    int val;
    struct node* next;
} Node;

void print(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf("\n");
}

void insertAfter(Node *head, int key, int value){
    Node *temp = head;
    while(temp != NULL){
        if(temp->val == key){
            Node *newNode = (Node*)malloc(sizeof(Node));
            newNode->val = value;
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
}

int main(){
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
    int key;
    printf("Enter value of key: ");
    scanf("%d",&key);
    int value;
    printf("Enter value to add: ");
    scanf("%d",&value);
    insertAfter(head, key, value);
    printf("The linked list after adding: ");
    print(head);
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time Taken: %lf \n",time);
    return 0;
}