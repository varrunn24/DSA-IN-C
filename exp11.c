#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data; 
    struct Node *next;
};
struct Node *head=NULL;
struct Node *createNode(){
struct Node *temp=(struct Node*)malloc(sizeof(struct Node));//dynamic memory allocation
printf("Enter data:");
scanf("%d",&temp->data);
temp->next=NULL;}
void createlist(){
    int n,i;
    printf("Enter total size of List:");
    scanf("%d",&n);
    struct Node *temp;
    for(i=1;i<=n;i++){
        struct Node *newNode=createNode();
        if(head==NULL)
        head=newNode;
        else{
        temp->next=newNode;
        }
        temp=newNode;
    }
}
void display(){
if(head==NULL)
printf("List is Empty !!!!\n");
else{
    printf("Queue Elements are:");
struct Node *temp=head;
while(temp!=NULL){
printf("%d ",temp->data);
temp=temp->next;
}
}
}
void enqueue(){
struct Node *newNode=createNode();
if(head==NULL)
head=newNode;
else{
    struct Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
}
void dequeue(){
if(head==NULL)
printf("List is Empty !!!!\n");
else
{
struct Node *temp=head;
head=head->next;
printf("Element dequeued:%d\n", temp->data);
}
}
void peek(){
if(head==NULL)
printf("List is Empty !!!!\n");
else{
    printf("Front element of the queue:%d\n",head->data);
}
}
int main()
{
while(1){
//system("cls");
printf("****Implementation of Queue using Linked List****\n");
printf("1. Enqueue element in the List\n");
printf("2. Dequeue element from the List\n");
printf("3. Peek element in the List\n");
printf("4. Display all elements of the List\n");
printf("5. Exit\n");
int choice;
printf("Enter Choice:");
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
//break;
default:
printf("Invalid Choice !!!!\n");
break;
}
system("pause");
}
return 0;
}