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
temp->next=NULL;//it is the ist node that is to be creted ryt now , so, it will not cantain the address of its next node
return temp;
}
void display(){
struct Node *temp=head;
if(temp==NULL){
    printf("Stack is Empty !!!!\n");
}
printf("linked List elements are: ");
while(temp!=NULL){
printf("%d ",temp->data);
temp=temp->next;
}
}
void push(){//logic used: insertElementInBeg();-->linked List
struct Node *newNode=createNode();
newNode->next=head;
head=newNode;
}
void pop(){
if(head==NULL)
printf("Stack is Empty !!!!\n");
else{
struct Node *temp=head;
head=head->next;
printf("Element Popped:%d\n",temp->data);
}
}
void peek(){
if(head==NULL){
    printf("Stack is Empty !!!!\n");}
    else{
    printf("Top element of the stack :%d\n",head->data);
    }
}
int main()
    {
while(1){
    //system("cls");
    printf("****Implementation of Stack using Linked List****\n");
    printf("1. Push Element in Stack\n");
    printf("2. Pop Element from Stack\n");
    printf("3. Peek Element at the top of Stack\n");
    printf("4. Display Stack\n");
    printf("5. Exit\n");
    int choice;
    printf("Enter Choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1:
    push();
    break;
    case 2:
    pop();
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
printf("Invalid Choice !!!!\n");
break;
    }
    system("pause");}
return 0;
    }