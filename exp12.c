#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    int priority;
    struct Node *next;
};
struct Node *head=NULL;
struct Node* createNode(){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data:");
    scanf("%d",&temp->data);
    printf("Enter priority:");
    scanf("%d",&temp->priority);
    temp->next=NULL;
    return temp;
}
void display(){
    struct Node *temp=head;
    if(temp == NULL) {
        printf("Priority Queue is empty!!!\n");
        return;
    }
    printf("Priority Queue elements: ");
    while(temp!=NULL) {
        printf("(%d, %d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}
void enqueue(){
    struct Node *newNode=createNode();
    if(head == NULL || newNode->priority > head->priority) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node *temp = head;
        while(temp->next != NULL && temp->next->priority >= newNode->priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void dequeue(){
    if(head==NULL)
        printf("Priority Queue is empty!!!\n");
    else{
        struct Node *temp=head;
        head=head->next;
        printf("Element dequeued: (%d, %d)\n", temp->data, temp->priority);
        free(temp);
    }
}

void peek(){
    if(head == NULL) {
        printf("Priority Queue is empty!!!\n");
    } else {
        printf("Peek element of the Priority Queue: (%d, %d)\n", head->data, head->priority);
    }
}
int main(){ 
    while(1){
        //system("cls");
        printf("****Implementation of Priority Queue using singly Linked List****\n");
        printf("1. Enqueue Element in Priority Queue\n");
        printf("2. Dequeue Element from Priority Queue\n");
        printf("3. Peek Element of Priority Queue\n");
        printf("4. Display Priority Queue\n");
        printf("5. Exit\n");
        int choice;
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!!!!\n");
                break;
        }
        system("pause");
    }
    return 0;
}