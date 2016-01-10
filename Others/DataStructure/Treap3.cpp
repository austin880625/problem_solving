#include<iostream>
#include<stdlib.h>

using namespace std;
template<class T>
struct Node
{
    Node *L,*R;
    T value;
    int fix,size;
    Node(T v)
    {
        L=NULL;
        R=NULL;
        value=v;
        fix=rand();
        size=1;
    }
    void maintain()
    {
        size=1;
        if(R!=NULL)size+=R->size;
        if(L!=NULL)size+=L->size;
    }
};
template<class T>
void llRotate(Node<T> *&A)
{
    Node<T> *b=A->R;
    A->R=b->L;
    b->L=A;
    A->maintain();b->maintain();
    A=b;
}
template<class T>
void rrRotate(Node<T> *&A)
{
    Node<T> *b=A->L;
    A->L=b->R;
    b->R=A;
    A->maintain();b->maintain();
    A=b;
}

template<class T>
void Insert(Node<T> *&A,T v)
{
    if(A==NULL)
    {
        A=new Node<T>(v);
    }
    else if(v<A->value)
    {
        A->size++;
        Insert(A->L,v);
        if(A->fix>A->L->fix)rrRotate(A);
    }
    else
    {
        A->size++;
        Insert(A->R,v);
        if(A->fix>A->R->fix)llRotate(A);
    }
}

template<class T>
void Delete(Node<T> *&A,T v)
{
    if(A==NULL)return;
    A->size--;
    if(A->value>v)
        Delete(A->L,v);
    else if(A->value<v)
        Delete(A->R,v);
    else
    {
        if(A->L==NULL||A->R==NULL)
        {
            Node<T> *t=A;
            if(A->L!=NULL)
                A=A->L;
            else
                A=A->R;
            delete t;
        }
        else
        {
            if(A->L->fix>A->R->fix){llRotate(A);Delete(A->L,v);}
            else {rrRotate(A);Delete(A->L,v);}
        }
    }
}

template<class T>
T Rank(Node<T> *&A,T v)
{
    if(A==NULL)return 0;
    if(A->value==v)
    {
        if(A->L==NULL)return 1;
        return A->L->size+1;
    }
    if(A->value>v)return Rank(A->L,v);
    if(A->value<v)return Rank(A->R,v)+(A->L==NULL ? 0 : A->L->size)+1;
}

int main()
{
    srand(time(NULL));
    char com;
    int num;
    Node<int> *root=NULL;
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
    }
    return 0;
}
