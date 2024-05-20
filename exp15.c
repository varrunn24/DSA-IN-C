#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node *left;
    int data;
    struct Node *right;
};
struct Node* createNode(){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter Tree Element : ");
    scanf("%d",&temp->data);
    temp->left=temp->right=NULL;
    return temp;
}
void insertNodeInLeft(struct Node *parent){
    parent->left=createNode();

}
void insertNodeInRight(struct Node *parent){
    parent->right=createNode();
}
int search(struct Node *root,int value){
    static int flag=0;
   if(root!=NULL){
    if(root->data==value)
    flag= 1;
    else{
        search(root->left,value);
        search(root->right,value);
    }
   }
   return flag;
}
struct Node* preorder(struct Node *root)
{
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
struct Node* postorder(struct Node *root)
{
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
struct Node* inorder(struct Node *root)
{
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
        
    }
}
int main(){
       struct Node *root=createNode();//17
       insertNodeInRight(root);//72
       insertNodeInLeft(root->right);//35
       insertNodeInLeft(root);//19
       insertNodeInRight(root->right->left);//22
       insertNodeInRight(root->left);//79
       printf("\nPreorder Traversal :  ");
       preorder(root);
       printf("\nPostorder Traversal : ");
       postorder(root);
       printf("\nInorder Traversal : ");
       inorder(root);
       int val;

       printf("\nEnter Searching Element : ");
       scanf("%d",&val);
       if(search(root,val)==1)
       printf("Found !!!!\n");
       else
        printf("Not Found !!!!\n");
       return 0;
}