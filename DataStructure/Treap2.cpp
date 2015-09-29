#include<iostream>

using namespace std;

int ran()
{
    static unsigned x=1739492;
    return x=x*101+3818;
}

struct Node
{
    int val,pri,siz;
    Node *L,*R;
    Node(int v)
    {
        val=v;
        pri=ran();
        siz=1;
        L=NULL;
        R=NULL;
    }
    void maintain()
    {
        int s=1;
        if(L!=NULL)s+=L->siz;
        if(R!=NULL)s+=R->siz;
        siz=s;
    }
};

void lrotate(Node *&A)
{
    Node* B=A->R;
    A->R=B->L;
    B->L=A;
    A->maintain();B->maintain();
    A=B;
}

void rrotate(Node *&A)
{
    Node* B=A->L;
    A->L=B->R;
    B->R=A;
    A->maintain();B->maintain();
    A=B;
}

void Insert(Node *&A,int v)
{
    if(A==NULL)
    {
        Node *P = new Node(v);
        A=P;
    }else if(v<A->val)
    {
        A->siz++;
        Insert(A->L,v);
        if(A->pri>A->L->pri){rrotate(A);}
    }
    else
    {
        A->siz++;
        Insert(A->R,v);
        if(A->pri>A->R->pri){lrotate(A);}
    }
}

void Delete(Node *&A,int v)
{
    if(A==NULL)cout<<v<<" does not exists."<<endl;
    else if(v==A->val)
    {
        Node *P=A;
        if(A->L==NULL||A->R==NULL)
        {
            A=(A->L==NULL ? A->R : A->L);
            delete P;
        }
        else
        {
            if(A->L->pri<A->R->pri){rrotate(A);Delete(A,v);}
            else {lrotate(A);Delete(A,v);}
        }
    }
    else if(v<A->val)
        Delete(A->L,v);
    else
        Delete(A->R,v);
}

int query(Node *&A,int r)
{
    if(A==NULL)return -1;
    int lsiz;
    if(A->L==NULL)lsiz=1;
    else lsiz=A->L->siz+1;

    if(r==lsiz)return A->val;
    else if(r<lsiz)return query(A->L,r);
    else return query(A->R,r-lsiz);
}

int main()
{
    char c;
    int v;
    Node* T=NULL;
    while(cin>>c)
    {
        cin>>v;
        if(c=='i')Insert(T,v);
        if(c=='d')Delete(T,v);
        if(c=='q')cout<<query(T,v)<<endl;
    }
    return 0;
}
