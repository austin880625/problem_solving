//POJ 3580
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
int n,m;

struct Node
{
    int v,sz,flip;
    Node* ch[2];
    Node(){sz=0;}
    Node(int _v):v(_v),sz(1),flip(0){ch[0]=NULL;ch[1]=NULL;}
};
Node* null= new Node();

void init(Node *&O){O->ch[0]=O->ch[1]=null;}
void maintain(Node *&O){O->sz=O->ch[0]->sz+1+O->ch[1]->sz;}
void rotate(Node *&O,int dir)
{
    Node *T=O->ch[dir^1];
    O->ch[dir^1]=T->ch[dir];
    T->ch[dir]=O;
    maintain(O);maintain(T);
    O=T;
}
void pushdown(Node *&O)
{
    if(O->flip)
    {
        swap(O->ch[0],O->ch[1]);
        O->flip=0;
        O->ch[0]->flip^=1;
        O->ch[1]->flip^=1;

    }
}
void Splay(Node *&O,int k)  //splay kth to root
{
    if(k>O->sz)return ;//沒這個東西
    pushdown(O);
    int now=O->ch[0]->sz+1,dir1=(k==now ? -1 : (k<now ? 0 : 1));
    k-=dir1*now;    //如果在左子樹名次不會變，在右子樹要減目前節點的rank

    if(dir1!=-1)//需要轉的話
    {
        //以下是對左子樹做的事
        Node *p=O->ch[dir1];
        pushdown(p);
        int childnow=p->ch[0]->sz+1,dir2=(k==childnow ? -1 : (k<childnow ? 0 : 1)); //子樹節點的rank
        k-=dir2*childnow;
        if(dir2!=-1)    //目標不在孫子
        {
            Splay(p->ch[dir2],k);  //把它轉到孫子
            if(dir1==dir2)  //一字型
            {
                rotate(O,dir1^1); //先轉根
            }
            else    //之字形
            {
                rotate(O->ch[dir1],dir2^1); //先轉兒子
            }
        }
        rotate(O,dir1^1);   //根要再轉一次，一字型：原本的兒子變成根，之字形：原本的根還是根
    }
}
//只要靠splay一切都能搞定
void Split(Node *&O,int k,Node *&A,Node *&B)
{
    Splay(O,k);
    B=O->ch[1];
    O->ch[1]=null;
    A=O;
    if(B!=null)maintain(B);maintain(A);
}
void Merge(Node *&A,Node *&B)
{
    //cout<<A->v<<endl;
    Splay(A,A->sz);
    A->ch[1]=B;
    maintain(A);
}
void Insert(Node *&O,int v)
{
    if(O==NULL){O=new Node(v);init(O);return ;}
    Node* P=new Node(v);
    init(P);
    Merge(O,P);
}

void print(Node*& O)
{
    pushdown(O);
    if(O->ch[0]!=null)print(O->ch[0]);
    if(O->v!=0&&O->v!=n+1)printf("%d\n",O->v);
    if(O->ch[1]!=null)print(O->ch[1]);
}
void solve(Node *&O,int a,int b)
{
    Node *L,*R,*T;
    Split(O,a,L,T);
    Node *mid,*tail;
    Split(T,b-a+1,mid,R);
    //print(mid);
    mid->flip^=1;

    Merge(L,R);
    Merge(L,mid);
    O=L;
}


int main()
{
    Node* ST=NULL;
    null->ch[0]=null->ch[1]=null;
    while(scanf("%d %d",&n,&m)==2)
    {
        ST=NULL;
        for(int i=0;i<=n;i++){Insert(ST,i);}
        //print(ST);cout<<endl;
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            solve(ST,a,b);
            //print(ST);cout<<endl;
        }
        print(ST);
    }
    return 0;
}
