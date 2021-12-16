#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};
struct Node * createNode(int data)
{
    struct Node * n;
    n=(struct Node *)malloc(sizeof(struct Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
};
struct Node * search(struct Node * root,int val)
{
    if(root==NULL)
        return root;
    if(root->data==val)
        return root;
    else if(root->data>val)
        return search(root->left,val);
    else
        return search(root->right,val);
};
struct Node * searchIter(struct Node * root,int val)
{
    while(root!=NULL)
    {
        if(root->data==val)
            return root;
        else if(root->data>val)
            root=root->left;
        else
            root=root->right;
    }
    return NULL;
};
void main()
{
    struct Node *p=createNode(20);
    struct Node *p1=createNode(15);
    struct Node *p2=createNode(28);
    struct Node *p3=createNode(13);
    struct Node *p4=createNode(18);
    struct Node *p5=createNode(25);
    struct Node *p6=createNode(29);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
    p2->right=p6;
    if(search(p,29)==0)
        printf("\nNot Found");
    else
        printf("\nElement Found");
    if(searchIter(p,13)==0)
        printf("\nNot Found");
    else
        printf("\nElement Found");
}
