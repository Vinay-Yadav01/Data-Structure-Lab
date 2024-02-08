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


Node* deleteBefore(Node *head, int key){
    Node *curr = head, *prev = NULL;
    while(curr != NULL && curr->next != NULL){
        if(curr->next->val == key){
            if(prev == NULL){
                // If the node to delete is the first node
                Node *temp = head;
                head = head->next;
                free(temp);
                break;
            } else {
                // Delete the node before the node with the key value
                Node *temp = prev->next;
                prev->next = temp->next;
                free(temp);
                break;
            }
        }
        prev = curr;
        curr = curr->next;
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
    head = deleteBefore(head, key);
    printf("The linked list after deleting: ");
    print(head);
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time Taken: %lf \n",time);
    return 0;
}
