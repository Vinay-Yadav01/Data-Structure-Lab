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

Node* delete(Node *head, int key){
    Node *temp = head;
    while(temp != NULL){
        if(temp==head && temp->val == key){
            Node *temp2 = temp->next;
            head = temp2;
            free(temp);
            break;
        }
        if(temp->next->val == key){
            Node *temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);    
            break;
        }
        temp = temp->next;
    }
    return head;
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
    head = delete(head, key);
    printf("The linked list after deleting: ");
    print(head);
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time Taken: %lf \n",time);
    return 0;
}
