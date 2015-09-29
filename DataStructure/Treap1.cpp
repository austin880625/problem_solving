#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
    Node *left,*right;
    int value,fix,size;
    Node(int val)
    {
        left=NULL;
        right=NULL;
        value=val;
        fix=rand();
        size=1;
    }
    void maintain()
    {
        size=1;
        if(left!=NULL)size+=left->size;
        if(right!=NULL)size+=right->size;
    }
};

void rRotate(Node *&N)
{
    Node *b=N->left;
    N->left=b->right;
    b->right=N;
    N->maintain();b->maintain();
    N=b;
}
void lRotate(Node *&N)
{
    Node *b=N->right;
    N->right=b->left;
    b->left=N;
    N->maintain();b->maintain();
    N=b;
}

void Insert(Node *&N,int v)
{
    if(N==NULL)
    {
        Node *newNode = new Node(v);
        N=newNode;
    }
    else if(v<N->value)
    {
        N->size++;
        Insert(N->left,v);
        if(N->fix>N->left->fix)
        {rRotate(N);cout<<"rotated"<<endl;}
    }

    else
    {
        N->size++;
        Insert(N->right,v);
        if(N->fix>N->right->fix)
        {lRotate(N);cout<<"rotated"<<endl;}
    }
}

void Delete(Node *&N,int v)
{
    if(N==NULL)return;
    N->size--;
    if(v<N->value)
    {
        Delete(N->left,v);
    }
    if(v>N->value)
    {
        Delete(N->right,v);
    }
    else
    {
        if(N->left==NULL||N->right==NULL)
        {
            Node *t=N;
            if(N->left!=NULL)
            {
                N=N->left;
            }
            else
            {
                N=N->right;
            }
            delete t;
        }
        else
        {
            if(N->left->fix>N->right->fix)
            {
                rRotate(N);
                Delete(N->right,v);
            }
            else
            {
                lRotate(N);
                Delete(N->left,v);
            }
        }
    }
}

int Rank(Node *&N,int v)
{
    if(N==NULL)return 0;
    if(v==N->value){
        if(N->left==NULL)return 1;
        return N->left->size+1;
    }
    else if(v<N->value)return Rank(N->left,v);
    else return (N->left==NULL ? 0 : N->left->size)+Rank(N->right,v)+1;
}
int nodeSize(Node *&N,int v)
{
    if(N->value==v)return N->size;
    if(v<N->value)return nodeSize(N->left,v);
    else return nodeSize(N->right,v);
}

int main()
{
    char com;
    int num;
    Node *root=NULL;
    while(cin>>com)
    {
        cin>>num;
        if(com=='i')
        {
            Insert(root,num);
        }
        if(com=='d')
        {
            Delete(root,num);
        }
        if(com=='q')
        {
            cout<<Rank(root,num)<<endl;
        }
        if(com=='s')
        {
            cout<<nodeSize(root,num)<<endl;
        }
    }
    return 0;
}
