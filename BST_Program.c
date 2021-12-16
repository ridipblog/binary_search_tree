#include<stdio.h>
#include<stdlib.h>
int count=0;
struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};
struct Node * insertIter(struct Node * root)
{
    struct Node * ptr,*parentptr,*nodeptr;
    int val;
    while(1)
    {
        printf("\n0 for exit ");
        printf("\nEnter Value ");
        scanf("%d",&val);
        if(val==0)
            break;
        ptr=(struct Node *)malloc(sizeof(struct Node));
        ptr->data=val;
        ptr->left=NULL;
        ptr->right=NULL;
        if(root==NULL)
        {
            root=ptr;
            root->left=NULL;
            root->right=NULL;
        }
        else
        {
            parentptr=NULL;
            nodeptr=root;
            while(nodeptr!=NULL)
            {
                parentptr=nodeptr;
                if(val<nodeptr->data)
                    nodeptr=nodeptr->left;
                else
                    nodeptr=nodeptr->right;
            }
            if(val<parentptr->data)
                parentptr->left=ptr;
            else
                parentptr->right=ptr;
        }
    }
    return root;
};
void inOrder(struct Node * root)
{
    if(root!=NULL)
    {
        count++;
        inOrder(root->left);
        printf("\n%d ",root->data);
        inOrder(root->right);
    }
}
struct Node * smallVal(struct Node * root)
{
    if((root==NULL)||(root->left==NULL))
    {
        return root;
    }
    else
    {
        return smallVal(root->left);
    }
};
struct Node * bigVal(struct Node * root)
{
    if((root==NULL)||(root->right==NULL))
        return root;
    else
        return bigVal(root->right);
};
struct Node * inOrderPredecessor(struct Node * root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
};
struct Node * deleteVal(struct Node * root,int val)
{
    struct Node * iPre;
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if(val<root->data)
    {
        root->left=deleteVal(root->left,val);
    }
    else if(val>root->right)
    {
        root->right=deleteVal(root->right,val);
    }
    else
    {
        iPre=inOrderPredecessor(root);
        root->data=iPre->data;
        root->left=deleteVal(root->left,iPre->data);
    }
    return root;
};
struct Node * deleteTree(struct Node * root)
{
    if(root!=NULL)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
    return root;
}
void main()
{
    struct Node * tree=NULL;
    struct Node * ptr;
    int option;
    while(1)
    {
        printf("\n1 for insert ");
        printf("\n2 for in order ");
        printf("\n3 for Small Value ");
        printf("\n4 for Bigest Value ");
        printf("\n5 for delete Value ");
        printf("\n0 for exit ");
        scanf("%d",&option);
        if(option==1)
        {
            tree=insertIter(tree);
        }
        else if(option==2)
        {
            count=0;
            inOrder(tree);
            printf("\nCount %d ",count);
        }
        else if(option==3)
        {
            ptr=smallVal(tree);
            printf("\nSmallest Value %d ",ptr->data);
        }
        else if(option==4)
        {
            ptr=bigVal(tree);
            printf("\nBigest Value %d ",ptr->data);
        }
        else if(option==5)
        {
            printf("\nEnter Value ");
            int val;
            scanf("%d",&val);
            tree=deleteVal(tree,val);
        }
        else if(option==0)
        {
            break;
        }
    }
}
