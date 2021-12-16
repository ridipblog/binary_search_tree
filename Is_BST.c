#include<stdio.h>
#include<stdlib.h>
int top=-1,top1_order=0;
struct Node
{
    int data;
    struct Node *left;
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
void inorder(struct Node * root,int arr[])
{
    if(root!=NULL)
    {
        top1_order++;
        inorder(root->left,arr);
        arr[++top]=root->data;
        inorder(root->right,arr);
    }
}
int isBST(struct Node * root)
{
    static struct Node *prev=NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
int isBSTArr(int arr[])
{
    int r=0,j=0;
    for(int i=0;i<top1_order-1;i++)
    {
        j=i+1;
        if(arr[i]<arr[j])
        {
            r=1;
        }
        else
        {
            r=0;
            break;
        }
    }
    return r;
}
void main()
{
    int arr[top1_order];
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
    inorder(p,arr);
    printf("\n %d ",isBST(p));
    if(isBSTArr(arr)==1)
    {
        printf("\nBST Tree");
    }
}

